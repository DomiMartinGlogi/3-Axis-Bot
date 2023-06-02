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

// Joystick Input Data last Cycle
int a_input_prv;
int b_input_prv;
int c_input_prv;

void selfTest(){
    delay(50);
    for (int i = 1; i <= 50; i++){
        aAxis.write(i);
        bAxis.write(i);
        cAxis.write(i);
        delay(30);
    }
    delay(500);
    for (int i = 50; i <= 100; i++){
        aAxis.write(i);
        bAxis.write(i);
        cAxis.write(i);
        delay(30);
    }
    delay(500);
    for (int i = 100; i >= 50; i--){
        aAxis.write(i);
        bAxis.write(i);
        cAxis.write(i);
        delay(30);
    }
    delay(500);
}

void setup() {
    Serial.begin(9600);

    aAxis.attach(A_AXIS_PIN);
    bAxis.attach(B_AXIS_PIN);
    cAxis.attach(C_AXIS_PIN);

    a_input_prv = 50;
    b_input_prv = 50;
    c_input_prv = 50;

    selfTest();
}

void loop() {
    a_input = analogRead(A_INPUT);
    Serial.print("A Raw: ");
    Serial.print((int)a_input);
    a_input = map(a_input, 0, 1023, 0, 180);

    b_input = analogRead(B_INPUT);
    Serial.print(" B Raw: ");
    Serial.print((int)b_input);
    b_input = map(b_input, 0, 1023, 0, 100);

    c_input = analogRead(C_INPUT);
    Serial.write(" C Raw: ");
    Serial.print((int)c_input);
    Serial.print('\n');
    c_input = map(c_input, 0, 1023,0,180);

    if(abs(a_input - a_input_prv) < 5) {
        aAxis.write(a_input);
        a_input_prv = a_input;
    }

    if (abs(b_input - b_input_prv) < 5) {
        bAxis.write(b_input);
        b_input_prv = b_input;
    }

    if (abs(c_input - c_input_prv) < 5) {
        cAxis.write(c_input);
        c_input_prv = c_input;
    }

    delay(50);
}
