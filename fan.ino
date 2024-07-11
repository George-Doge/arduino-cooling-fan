const int directionA = 3;
const int directionB = 4;
const int powerPin = 5;
const int buttonPin = 13;

#define powerReadPin A0
#define directionReadPin A1

int powerReadValue;
int directionReadValue;

void setup() {
    pinMode(directionA, OUTPUT);
    pinMode(directionB, OUTPUT);
    pinMode(powerPin, OUTPUT);
    pinMode(powerReadPin, INPUT);
    pinMode(directionReadPin, INPUT);
    pinMode(buttonPin, INPUT);

    Serial.begin(9600);
}

void loop() {
    powerReadValue = analogRead(powerReadPin); // UP-DOWN axis
    directionReadValue = analogRead(directionReadPin); // LEFT-RIGHT axis

    if (powerReadValue <= 400) {
        powerReadValue = 0;
    }

    if (directionReadValue <= 250) {
        digitalWrite(directionA, LOW);
        digitalWrite(directionB, HIGH);
    }
    else if (directionReadValue >= 1000) {
        digitalWrite(directionA, HIGH);
        digitalWrite(directionB, LOW);
    }

    analogWrite(powerPin, powerReadValue);


    // Serial.println(directionReadValue);
}