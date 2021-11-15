#ifndef RSA_HASH_H
#define RSA_HASH_H

#include <QWidget>
#include <rsa.h>;

namespace Ui {
class RSA_Hash;
}

class RSA_Hash : public QWidget
{
    Q_OBJECT

public:
    explicit RSA_Hash(QWidget *parent = nullptr);
    ~RSA_Hash();

public slots:
    void setOutputTextEdit();
    void Edits(const QString &);
    void setInput_OutputTextEdit();
    void clear();
private:
    Ui::RSA_Hash *ui;
    uint64_t privateKey;
    std::vector<uint64_t> encryptedValues;
};

#endif // RSA_HASH_H
