#include <Arduino.h>
#include <Servo.h>

// Servos
Servo aAxis;
Servo bAxis;
Servo cAxis;

// Servo Output Pins
constexpr int A_AXIS_PIN = 10;
constexpr int B_AXIS_PIN = 11;
constexpr int C_AXIS_PIN = 12;

// Joystick Input Pins
constexpr int A_INPUT = 0;
constexpr int B_INPUT = 1;
constexpr int C_INPUT = 2;

// Joystick Input Data;
int a_input;
int b_input;
int c_input;


void setup() {
    Serial.begin(9600);

    aAxis.attach(A_AXIS_PIN);
    bAxis.attach(B_AXIS_PIN);
    cAxis.attach(C_AXIS_PIN);
}

void loop() {
    a_input = analogRead(A_INPUT);
    Serial.write("A Raw: ");
    Serial.write((int)a_input);
    Serial.write('\n');
    a_input = map(a_input, 0, 1023, 0, 180);
    Serial.write("A Mapped : ");
    Serial.write((int)a_input);
    Serial.write("\n \n");

    b_input = analogRead(B_INPUT);
    Serial.write("B Raw: ");
    Serial.write((int)b_input);
    Serial.write('\n');
    b_input = map(b_input, 0, 1023, 0, 100);
    Serial.write("B Mapped: ");
    Serial.write((int)b_input);
    Serial.write("\n \n");

    c_input = analogRead(C_INPUT);
    Serial.write("C Raw: ");
    Serial.write((int)c_input);
    Serial.write('\n');
    c_input = map(c_input, 0, 1023,0,180);
    Serial.write("C Mapped: ");
    Serial.write((int)c_input);
    Serial.write("\n \n");

    aAxis.write(a_input);
    bAxis.write(b_input);
    cAxis.write(c_input);

    Serial.write("\n \n");
    delay(
            50);
}
