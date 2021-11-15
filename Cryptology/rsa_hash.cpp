#include "rsa_hash.h"
#include "ui_rsa_hash.h"
#include <QCryptographicHash>
#include <QString>
#include <md5.h>
#include <string>
#include <sstream>
#include <rsa.h>
#include <math.h>
#include <QMessageBox>

Q_DECLARE_METATYPE(MD5);
RSA_Hash::RSA_Hash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RSA_Hash)
{
    ui->setupUi(this);
    ui->input_outputTextEdit->setVisible(false);
    ui->Decode->setVisible(false);
    ui->labelN->setVisible(false);
    ui->labelPublicKey->setVisible(false);
    ui->labelPrivateKey->setVisible(false);
    connect(ui->Generate, SIGNAL(clicked()),this,SLOT(setOutputTextEdit()));
    connect(ui->Decode, SIGNAL(clicked()),this,SLOT(setInput_OutputTextEdit()));
    connect(ui->Clear, SIGNAL(clicked()),this, SLOT(clear()));
    connect(ui->Functions, SIGNAL(currentTextChanged(const QString &)), this, SLOT(Edits(const QString &)));
    ui->outputTextEdit->setReadOnly(true);
    ui->input_outputTextEdit->setReadOnly(true);
}

void RSA_Hash::clear(){
    emit ui->inputTextEdit->clear();
    emit ui->input_outputTextEdit->clear();
    emit ui->outputTextEdit->clear();
    emit ui->labelPrivateKey->setText("public key d =");
    emit ui->labelPublicKey->setText("public key e =");
}

void RSA_Hash::setOutputTextEdit(){
    std::string input = ui->inputTextEdit->toPlainText().toStdString();  //wieso ist es hier pointer und nicht besitzer?
    std::string output;
    if(ui->Functions->currentText() == "RSA"){
        if(input == ""){
           QMessageBox msgbox;
           msgbox.setText("There is no input");
           msgbox.exec();
        }
        else{
            RSA rsa(input);
            this->privateKey = rsa.d;
            this->encryptedValues = rsa.encryptedValues;
            ui->labelPublicKey->setText("public key e = " + QString::number(rsa.e));
            ui->labelPrivateKey->setText("private key d = " + QString::number(rsa.d));
            output = rsa.encryptedValueOfTheMessage;
            emit ui->input_outputTextEdit->setText(QString::fromLocal8Bit(output.c_str()));
        }
    }
    else{
        MD5 md5(input);
        std::string output = "The hash value of my MD5 function: "  + md5.hashValueOfInput;
        QString encodedPass = QString(QCryptographicHash::hash(input.data(),QCryptographicHash::Md5).toHex());
        output += "\nThe hash value of the Qt MD5 function: " + encodedPass.toStdString();
        emit ui->outputTextEdit->setText(QString::fromLocal8Bit(output.c_str()));
    }
}

void RSA_Hash::setInput_OutputTextEdit(){
    RSA rsa;
    rsa.decryptTheMessage(this->privateKey, this->encryptedValues);
    std::string output = rsa.decryptedValueOfTheMessage;
    emit ui->outputTextEdit->setText(QString::fromLocal8Bit(output.c_str()));
}

void RSA_Hash::Edits(const QString &){
    if(ui->Functions->currentText() == "RSA"){
        ui->input_outputTextEdit->setVisible(true);
        ui->Decode->setVisible(true);
        ui->labelN->setVisible(true);
        ui->labelPublicKey->setVisible(true);
        ui->labelPrivateKey->setVisible(true);
        ui->Generate->setText("Encode");
    }
    else{
        ui->input_outputTextEdit->setVisible(false);
        ui->Decode->setVisible(false);
        ui->labelN->setVisible(false);
        ui->labelPublicKey->setVisible(false);
        ui->labelPrivateKey->setVisible(false);
        ui->Generate->setText("Generate");
    }
    emit this->clear();
}

RSA_Hash::~RSA_Hash()
{
    delete ui;
}
