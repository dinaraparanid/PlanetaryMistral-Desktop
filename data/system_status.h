#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include "system_location.h"
#include "system_time.h"
#include "system_view.h"

namespace planetary_mistral {
    namespace data {
        struct system_status {
            system_location location;
            QString selection_info;
            system_time time;
            system_view view;

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
                    const std::u16string& selection_info,
                    const system_time& time,
                    const system_view& view
            );
        };
    }
}

#endif // SYSTEM_STATUS_H
