#ifndef NETWORK_H
#define NETWORK_H

#include <QThread>

class network : public QThread
{
	Q_OBJECT

public:
	network(QObject *parent);
	~network();
protected:
	void run();
private:
	
};

#endif // NETWORK_H
