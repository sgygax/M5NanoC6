// MQTT subscribe
//
// mqtt lib:      https://github.com/256dpi/arduino-mqtt
// mqtt provider: https://www.shiftr.io/try/

//-------------------------------------------------------------------
#include <WiFi.h>
#include <MQTT.h>

//-------------------------------------------------------------------
// WiFi:
#define WIFI_SSID  "........"  /* to change */
#define WIFI_KEY   "........"  /* to change */

//-------------------------------------------------------------------
#define MQTT_CLIENT_ID  "BBW_ESP32_XYZ"  /* to change */

#define MQTT_BROKER_URL            "public.cloud.shiftr.io"
#define MQTT_BROKER_USER_NAME      "public"
#define MQTT_BROKER_USER_PASSWORD  "public"

//-------------------------------------------------------------------
WiFiClient wifinetwork;
MQTTClient mqttclient;

//-------------------------------------------------------------------
void setup(void)
{
  //---
  Serial.begin(115200);

  //---
  WiFi.begin(WIFI_SSID, WIFI_KEY);
  Serial.print("Connecting to network ");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  Serial.println(" Done");

  //---
  mqttclient.begin(wifinetwork);

  mqttclient.setHost(MQTT_BROKER_URL);
  Serial.print("Connecting to MQTT broker ");

  while (mqttclient.connect(MQTT_CLIENT_ID, MQTT_BROKER_USER_NAME, MQTT_BROKER_USER_PASSWORD) == false) {
    Serial.print(".");
    delay(250);
  }
  Serial.println(" Done");

  //---
  // subscribe topic
  mqttclient.subscribe("AAAA/BBBB/TEXT");

  // callback funktion
  mqttclient.onMessage(messageReceived);
}

//-------------------------------------------------------------------
void loop(void)
{
  mqttclient.loop();
}

//-------------------------------------------------------------------
void messageReceived(String &topic, String &payload) 
{
  Serial.println(String("Topic:   ") + topic);
  Serial.println(String("Payload: ") + payload);
}

