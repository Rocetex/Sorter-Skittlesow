#ifndef SENSORRGB_H
#define SENSORRGB_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>  /** < versja 1.12.0 */

/**
 * @brief SensorRGB - Klasa reprezentująca czujnik RGB.
 * 
 * Klasa dziedziczy po klasie Adafruit_NeoPixel, co umożliwia korzystanie z funkcji obsługujących diody NeoPixel.
 * Pozwala na odczytywanie kolorów z czujnika w kilku określinych trybach:
 * readRawData -> dane RGB prosto z czujnika
 * readColor -> dane RGB skorygowane o wartości kalibracyjne
 * readGrayscale -> dane w sakli szarści
 *
 * Autorzy: 263581, 263671, 263686
 * Data ostatniej modyfikacji: Styczeń 19, 2024
 */

class SensorRGB : public Adafruit_NeoPixel {
private:
    int sensorPin; /**< Numer pinu, do którego podłączony jest czujnik. */

    /**
     * @brief Odczytuje wartość zadanego subkoloru (czerwonego, zielonego lub niebieskiego).
     * 
     * @param red Wartość 1, jeśli chcesz odczytać subkolor czerwony, 0 w przeciwnym razie.
     * @param green Wartość 1, jeśli chcesz odczytać subkolor zielony, 0 w przeciwnym razie.
     * @param blue Wartość 1, jeśli chcesz odczytać subkolor niebieski, 0 w przeciwnym razie.
     * @return int Odczytana wartość subkoloru.
     */
    int readSubColor(bool red, bool green, bool blue);

public:
    /**
     * @brief Konstruktor klasy SensorRGB.
     * 
     * @param numPixels Liczba pikseli obsługiwanych przez diody NeoPixel.
     * @param ctrlPin Numer pinu sterującego diodami NeoPixel.
     * @param type Typ diod NeoPixel.
     * @param sensorPin Numer pinu, do którego podłączony jest czujnik.
     */
    SensorRGB(uint16_t numPixels, uint8_t ctrlPin, neoPixelType type, int sensorPin);

    /**
     * @brief Odczytuje surowe dane z czujnika RGB.
     * 
     * @param r Referencja do zmiennej, w której zostanie zapisana wartość czerwonego subkoloru.
     * @param g Referencja do zmiennej, w której zostanie zapisana wartość zielonego subkoloru.
     * @param b Referencja do zmiennej, w której zostanie zapisana wartość niebieskiego subkoloru.
     */
    void readRawData(int &r, int &g, int &b);

    /**
     * @brief Odczytuje kolor z czujnika RGB i mapuje go na zakres 0-255.
     * 
     * @param r Referencja do zmiennej, w której zostanie zapisana wartość czerwonego subkoloru.
     * @param g Referencja do zmiennej, w której zostanie zapisana wartość zielonego subkoloru.
     * @param b Referencja do zmiennej, w której zostanie zapisana wartość niebieskiego subkoloru.
     */
    void readColor(int &r, int &g, int &b);

    /**
     * @brief Odczytuje wartość w skali szarości z czujnika RGB.
     * 
     * @param w Referencja do zmiennej, w której zostanie zapisana wartość subkoloru szarości.
     */
    void readGrayscale(int &w);
};

#endif
