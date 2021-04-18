#pragma once

#include "size.hh"
#include <iostream>
#include <iomanip>
#define MIN_DIFF 0.0000000001

class Vector
{

private:
    double size[SIZE]; //Tablica wektora

public:
    Vector();

    Vector(double[SIZE]);

    Vector operator+(const Vector &v);

    Vector operator-(const Vector &v);

    Vector operator*(const double &tmp);

    Vector operator/(const double &tmp);

    const double &operator[](int index) const;

    double &operator[](int index);

    bool operator == (const Vector V)const;
};

std::ostream &operator<<(std::ostream &out, Vector const &tmp);

std::istream &operator>>(std::istream &in, Vector &tmp);

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = 0;
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator+(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] += v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator-(const Vector &v)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] -= v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator*(const double &tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      tmp - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator/(const double &tmp)
{
    Vector result;

    if (tmp == 0)
    {
        throw "Pamiętaj ch....o nie dziel przez 0";
    }
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
const double &Vector::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
double &Vector::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

bool Vector::operator == (const Vector V)const
{
    if(abs(size[0]-V[0])<MIN_DIFF && abs(size[1]-V[1])<MIN_DIFF)
    {
        return true;
    }
    return false;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
std::ostream &operator<<(std::ostream &out, Vector const &tmp)
{
    //zmieniony sposób wyświetlania wektora
    out << tmp[0] << " " << tmp[1];
    return out;
}
// std::ofstream &operator<<(std::ofstream &Strm, Vector const &tmp)
// {
//     //zmieniony sposób wyświetlania wektora
//     Strm << tmp[0] << " " << tmp[1];
//     return Strm;
// }

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
std::istream &operator>>(std::istream &in, Vector &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
