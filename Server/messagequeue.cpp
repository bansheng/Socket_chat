#include "messagequeue.h"

messageQueue::messageQueue(QString mymessage, QString myname, messageQueue* mynext, bool mysend)
{
    this->message = mymessage;
    this->recvname = myname;
    this->next = mynext;
    this->issended = mysend;
}
