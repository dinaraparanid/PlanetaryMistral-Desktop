#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <QObject>
#include <QString>

#include <string>

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        class system_time : public QObject {
            Q_OBJECT

            Q_PROPERTY(long double delta_t READ delta_t WRITE set_delta_t NOTIFY delta_t_changed)
            Q_PROPERTY(long double gmt_shift READ gmt_shift WRITE set_gmt_shift NOTIFY gmt_shift_changed)
            Q_PROPERTY(bool time_now READ time_now WRITE set_time_now NOTIFY time_now_changed)
            Q_PROPERTY(long double jday READ jday WRITE set_jday NOTIFY jday_changed)
            Q_PROPERTY(QString local READ local WRITE set_local NOTIFY local_changed)
            Q_PROPERTY(QString time_zone READ time_zone WRITE set_time_zone NOTIFY time_zone_changed)
            Q_PROPERTY(long double timerate READ timerate WRITE set_timerate NOTIFY timerate_changed)
            Q_PROPERTY(QString utc READ utc WRITE set_utc NOTIFY utc_changed)

        public:
            static system_time from_json(json& obj, QObject* parent = nullptr) {
                return system_time(
                        obj["deltaT"].get<long double>(),
                        obj["gmtShift"].get<long double>(),
                        obj["isTimeNow"].get<bool>(),
                        obj["jday"].get<long double>(),
                        obj["local"].get<std::string>(),
                        obj["timeZone"].get<std::string>(),
                        obj["timerate"].get<long double>(),
                        obj["utc"].get<std::string>(),
                        parent
                );
            }

            explicit system_time(QObject* parent = nullptr);

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    const QString& local,
                    const QString& time_zone,
                    long double timerate,
                    const QString& utc,
                    QObject* parent = nullptr
            );

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    QString&& local,
                    QString&& time_zone,
                    long double timerate,
                    QString&& utc,
                    QObject* parent = nullptr
            );

            system_time(
                    long double delta_t,
                    long double gmt_shift,
                    bool is_time_now,
                    long double jday,
                    const std::string& local,
                    const std::string& time_zone,
                    long double timerate,
                    const std::string& utc,
                    QObject* parent = nullptr
            );

            system_time& operator=(const system_time& other) {
                if (this == &other)
                    return *this;

                set_delta_t(other.m_delta_t);
                set_gmt_shift(other.m_gmt_shift);
                set_time_now(other.m_time_now);
                set_jday(other.m_jday);
                set_local(other.m_local);
                set_time_zone(other.m_time_zone);
                set_timerate(other.m_timerate);
                set_utc(other.m_utc);

                return *this;
            }

            system_time& operator=(system_time&& other) {
                if (this == &other)
                    return *this;

                set_delta_t(std::move(other.m_delta_t));
                set_gmt_shift(std::move(other.m_gmt_shift));
                set_time_now(std::move(other.m_time_now));
                set_jday(std::move(other.m_jday));
                set_local(std::move(other.m_local));
                set_time_zone(std::move(other.m_time_zone));
                set_timerate(std::move(other.m_timerate));
                set_utc(std::move(other.m_utc));

                return *this;
            }

            system_time(const system_time& time, QObject* parent = nullptr);
            system_time(system_time&& time, QObject* parent = nullptr);

            long double delta_t() const;
            void set_delta_t(long double delta_t);

            long double gmt_shift() const;
            void set_gmt_shift(long double gmt_shift);

            bool time_now() const;
            void set_time_now(bool time_now);

            long double jday() const;
            void set_jday(long double jday);

            const QString& local() const;
            void set_local(const QString& local);
            void set_local(QString&& local);

            const QString& time_zone() const;
            void set_time_zone(const QString& time_zone);
            void set_time_zone(QString&& time_zone);

            long double timerate() const;
            void set_timerate(long double timerate);

            const QString& utc() const;
            void set_utc(const QString& utc);
            void set_utc(QString&& utc);

        signals:
            void delta_t_changed();
            void gmt_shift_changed();
            void time_now_changed();
            void jday_changed();
            void local_changed();
            void time_zone_changed();
            void timerate_changed();
            void utc_changed();

        private:
            long double m_delta_t;
            long double m_gmt_shift;
            bool m_time_now;
            long double m_jday;
            QString m_local;
            QString m_time_zone;
            long double m_timerate;
            QString m_utc;
        };
    }
}

Q_DECLARE_METATYPE(planetary_mistral::data::system_time)

#endif // SYSTEM_TIME_H
