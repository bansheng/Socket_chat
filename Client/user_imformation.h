#ifndef USER_IMFORMATION_H
#define USER_IMFORMATION_H
#include <QString>

class user_imformation
{
public:
    QString username;
    int state;//1表示在线，0表示不在线
    QString ip;
    int port;
    bool hasbeenConnected;
    user_imformation(QString myname, int ison, QString myip, int myport, bool myhasbeenConnected=false);
    QString toString();
};

#endif // USER_IMFORMATION_H
