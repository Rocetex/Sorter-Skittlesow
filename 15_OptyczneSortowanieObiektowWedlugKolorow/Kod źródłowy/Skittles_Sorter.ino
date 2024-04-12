#include "SorterRGB.h"
#include "SensorRGB.h"
#include "StepperMotor.h"
#include <Servo.h>          

/**
 * @brief Skittles_Sorter - główny plik wykonawczy dla urządzenia sortującego kolorowe obiekty.
 * 
 * Program zawiera: konfigurację pinów mikrokontrolera, kostruktory urządzeń składowych, 
 * obsłgę głównej pętl programu oraz obsługę przerwania.
 *
 * Autorzy: 263581, 263671, 263686
 * Data ostatniej modyfikacji: Styczeń 19, 2024
 */

  /**
  * DO KONFIGURACJI :
  * Numery pinów ustawić zgodnie ze schematem połączeń w wypadku użycia własnego modułu sterowania!
  * Ważne:
  * SENSOR_SENS_PIN - dowolny pin analogowy
  * SERVO_PIN - dowolny pin obsługujący PWM
  */
#define NUMPIXELS 1           /**< Liczba pikseli w sensorze RGB. */
#define SENSOR_CTRL_PIN 8     /**< Numer pinu sterującego sensorem RGB. */
#define SENSOR_SENS_PIN A5    /**< Numer pinu odczytu sygnału z sensora RGB (pin analogowy). */

#define MOTOR_CTRL_PIN 10     /**< Numer pinu sterującego silnikiem krokowym. */
#define SERVO_PIN 6           /**< Numer pinu sterującego serwem. */
#define INTERRUPT_PIN 2       /**< Numer pinu przerwania związanego z transoptorem. */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SensorRGB sensor(NUMPIXELS, SENSOR_CTRL_PIN, NEO_GRB + NEO_KHZ800, SENSOR_SENS_PIN);
StepperMotor stepper(MOTOR_CTRL_PIN);
Servo sinkServo;
SorterRGB sorter;

int R, G, B;
int colorIndex = 0;
int motorSpeed = 270;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Funkcja inicjalizująca serwo, przerwanie oraz komunikację szeregową.
 */
void setup() {
    sinkServo.attach(SERVO_PIN);

    pinMode(INTERRUPT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), handleInterrupt, RISING);

    Serial.begin(9600);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Pętla główna programu.
 */
void loop() {
    stepper.makeStep(motorSpeed);
}

/**
 * @brief Funkcja obsługująca przerwanie związane z odczytem koloru po wyzwoleniu transoptora.
 * 
 * > Zczytuje kolory nowego obiektu
 * > Określa kolor obiektu na podstawie kolorów odniesienia
 * > Nastawia serwo na podstawie koloru
 * > Wyświetla w konsoli dane kalibracyjne
 */
void handleInterrupt() {

    sensor.readColor(R, G, B);
    colorIndex = sorter.getClosestColorIndex(R, G, B);
    sinkServo.write(colorIndex*45);

    Serial.print(R);
    Serial.print(',');
    Serial.print(G);
    Serial.print(',');
    Serial.print(B);
    Serial.print('\n');

    Serial.print("indeks: ");
    Serial.print(colorIndex);
    Serial.print('\n');
}

