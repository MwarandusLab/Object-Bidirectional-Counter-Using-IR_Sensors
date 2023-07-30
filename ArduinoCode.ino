#define sensorPin1 12
#define sensorPin2 11
#define RedLed 2

int sensorState1 = 0;
int sensorState2 = 0;
int count = 0;

void setup() {
  pinMode(sensorPin1, INPUT_PULLUP);
  pinMode(sensorPin2, INPUT_PULLUP);
  pinMode(RedLed, OUTPUT);

  Serial.begin(9600);
  Serial.println("COUNTER");
  Serial.println("No Visitors");
  delay(200);
}

void loop() {
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);

  if (sensorState1 == LOW) {
    count++;
    delay(500);
  }

  if (sensorState2 == LOW) {
    count--;
    delay(500);
  }

  if (count <= 0) {
    digitalWrite(RedLed, LOW);
    Serial.println("No visitors");
  } else {
    digitalWrite(RedLed, HIGH);
    Serial.print("Visitors: ");
    Serial.println(count);
  }
}
