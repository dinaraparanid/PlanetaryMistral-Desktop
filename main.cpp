#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickView>
#include <QQmlContext>
#include <QDebug>

#include "data/system_location.h"
#include "data/system_status.h"
#include "data/system_time.h"
#include "data/system_view.h"

#include "domain/client.h"

using namespace planetary_mistral;

int main(int argc, char** argv) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<data::system_location>("com.paranid5.planetary_mistral", 1, 0, "system_location");
    qmlRegisterType<data::system_time>("com.paranid5.planetary_mistral", 1, 0, "system_time");
    qmlRegisterType<data::system_view>("com.paranid5.planetary_mistral", 1, 0, "system_view");
    qmlRegisterType<data::system_status>("com.paranid5.planetary_mistral", 1, 0, "system_status");

    auto client = domain::make_client();
    auto stat = domain::get_system_status(client);

    if (stat.has_value())
        engine.rootContext()->setContextProperty("system", &stat.value());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
