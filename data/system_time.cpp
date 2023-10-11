#include "system_time.h"

using system_time = planetary_mistral::data::system_time;

system_time::system_time(QObject* parent) : QObject(parent) {}

system_time::system_time(
        const long double delta_t,
        const long double gmt_shift,
        const bool is_time_now,
        const long double jday,
        const QString& local,
        const QString& time_zone,
        const long double timerate,
        const QString& utc,
        QObject* parent
) : QObject(parent),
    m_delta_t(delta_t),
    m_gmt_shift(gmt_shift),
    m_time_now(is_time_now),
    m_jday(jday),
    m_local(local),
    m_time_zone(time_zone),
    m_timerate(timerate),
    m_utc(utc) {}

system_time::system_time(
        const long double delta_t,
        const long double gmt_shift,
        const bool is_time_now,
        const long double jday,
        QString&& local,
        QString&& time_zone,
        const long double timerate,
        QString&& utc,
        QObject* parent
) : QObject(parent),
    m_delta_t(delta_t),
    m_gmt_shift(gmt_shift),
    m_time_now(is_time_now),
    m_jday(jday),
    m_local(local),
    m_time_zone(time_zone),
    m_timerate(timerate),
    m_utc(utc) {}

system_time::system_time(
        const long double delta_t,
        const long double gmt_shift,
        const bool is_time_now,
        const long double jday,
        const std::string& local,
        const std::string& time_zone,
        const long double timerate,
        const std::string& utc,
        QObject* parent
) : QObject(parent),
    m_delta_t(delta_t),
    m_gmt_shift(gmt_shift),
    m_time_now(is_time_now),
    m_jday(jday),
    m_local(QString::fromStdString(local)),
    m_time_zone(QString::fromStdString(time_zone)),
    m_timerate(timerate),
    m_utc(QString::fromStdString(utc)) {}

system_time::system_time(const system_time& time, QObject* parent) :
    QObject(parent),
    m_delta_t(time.m_delta_t),
    m_gmt_shift(time.m_gmt_shift),
    m_time_now(time.m_time_now),
    m_jday(time.m_jday),
    m_local(time.m_local),
    m_time_zone(time.m_time_zone),
    m_timerate(time.m_timerate),
    m_utc(time.m_utc) {}

system_time::system_time(system_time&& time, QObject* parent) :
    QObject(parent),
    m_delta_t(time.m_delta_t),
    m_gmt_shift(time.m_gmt_shift),
    m_time_now(time.m_time_now),
    m_jday(time.m_jday),
    m_local(time.m_local),
    m_time_zone(time.m_time_zone),
    m_timerate(time.m_timerate),
    m_utc(time.m_utc) {}

long double system_time::delta_t() const { return m_delta_t; }

void system_time::set_delta_t(long double delta_t) {
    m_delta_t = delta_t;
    emit(delta_t_changed());
}

long double system_time::gmt_shift() const { return m_gmt_shift; }

void system_time::set_gmt_shift(long double gmt_shift) {
    m_gmt_shift = gmt_shift;
    emit(gmt_shift_changed());
}

bool system_time::time_now() const { return m_time_now; }

void system_time::set_time_now(bool time_now) {
    m_time_now = time_now;
    emit(time_now_changed());
}

long double system_time::jday() const { return m_jday; }

void system_time::set_jday(long double jday) {
    m_jday = jday;
    emit(jday_changed());
}

const QString& system_time::local() const { return m_local; }

void system_time::set_local(const QString& local) {
    m_local = local;
    emit(local_changed());
}

void system_time::set_local(QString&& local) {
    m_local = local;
    emit(local_changed());
}

const QString& system_time::time_zone() const { return m_time_zone; }

void system_time::set_time_zone(const QString& time_zone) {
    m_time_zone = time_zone;
    emit(time_zone_changed());
}

void system_time::set_time_zone(QString&& time_zone) {
    m_time_zone = time_zone;
    emit(time_zone_changed());
}

long double system_time::timerate() const { return m_timerate; }

void system_time::set_timerate(long double timerate) {
    m_timerate = timerate;
    emit(timerate_changed());
}

const QString& system_time::utc() const { return m_utc; }

void system_time::set_utc(const QString& utc) {
    m_utc = utc;
    emit(utc_changed());
}

void system_time::set_utc(QString&& utc) {
    m_utc = utc;
    emit(utc_changed());
}
