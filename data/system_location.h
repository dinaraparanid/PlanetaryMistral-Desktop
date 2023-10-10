#ifndef SYSTEM_LOCATION_H
#define SYSTEM_LOCATION_H

#include <QString>
#include <string>

#include "domain/json.hpp"

using json = nlohmann::json;

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

            static system_location from_json(json& obj) {
                return system_location(
                        obj["altitude"].get<int>(),
                        obj["landscapeKey"].get<std::u16string>(),
                        obj["latitude"].get<long double>(),
                        obj["longitude"].get<long double>(),
                        obj["name"].get<std::u16string>(),
                        obj["planet"].get<std::u16string>(),
                        obj["region"].get<std::u16string>(),
                        obj["role"].get<std::u16string>(),
                        obj["state"].get<std::u16string>()
                );
            }

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
                    const std::u16string& landscape_key,
                    long double latitude,
                    long double longitude,
                    const std::u16string& name,
                    const std::u16string& planet,
                    const std::u16string& region,
                    const std::u16string& role,
                    const std::u16string& state
            );
        };
    }
}

#endif // SYSTEM_LOCATION_H
