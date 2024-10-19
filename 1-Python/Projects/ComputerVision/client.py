import paho.mqtt.client as mqtt
import json
from led_controle import *


# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    # Subscribing to topics
    client.subscribe("CoreElectronics/led_controle")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    print(f"Message received on topic {msg.topic}: {msg.payload.decode()}")
    payload_list = [0,0,0,0,0]
    try:
        # Decode the JSON payload
        payload_list = json.loads(msg.payload.decode())
        if isinstance(payload_list, list):
            # Example of accessing the list safely
            if len(payload_list) > 1:  # Ensure the list has at least 2 elements
                if payload_list[0] == 1:
                    led_on(LED_PIN2)
                elif payload_list[0] == 0:
                    led_off(LED_PIN2)
                if payload_list[1] == 1:
                    led_on(LED_PIN3)
                elif payload_list[1] == 0:
                    led_off(LED_PIN3)
        
                if payload_list[2] == 1:
                    led_on(LED_PIN4)
                elif payload_list[2] == 0:
                    led_off(LED_PIN4)
        
                if payload_list[3] == 1:
                    led_on(LED_PIN17)
                elif payload_list[3] == 0:
                    led_off(LED_PIN17)
        
                if payload_list[4] == 1:
                    led_on(LED_PIN27)
                elif payload_list[4] == 0:
                    led_off(LED_PIN27)      
            else:
                print("The list is too short to access the second element.")
        

    except json.JSONDecodeError:
        print("Failed to decode message as JSON list")


# Set up the GPIO pin
set_gpio_pin(LED_PIN2)
set_gpio_pin(LED_PIN3)
set_gpio_pin(LED_PIN4)
set_gpio_pin(LED_PIN17)
set_gpio_pin(LED_PIN27)



# Create an MQTT client and attach our routines to it.
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# Connect to the MQTT broker.
client.connect("test.mosquitto.org", 1883, 60)

# Process network traffic and dispatch callbacks. This will also handle
# reconnecting and sending keep-alive messages.
client.loop_forever()
