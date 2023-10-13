#ifndef SYSTEM_VIEW_H
#define SYSTEM_VIEW_H

#include "domain/json.hpp"

namespace planetary_mistral {
    namespace data {
        struct system_view  {
            int fov;

            static system_view from_json(nlohmann::json& obj) {
                return system_view(obj["fov"].get<int>());
            }

            system_view();
            explicit system_view(int fov);
            explicit system_view(const system_view& view);
            explicit system_view(system_view&& view);

            system_view& operator=(const system_view& other) {
                if (this == &other)
                    return *this;

                fov = other.fov;
                return *this;
            }

            system_view& operator=(system_view&& other) {
                if (this == &other)
                    return *this;

                fov = other.fov;
                return *this;
            }
        };
    }
}

#endif // SYSTEM_VIEW_H
