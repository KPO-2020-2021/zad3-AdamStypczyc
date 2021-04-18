#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "Prostokat.hh"
#include "../include/lacze_do_gnuplota.hh"
/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK 100
#define DL_DLUGI_BOK 150

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream &StrmWy,
                                             double Przesuniecie)
{
    //---------------------------------------------------------------
    // To tylko przyklad !!!
    // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych
    // zmiennych do reprezentowania wspolrzednych!
    //
    double x1, y1, x2, y2, x3, y3, x4, y4;

    x1 = y1 = 10;
    x2 = x1 + DL_DLUGI_BOK;
    y2 = y1;
    x3 = x2;
    y3 = y2 + DL_KROTKI_BOK;
    x4 = x3 - DL_DLUGI_BOK;
    y4 = y3;

    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
           << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x2 + Przesuniecie
           << std::setw(16) << std::fixed << std::setprecision(10) << y2 + Przesuniecie << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x3 + Przesuniecie
           << std::setw(16) << std::fixed << std::setprecision(10) << y3 + Przesuniecie << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x4 + Przesuniecie
           << std::setw(16) << std::fixed << std::setprecision(10) << y4 + Przesuniecie << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << x1 + Przesuniecie
           << std::setw(16) << std::fixed << std::setprecision(10) << y1 + Przesuniecie << std::endl;
    // Jeszcze raz zapisujemy pierwszy punkt,
    // aby gnuplot narysowal zamkniętą linię.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku, Prostokat Pr)
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }

    StrmPlikowy << Pr;
    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}
void pokaz_menu(char &wybor)
{
    std::cout << "Opcje: " << std::endl;
    std::cout << "o - obrot prostokata o zadany kat" << std::endl;
    std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
    std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    std::cout << "Twoj wybor? (m - menu) > ";
    std::cin >> wybor;
    std::cout << "------------------------------------" << std::endl;
}
int menu()
{
    long int n;
    char wybor;
    Prostokat Pr;
    Vector translacja;
    Vector poczatek;
    Matrix obrot;
    double tab1[2];
    double tab2[2];
    double w, h;
    PzG::LaczeDoGNUPlota Lacze;
    double kat;
    std::cout << "Od jakiego punktu mają wychodzić pozostałe punkty?\nPodaj współrzędne x,y " << std::endl;
    std::cin >> tab1[0];
    std::cin >> tab1[1];
    poczatek = Vector(tab1);
    std::cout << "Podaj szerokość prostokata" << std::endl;
    std::cin >> w;
    std::cout << "Podaj wysokość prostokata" << std::endl;
    std::cin >> h;
    std::cout << "------------------------------------" << std::endl;
    //   1. Rysowane jako linia ciagl o grubosci 2 piksele
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Ciagly, 2);
    //
    //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
    //      których połowa długości boku wynosi 2.
    //
    Lacze.DodajNazwePliku("../datasets/prostokat.dat", PzG::RR_Punktowy, 2);
    //
    //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
    //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
    //  jako wspolrzedne punktow podajemy tylko x,y.
    //
    Lacze.ZmienTrybRys(PzG::TR_2D);
    Pr = Prostokat(poczatek, h, w);
    if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
        return 1;
    Lacze.Rysuj();
    while (1)
    {
        pokaz_menu(wybor);
        switch (wybor)
        {
        case 'o':
            std::cout << "O jaki kąt ma się obrócić?" << std::endl;
            std::cin >> kat;
            obrot = Matrix();
            obrot.przypisz_stopnie(kat);
            obrot.StopienNaRadian();
            obrot.Oblicz_tablice();
            std::cout << "Ile razy ma się obrócić? " << std::endl;
            std::cin >> n;
            n = n % 36;
            for (int i = 0; i < n; ++i)
            {
                Pr = Pr * obrot;
                if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat", Pr))
                    return 1;
            }
            Lacze.Rysuj();
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'p':
            translacja = Vector();
            std::cout << "O jaki wektor [x,y] ma być przesunięty prostokat? \nPodaj dwie liczby, 1. to x, a 2. to y" << std::endl;
            std::cin >> tab2[0];
            std::cin >> tab2[1];
            translacja = Vector(tab2);
            if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat", Pr + translacja))
                return 1;
            Lacze.Rysuj();
            Pr.dlugosc();
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'w':
            std::cout << Pr;
            std::cout << "------------------------------------" << std::endl;
            break;
        case 'm':
            pokaz_menu(wybor);
            break;
        case 'k':
            std::cout << "Do zobaczenia!!!" << std::endl;
            return 0;
            break;
        }
    }
    return 1;
}
