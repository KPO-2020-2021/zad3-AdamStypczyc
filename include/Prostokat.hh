#pragma once

#define MIN_DIFF 0.00000000001
#include <iostream>
#include <cmath>
#include "vector.hh"
#include "matrix.hh"

class Prostokat
{
private:
    Vector wspol[4];

public:
    Prostokat();
    Prostokat(Vector poczatek, double h = 0, double w = 0);
    Vector &operator[](int i);
    const Vector operator[](int i) const;
    Prostokat operator+(const Vector translacja);
    void dlugosc();
    Prostokat &operator*(Matrix Macierz_obrotu);
};
Prostokat::Prostokat()
{
    for(int i = 0; i<2*SIZE; i++)
    {
        wspol[i]=Vector();
    }
}
Prostokat::Prostokat(Vector poczatek, double h, double w)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        wspol[i] = poczatek;
    }
    wspol[1][1] += h;
    wspol[2][0] += w;
    wspol[2][1] += h;
    wspol[3][0] += w;
}
Vector &Prostokat::operator[](int i)
{
    return wspol[i];
}
const Vector Prostokat::operator[](int i) const
{
    return wspol[i];
}
Prostokat Prostokat::operator+(const Vector translacja)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        wspol[i] = wspol[i] + translacja;
    }
    return *this;
}
void Prostokat::dlugosc()
{
    double Wek0[2], Wek1[2], Wek2[2], Wek3[2];
    double Bok1, Bok2, Bok3, Bok0;
    Wek0[0] = wspol[0][0] - wspol[1][0]; //x
    Wek0[1] = wspol[0][1] - wspol[1][1]; //y

    Wek1[0] = wspol[1][0] - wspol[2][0]; //x
    Wek1[1] = wspol[1][1] - wspol[2][1]; //y

    Wek2[0] = wspol[2][0] - wspol[3][0]; //x
    Wek2[1] = wspol[2][1] - wspol[3][1]; //y

    Wek3[0] = wspol[3][0] - wspol[0][0]; //x
    Wek3[1] = wspol[3][1] - wspol[0][1]; //y

    Bok0 = sqrt(pow(Wek0[0], 2) + pow(Wek0[1], 2));
    Bok1 = sqrt(pow(Wek1[0], 2) + pow(Wek1[1], 2));
    Bok2 = sqrt(pow(Wek2[0], 2) + pow(Wek2[1], 2));
    Bok3 = sqrt(pow(Wek3[0], 2) + pow(Wek3[1], 2));
    std::cout << std::endl;
    if (abs(Bok0 - Bok2) < MIN_DIFF && abs(Bok1 - Bok3) < MIN_DIFF)
    {
        std::cout << ":) Boki są sobie równe, a ich długości wynoszą: " << std::endl;
    }
    else
    {
        std::cout << ":( Boki nie są sobie równe, a ich długości wynoszą: " << std::endl;
    }
    std::cout << Bok0 << std::endl;
    std::cout << Bok1 << std::endl;
    std::cout << Bok2 << std::endl;
    std::cout << Bok3 << std::endl;
}
Prostokat &Prostokat::operator*(Matrix Macierz_obrotu)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        double _x = wspol[i][0];
        double _y = wspol[i][1];
        wspol[i][0]=_x * Macierz_obrotu(0,0)+ _y * Macierz_obrotu(0, 1);
        wspol[i][1]=_x * Macierz_obrotu(1,0)+ _y * Macierz_obrotu(1, 1);
    }
    return *this;
}
std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr);
std::istream &operator>>(std::istream &Strm, const Prostokat &Pr);

std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr)
{
    for (int i = 0; i < 2 * SIZE; i++)
    {
        Strm << std::setw(20) << std::fixed << std::setprecision(10) << Pr[i] << std::endl;
    }
    Strm << std::setw(20) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    return Strm;
}
std::istream &operator>>(std::istream &Strm, const Prostokat &Pr)
{
    for (int i = 0; i < 2 * SIZE; ++i)
    {
        Strm >> Pr[i];
    }
    std::cout << std::endl;
    return Strm;
}