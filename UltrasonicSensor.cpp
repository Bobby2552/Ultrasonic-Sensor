/*
  UltrasonicSensor.cpp - Library for using 4 pin ultrasonic sensors.
  Created by Ben N. Scholer, May 22, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int echo, int trig) {
  echoPin = echo;
  trigPin = trig;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long UltrasonicSensor::ping() {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return(duration);
}

long UltrasonicSensor::ping(long timeout) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, timeout);

  return(duration);
}

long UltrasonicSensor::pingSmooth(int iterations) {
  long sum = 0;
  for (int i = 0; i < iterations; i++) {
    sum += ping();
  }
  return sum / iterations;
}

long UltrasonicSensor::pingSmooth(int iterations, long timeout) {
  long sum = 0;
  for (int i = 0; i < iterations; i++) {
    sum += ping(timeout);
  }
  return sum / iterations;
}

float UltrasonicSensor::toIn(long time) {
  return time / 74 / 2;
}

float UltrasonicSensor::toCm(long time) {
  return time / 29 / 2;
}
