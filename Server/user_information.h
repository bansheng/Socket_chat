#ifndef USER_IMFORMATION_H
#define USER_IMFORMATION_H
#include <QString>

class user_imformation
{
public:
    QString username;
    QString password;
    QString question;
    QString answer;
    int state;//1表示在线，0表示不在线
    QString ip;
    int port;
    user_imformation(QString myname, QString mypassword, QString myquestion, QString myanswer, int ison=0, QString myip="ip", int myport=0);
    bool setIpPort(QString myname, QString myip, int myport);
    bool setstate(QString myname);
    QString toString();
};

#endif // USER_IMFORMATION_H
