#ifndef SYSTEM_LOCATION_H
#define SYSTEM_LOCATION_H

#include <QString>
#include <string>

namespace planetary_mistral {
    namespace data {
        struct system_location {
            int altitude;
            QString landscape_key;
            double latitude;
            double longitude;
            QString name;
            QString planet;
            QString region;
            QString role;
            QString state;

            system_location(
                    int altitude,
                    const QString& landscape_key,
                    double latitude,
                    double longitude,
                    const QString& name,
                    const QString& planet,
                    const QString& region,
                    const QString& role,
                    const QString& state
            );

            system_location(
                    int altitude,
                    QString&& landscape_key,
                    double latitude,
                    double longitude,
                    QString&& name,
                    QString&& planet,
                    QString&& region,
                    QString&& role,
                    QString&& state
            );

            system_location(
                    int altitude,
                    const std::u16string& landscape_key,
                    double latitude,
                    double longitude,
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
