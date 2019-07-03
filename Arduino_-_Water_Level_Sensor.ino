/* Project name: Arduino - Water Level Sensor
   Project URI: http://www.studiopieters.nl/arduino-water-level-sensor/
   Description: Arduino - Water Level Sensor
   Version: 0.1.3
   License: GNU General Public License V2 or later  */


byte sensorPin[] = {8, 9, 10};
byte ledPin[] = {11, 12, 13}; // number of leds = numbers of sensors
const byte sensors = 3;
int level = 0;


void setup() {
  for (int i = 0; i < sensors; i++) {
    pinMode(sensorPin[i], INPUT);
    pinMode(ledPin[i], OUTPUT);
  }


}

void loop() {
  level = 0;
  for (int i = 0; i < sensors; i++) {
    if (digitalRead(sensorPin[i]) == LOW) {
      digitalWrite(ledPin[i], HIGH);
      level = sensors - i;
    } else {
      digitalWrite(ledPin[i], LOW);
    }
  }

  Serial.print("Water level");

  switch (level) {
    case 1:
      Serial.print("HIGH");

      break;
    case 2:
      Serial.print("AVERAGE");

      break;
    case 3:
      Serial.print("LOW");

      break;
    default:
      Serial.print("NO WATER");

      break;
  }
  delay(50);
}
