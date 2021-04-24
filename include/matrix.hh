#ifndef MATRIX_HH
#define MATRIX_HH
#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy
    double kat_stopnie;
    double kat_radian;

public:
    Matrix(double[SIZE][SIZE]); // Konstruktor klasy

    Matrix(); // Konstruktor klasy

    Vector operator*(Vector tmp); // Operator mnożenia przez wektor

    Matrix operator+(Matrix tmp);
    Matrix operator-(Matrix tmp);

    double Wyznacznik_Gauss();
    double &operator()(unsigned int row, unsigned int column);

    const double &operator()(unsigned int row, unsigned int column) const;
    void StopienNaRadian();
    void Oblicz_Macierz_Obrotu();
    void przypisz_stopnie(double stopnie);
    bool operator==(const Matrix tmp) const;
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);

/*!
 *  Konstruktor klasy Matrix.                                                 
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     Macierz wypelnione wartoscia 0.                                       
 */
Matrix::Matrix()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = 0;
        }
    }
}

/*!
 *  Konstruktor parametryczny klasy Matrix.                                              
 *  Argumenty:                                                                
 *      tmp - dwuwymiarowa tablica z elementami typu double.                               
 *  Zwraca:                                                                   
 *      Macierz wypelniona wartosciami podanymi w argumencie.                 
 */
Matrix::Matrix(double tmp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = tmp[i][j];
        }
    }
}

/*!
 *  Realizuje mnozenie macierzy przez wektor.                                
 *  Argumenty:                                                                
 *      this - macierz, czyli pierwszy skladnik mnozenia,                     
 *     v - wektor, czyli drugi skladnik mnozenia.                            
 *  Zwraca:                                                                   
 *      Iloczyn dwoch skladnikow przekazanych jako wektor.                    
 */

Vector Matrix::operator*(Vector tmp)
{
    Vector result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/*!
 *  Funktor macierzy                                                          
 *  Argumenty:                                                                
 *      row - numer wiersza.                                                  
 *      column - numer kolumny.                                               
 *  Zwraca:                                                                   
 *      Wartosc macierzy w danym miejscu tablicy.                             
 */
double &Matrix::operator()(unsigned int row, unsigned int column)
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!
 *  Funktor macierzy                                                          
 *  Argumenty:                                                                
 *      row - numer wiersza.                                                  
 *      column - numer kolumny.                                               
 *  Zwraca:                                                                   
 *      Wartosc macierzy w danym miejscu tablicy jako stala.                  
 */
const double &Matrix::operator()(unsigned int row, unsigned int column) const
{

    if (row >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/*!
 *  Przeciążenie dodawania macierzy                                                          
 *  Argumenty:                                                                
 *      this - macierz, czyli pierwszy skladnik dodawania,                     
 *      v - wektor, czyli drugi skladnik dodawania.                                               
 *  Zwraca:                                                                   
 *      Macierz - iloczyn dwóch podanych macierzy.                  
 */
Matrix Matrix::operator+(Matrix tmp)
{
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}
Matrix Matrix::operator-(Matrix tmp)
{
    Matrix result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->value[i][j] - tmp(i, j);
        }
    }
    return result;
}
/*!
 *  Przeciazenie operatora >>                                                 
 *  Argumenty:                                                                
 *      in - strumien wyjsciowy,                                              
 *      mat - macierz.                                                         
 */
std::istream &operator>>(std::istream &in, Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

/*!
 *  Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      out - strumien wejsciowy,                                             
 *      mat - macierz.                                                        
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

void Matrix::StopienNaRadian()
{
    kat_radian = kat_stopnie * M_PI / 180;
}
void Matrix::Oblicz_Macierz_Obrotu()
{
    value[0][0] = cos(kat_radian);
    value[0][1] = -sin(kat_radian);
    value[1][0] = sin(kat_radian);
    value[1][1] = cos(kat_radian);
}
void Matrix::przypisz_stopnie(double stopnie)
{
    kat_stopnie = stopnie;
}

bool Matrix::operator==(const Matrix tmp) const
{
    // if (std::abs(this->value[0][0] - tmp(0, 0)) <= MIN_DIFF && std::abs(this->value[1][0] - tmp(1, 0)) <= MIN_DIFF && std::abs(this->value[0][1] - tmp(0, 1)) <= MIN_DIFF && std::abs(this->value[1][1] - tmp(1, 1)) <= MIN_DIFF)
    if (std::abs(value[0][0] - tmp(0, 0)) <= MIN_DIFF && std::abs(value[1][0] - tmp(1, 0)) <= MIN_DIFF && std::abs(value[0][1] - tmp(0, 1)) <= MIN_DIFF && std::abs(value[1][1] - tmp(1, 1)) <= MIN_DIFF)

    {
        return true;
    }
    return false;
}

double Matrix::Wyznacznik_Gauss()
//obliczanie wyznacznika
{
    double Wyznacznik = 1, ratio; //zmienna wyznacznika i stosunek potrzebny do odejmowania wartości w następnym wierszu(potrzebne przy zerowaniu)
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = i + 1; j <= SIZE; ++j)
        {
            if (this->value[i][i] != 0)
            {
                ratio = this->value[j][i] / this->value[i][i];
                for (int k = 0; k < SIZE; ++k)
                {
                    this->value[j][k] = this->value[j][k] - this->value[i][k] * ratio;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        Wyznacznik = Wyznacznik * this->value[i][i];
    }
    return Wyznacznik;
}
#endif
