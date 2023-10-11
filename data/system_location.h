#ifndef SYSTEM_LOCATION_H
#define SYSTEM_LOCATION_H

#include <QObject>
#include <QString>

#include <string>

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        class system_location : public QObject {
            Q_OBJECT

            Q_PROPERTY(int altitude READ altitude WRITE set_altitude NOTIFY altitude_changed)
            Q_PROPERTY(QString landscape_key READ landscape_key WRITE set_landscape_key NOTIFY landscape_key_changed)
            Q_PROPERTY(long double latitude READ latitude WRITE set_latitude NOTIFY latitude_changed)
            Q_PROPERTY(long double longitude READ longitude WRITE set_longitude NOTIFY longitude_changed)
            Q_PROPERTY(QString name READ name WRITE set_name NOTIFY name_changed)
            Q_PROPERTY(QString planet READ planet WRITE set_planet NOTIFY planet_changed)
            Q_PROPERTY(QString region READ region WRITE set_region NOTIFY region_changed)
            Q_PROPERTY(QString role READ role WRITE set_role NOTIFY role_changed)
            Q_PROPERTY(QString state READ state WRITE set_state NOTIFY state_changed)

        public:
            static system_location from_json(json& obj, QObject* parent = nullptr) {
                return system_location(
                        obj["altitude"].get<int>(),
                        obj["landscapeKey"].get<std::string>(),
                        obj["latitude"].get<long double>(),
                        obj["longitude"].get<long double>(),
                        obj["name"].get<std::string>(),
                        obj["planet"].get<std::string>(),
                        obj["region"].get<std::string>(),
                        obj["role"].get<std::string>(),
                        obj["state"].get<std::string>(),
                        parent
                );
            }

            explicit system_location(QObject* parent = nullptr);

            system_location(
                    int altitude,
                    const QString& landscape_key,
                    long double latitude,
                    long double longitude,
                    const QString& name,
                    const QString& planet,
                    const QString& region,
                    const QString& role,
                    const QString& state,
                    QObject* parent = nullptr
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
                    QString&& state,
                    QObject* parent = nullptr
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
                    const std::string& state,
                    QObject* parent = nullptr
            );

            system_location(const system_location& location, QObject* parent = nullptr);
            system_location(system_location&& location, QObject* parent = nullptr);

            system_location& operator=(const system_location& other) {
                if (this == &other)
                    return *this;

                set_altitude(other.m_altitude);
                set_landscape_key(other.m_landscape_key);
                set_latitude(other.m_latitude);
                set_longitude(other.m_longitude);
                set_name(other.m_name);
                set_planet(other.m_planet);
                set_region(other.m_region);
                set_role(other.m_role);
                set_state(other.m_state);

                return *this;
            }

            system_location& operator=(system_location&& other) {
                if (this == &other)
                    return *this;

                set_altitude(std::move(other.m_altitude));
                set_landscape_key(std::move(other.m_landscape_key));
                set_latitude(std::move(other.m_latitude));
                set_longitude(std::move(other.m_longitude));
                set_name(std::move(other.m_name));
                set_planet(std::move(other.m_planet));
                set_region(std::move(other.m_region));
                set_role(std::move(other.m_role));
                set_state(std::move(other.m_state));

                return *this;
            }

            int altitude() const;
            void set_altitude(int altitude);

            const QString& landscape_key() const;
            void set_landscape_key(const QString& landscape_key);
            void set_landscape_key(QString&& landscape_key);

            long double latitude() const;
            void set_latitude(long double latitude);

            long double longitude() const;
            void set_longitude(long double longitude);

            const QString& name() const;
            void set_name(const QString& name);
            void set_name(QString&& name);

            const QString& planet() const;
            void set_planet(const QString& planet);
            void set_planet(QString&& planet);

            const QString& region() const;
            void set_region(const QString& region);
            void set_region(QString&& region);

            const QString& role() const;
            void set_role(const QString& role);
            void set_role(QString&& role);

            const QString& state() const;
            void set_state(const QString& state);
            void set_state(QString&& state);

        signals:
            void altitude_changed();
            void landscape_key_changed();
            void latitude_changed();
            void longitude_changed();
            void name_changed();
            void planet_changed();
            void region_changed();
            void role_changed();
            void state_changed();

        private:
            int m_altitude;
            QString m_landscape_key;
            long double m_latitude;
            long double m_longitude;
            QString m_name;
            QString m_planet;
            QString m_region;
            QString m_role;
            QString m_state;
        };
    }
}

Q_DECLARE_METATYPE(planetary_mistral::data::system_location)

#endif // SYSTEM_LOCATION_H
