#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <QDebug>

#include "client.h"
#include "json.hpp"

#include "data/system_status.h"

const char* const HOST = "localhost";
const char* const PORT = "8080";

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;

using tcp = net::ip::tcp;
using json = nlohmann::json;

namespace planetary_mistral {
    namespace domain {
        std::optional<client> make_client() {
            try {
                net::io_context ioc;
                tcp::resolver resolver(ioc);
                client stream(ioc);

                const auto res = resolver.resolve(HOST, PORT);
                stream.connect(res);
                return std::optional<client>(std::move(stream));
            } catch (const boost::wrapexcept<boost::system::system_error>& e) {
                return std::optional<client>();
            }
        }

        std::optional<system_status> get_system_status(client& stream) {
            http::request<http::string_body> req;
            req.version(11);
            req.method(http::verb::get);
            req.target("/system/system_status");
            req.set(http::field::host, HOST);
            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

            http::write(stream, req);

            beast::flat_buffer buffer;
            http::response<http::string_body> res;
            http::read(stream, buffer, res);

            const auto status = res.result();
            auto body = res.body();
            qDebug() << "API response:" << body.c_str();
            auto data = json::parse(body);

            return status == http::status::ok
                    ? std::make_optional(system_status::from_json(data))
                    : std::nullopt;
        }
    }
}
