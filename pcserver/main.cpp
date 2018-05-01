#include <QApplication>
#include <QTranslator>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QTextCodec>
#include <QMessageBox>
#include <QDebug>

#if defined(__APPLE__) || defined(MACOSX)
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else
    #include <Windows.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
    //#include "GLUT/glut.h"//depends on where you put GLUT
#endif


//#ifndef Q_OS_WIN
//#include "3rdparty/eventdispatcher_libev/eventdispatcher_libev.h"
//#endif

#include "mainwindow.h"
//#include "logindialog.h"
//#include "networkinformation.h"
#include "utils.h"
#include "xmlparser.h"

SettingInfo settingInfo;
SessionInfo sessionInfo;

int main(int argc, char *argv[]) {
    settingInfo.sysName = PCSERVER_NAME;
    settingInfo.sysVersion = PCSERVER_VERSION;
    settingInfo.sysDate = PCSERVER_DATE;

//    glutInit(&argc, argv);

    // 处理消息
//    qInstallMessageHandler(Utils::MessageHandler);
//#ifndef Q_OS_WIN
//    QCoreApplication::setEventDispatcher(new EventDispatcherLibEv());
//#endif

    QTextCodec *pCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(pCodec);
    //
    QApplication app(argc, argv);

    // Load an application style
    QFile styleFile( ":/qdarkstyle/style.qss" );
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style( styleFile.readAll());
    app.setStyleSheet( style );

    QTranslator translator;

    translator.load(":/res/language/qt_zh_CN.qm");
    app.installTranslator(&translator);

//    if(!EncryptModule) {
//        return 1;
//    }


//    if (!db.connectMySQL()) {
//        return 1;
//    }

    QSplashScreen *splash = new QSplashScreen;

    splash->setPixmap(QPixmap(":/res/images/logo.png"));
    splash->show();

//    LoginDialog *login = new LoginDialog;
//    Utils::Sleep(1000);// sleep 1s for start logo
//    login->show();

    MainWindow *mainwindow = new MainWindow;
    mainwindow->show();

//    NetworkInformation *network = new NetworkInformation;
//    network->show();

//    QByteArray a = QString("admin").toLocal8Bit().toBase64();
//    QString newStr(a);
//    qDebug() << newStr << " " << QTextCodec::codecForName("GBK")->toUnicode(QByteArray::fromBase64(newStr.toLocal8Bit()));;

    splash->finish(mainwindow);
//    splash->finish(login);
    delete splash;

    return app.exec();
}
