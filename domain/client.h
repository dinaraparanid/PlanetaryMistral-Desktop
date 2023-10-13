#ifndef CLIENT_H
#define CLIENT_H

#include <boost/beast/core.hpp>
#include <optional>

#include "client.h"
#include "data/system_status.h"

namespace beast = boost::beast;
using system_status = planetary_mistral::data::system_status;

namespace planetary_mistral {
    namespace domain {
        using client = beast::tcp_stream;

        std::optional<client> make_client();
        std::optional<system_status> get_system_status(client& stream);
    }
}

#endif // CLIENT_H
