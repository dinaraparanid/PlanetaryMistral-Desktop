#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "data/system_status.h"
#include "presentation/models/system_status_model.h"

#include "domain/client.h"

using namespace planetary_mistral;

int main(int argc, char** argv) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    presentation::system_status_model* sys = nullptr;
    auto client_opt = domain::make_client();

    if (client_opt.has_value()) {
        auto stat = domain::get_system_status(client_opt.value());

        if (stat.has_value()) {
            sys = new presentation::system_status_model(stat.value());
            engine.rootContext()->setContextProperty("system", sys);
        }
    }

    engine.load(QUrl(QStringLiteral("qrc:/presentation/ui/main.qml")));

    auto res = app.exec();
    if (sys != nullptr) delete sys;
    return res;
}
