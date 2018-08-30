#include "user_information.h"

user_imformation::user_imformation(QString myname, QString mypassword, QString myquestion, QString myanswer, int ison, QString myip, int myport)
{
    this->username = myname;
    this->password = mypassword;
    this->answer = myanswer;
    this->question = myquestion;
    this->state = ison;
    this->ip = myip;
    this->port = myport;
}

bool user_imformation::setIpPort(QString myname, QString myip, int myport)
{
    if(this->username == myname)
    {
        this->ip = myip;
        this->port = myport;
        return true;
    }
    else return false;
}

bool user_imformation::setstate(QString myname)
{
    if(this->username == myname)
    {
        this->state = 1;
        return true;
    }
    else return false;
}

QString user_imformation::toString()
{
    return QString("%1 %2 %3 %4 ").arg(username).arg(state).arg(ip).arg(port);
}
