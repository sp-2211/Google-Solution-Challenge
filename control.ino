/*New blynk app project
   Home Page
*/

//Include the library files
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPLqTTcBTPj"
#define BLYNK_TEMPLATE_NAME "SERVO CONTROL"
#define BLYNK_AUTH_TOKEN "nPPV6FHtqZmegxIbWf-TcPuvyo2-GXtl"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "_sp_";
char pass[] = "qwertyuiop0";

int ledPin = 4;
int covpin = 5;

Servo servo;
BLYNK_WRITE(V1)
{
  int pos = param.asInt();
  Serial.println(pos);
  servo.write(pos);
}
BLYNK_WRITE(V0) {
  digitalWrite(ledPin, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(covpin, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(ledPin, OUTPUT);
  pinMode(covpin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, HIGH);
  digitalWrite(covpin
  , HIGH);
  //Initialize the Blynk library
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  servo.attach(2);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
  Serial.println(WiFi.localIP());
}
