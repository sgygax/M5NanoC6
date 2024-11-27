// WebServer in station mode:
// The ESP32 operates in station mode,  
// connects to the local WiFi network (SSID: m126, KEY: M126M126), 
// and then starts a web server with an HTML page.

//-------------------------------------------------------------------
#include <WiFi.h>
#include <WebServer.h>

//-------------------------------------------------------------------
// WiFi:
const char WIFI_SSID[] = "m126";
const char WIFI_PASSWORD[] = "M126M126";

// Webserver Objekt (Port 80)
WebServer webserver(80);

//-------------------------------------------------------------------
void setup(void)
{
  //---
  // UART starten (115200 Baud)
  Serial.begin(115200);

  //---
  // WiFi verbinden
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Verbinde mit ");
  Serial.print(WIFI_SSID);

  // Warten bis mit WiFi verbunden...
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println(" Verbunden!");

  // Zugewiesene IP-Adresse ausgeben
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

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
  delay(10);
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
          <h2>Random 0..1000</h2>
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
