#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double x;
MeLightSensor lightsensor_7(7);
MePIRMotionSensor pir_6(6);
MeTemperature temperature_3_1(3,1);
Me7SegmentDisplay seg7_4(4);
Servo servo_3_2;
MePort port_3(3);
MeUltrasonicSensor ultrasonic_8(8);



void setup(){
    servo_3_2.attach(port_3.pin2());
    while(!(((lightsensor_7.read()) < (300)) && (pir_6.isHumanDetected())))
    {
        _loop();
        x = temperature_3_1.temperature();
        seg7_4.display((float)x);
        _delay(0.3);
    }
    servo_3_2.write(45);
    while(!((ultrasonic_8.distanceCm()) < (6)))
    {
        _loop();
    }
    servo_3_2.write(135);
    
}

void loop(){
    
    x = temperature_3_1.temperature();
    seg7_4.display((float)x);
    _delay(0.3);
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

