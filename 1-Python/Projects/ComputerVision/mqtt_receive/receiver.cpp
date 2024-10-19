#include <iostream>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS("tcp://test.mosquitto.org:1883");
const std::string CLIENT_ID("receiver_client");
const std::string TOPIC("test/message");
const int QOS = 1;

class callback : public virtual mqtt::callback
{
public:
    void message_arrived(mqtt::const_message_ptr msg) override
    {
        std::cout << "Received message: " << msg->get_payload_str() << std::endl;
    }
};

int main()
{
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try
    {
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();

        client.subscribe(TOPIC, QOS)->wait();

        std::cout << "Waiting for messages. Press 'Enter' to exit." << std::endl;
        std::cin.ignore(); // Wait for user to press Enter

        client.disconnect()->wait();
    }
    catch (const mqtt::exception &exc)
    {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
