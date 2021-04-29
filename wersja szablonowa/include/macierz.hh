#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "wektor.hh"

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
class Macierz
{

private:
    Templ_Typ value[Templ_Rozmiar][Templ_Rozmiar]; // Wartosci macierzy
    double kat_stopnie;
    double kat_radian;
    double kat_stopnieX;
    double kat_radianX;
    double kat_stopnieY;
    double kat_radianY;
    double kat_stopnieZ;
    double kat_radianZ;

public:
    Macierz(Templ_Typ tmp[Templ_Rozmiar][Templ_Rozmiar]); // Konstruktor klasy

    Macierz(); // Konstruktor klasy

    // Wektor operator*(Wektor tmp); // Operator mnożenia przez wektor

    Macierz operator+(Macierz tmp);
    Macierz operator-(Macierz tmp);
    Macierz operator*(Macierz tmp);

    Templ_Typ &operator()(unsigned int row, unsigned int column);

    const Templ_Typ &operator()(unsigned int row, unsigned int column) const;
    void StopienNaRadian();
    void StopienNaRadianX();
    void StopienNaRadianY();
    void StopienNaRadianZ();

    void Oblicz_Macierz_Obrotu();
    void Oblicz_Macierz_ObrotuX();
    void Oblicz_Macierz_ObrotuY();
    void Oblicz_Macierz_ObrotuZ();

    void przypisz_stopnie(double stopnie);
    void przypisz_stopnieX(double stopnie);
    void przypisz_stopnieY(double stopnie);
    void przypisz_stopnieZ(double stopnie);

    bool operator==(const Macierz tmp) const;
};
template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar>::Macierz(Templ_Typ tmp[Templ_Rozmiar][Templ_Rozmiar])
{
    for (unsigned int index = 0; index < Templ_Rozmiar; ++index)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            value[index][j] = tmp[index][j];
        }
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar>::Macierz()
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            value[i][j] = 0;
        }
    }
}

// template <typename Templ_Typ, unsigned int Templ_Rozmiar>
// Wektor<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator*(Wektor<Templ_Typ, Templ_Rozmiar> tmp)
// {
//     Wektor<Templ_Typ, Templ_Rozmiar> result;
//     for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
//     {
//         for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
//         {
//             result[i] += value[i][j] * tmp[j];
//         }
//     }
//     return result;
// }

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator+(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator-(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            result(i, j) = this->value[i][j] - tmp(i, j);
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Macierz<Templ_Typ, Templ_Rozmiar> Macierz<Templ_Typ, Templ_Rozmiar>::operator*(Macierz<Templ_Typ, Templ_Rozmiar> tmp)
{
    Macierz result = Macierz();
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            for (unsigned int k = 0; k < Templ_Rozmiar; ++k)
            {
                result(i, j) += this->value[i][k] * tmp(k, j);
            }
        }
    }
    return result;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
Templ_Typ &Macierz<Templ_Typ, Templ_Rozmiar>::operator()(unsigned int row, unsigned int column)
{
    if (row >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0);
    }

    if (column >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0);
    }
    return value[row][column];
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
const Templ_Typ &Macierz<Templ_Typ, Templ_Rozmiar>::operator()(unsigned int row, unsigned int column) const
{
    if (row >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= Templ_Rozmiar)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::StopienNaRadian()
{
    kat_radian = kat_stopnie * M_PI / 180;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::StopienNaRadianX()
{
    kat_radianX = kat_stopnieX * M_PI / 180;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::StopienNaRadianY()
{
    kat_radianY = kat_stopnieY * M_PI / 180;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::StopienNaRadianZ()
{
    kat_radianZ = kat_stopnieZ * M_PI / 180;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::Oblicz_Macierz_Obrotu()
{
    if (Templ_Rozmiar == 2)
    {
        value[0][0] = cos(kat_radian);
        value[0][1] = -sin(kat_radian);
        value[1][0] = sin(kat_radian);
        value[1][1] = cos(kat_radian);
    }
    else
    {
        std::cerr << "Błąd!!!" << std::endl;
    }
}
template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::Oblicz_Macierz_ObrotuX()
{
    if (Templ_Rozmiar == 3)
    {
        value[0][0] = 1;
        value[0][1] = 0;
        value[0][2] = 0;
        value[1][0] = 0;
        value[1][1] = cos(kat_radianX);
        value[1][2] = -sin(kat_radianX);
        value[2][0] = 0;
        value[2][1] = sin(kat_radianX);
        value[2][2] = cos(kat_radianX);
    }
    else
    {
        std::cerr << "Błąd!!!" << std::endl;
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::Oblicz_Macierz_ObrotuY()
{
    if (Templ_Rozmiar == 3)
    {
        value[0][0] = cos(kat_radianY);
        value[0][1] = 0;
        value[0][2] = sin(kat_radianY);
        value[1][0] = 0;
        value[1][1] = 1;
        value[1][2] = 0;
        value[2][0] = -sin(kat_radianY);
        value[2][1] = 0;
        value[2][2] = cos(kat_radianY);
    }
    else
    {
        std::cerr << "Błąd!!!" << std::endl;
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::Oblicz_Macierz_ObrotuZ()
{
    if (Templ_Rozmiar == 3)
    {
        value[0][0] = cos(kat_radianZ);
        value[0][1] = -sin(kat_radianZ);
        value[0][2] = 0;
        value[1][0] = sin(kat_radianZ);
        value[1][1] = cos(kat_radianZ);
        value[1][2] = 0;
        value[2][0] = 0;
        value[2][1] = 0;
        value[2][2] = 1;
    }
    else
    {
        std::cerr << "Błąd!!!" << std::endl;
    }
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::przypisz_stopnie(double stopnie)
{
    kat_stopnie = stopnie;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::przypisz_stopnieX(double stopnie)
{
    kat_stopnieX = stopnie;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::przypisz_stopnieY(double stopnie)
{
    kat_stopnieY = stopnie;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
void Macierz<Templ_Typ, Templ_Rozmiar>::przypisz_stopnieZ(double stopnie)
{
    kat_stopnieZ = stopnie;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
bool Macierz<Templ_Typ, Templ_Rozmiar>::operator==(const Macierz<Templ_Typ, Templ_Rozmiar> tmp) const
{
    int liczenie = 0;
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            if (std::abs(value[i][j] - tmp(i, j)) <= MIN_DIFF)
            {
                ++liczenie;
            }
        }
    }
    if (liczenie == pow(Templ_Rozmiar, 2))
    {
        return true;
    }
    return false;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
std::istream &operator>>(std::istream &in, Macierz<Templ_Typ, Templ_Rozmiar> &mat)
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

template <typename Templ_Typ, unsigned int Templ_Rozmiar>
std::ostream &operator<<(std::ostream &out, Macierz<Templ_Typ, Templ_Rozmiar> const &mat)
{
    for (unsigned int i = 0; i < Templ_Rozmiar; ++i)
    {
        for (unsigned int j = 0; j < Templ_Rozmiar; ++j)
        {
            out << "| " << mat(i, j) << " | ";
        }
        std::cout << std::endl;
    }
    return out;
}
#endif