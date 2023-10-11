#ifndef SYSTEM_VIEW_H
#define SYSTEM_VIEW_H

#include <QObject>

#include "domain/json.hpp"

using json = nlohmann::json;

namespace planetary_mistral {
    namespace data {
        class system_view : public QObject  {
            Q_OBJECT

            Q_PROPERTY(int fov READ fov WRITE set_fov NOTIFY fov_changed)

        public:
            static system_view from_json(json& obj, QObject* parent = nullptr) {
                return system_view(obj["fov"].get<int>(), parent);
            }

            explicit system_view(QObject* parent = nullptr);
            system_view(int fov, QObject* parent = nullptr);
            system_view(const system_view& view, QObject* parent = nullptr);
            system_view(system_view&& view, QObject* parent = nullptr);

            system_view& operator=(const system_view& other) {
                if (this == &other)
                    return *this;

                set_fov(other.m_fov);
                return *this;
            }

            system_view& operator=(system_view&& other) {
                if (this == &other)
                    return *this;

                set_fov(other.m_fov);
                return *this;
            }

            int fov() const;
            void set_fov(int fov);

        signals:
            void fov_changed();

        private:
            int m_fov;
        };
    }
}

Q_DECLARE_METATYPE(planetary_mistral::data::system_view)

#endif // SYSTEM_VIEW_H
