#include "system_location.h"

using system_location = planetary_mistral::data::system_location;

system_location::system_location(QObject* parent) : QObject(parent) {}

system_location::system_location(
        const int altitude,
        const QString& landscape_key,
        const long double latitude,
        const long double longitude,
        const QString& name,
        const QString& planet,
        const QString& region,
        const QString& role,
        const QString& state,
        QObject* parent
) : QObject(parent),
    m_altitude(altitude),
    m_landscape_key(landscape_key),
    m_latitude(latitude),
    m_longitude(longitude),
    m_name(name),
    m_planet(planet),
    m_region(region),
    m_role(role),
    m_state(state) {}

system_location::system_location(
        const int altitude,
        QString&& landscape_key,
        const long double latitude,
        const long double longitude,
        QString&& name,
        QString&& planet,
        QString&& region,
        QString&& role,
        QString&& state,
        QObject* parent
) : QObject(parent),
    m_altitude(altitude),
    m_landscape_key(landscape_key),
    m_latitude(latitude),
    m_longitude(longitude),
    m_name(name),
    m_planet(planet),
    m_region(region),
    m_role(role),
    m_state(state) {}

system_location::system_location(
        const int altitude,
        const std::string& landscape_key,
        const long double latitude,
        const long double longitude,
        const std::string& name,
        const std::string& planet,
        const std::string& region,
        const std::string& role,
        const std::string& state,
        QObject* parent
) : QObject(parent),
    m_altitude(altitude),
    m_landscape_key(QString::fromStdString(landscape_key)),
    m_latitude(latitude),
    m_longitude(longitude),
    m_name(QString::fromStdString(name)),
    m_planet(QString::fromStdString(planet)),
    m_region(QString::fromStdString(region)),
    m_role(QString::fromStdString(role)),
    m_state(QString::fromStdString(state)) {}

system_location::system_location(const system_location& location, QObject* parent) :
    QObject(parent),
    m_altitude(location.m_altitude),
    m_landscape_key(location.m_landscape_key),
    m_latitude(location.m_latitude),
    m_longitude(location.m_longitude),
    m_name(location.m_name),
    m_planet(location.m_planet),
    m_region(location.m_region),
    m_role(location.m_role),
    m_state(location.m_state) {}

system_location::system_location(system_location&& location, QObject* parent) :
    QObject(parent),
    m_altitude(location.m_altitude),
    m_landscape_key(location.m_landscape_key),
    m_latitude(location.m_latitude),
    m_longitude(location.m_longitude),
    m_name(location.m_name),
    m_planet(location.m_planet),
    m_region(location.m_region),
    m_role(location.m_role),
    m_state(location.m_state) {}

int system_location::altitude() const { return m_altitude; }

void system_location::set_altitude(const int altitude) {
    m_altitude = altitude;
    emit(altitude_changed());
}

const QString& system_location::landscape_key() const { return m_landscape_key; }

void system_location::set_landscape_key(const QString& landscape_key) {
    m_landscape_key = landscape_key;
    emit(landscape_key_changed());
}

void system_location::set_landscape_key(QString&& landscape_key) {
    m_landscape_key = landscape_key;
    emit(landscape_key_changed());
}

long double system_location::latitude() const { return m_latitude; }

void system_location::set_latitude(const long double latitude) {
    m_latitude = latitude;
    emit(latitude_changed());
}

long double system_location::longitude() const { return m_longitude; }

void system_location::set_longitude(const long double longitude) {
    m_longitude = longitude;
    emit(longitude_changed());
}

const QString& system_location::name() const { return m_name; }

void system_location::set_name(const QString& name) {
    m_name = name;
    emit(name_changed());
}

void system_location::set_name(QString&& name) {
    m_name = name;
    emit(name_changed());
}

const QString& system_location::planet() const { return m_planet; }

void system_location::set_planet(const QString& planet) {
    m_planet = planet;
    emit(planet_changed());
}

void system_location::set_planet(QString&& planet) {
    m_planet = planet;
    emit(planet_changed());
}

const QString& system_location::region() const { return m_region; }

void system_location::set_region(const QString& region) {
    m_region = region;
    emit(region_changed());
}

void system_location::set_region(QString&& region) {
    m_region = region;
    emit(region_changed());
}

const QString& system_location::role() const { return m_role; }

void system_location::set_role(const QString& role) {
    m_role = role;
    emit(role_changed());
}

void system_location::set_role(QString&& role) {
    m_role = role;
    emit(role_changed());
}

const QString& system_location::state() const { return m_state; }

void system_location::set_state(const QString& state) {
    m_state = state;
    emit(state_changed());
}

void system_location::set_state(QString&& state) {
    m_state = state;
    emit(state_changed());
}
