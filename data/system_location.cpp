#include "system_location.h"

namespace planetary_mistral {
    namespace data {
        system_location::system_location(
                const int altitude,
                const QString& landscape_key,
                const double latitude,
                const double longitude,
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
                const double latitude,
                const double longitude,
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
                const std::u16string& landscape_key,
                const double latitude,
                const double longitude,
                const std::u16string& name,
                const std::u16string& planet,
                const std::u16string& region,
                const std::u16string& role,
                const std::u16string& state
        ) : altitude(altitude),
            landscape_key(QString::fromStdU16String(landscape_key)),
            latitude(latitude),
            longitude(longitude),
            name(QString::fromStdU16String(name)),
            planet(QString::fromStdU16String(planet)),
            region(QString::fromStdU16String(region)),
            role(QString::fromStdU16String(role)),
            state(QString::fromStdU16String(state)) {}
    }
}
