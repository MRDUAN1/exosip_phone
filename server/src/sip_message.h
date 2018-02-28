#ifndef SIP_MESSAGE_H
#define SIP_MESSAGE_H

#include <QObject>

class sip_message : public QObject
{
	Q_OBJECT

public:
	sip_message(QObject *parent);
	~sip_message();

private:
	
};

#endif // SIP_MESSAGE_H
