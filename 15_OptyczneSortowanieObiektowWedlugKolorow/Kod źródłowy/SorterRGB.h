#ifndef SORTERRGB_H
#define SORTERRGB_H

#define COLUMNS 3  // Liczba składowych: 3 (r + g + b)
#define REFERENCE_POINTS_COUNT 5  // Liczba punktów odniesienia w tablicy

#include <Arduino.h>

#include <math.h>

/**
 * @brief SorterRGB - Klasa reprezentująca sortownik RGB.
 * 
 * Klasa zawiera metody rozpoznawania koloru oraz sortowania na jego podstawie. Osiąga to poprzez 
 * określenie indeksu koloru odniesienia najbliższego do koloru zbadanego. 
 *
 * Autorzy: 263581, 263671, 263686
 * Data ostatniej modyfikacji: Styczeń 19, 2024
 */
class SorterRGB {

private:
    //Servo sinkServo;    /**< Obiekt serwo do sterowania sortownikiem. */
    //int servoPin;       /**< Numer pinu do podłączenia serwa. */

    /**
     * @brief Oblicza odległość między dwoma punktami w przestrzeni kolorów RGB (3d).
     * 
     * @param pointA Tablica z wartościami koloru pierwszego punktu.
     * @param pointB Tablica z wartościami koloru drugiego punktu.
     * @return double Odległość między punktami.
     */
    double calculateDistance(int pointA[COLUMNS], int pointB[COLUMNS]);

    /**
     * @brief Znajduje najbliższy punkt odniesienia do zmierzonego punktu w przestrzeni kolorów RGB (3d).
     * 
     * @param newPoint Tablica z wartościami koloru.
     * @param referencePoints Tablica z punktami odniesienia.
     * @return int Indeks najbliższego punktu odniesienia.
     */
    int findClosestPoint(int newPoint[COLUMNS], int referencePoints[REFERENCE_POINTS_COUNT][COLUMNS]);

public:
    /**
     * @brief Konstruktor klasy SorterRGB.
     * 
     * @param servoPin Numer pinu, do którego podłączone jest serwo.
     */
    SorterRGB();

    /**
     * @brief Zwraca indeks najbliższego koloru na podstawie wartości RGB zbadanego obiektu.
     * 
     * @param R Wartość składowej czerwonej.
     * @param G Wartość składowej zielonej.
     * @param B Wartość składowej niebieskiej.
     * @return int Indeks najbliższego koloru.
     */
    int getClosestColorIndex(int R, int G, int B);
};

#endif
