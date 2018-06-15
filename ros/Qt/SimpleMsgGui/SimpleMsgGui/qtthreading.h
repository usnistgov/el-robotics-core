#ifndef QTTHREADING_H
#define QTTHREADING_H

#include <QMainWindow>
#include <QObject>
#include <QThread>
#include <QMutex>
#include <QThread>
#include <QVector>
#include <QString>
#include <QTcpSocket>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QTcpServer>

#include <functional>
#include <memory>
#include <assert.h>
using namespace std::placeholders;

class QtSocketThreadBase;

class QtSocketThreadBase: public QThread
{
    Q_OBJECT
public:
    QtSocketThreadBase(QThread *parent = 0);
    ~QtSocketThreadBase(){}
    void connection(const QString &ipAddr, const ushort port );
    void disconnect();
    void startThread();
    void stopThread();
    int readBytes(void *buffer, size_t size, bool nothrow=false);
    bool writeBytes(void * buffer, size_t size, bool nothrow=true);
    int waitForInput();
    virtual void run();
    void suspend();
    void resume();
    void SendMessage(std::string, int type=0);
    void waitIfPaused();
    void multiline_ascii_write(std::string lines);
    bool isRunning();

    QString mIP;
    ushort mPort;
    QTcpSocket *socket;
    int type;
protected:
    void setRunThread( bool newVal );
    bool getRunThread();
    QMutex mMutex;
    QMutex sync;
    QWaitCondition pauseCond;
    bool pause;

private:
    bool mRunThread;
signals:
    void TypedMessageEmitted(int, QString);
};

class QtStatusConnection : public QtSocketThreadBase
{
    Q_OBJECT
public:
    QtStatusConnection(QThread *parent = 0);
    void run();
    void SendJoints();
protected:
    QMutex mMutex;
signals:
    void UpdateJointsEmitted();

};
class QtCommandConnection : public QtSocketThreadBase
{
    Q_OBJECT
public:
    QtCommandConnection(QThread *parent = 0);
    void run();

protected:
    QMutex mMutex;

};


#endif // QTTHREADING_H
