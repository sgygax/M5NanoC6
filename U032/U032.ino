// A GPS unit that integrates a AT6558 navigation chip and a MAX2659 amplification chip.
// - https://docs.m5stack.com/en/unit/gps
// - https://github.com/Tinyu-Zhao/TinyGPSPlus-ESP32

//-------------------------------------------------------------------
#include "TinyGPSPlus.h"

//-------------------------------------------------------------------
const int PIN_UART_RX = 1;
const int PIN_UART_TX = 2;

TinyGPSPlus gps;

unsigned long timestamp = 0;

//-------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);

  Serial1.begin(9600, SERIAL_8N1, PIN_UART_RX, PIN_UART_TX);
}

//-------------------------------------------------------------------
void loop(void)
{
  while (Serial1.available() > 0) {
    gps.encode(Serial1.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("LOCATION   Fix Age=");
    Serial.print(gps.location.age());
    Serial.print("ms Raw Lat=");
    Serial.print(gps.location.rawLat().negative ? "-" : "+");
    Serial.print(gps.location.rawLat().deg);
    Serial.print("[+");
    Serial.print(gps.location.rawLat().billionths);
    Serial.print(" billionths],  Raw Long=");
    Serial.print(gps.location.rawLng().negative ? "-" : "+");
    Serial.print(gps.location.rawLng().deg);
    Serial.print("[+");
    Serial.print(gps.location.rawLng().billionths);
    Serial.print(" billionths],  Lat=");
    Serial.print(gps.location.lat(), 6);
    Serial.print(" Long=");
    Serial.println(gps.location.lng(), 6);
  }

  else if (gps.date.isUpdated()) {
    Serial.print("DATE       Fix Age=");
    Serial.print(gps.date.age());
    Serial.print("ms Raw=");
    Serial.print(gps.date.value());
    Serial.print(" Year=");
    Serial.print(gps.date.year());
    Serial.print(" Month=");
    Serial.print(gps.date.month());
    Serial.print(" Day=");
    Serial.println(gps.date.day());
  }

  else if (gps.time.isUpdated()) {
    Serial.print("TIME       Fix Age=");
    Serial.print(gps.time.age());
    Serial.print("ms Raw=");
    Serial.print(gps.time.value());
    Serial.print(" Hour=");
    Serial.print(gps.time.hour());
    Serial.print(" Minute=");
    Serial.print(gps.time.minute());
    Serial.print(" Second=");
    Serial.print(gps.time.second());
    Serial.print(" Hundredths=");
    Serial.println(gps.time.centisecond());
  }

  else if (gps.speed.isUpdated()) {
    Serial.print("SPEED      Fix Age=");
    Serial.print(gps.speed.age());
    Serial.print("ms Raw=");
    Serial.print(gps.speed.value());
    Serial.print(" Knots=");
    Serial.print(gps.speed.knots());
    Serial.print(" MPH=");
    Serial.print(gps.speed.mph());
    Serial.print(" m/s=");
    Serial.print(gps.speed.mps());
    Serial.print(" km/h=");
    Serial.println(gps.speed.kmph());
  }

  else if (gps.course.isUpdated()) {
    Serial.print("COURSE     Fix Age=");
    Serial.print(gps.course.age());
    Serial.print("ms Raw=");
    Serial.print(gps.course.value());
    Serial.print(" Deg=");
    Serial.println(gps.course.deg());
  }

  else if (gps.altitude.isUpdated()) {
    Serial.print("ALTITUDE   Fix Age=");
    Serial.print(gps.altitude.age());
    Serial.print("ms Raw=");
    Serial.print(gps.altitude.value());
    Serial.print(" Meters=");
    Serial.print(gps.altitude.meters());
    Serial.print(" Miles=");
    Serial.print(gps.altitude.miles());
    Serial.print(" KM=");
    Serial.print(gps.altitude.kilometers());
    Serial.print(" Feet=");
    Serial.println(gps.altitude.feet());
  }

  else if (gps.satellites.isUpdated()) {
    Serial.print("SATELLITES Fix Age=");
    Serial.print(gps.satellites.age());
    Serial.print("ms Value=");
    Serial.println(gps.satellites.value());
  }

  else if (gps.hdop.isUpdated()) {
    Serial.print("HDOP       Fix Age=");
    Serial.print(gps.hdop.age());
    Serial.print("ms raw=");
    Serial.print(gps.hdop.value());
    Serial.print(" hdop=");
    Serial.println(gps.hdop.hdop());
  }

  else if ((millis() - timestamp) > 5000) {
    timestamp = millis();

    Serial.println();
    if (gps.location.isValid()) {
      static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;
      double distanceToLondon =
        TinyGPSPlus::distanceBetween(
          gps.location.lat(),
          gps.location.lng(),
          LONDON_LAT,
          LONDON_LON);
      double courseToLondon =
        TinyGPSPlus::courseTo(
          gps.location.lat(),
          gps.location.lng(),
          LONDON_LAT,
          LONDON_LON);

      Serial.print("LONDON     Distance=");
      Serial.print(distanceToLondon / 1000, 6);
      Serial.print(" km Course-to=");
      Serial.print(courseToLondon, 6);
      Serial.print(" degrees [");
      Serial.print(TinyGPSPlus::cardinal(courseToLondon));
      Serial.println("]");
    }

    Serial.print("DIAGS      Chars=");
    Serial.print(gps.charsProcessed());
    Serial.print(" Sentences-with-Fix=");
    Serial.print(gps.sentencesWithFix());
    Serial.print(" Failed-checksum=");
    Serial.print(gps.failedChecksum());
    Serial.print(" Passed-checksum=");
    Serial.println(gps.passedChecksum());

    if (gps.charsProcessed() < 10) {
      Serial.println("WARNING: No GPS data.  Check wiring.");
    }

    Serial.println();
  }
}
