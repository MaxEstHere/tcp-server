#include <iostream>
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

using namespace boost::asio;
using namespace boost::asio::ip;

//initialization
io_service service;
tcp::endpoint end{ tcp::v4(), 9999 };
tcp::acceptor acceptor(service, end);
tcp::socket socket(service);
std::string string;
//write in buff
void write(const boost::system::error_code &ec, std::size_t bytes)
{
    socket.shutdown(tcp::socket::shutdown_send);
    if (ec) return;
}
void hi(const boost::system::error_code  &ec)
{
    string = "This tcp server  display  message for test";
    async_write(socket, buffer(string), write);
    if (ec) return;
}

int main(int argc, char * argv[])
{
    acceptor.listen();
    acceptor.async_accept(socket, hi);
    service.run();
    return 0;
}

