#include <QApplication>
#include "rsa_hash.h"
#include <QString>
#include <string>

int main (int argc, char *argv[]){
    QApplication app(argc,argv);
    RSA_Hash window {};
    window.show();
    return app.exec();
}
