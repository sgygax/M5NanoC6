// Animal 134.2kHz RFID reader WL-134.
// - https://de.aliexpress.com/item/4000601988338.html

//-------------------------------------------------------------------
const int PIN_UART1_RX = 1;
const int PIN_UART1_TX = 2;

//-------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  Serial1.begin(9600, SERIAL_8N1, PIN_UART1_RX, PIN_UART1_TX);
}

//-------------------------------------------------------------------
void loop()
{
  // new data from reader
  if(Serial1.available() == 30){
    
    int anzahl = Serial1.available();
    int buffer[anzahl];

    // read and save
    for(int x=0; x<anzahl; x++){
      buffer[x] = Serial1.read();
    }

    // show index
    for(int x=0; x<anzahl; x++){
      Serial.printf("%2d ", x);     
    }
    Serial.println(" INDEX");

    // show data (ascii)
    for(int x=0; x<anzahl; x++){
      Serial.printf(" %c ", buffer[x]);     
    }
    Serial.println(" DATA (ASCII)");
    
    // show data (hex)
    for(int x=0; x<anzahl; x++){
      Serial.printf("%02X ", buffer[x]);     
    }
    Serial.println(" DATA (HEX)");
   
    Serial.println();   
  }  
}
