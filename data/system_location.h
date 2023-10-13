#ifndef SYSTEM_LOCATION_H
#define SYSTEM_LOCATION_H

#include <QString>
#include <string>

#include "domain/json.hpp"

namespace planetary_mistral {
    namespace data {
        struct system_location {
            int altitude;
            QString landscape_key;
            long double latitude;
            long double longitude;
            QString name;
            QString planet;
            QString region;
            QString role;
            QString state;

            static system_location from_json(nlohmann::json& obj) {
                return system_location(
                        obj["altitude"].get<int>(),
                        obj["landscapeKey"].get<std::string>(),
                        obj["latitude"].get<long double>(),
                        obj["longitude"].get<long double>(),
                        obj["name"].get<std::string>(),
                        obj["planet"].get<std::string>(),
                        obj["region"].get<std::string>(),
                        obj["role"].get<std::string>(),
                        obj["state"].get<std::string>()
                );
            }

            system_location();

            system_location(
                    int altitude,
                    const QString& landscape_key,
                    long double latitude,
                    long double longitude,
                    const QString& name,
                    const QString& planet,
                    const QString& region,
                    const QString& role,
                    const QString& state
            );

            system_location(
                    int altitude,
                    QString&& landscape_key,
                    long double latitude,
                    long double longitude,
                    QString&& name,
                    QString&& planet,
                    QString&& region,
                    QString&& role,
                    QString&& state
            );

            system_location(
                    int altitude,
                    const std::string& landscape_key,
                    long double latitude,
                    long double longitude,
                    const std::string& name,
                    const std::string& planet,
                    const std::string& region,
                    const std::string& role,
                    const std::string& state
            );

            explicit system_location(const system_location& location);
            explicit system_location(system_location&& location);

            system_location& operator=(const system_location& other) {
                if (this == &other)
                    return *this;

                altitude = other.altitude;
                landscape_key = other.landscape_key;
                latitude = other.latitude;
                longitude = other.longitude;
                name = other.name;
                planet = other.planet;
                region = other.region;
                role = other.role;
                state = other.state;

                return *this;
            }

            system_location& operator=(system_location&& other) {
                if (this == &other)
                    return *this;

                altitude = std::move(other.altitude);
                landscape_key = std::move(other.landscape_key);
                latitude = std::move(other.latitude);
                longitude = std::move(other.longitude);
                name = std::move(other.name);
                planet = std::move(other.planet);
                region = std::move(other.region);
                role = std::move(other.role);
                state = std::move(other.state);

                return *this;
            }
        };
    }
}

#endif // SYSTEM_LOCATION_H
