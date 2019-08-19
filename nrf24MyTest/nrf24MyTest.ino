// Tutorial
// https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
// board proble:
// https://github.com/arduino/Arduino/issues/6628
// board atmega8
// https://mcudude.github.io/MiniCore/package_MCUdude_MiniCore_index.json
// minicore
/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 6); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT); // button pin
  while(!Serial)
  ;
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
  Serial.println("NRF24L01 Test.");
  Serial.print("isChipConnected()=");
  Serial.println(radio.isChipConnected());
  Serial.print("pip address=");
  for(int i=0;i<6;i++)
    Serial.print((char)address[i]); // as the print function refuese to print the const char type
  Serial.println();
  Serial.println("This is the transmitter");
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  Serial.print("Sending data=");
  Serial.println(text);
  delay(1000);
  Serial.print("pin 8=");
  Serial.println(digitalRead(8));
}
