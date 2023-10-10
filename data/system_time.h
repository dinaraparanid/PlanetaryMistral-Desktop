#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <QString>
#include <string>

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        struct system_time {
            long double delta_t;
            long double gmt_shift;
            bool is_time_now;
            long double jday;
            QString local;
            QString time_zone;
            long double timerate;
            QString utc;

            static system_time from_json(json& obj) {
                return system_time(
                        obj["deltaT"].get<long double>(),
                        obj["gmtShift"].get<long double>(),
                        obj["isTimeNow"].get<bool>(),
                        obj["jday"].get<long double>(),
                        obj["local"].get<std::u16string>(),
                        obj["timeZone"].get<std::u16string>(),
                        obj["timerate"].get<long double>(),
                        obj["utc"].get<std::u16string>()
                );
            }

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
                    const std::u16string& local,
                    const std::u16string& time_zone,
                    long double timerate,
                    const std::u16string& utc
            );
        };
    }
}

#endif // SYSTEM_TIME_H
