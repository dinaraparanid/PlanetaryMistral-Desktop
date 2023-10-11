#include "system_status.h"

using namespace planetary_mistral::data;

system_status::system_status(QObject* parent) : QObject(parent) {}

system_status::system_status(
        const system_location& location,
        const QString& selection_info,
        const system_time& time,
        const system_view& view,
        QObject* parent
) : QObject(parent),
    m_location(location),
    m_selection_info(selection_info),
    m_time(time),
    m_view(view) {}

system_status::system_status(
        system_location&& location,
        QString&& selection_info,
        system_time&& time,
        system_view&& view,
        QObject* parent
) : QObject(parent),
    m_location(location),
    m_selection_info(selection_info),
    m_time(time),
    m_view(view) {}

system_status::system_status(
        const system_location& location,
        const std::string& selection_info,
        const system_time& time,
        const system_view& view,
        QObject* parent
) : QObject(parent),
    m_location(location),
    m_selection_info(QString::fromStdString(selection_info)),
    m_time(time),
    m_view(view) {}

system_status::system_status(const system_status& status, QObject* parent) :
    QObject(parent),
    m_location(status.m_location),
    m_selection_info(status.m_selection_info),
    m_time(status.m_time),
    m_view(status.m_view) {}

system_status::system_status(system_status&& status, QObject* parent) :
    QObject(parent),
    m_location(status.m_location),
    m_selection_info(status.m_selection_info),
    m_time(status.m_time),
    m_view(status.m_view) {}

const system_location& system_status::location() const { return m_location; }

void system_status::set_location(const system_location& location) {
    m_location = location;
    emit(location_changed());
}

void system_status::set_location(system_location&& location) {
    m_location = location;
    emit(location_changed());
}

const QString& system_status::selection_info() const { return m_selection_info; }

void system_status::set_selection_info(const QString& selection_info) {
    m_selection_info = selection_info;
    emit(selection_info_changed());
}

void system_status::set_selection_info(QString&& selection_info) {
    m_selection_info = selection_info;
    emit(selection_info_changed());
}

const system_time& system_status::time() const { return m_time; }

void system_status::set_time(const system_time& time) {
    m_time = time;
    emit(time_changed());
}

void system_status::set_time(system_time&& time) {
    m_time = time;
    emit(time_changed());
}

const system_view& system_status::view() const { return m_view; }

void system_status::set_view(const system_view& view) {
    m_view = view;
    emit(view_changed());
}

void system_status::set_view(system_view&& view) {
    m_view = view;
    emit(view_changed());
}

const QString& system_status::planet() const { return m_location.planet(); }

void system_status::set_planet(const QString& planet) {
    m_location.set_planet(planet);
    emit(planet_changed());
}

void system_status::set_planet(QString&& planet) {
    m_location.set_planet(planet);
    emit(planet_changed());
}

const QString& system_status::local() const { return m_time.local(); }

void system_status::set_local(const QString& local) {
    m_time.set_local(local);
    emit(local_changed());
}

void system_status::set_local(QString&& local) {
    m_time.set_local(local);
    emit(local_changed());
}
