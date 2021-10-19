#include <WiFiNINA.h>
#include "wifi_stuff.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while(!Serial);

  while(status != WL_CONNECTED){
    Serial.print("Attemping to connect to network: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);

    //wait 10 seconds for connection
    delay(10000);
  }

  //connected now so print data about connection
  Serial.println("You're connected to the network");

  Serial.println("--------------------------");
  printData();
  Serial.println("--------------------------");
}

void loop() {
  delay(10000);
  printData();
  Serial.println("--------------------------");
}

void printData(){
  Serial.println("Board information");
  //print the boards IP address
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  Serial.println();
  Serial.println("Network Information");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  //print out the received signal
  long rssi = WiFi.RSSI();
  Serial.print("Signal Strength (RSSI): ");
  Serial.println(rssi);
}
