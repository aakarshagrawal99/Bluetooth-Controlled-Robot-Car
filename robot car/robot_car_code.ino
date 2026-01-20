#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3); // RX, TX

// Motor driver pins
int ENA = 9;
int IN1 = 8;
int IN2 = 7;
int IN3 = 6;
int IN4 = 5;
int ENB = 10;

char cmd;

void setup() {
  bt.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 200); // speed (0–255)
  analogWrite(ENB, 200);

  stopCar();
}

void loop() {
  if (bt.available()) {
    cmd = bt.read();

    // Forward
    if (cmd == 'F' || cmd == 'f') forward();

    // Backward
    else if (cmd == 'B' || cmd == 'b') backward();

    // Left
    else if (cmd == 'L' || cmd == 'l') left();

    // Right
    else if (cmd == 'R' || cmd == 'r') right();

    // Stop
    else if (cmd == 'S' || cmd == 's') stopCar();
  }
}

// ---- motor functions ----

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
