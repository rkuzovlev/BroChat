#ifndef QCHATSTATISTIC
#define QCHATSTATISTIC

#include <QObject>
#include <QString>

class QChatStatistic: public QObject
{
    Q_OBJECT
public:
            QChatStatistic( const QString & service, const QString & statistic, QObject * parent = nullptr );
            ~QChatStatistic() override;
public:
    QString service() const;
    void    setService( const QString & service );

    QString statistic() const;
    void    setStatistic( const QString & statistic );
private:
    QString service_;
    QString statistic_;
};

#endif // QCHATSTATISTIC

