#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <QString>
class messageQueue
{
public:
    QString message;
    QString recvname; //接受者
    messageQueue* next;
    bool issended;
    messageQueue(QString mymessage, QString myname, messageQueue* mynext=NULL, bool mysend=false);
};

#endif // MESSAGEQUEUE_H
