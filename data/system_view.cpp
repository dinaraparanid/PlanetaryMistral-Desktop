#include "system_view.h"

using system_view = planetary_mistral::data::system_view;

system_view::system_view(QObject* parent) : QObject(parent) {}
system_view::system_view(const int fov, QObject* parent) : QObject(parent), m_fov(fov) {}
system_view::system_view(const system_view& view, QObject* parent) : QObject(parent), m_fov(view.m_fov) {}
system_view::system_view(system_view&& view, QObject* parent) : QObject(parent), m_fov(view.m_fov) {}

int system_view::fov() const { return m_fov; }

void system_view::set_fov(int fov) {
    m_fov = fov;
    emit(fov_changed());
}
