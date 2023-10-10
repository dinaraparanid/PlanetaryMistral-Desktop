#ifndef SYSTEM_VIEW_H
#define SYSTEM_VIEW_H

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        struct system_view {
            int fov;

            static system_view from_json(json& obj) {
                return system_view(obj["fov"].get<int>());
            }

            explicit system_view(const int fov) : fov(fov) {}
        };
    }
}

#endif // SYSTEM_VIEW_H
