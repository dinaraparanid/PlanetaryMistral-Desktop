#ifndef SYSTEM_STATUS_MODEL_H
#define SYSTEM_STATUS_MODEL_H

#include <QObject>

#include "data/system_status.h"

namespace planetary_mistral {
    namespace presentation {
        class system_status_model : public QObject {
            Q_OBJECT

            Q_PROPERTY(QString planet READ planet WRITE set_planet NOTIFY planet_changed)
            Q_PROPERTY(QString local_time READ local_time WRITE set_local_time NOTIFY local_time_changed)

        public:
            explicit system_status_model(QObject* parent = nullptr);

            system_status_model(
                    const data::system_status& status,
                    QObject* parent = nullptr
            );

            system_status_model(
                    data::system_status&& status,
                    QObject* parent = nullptr
            );

            system_status_model(
                    const QString& planet,
                    const QString& local_time,
                    QObject* parent = nullptr
            );

            system_status_model(
                    QString&& planet,
                    QString&& local_time,
                    QObject* parent = nullptr
            );

            system_status_model(
                    const system_status_model& status,
                    QObject* parent = nullptr
            );

            system_status_model(
                    system_status_model&& status,
                    QObject* parent = nullptr
            );

            system_status_model& operator=(const system_status_model& other) {
                if (this == &other)
                    return *this;

                set_planet(other.m_planet);
                set_local_time(other.m_local_time);
                return *this;
            }

            system_status_model& operator=(system_status_model&& other) {
                if (this == &other)
                    return *this;

                set_planet(other.m_planet);
                set_local_time(other.m_local_time);
                return *this;
            }

            const QString& planet() const;
            void set_planet(const QString& planet);
            void set_planet(QString&& planet);

            const QString& local_time() const;
            void set_local_time(const QString& local_time);
            void set_local_time(QString&& local_time);

        signals:
            void planet_changed();
            void local_time_changed();

        private:
            QString m_planet;
            QString m_local_time;
        };
    }
}

Q_DECLARE_METATYPE(planetary_mistral::presentation::system_status_model)

#endif // SYSTEM_STATUS_MODEL_H
