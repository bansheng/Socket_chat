#include "user_imformation.h"

user_imformation::user_imformation(QString myname, int ison, QString myip, int myport, bool myhasbeenConnected)
{
    this->username = myname;
    this->state = ison;
    this->ip = myip;
    this->port = myport;
    this->hasbeenConnected = myhasbeenConnected;
}

QString user_imformation::toString()
{
    return QString("%1 %2 %3 %4 ").arg(username).arg(state).arg(ip).arg(port);
}
