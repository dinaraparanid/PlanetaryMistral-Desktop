#include "system_time.h"

using system_time = planetary_mistral::data::system_time;

system_time::system_time() {}

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
    time_now(is_time_now),
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
    time_now(is_time_now),
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
        const std::string& local,
        const std::string& time_zone,
        const long double timerate,
        const std::string& utc
) : delta_t(delta_t),
    gmt_shift(gmt_shift),
    time_now(is_time_now),
    jday(jday),
    local(QString::fromStdString(local)),
    time_zone(QString::fromStdString(time_zone)),
    timerate(timerate),
    utc(QString::fromStdString(utc)) {}

system_time::system_time(const system_time& time) :
    delta_t(time.delta_t),
    gmt_shift(time.gmt_shift),
    time_now(time.time_now),
    jday(time.jday),
    local(time.local),
    time_zone(time.time_zone),
    timerate(time.timerate),
    utc(time.utc) {}

system_time::system_time(system_time&& time) :
    delta_t(std::move(time.delta_t)),
    gmt_shift(std::move(time.gmt_shift)),
    time_now(std::move(time.time_now)),
    jday(std::move(time.jday)),
    local(std::move(time.local)),
    time_zone(std::move(time.time_zone)),
    timerate(std::move(time.timerate)),
    utc(std::move(time.utc)) {}
