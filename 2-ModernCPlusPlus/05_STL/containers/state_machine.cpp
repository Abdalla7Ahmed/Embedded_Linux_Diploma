#include <iostream>
#include <map>
#include <random>
#include <chrono>
#include <thread>
// Configure --> Drop , Connect
// Connect --> send  , Drop
// Drop --> Idle
// Send --> Idle , Drop
// Idle --> configure

enum class state : unsigned char
{
    CONFIGURE_STATE,
    CONNECT_STATE,
    DROP_STATE,
    SEND_STATE,
    IDLE_STATE
};
enum class goto_state : unsigned char
{
    GOTO_CONFIGURE_STATE,
    GOTO_CONNECT_STATE,
    GOTO_DROP_STATE,
    GOTO_SEND_STATE,
    GOTO_IDLE_STATE
};

bool perform()
{
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform distribution from 0 to 1
    std::uniform_int_distribution<> dis(0, 1);

    // Generate and return a random value
    return dis(gen);
    // return 1;
}

int main(int argc, const char **argv)
{

    std::map<state, std::map<goto_state, state>> stateMap;
    stateMap[state::CONFIGURE_STATE] = {{goto_state::GOTO_DROP_STATE, state::DROP_STATE},
                                        {goto_state::GOTO_CONNECT_STATE, state::CONNECT_STATE}};

    stateMap[state::CONNECT_STATE] = {{goto_state::GOTO_SEND_STATE, state::SEND_STATE},
                                      {goto_state::GOTO_DROP_STATE, state::DROP_STATE}};

    stateMap[state::DROP_STATE] = {{goto_state::GOTO_IDLE_STATE, state::IDLE_STATE}};

    stateMap[state::SEND_STATE] = {{goto_state::GOTO_IDLE_STATE, state::IDLE_STATE},
                                   {goto_state::GOTO_DROP_STATE, state::DROP_STATE}};

    stateMap[state::IDLE_STATE] = {{goto_state::GOTO_CONFIGURE_STATE, state::CONFIGURE_STATE}};

    state current_state = state::IDLE_STATE;
    while (1)
    {
        switch (current_state)
        {
        case state::CONFIGURE_STATE:
            std::cout << "in configure state" << std::endl;
            if (perform())
            {
                current_state = stateMap[current_state][goto_state::GOTO_CONNECT_STATE];
            }
            else
            {
                current_state = stateMap[current_state][goto_state::GOTO_DROP_STATE];
            }
            break;
        case state::CONNECT_STATE:
            std::cout << "in connect state" << std::endl;
            if (perform())
            {
                current_state = stateMap[current_state][goto_state::GOTO_SEND_STATE];
            }
            else
            {
                current_state = stateMap[current_state][goto_state::GOTO_DROP_STATE];
            }
            break;
        case state::DROP_STATE:
            std::cout << "in drop state" << std::endl;
            current_state = stateMap[current_state][goto_state::GOTO_IDLE_STATE];
            exit(0);
            break;
        case state::SEND_STATE:
            std::cout << "in send state" << std::endl;
            if (perform())
            {
                current_state = stateMap[current_state][goto_state::GOTO_IDLE_STATE];
            }
            else
            {
                current_state = stateMap[current_state][goto_state::GOTO_DROP_STATE];
            }

            break;
        case state::IDLE_STATE:
            std::cout << "in idle state" << std::endl;
            current_state = stateMap[current_state][goto_state::GOTO_CONFIGURE_STATE];
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}