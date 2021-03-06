#ifndef QLIVECODINGCHAT
#define QLIVECODINGCHAT

#include <QMap>
#include <QDateTime>
#include <QXmppClient.h>

#include "../core/qchatservice.h"

class QNetworkAccessManager;

class QXmppMucManager;
class QXmppMessage;

class QWebSocket;

class QLivecodingChat: public QChatService
{
    Q_OBJECT
public:
    explicit                    QLivecodingChat( QObject * parent = nullptr );
                                ~QLivecodingChat() override;
private:
    void                        loadSettings();

    //sid for websocket statistic connection
    void                        loadSid();

    //join afte 3probe received from livecoding
    //void                        joinToChannel();

    void                        loadSmiles() override;

//    void                        loadStatistic();

    void                        connectToWebSocket();
    void                        disconnectFromWebSocket();
    void                        reconnectToWebSocket();

protected:
    void                        timerEvent( QTimerEvent * event ) override;
public slots:
    void                        connect() override;
    void                        disconnect() override;
    void                        reconnect() override;
private slots:
    void                        onConnected();
    void                        onError( QXmppClient::Error );
    void                        onMessageReceived( const QXmppMessage & message );

    void                        onSidLoaded();
    void                        onSidLoadError();

//    void                        onJoinToChannelReplyLoaded();
//    void                        onJoinToChannelReplyLoadError();

    void                        onWebSocketConnected();
    void                        onWebSocketError();
    void                        onWebSocketMessageReceived( const QString & message );

    void                        onSmilesLoaded();
    void                        onSmilesLoadError();

//    void                        onStatisticLoaded();
//    void                        onStatisticLoadError();

    void                        LoadUserInfo( const QString & userName );

    void                        onUserInfoLoaded();
    void                        onUserInfoLoadError();

    void                        changeBadges( bool badges );

private:
    QNetworkAccessManager *     nam_;
    QXmppClient *               xmppClient_ = {nullptr};
    QXmppMucManager *           mucManager_ = {nullptr};
    QWebSocket *                socket_ = {nullptr};
    QString                     sid_;
    QString                     channelName_;
    QString                     login_;
    QString                     password_;
    QDateTime                   connectionTime_;
    int                         reconnectTimerId_ = {-1};
    int                         reconnectWebSocketTimerId_ = {-1};
    int                         saveWebSocketConnectionTimerId_ = {-1};
//    int                         statisticTimerId_;
//    int                         statisticInterval_;
    bool                        badges_ = {false};
    QMap<QString, QString>      badgesMap_;

    static const QString        SERVICE_NAME;
    static const QString        SERVICE_USER_NAME;

    static const int            RECONNECT_INTERVAL;
    static const int            RECONNECT_WEB_SOCKET_INTERVAL;
    static const int            SAVE_WEB_SOCKET_CONNECTION_INTERVAL;
};

#endif // QLIVECODINGCHAT

