#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <QString>
#include <string>

#include "domain/json.hpp"

namespace planetary_mistral {
    namespace data {
        struct system_time {
            long double delta_t;
            long double gmt_shift;
            bool time_now;
            long double jday;
            QString local;
            QString time_zone;
            long double timerate;
            QString utc;

            static system_time from_json(nlohmann::json& obj) {
                return system_time(
                        obj["deltaT"].get<long double>(),
                        obj["gmtShift"].get<long double>(),
                        obj["isTimeNow"].get<bool>(),
                        obj["jday"].get<long double>(),
                        obj["local"].get<std::string>(),
                        obj["timeZone"].get<std::string>(),
                        obj["timerate"].get<long double>(),
                        obj["utc"].get<std::string>()
                );
            }

            system_time();

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    const QString& local,
                    const QString& time_zone,
                    long double timerate,
                    const QString& utc
            );

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    QString&& local,
                    QString&& time_zone,
                    long double timerate,
                    QString&& utc
            );

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    const std::string& local,
                    const std::string& time_zone,
                    long double timerate,
                    const std::string& utc
            );

            explicit system_time(const system_time& time);
            explicit system_time(system_time&& time);

            system_time& operator=(const system_time& other) {
                if (this == &other)
                    return *this;

                delta_t = other.delta_t;
                gmt_shift = other.gmt_shift;
                time_now = other.time_now;
                jday = other.jday;
                local = other.local;
                time_zone = other.time_zone;
                timerate = other.timerate;
                utc = other.utc;

                return *this;
            }

            system_time& operator=(system_time&& other) {
                if (this == &other)
                    return *this;

                delta_t = std::move(other.delta_t);
                gmt_shift = std::move(other.gmt_shift);
                time_now = std::move(other.time_now);
                jday = std::move(other.jday);
                local = std::move(other.local);
                time_zone = std::move(other.time_zone);
                timerate = std::move(other.timerate);
                utc = std::move(other.utc);

                return *this;
            }
        };
    }
}

#endif // SYSTEM_TIME_H
