
#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include "system_location.h"
#include "system_time.h"
#include "system_view.h"

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        class system_status : public QObject {
            Q_OBJECT

            Q_PROPERTY(planetary_mistral::data::system_location location READ location WRITE set_location NOTIFY location_changed)
            Q_PROPERTY(QString selection_info READ selection_info WRITE set_selection_info NOTIFY selection_info_changed)
            Q_PROPERTY(planetary_mistral::data::system_time time READ time WRITE set_time NOTIFY time_changed)
            Q_PROPERTY(planetary_mistral::data::system_view view READ view WRITE set_view NOTIFY view_changed)

            Q_PROPERTY(QString planet READ planet WRITE set_planet NOTIFY planet_changed)
            Q_PROPERTY(QString local READ local WRITE set_local NOTIFY local_changed)

        public:
            static system_status from_json(json& obj, QObject* parent = nullptr) {
                return system_status(
                        system_location::from_json(obj["location"], parent),
                        obj["selectioninfo"].get<std::string>(),
                        system_time::from_json(obj["time"], parent),
                        system_view::from_json(obj["view"], parent)
                );
            }

            explicit system_status(QObject* parent = nullptr);

            system_status(
                    const system_location& location,
                    const QString& selection_info,
                    const system_time& time,
                    const system_view& view,
                    QObject* parent = nullptr
            );

            system_status(
                    system_location&& location,
                    QString&& selection_info,
                    system_time&& time,
                    system_view&& view,
                    QObject* parent = nullptr
            );

            system_status(
                    const system_location& location,
                    const std::string& selection_info,
                    const system_time& time,
                    const system_view& view,
                    QObject* parent = nullptr
            );

            system_status(
                    const system_status& status,
                    QObject* parent = nullptr
            );

            system_status(
                    system_status&& status,
                    QObject* parent = nullptr
            );

            system_status operator=(const system_status& other) {
                if (this == &other)
                    return *this;

                set_location(other.m_location);
                set_selection_info(other.m_selection_info);
                set_time(other.m_time);
                set_view(other.m_view);

                return *this;
            }

            system_status operator=(system_status&& other) {
                if (this == &other)
                    return *this;

                set_location(std::move(other.m_location));
                set_selection_info(std::move(other.m_selection_info));
                set_time(std::move(other.m_time));
                set_view(std::move(other.m_view));

                return *this;
            }

            const system_location& location() const;
            void set_location(const system_location& location);
            void set_location(system_location&& location);

            const QString& selection_info() const;
            void set_selection_info(const QString& selection_info);
            void set_selection_info(QString&& selection_info);

            const system_time& time() const;
            void set_time(const system_time& time);
            void set_time(system_time&& time);

            const system_view& view() const;
            void set_view(const system_view& view);
            void set_view(system_view&& view);

            const QString& planet() const;
            void set_planet(const QString& planet);
            void set_planet(QString&& planet);

            const QString& local() const;
            void set_local(const QString& local);
            void set_local(QString&& local);

        signals:
            void location_changed();
            void selection_info_changed();
            void time_changed();
            void view_changed();

            void planet_changed();
            void local_changed();

        private:
            system_location m_location;
            QString m_selection_info;
            system_time m_time;
            system_view m_view;
        };
    }
}

Q_DECLARE_METATYPE(planetary_mistral::data::system_status)

#endif // SYSTEM_STATUS_H
