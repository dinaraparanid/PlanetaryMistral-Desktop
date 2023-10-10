#ifndef CLIENT_H
#define CLIENT_H

#include <boost/beast/core.hpp>

#include "client.h"

namespace beast = boost::beast;

namespace planetary_mistral {
    namespace domain {
        using client = beast::tcp_stream;

        client make_client();

        void get_system_status(client& stream);
    }
}

#endif // CLIENT_H
