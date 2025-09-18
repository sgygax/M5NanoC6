// WebServer in Access Point (AP) mode:
// The ESP32 operates in Access Point (AP) mode,
// creates its own WiFi network (SSID: ESP32-NETWORK, KEY: 12345678),
// and then starts a web server with an HTML page.

//-------------------------------------------------------------------
#include <WiFi.h>
#include <WebServer.h>

//-------------------------------------------------------------------
// WiFi:
const char WIFI_AP_SSID[] = "ESP32-NETWORK";
const char WIFI_AP_KEY[] = "12345678";

// Webserver Objekt (Port 80)
WebServer webserver(80);

//-------------------------------------------------------------------
void setup(void)
{
  //---
  // UART starten (115200 Baud)
  Serial.begin(115200);
  delay(5000);
  
  //---
  // Modus Access Point (AP) auf dem ESP32 aktivieren
  WiFi.mode(WIFI_AP);

  // Zugangsdaten (SSID, KEY) konfigurieren und Access Point starten
  WiFi.softAP(WIFI_AP_SSID, WIFI_AP_KEY);
  Serial.println("Access Point gestartet!");
  Serial.print("SSID: ");
  Serial.println(WIFI_AP_SSID);
  Serial.print("KEY: ");
  Serial.println(WIFI_AP_KEY);
  Serial.print("IP-Adresse des Access Points: ");
  Serial.println(WiFi.softAPIP());

  //---
  // Webserver URL konfigurieren
  webserver.on("/", handle_page_index);

  // Webserver starten
  webserver.begin();
  Serial.println("Webserver gestartet!");
}

//-------------------------------------------------------------------
void loop(void)
{
  // Webserver bedienen
  webserver.handleClient();
}

//-------------------------------------------------------------------
void handle_page_index() {
  //---
  // HTML-Template
  String html_template = R"(
    <!DOCTYPE html>
    <html>
      <head>
        <title>ESP32 Webserver</title>
      </head>
            
      <body>
        <h1>ESP32 Webserver</h1>
        <div>
          <h2>Random Generator</h2>
          <p>Value: *RANDOM_VALUE_TEXT*</p>
          <hr>
          <a href="/">[Reload]</a>
        </div>
      </body>
    </html>
  )";

  //---
  // HTML-Template updaten
  html_template.replace("*RANDOM_VALUE_TEXT*", String(random(0, 1000 + 1)) );

  //---
  // HTML an Client senden
  webserver.send(200, "text/html", html_template);
}

