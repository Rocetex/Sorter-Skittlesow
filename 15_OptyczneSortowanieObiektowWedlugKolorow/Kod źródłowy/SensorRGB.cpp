#include "SensorRGB.h"

/**
 * @brief Konstruktor klasy SensorRGB.
 * 
 * @param numPixels Liczba pikseli obsługiwanych przez diody NeoPixel.
 * @param ctrlPin Numer pinu sterującego diodami NeoPixel.
 * @param type Typ diod NeoPixel.
 * @param sensorPin Numer pinu, do którego podłączony jest czujnik.
 */
SensorRGB::SensorRGB(uint16_t numPixels, uint8_t ctrlPin, neoPixelType type, int sensorPin) : Adafruit_NeoPixel(numPixels, ctrlPin, type) {
    this->sensorPin = sensorPin;
    begin();
}

/**
 * @brief Odczytuje wartość subkoloru (czerwonego, zielonego lub niebieskiego).
 * 
 * @param red Wartość 1, jeśli chcesz odczytać subkolor czerwony, 0 w przeciwnym razie.
 * @param green Wartość 1, jeśli chcesz odczytać subkolor zielony, 0 w przeciwnym razie.
 * @param blue Wartość 1, jeśli chcesz odczytać subkolor niebieski, 0 w przeciwnym razie.
 * @return int Odczytana wartość subkoloru.
 */
int SensorRGB::readSubColor(bool red, bool green, bool blue) {
    int measureValue;
    /**
    * Nastawianie subkoloru badanego
    */
    clear();                                                      /**< Wyczyść kolejkę kolorów. */
    setPixelColor(0, Color(red * 255, green * 255, blue * 255));  /**< Zapisz kolor do kolejki. */
    show();                                                       /**< Wyślij kolor na diodę. */
    delay(30);                                                    /**< Opóźnienie na bezwładnoeść fotorezystora KONFIGUROWALNE. */
    measureValue = analogRead(sensorPin);                         /**< odczytaj wartość z fotorezystora. */

    /**
    * Wyłącz czujnik po pomiarze
    */
    clear();
    show();

    return measureValue;
}

/**
 * @brief Odczytuje surowe dane z czujnika RGB.
 * 
 * @param r Referencja do zmiennej, w której zostanie zapisana wartość czerwonego subkoloru.
 * @param g Referencja do zmiennej, w której zostanie zapisana wartość zielonego subkoloru.
 * @param b Referencja do zmiennej, w której zostanie zapisana wartość niebieskiego subkoloru.
 */
void SensorRGB::readRawData(int &r, int &g, int &b) {
    r = readSubColor(1, 0, 0);
    g = readSubColor(0, 1, 0);
    b = readSubColor(0, 0, 1);
}

/**
 * @brief Odczytuje kolor z czujnika RGB i mapuje go na zakres 0-255.
 *
 * DO KALIBRACJI :
 * struktura funkcji: map(subColor, sensMin, sensMax, newMin, newMax);
 * Dolny przedział (odbicia wewnętrzne czujnika) - wystaw czujnik w ciemną, pustą przestrzeń
 * Górny przedział (odbicie od obiektu) - ustaw czujnik w odległości roboczej od białego obiektu 
 *
 * @param r Referencja do zmiennej, w której zostanie zapisana wartość czerwonego subkoloru.
 * @param g Referencja do zmiennej, w której zostanie zapisana wartość zielonego subkoloru.
 * @param b Referencja do zmiennej, w której zostanie zapisana wartość niebieskiego subkoloru.
 */
void SensorRGB::readColor(int &r, int &g, int &b) {
    readRawData(r, g, b);
    r  = map(r, 50, 855, 0, 255);
    g  = map(g, 30, 675, 0, 255);
    b  = map(b, 30, 570, 0, 255);
}
