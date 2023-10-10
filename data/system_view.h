#ifndef SYSTEM_VIEW_H
#define SYSTEM_VIEW_H

namespace planetary_mistral {
    namespace data {
        struct system_view {
            int fov;

            explicit system_view(const int fov) : fov(fov) {}
        };
    }
}

#endif // SYSTEM_VIEW_H
