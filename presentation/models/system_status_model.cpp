#include "system_status_model.h"

using namespace planetary_mistral;

presentation::system_status_model::system_status_model(QObject* parent) : QObject(parent) {}

presentation::system_status_model::system_status_model(
        const data::system_status& status,
        QObject* parent
) : QObject(parent),
    m_planet(status.location.planet),
    m_local_time(status.time.local) {}

presentation::system_status_model::system_status_model(
        data::system_status&& status,
        QObject* parent
) : QObject(parent),
    m_planet(std::move(status.location.planet)),
    m_local_time(std::move(status.time.local)) {}

presentation::system_status_model::system_status_model(
        const QString& planet,
        const QString& local_time,
        QObject* parent
) : QObject(parent),
    m_planet(planet),
    m_local_time(local_time) {}

presentation::system_status_model::system_status_model(
        QString&& planet,
        QString&& local_time,
        QObject* parent
) : QObject(parent),
    m_planet(planet),
    m_local_time(local_time) {}

presentation::system_status_model::system_status_model(
        const presentation::system_status_model& status,
        QObject* parent
) : QObject(parent),
    m_planet(status.m_planet),
    m_local_time(status.m_local_time) {}

presentation::system_status_model::system_status_model(
        presentation::system_status_model&& status,
        QObject* parent
) : QObject(parent),
m_planet(std::move(status.m_planet)),
m_local_time(std::move(status.m_local_time)) {}

const QString& presentation::system_status_model::planet() const { return m_planet; }

void presentation::system_status_model::set_planet(const QString& planet) {
    m_planet = planet;
    emit(planet_changed());
}

void presentation::system_status_model::set_planet(QString&& planet) {
    m_planet = planet;
    emit(planet_changed());
}

const QString& presentation::system_status_model::local_time() const { return m_local_time; }

void presentation::system_status_model::set_local_time(const QString& local_time) {
    m_local_time = local_time;
    emit(local_time_changed());
}

void presentation::system_status_model::set_local_time(QString&& local_time) {
    m_local_time = local_time;
    emit(local_time_changed());
}
