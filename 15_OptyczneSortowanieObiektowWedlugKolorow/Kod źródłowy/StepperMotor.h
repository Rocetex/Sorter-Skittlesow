#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include <Arduino.h>

/**
 * @brief StepperMotor - Klasa sterowania silnikiem krokowym.
 * 
 * Klasa umożliwia sterowanie silnikiem krokowym poprzez generowanie impulsów dla sterownika 
 * TMC2225. Sterownik każdy impuls odczytywany jest jako sygnał i wykonuje krok/mikrokrok. Zmieniając 
 * częstotliwoćś sygnału, zmieia się szybkość obrotu silnika.
 *
 * Autorzy: 263581, 263671, 263686
 * Data ostatniej modyfikacji: Styczeń 19, 2024
 */
 
class StepperMotor {
private:
    int motorPin; /**< Numer pinu, do którego podłączony jest silnik. */

public:
    /**
     * @brief Konstruktor klasy StepperMotor.
     * 
     * @param motorPin Numer pinu, do którego podłączony jest silnik.
     */
    StepperMotor(int motorPin);

    /**
     * @brief Uruchamia silnik krokowy z określoną częstotliwością obrotów.
     * 
     * @param frequency Częstotliwość obrotów silnika.
     */
    void makeStep(int frequency);

};

#endif
