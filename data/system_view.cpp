#include "system_view.h"

using system_view = planetary_mistral::data::system_view;

system_view::system_view() {}
system_view::system_view(const int fov) : fov(fov) {}
system_view::system_view(const system_view& view) : fov(view.fov) {}
system_view::system_view(system_view&& view) : fov(std::move(view.fov)) {}
