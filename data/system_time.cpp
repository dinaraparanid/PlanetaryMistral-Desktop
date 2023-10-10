#include "system_time.h"

namespace planetary_mistral {
    namespace data {
        system_time::system_time(
                const long double delta_t,
                const long double gmt_shift,
                const bool is_time_now,
                const long double jday,
                const QString& local,
                const QString& time_zone,
                const long double timerate,
                const QString& utc
        ) : delta_t(delta_t),
            gmt_shift(gmt_shift),
            is_time_now(is_time_now),
            jday(jday),
            local(local),
            time_zone(time_zone),
            timerate(timerate),
            utc(utc) {}

        system_time::system_time(
                const long double delta_t,
                const long double gmt_shift,
                const bool is_time_now,
                const long double jday,
                QString&& local,
                QString&& time_zone,
                const long double timerate,
                QString&& utc
        ) : delta_t(delta_t),
            gmt_shift(gmt_shift),
            is_time_now(is_time_now),
            jday(jday),
            local(local),
            time_zone(time_zone),
            timerate(timerate),
            utc(utc) {}

        system_time::system_time(
                const long double delta_t,
                const long double gmt_shift,
                const bool is_time_now,
                const long double jday,
                const std::u16string& local,
                const std::u16string& time_zone,
                const long double timerate,
                const std::u16string& utc
        ) : delta_t(delta_t),
            gmt_shift(gmt_shift),
            is_time_now(is_time_now),
            jday(jday),
            local(QString::fromStdU16String(local)),
            time_zone(QString::fromStdU16String(time_zone)),
            timerate(timerate),
            utc(QString::fromStdU16String(utc)) {}
    }
}
