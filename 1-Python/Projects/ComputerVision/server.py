# MQTT Publish Demo
# Publish two messages, to two different topics
import paho.mqtt.publish as publish
publish.single("CoreElectronics/test", 11, hostname="test.mosquitto.org")
publish.single("CoreElectronics/topic", 12, hostname="test.mosquitto.org")
print("Done")
