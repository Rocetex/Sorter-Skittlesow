#include "StepperMotor.h"

/**
 * @brief Konstruktor klasy StepperMotor.
 * 
 * @param motorPin Numer pinu, do którego podłączony jest sterownik silnika.
 */
StepperMotor::StepperMotor(int motorPin) {
    this->motorPin = motorPin;
}

/**
 * @brief Podaje na sterownik określoną częstotliwość (ustala prędkość).
 * 
 * @param frequency Częstotliwość tików na sterownik.
 */
void StepperMotor::makeStep(int frequency) {

  int periodMicroseconds = 1000000 / frequency;
  int halfPeriod = periodMicroseconds / 2;

  digitalWrite(motorPin, HIGH);
  delayMicroseconds(halfPeriod);

  digitalWrite(motorPin, LOW);
  delayMicroseconds(halfPeriod);
}
