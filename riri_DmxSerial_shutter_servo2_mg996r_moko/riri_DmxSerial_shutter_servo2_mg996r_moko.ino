#include <DMXSerial.h>
#include <Servo.h>  // the servo library
int val;
int vals;
Servo servo;    // declare variables for up to eight servos
const int RedPin = 9;  // PWM output pin for Red Light.
void setup () {
  pinMode(RedPin, OUTPUT);
  DMXSerial.init(DMXReceiver);
  servo.attach(13);
}
void loop() {
  val = (DMXSerial.read(501));
  vals = map(val, 0, 255, 160, 0);
  servo.write(vals);
  analogWrite(RedPin, val);
  delay(15);
}
