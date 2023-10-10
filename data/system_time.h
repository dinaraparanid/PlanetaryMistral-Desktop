#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <QString>
#include <string>

namespace planetary_mistral {
    namespace data {
        struct system_time {
            double delta_t;
            double gmt_shift;
            bool is_time_now;
            double jday;
            QString local;
            QString time_zone;
            double timerate;
            QString utc;

            system_time(
                    double delta_t,
                    double gmt_shift,
                    bool is_time_now,
                    double jday,
                    const QString& local,
                    const QString& time_zone,
                    double timerate,
                    const QString& utc
            );

            system_time(
                    double delta_t,
                    double gmt_shift,
                    bool is_time_now,
                    double jday,
                    QString&& local,
                    QString&& time_zone,
                    double timerate,
                    QString&& utc
            );

            system_time(
                    double delta_t,
                    double gmt_shift,
                    bool is_time_now,
                    double jday,
                    const std::u16string& local,
                    const std::u16string& time_zone,
                    double timerate,
                    const std::u16string& utc
            );
        };
    }
}

#endif // SYSTEM_TIME_H
