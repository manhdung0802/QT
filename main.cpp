#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "todomodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/CvsQml_ToDoList/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qmlRegisterType<TodoModel>("manhdung",1,0,"TodoModel");

    engine.load(url);

    return app.exec();
}
