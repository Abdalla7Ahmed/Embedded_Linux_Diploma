#include <iostream>
//#include <MQTTAsync.h>
#include <mqtt/async_client.h>


const std::string SERVER_ADDRESS("tcp://test.mosquitto.org:1883");
const std::string CLIENT_ID("sender_client");
const std::string TOPIC("test/message");
const int QOS = 1;

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    std::string payload = "Hello, MQTT!";
    std::cout << "Publishing message: " << payload << std::endl;

    try {
        mqtt::token_ptr conntok = client.connect(connOpts);
        conntok->wait();

        mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload, QOS, false);
        client.publish(pubmsg)->wait();

        client.disconnect()->wait();
    } catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}

