#include "system_status.h"

namespace planetary_mistral {
    namespace data {
        system_status::system_status(
                const system_location& location,
                const QString& selection_info,
                const system_time& time,
                const system_view& view
        ) : location(location),
            selection_info(selection_info),
            time(time),
            view(view) {}

        system_status::system_status(
                system_location&& location,
                QString&& selection_info,
                system_time&& time,
                system_view&& view
        ) : location(location),
            selection_info(selection_info),
            time(time),
            view(view) {}

        system_status::system_status(
                const system_location& location,
                const std::u16string& selection_info,
                const system_time& time,
                const system_view& view
        ) : location(location),
            selection_info(QString::fromStdU16String(selection_info)),
            time(time),
            view(view) {}
    }
}
