#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include "client.h"
#include "json.hpp"

#include "data/system_status.h"

const char* const HOST = "http://localhost:";
const char* const PORT = "system";

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;

using tcp = net::ip::tcp;
using json = nlohmann::json;

namespace planetary_mistral {
    namespace domain {
        client make_client() {
            net::io_context ioc;
            tcp::resolver resolver(ioc);
            beast::tcp_stream stream(ioc);

            const auto res = resolver.resolve(HOST, PORT);
            stream.connect(res);
            return stream;
        }

        std::optional<system_status> get_system_status(client& stream) {
            http::request<http::string_body> req;
            req.version(11);
            req.method(http::verb::get);
            req.target("system");
            req.set(http::field::host, HOST);
            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

            http::write(stream, req);

            beast::flat_buffer buffer;
            http::response<http::string_body> res;
            http::read(stream, buffer, res);

            auto status = res.result();
            auto data = json::parse(res.body());

            return status == http::status::ok
                    ? std::make_optional(system_status::from_json(data))
                    : std::nullopt;
        }
    }
}
