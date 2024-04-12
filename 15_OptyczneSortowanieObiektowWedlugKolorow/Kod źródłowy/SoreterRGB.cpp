#include "SorterRGB.h"

/**
 * @brief Konstruktor klasy SorterRGB.
 * 
 * @param newServo Obiekt serwa, którym będzie sterować program.
 * @param pin Numer pinu, do którego podłączone jest serwo.
 */
SorterRGB::SorterRGB(){
}

/**
 * @brief Oblicza odległość między dwoma punktami w przestrzeni kolorów RGB.
 * 
 * Bezpośrednia implementacja wzoru na odległość między punktami w 3d:
 * d = √((x2−x1)^2+(y2−y1)^2+(z2−z1)^2)
 *
 * @param pointA Tablica z wartościami koloru pierwszego punktu.
 * @param pointB Tablica z wartościami koloru drugiego punktu.
 * @return double Odległość między punktami.
 */
double SorterRGB::calculateDistance(int pointA[COLUMNS], int pointB[COLUMNS]) {
    double sumOfSquares = 0.0;

    for (int i = 0; i < COLUMNS; i++) {
        sumOfSquares += pow(pointA[i] - pointB[i], 2);
    }
    return sqrt(sumOfSquares);
}

/**
 * @brief Znajduje najbliższy punkt odniesienia do danego koloru.
 * 
 * @param newPoint Tablica z wartościami koloru.
 * @param referencePoints Tablica z punktami odniesienia.
 * @return int Indeks najbliższego punktu odniesienia.
 */
int SorterRGB::findClosestPoint(int newPoint[COLUMNS], int referencePoints[REFERENCE_POINTS_COUNT][COLUMNS]) {
    double smallestDistance = -1.0;
    int indexOfClosestPoint = -1;

    for (int i = 0; i < REFERENCE_POINTS_COUNT; i++) {
        double distance = abs(calculateDistance(newPoint, referencePoints[i]));
        if (smallestDistance == -1.0 || distance < smallestDistance) {
            smallestDistance = distance;
            indexOfClosestPoint = i;
        }
    }

    return indexOfClosestPoint;
}

/**
 * @brief Zwraca indeks najbliższego koloru na podstawie wartości RGB.
 * 
 * DO KALIBRACJI :
 * Manulanie posortować elementu wg. koloru
 * Określić ilośc kolorów, ustawić odpowiednie @see{REFERENCE_POINTS_COUNT}
 * Każdy kolor przpuścić przez sorter mając otwartą konsolę
 * Wypisane wartości przenieść do arkusza kalkulacyjnegi i uśrednić
 * Skorygować wartości w tablicy @see{referencePoints} do wartości uśrednionych
 *
 * @param R Wartość składowej czerwonej.
 * @param G Wartość składowej zielonej.
 * @param B Wartość składowej niebieskiej.
 * @return int Indeks najbliższego koloru.
 */
int SorterRGB::getClosestColorIndex(int R, int G, int B) {
    int referencePoints[REFERENCE_POINTS_COUNT][COLUMNS] = {
        {184, 102, 76},     //1 Red
        {206, 131, 94},    //2 Orange
        {122, 143, 92},     //3 Green
        {210, 179, 127},   //4 Yellow
        {112, 82, 76}     //5 Purple
      //  {0, 0, 0} 
    };

    int newPoint[COLUMNS] = {R, G, B};
    int colorIndex = findClosestPoint(newPoint, referencePoints);
    return colorIndex;
}