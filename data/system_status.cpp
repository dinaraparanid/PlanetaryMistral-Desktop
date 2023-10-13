#include "system_status.h"

using namespace planetary_mistral::data;

system_status::system_status() {}

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
        const std::string& selection_info,
        const system_time& time,
        const system_view& view
) : location(location),
    selection_info(QString::fromStdString(selection_info)),
    time(time),
    view(view) {}

system_status::system_status(const system_status& status) :
    location(status.location),
    selection_info(status.selection_info),
    time(status.time),
    view(status.view) {}

system_status::system_status(system_status&& status) :
    location(std::move(status.location)),
    selection_info(std::move(status.selection_info)),
    time(std::move(status.time)),
    view(std::move(status.view)) {}
