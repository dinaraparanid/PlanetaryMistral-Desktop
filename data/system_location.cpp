#include "system_location.h"

using system_location = planetary_mistral::data::system_location;

system_location::system_location() {}

system_location::system_location(
        const int altitude,
        const QString& landscape_key,
        const long double latitude,
        const long double longitude,
        const QString& name,
        const QString& planet,
        const QString& region,
        const QString& role,
        const QString& state
) : altitude(altitude),
    landscape_key(landscape_key),
    latitude(latitude),
    longitude(longitude),
    name(name),
    planet(planet),
    region(region),
    role(role),
    state(state) {}

system_location::system_location(
        const int altitude,
        QString&& landscape_key,
        const long double latitude,
        const long double longitude,
        QString&& name,
        QString&& planet,
        QString&& region,
        QString&& role,
        QString&& state
) : altitude(altitude),
    landscape_key(landscape_key),
    latitude(latitude),
    longitude(longitude),
    name(name),
    planet(planet),
    region(region),
    role(role),
    state(state) {}

system_location::system_location(
        const int altitude,
        const std::string& landscape_key,
        const long double latitude,
        const long double longitude,
        const std::string& name,
        const std::string& planet,
        const std::string& region,
        const std::string& role,
        const std::string& state
) : altitude(altitude),
    landscape_key(QString::fromStdString(landscape_key)),
    latitude(latitude),
    longitude(longitude),
    name(QString::fromStdString(name)),
    planet(QString::fromStdString(planet)),
    region(QString::fromStdString(region)),
    role(QString::fromStdString(role)),
    state(QString::fromStdString(state)) {}

system_location::system_location(const system_location& location) :
    altitude(location.altitude),
    landscape_key(location.landscape_key),
    latitude(location.latitude),
    longitude(location.longitude),
    name(location.name),
    planet(location.planet),
    region(location.region),
    role(location.role),
    state(location.state) {}

system_location::system_location(system_location&& location) :
    altitude(std::move(location.altitude)),
    landscape_key(std::move(location.landscape_key)),
    latitude(std::move(location.latitude)),
    longitude(std::move(location.latitude)),
    name(std::move(location.name)),
    planet(std::move(location.planet)),
    region(std::move(location.planet)),
    role(std::move(location.role)),
    state(std::move(location.role)) {}
