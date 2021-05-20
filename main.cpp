#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "factory.h"
#include "file.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Factory factory;
        engine.rootContext()->setContextProperty("factory", &factory);
    File file;
        engine.rootContext()->setContextProperty("file", &file);

    return app.exec();
}
