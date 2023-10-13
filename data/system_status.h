#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include "system_location.h"
#include "system_time.h"
#include "system_view.h"

#include "domain/json.hpp"

namespace planetary_mistral {
    namespace data {
        struct system_status {
            system_location location;
            QString selection_info;
            system_time time;
            system_view view;

            static system_status from_json(nlohmann::json& obj) {
                return system_status(
                        system_location::from_json(obj["location"]),
                        obj["selectioninfo"].get<std::string>(),
                        system_time::from_json(obj["time"]),
                        system_view::from_json(obj["view"])
                );
            }

            system_status();

            system_status(
                    const system_location& location,
                    const QString& selection_info,
                    const system_time& time,
                    const system_view& view
            );

            system_status(
                    system_location&& location,
                    QString&& selection_info,
                    system_time&& time,
                    system_view&& view
            );

            system_status(
                    const system_location& location,
                    const std::string& selection_info,
                    const system_time& time,
                    const system_view& view
            );

            explicit system_status(const system_status& status);
            explicit system_status(system_status&& status);

            system_status& operator=(const system_status& other) {
                if (this == &other)
                    return *this;

                location = other.location;
                selection_info = other.selection_info;
                time = other.time;
                view = other.view;

                return *this;
            }

            system_status& operator=(system_status&& other) {
                if (this == &other)
                    return *this;

                location = std::move(other.location);
                selection_info = std::move(other.selection_info);
                time = std::move(other.time);
                view = std::move(other.view);

                return *this;
            }
        };
    }
}

#endif // SYSTEM_STATUS_H
