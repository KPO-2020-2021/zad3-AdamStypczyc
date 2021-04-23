#include "../tests/doctest/doctest.h"
#include "Prostokat.hh"
TEST_CASE("test vector konstruktor 1")
{
  Vector x;
  x = Vector();

  CHECK(x[0] == 0);
  CHECK(x[1] == 0);
}
TEST_CASE("test vector konstrunktor 2")
{
  Vector x;
  double tab1[2] = {1, 2};
  x = Vector(tab1);

  CHECK(x[0] == 1);
  CHECK(x[1] == 2);
}
TEST_CASE("test vector Suma 1")
{
  Vector x, y, z;
  double tab1[2] = {1, 2}, tab2[2] = {3, 4}, tab3[2] = {4, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);

  CHECK(x + y == z);
}

TEST_CASE("test vector Suma 2")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {2, -3}, tab3[2] = {8, 3};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test vector Suma 3")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0, 0}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test Vector Suma 4")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.0, 0.0}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test Vector Suma 5")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.0000000001, 0.0000000001}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test Vector Suma 6")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.00000000001, 0.00000000001}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test Vector Suma 7")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.00000000009, 0.00000000009}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x + y == z);
}
TEST_CASE("test Vector Różnica 1")
{
  Vector x, y, z;
  double tab1[2] = {1, 1}, tab2[2] = {1, -3}, tab3[2] = {0, 4};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 2")
{
  Vector x, y, z;
  double tab1[2] = {5, 6}, tab2[2] = {2, 3}, tab3[2] = {3, 3};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 3")
{
  Vector x, y, z;
  double tab1[2] = {2, 2}, tab2[2] = {0, 0}, tab3[2] = {2, 2};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 4")
{
  Vector x, y, z;
  double tab1[2] = {1, 1}, tab2[2] = {0.0, 0.0}, tab3[2] = {1, 1};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 5")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.0000000001, 0.0000000001}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 6")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.00000000001, 0.00000000001}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test Vector Różnica 7")
{
  Vector x, y, z;
  double tab1[2] = {6, 6}, tab2[2] = {0.00000000009, 0.00000000009}, tab3[2] = {6, 6};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  CHECK(x - y == z);
}
TEST_CASE("test operatora [] 1")
{
  Vector x, y, z;
  double tab1[2] = {6, 7}, tab2[2] = {8, 9}, tab3[2] = {16, 126};
  x = Vector(tab1);
  y = Vector(tab2);
  z = Vector(tab3);
  double a, b, c, d, e, f;
  a = 6;
  b = 7;
  c = 8;
  d = 9;
  e = 16;
  f = 126;

  CHECK(a == x[0]);
  CHECK(b == x[1]);
  CHECK(c == y[0]);
  CHECK(d == y[1]);
  CHECK(e == z[0]);
  CHECK(f == z[1]);
}
TEST_CASE("test dzielenie vector 1")
{
  Vector x, wynik;
  double tab1[2] = {6, 9}, dzielnik = 3;
  x = Vector(tab1);
  wynik = x / dzielnik;
  CHECK(wynik[0] == 2);
  CHECK(wynik[1] == 3);
}
TEST_CASE("test dzielenie vector 2")
{
  Vector x, wynik;
  double tab1[2] = {2, 2}, dzielnik = 3;
  x = Vector(tab1);
  wynik = x / dzielnik;
  CHECK(wynik[0] == 0.666666666666666667);
  CHECK(wynik[1] == 0.666666666666666667);
}
TEST_CASE("test dzielenie vector 3")
{
  Vector x;
  double tab1[2] = {2, 2}, dzielnik = 0;
  x = Vector(tab1);
  WARN_THROWS(x / dzielnik);
}
TEST_CASE("test mnozenie vector 1")
{
  Vector x, wynik;
  double tab1[2] = {6, 9}, mnozenie = 3;
  x = Vector(tab1);
  wynik = x * mnozenie;
  CHECK(wynik[0] == 18);
  CHECK(wynik[1] == 27);
}
TEST_CASE("test mnozenie vector 2")
{
  Vector x, wynik;
  double tab1[2] = {6, 9}, mnozenie = 0;
  x = Vector(tab1);
  wynik = x * mnozenie;
  CHECK(wynik[0] == 0);
  CHECK(wynik[1] == 0);
}
TEST_CASE("test wyświetlanie vector standard")
{
  Vector x;
  double tab1[2] = {6, 7};
  x = Vector(tab1);
  std::ostringstream out;
  out << x;
  std::cout << out.str();
  CHECK("6 7" == out.str());
}

TEST_CASE("test wczytywanie vector standard")
{
  Vector x;

  std::istringstream in("21 37");
  in >> x;
  std::ostringstream out;
  out << x;
  std::cout << out.str() << std::endl;
  CHECK("21 37" == out.str());
}
/*!
 * 
 * Macierz
 */

TEST_CASE("Test martix konstruktor 1")
{
  Matrix x;
  x = Matrix();
  CHECK(x(0, 0) == 0);
  CHECK(x(0, 1) == 0);
  CHECK(x(1, 0) == 0);
  CHECK(x(1, 1) == 0);
}
TEST_CASE("Test martix konstruktor 2")
{
  Matrix x;
  double tab[SIZE][SIZE] = {{1, 2}, {3, 4}};
  x = Matrix(tab);
  CHECK(x(0, 0) == 1);
  CHECK(x(0, 1) == 2);
  CHECK(x(1, 0) == 3);
  CHECK(x(1, 1) == 4);
}
TEST_CASE("test mnozenie macierz razy vector 1")
{
  Vector x, wynik;
  double tab1[2] = {0, 2}, tab2[2] = {-2, 0};
  Matrix obrot = Matrix();
  obrot.przypisz_stopnie(90);
  obrot.StopienNaRadian();
  obrot.Oblicz_Macierz_Obrotu();
  x = Vector(tab1);
  x = obrot * x;
  wynik = Vector(tab2);
  CHECK(wynik == x);
}
TEST_CASE("test mnozenie macierz razy vector 2")
{
  Vector x, wynik;
  double tab1[2] = {2, 0}, tab2[2] = {sqrt(2), sqrt(2)};
  Matrix obrot = Matrix();
  obrot.przypisz_stopnie(45);
  obrot.StopienNaRadian();
  obrot.Oblicz_Macierz_Obrotu();
  x = Vector(tab1);
  x = obrot * x;
  wynik = Vector(tab2);
  CHECK(wynik == x);
}
TEST_CASE("Test martix dodawanie 1")
{
  Matrix a, b, c, d, e, f;
  double tab0[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab1[SIZE][SIZE] = {{5, 6}, {7, 8}};
  double tab2[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab3[SIZE][SIZE] = {{13, 14}, {15, 16}};
  double tab4[SIZE][SIZE] = {{6, 8}, {10, 12}};
  double tab5[SIZE][SIZE] = {{22, 24}, {26, 28}};
  a = Matrix(tab0);
  b = Matrix(tab1);
  c = Matrix(tab2);
  d = Matrix(tab3);
  e = Matrix(tab4);
  f = Matrix(tab5);
  CHECK(a + b == e);
  CHECK(c + d == f);
}
TEST_CASE("Test martix dodawanie 2")
{
  Matrix a, b, c, d, e, f, g, h, i;
  double tab0[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab1[SIZE][SIZE] = {{0.00000000001, 0.00000000001}, {0.00000000001, 0.00000000001}};
  double tab2[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab3[SIZE][SIZE] = {{0.000000000001, 0.000000000001}, {0.000000000001, 0.000000000001}};
  double tab4[SIZE][SIZE] = {{5, 6}, {7, 8}};
  double tab5[SIZE][SIZE] = {{0.000000000009, 0.000000000009}, {0.000000000009, 0.000000000009}};
  double tab6[SIZE][SIZE] = {{1, 2}, {3, 4}};
  double tab7[SIZE][SIZE] = {{9, 10}, {11, 12}};
  double tab8[SIZE][SIZE] = {{5, 6}, {7, 8}};
  a = Matrix(tab0);
  b = Matrix(tab1);
  c = Matrix(tab2);
  d = Matrix(tab3);
  e = Matrix(tab4);
  f = Matrix(tab5);
  g = Matrix(tab6);
  h = Matrix(tab7);
  i = Matrix(tab8);
  CHECK(a + b == g);
  CHECK(c + d == h);
  CHECK(e + f == i);
}
TEST_CASE("test operatora () 1")
{
  Matrix x, y, z;
  double tab1[2][2] = {{1, 2}, {3, 4}}, tab2[2][2] = {{5, 6}, {7, 8}}, tab3[2][2] = {{9, 10}, {11, 12}};
  x = Matrix(tab1);
  y = Matrix(tab2);
  z = Matrix(tab3);
  double a, b, c, d, e, f, g, h, i, j, k, l;
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  e = 5;
  f = 6;
  g = 7;
  h = 8;
  i = 9;
  j = 10;
  k = 11;
  l = 12;
  CHECK(a == x(0, 0));
  CHECK(b == x(0, 1));
  CHECK(c == x(1, 0));
  CHECK(d == x(1, 1));
  CHECK(e == y(0, 0));
  CHECK(f == y(0, 1));
  CHECK(g == y(1, 0));
  CHECK(h == y(1, 1));
  CHECK(i == z(0, 0));
  CHECK(j == z(0, 1));
  CHECK(k == z(1, 0));
  CHECK(l == z(1, 1));
}
TEST_CASE("Twst tworzenie macierzy obrotu 1")
{
  double kat = 45;
  Matrix obrot;
  obrot = Matrix();
  obrot.przypisz_stopnie(kat);
  obrot.StopienNaRadian();
  obrot.Oblicz_Macierz_Obrotu();
  CHECK(obrot(0, 0) == cos(M_PI / 4));
  CHECK(obrot(0, 1) == -sin(M_PI / 4));
  CHECK(obrot(1, 0) == sin(M_PI / 4));
  CHECK(obrot(1, 1) == cos(M_PI / 4));
}
/*!
 * Prostokat
 * 
 */
TEST_CASE("Test prostokat konstruktor 1")
{
  Prostokat x;
  x = Prostokat();
  CHECK(x[0][0] == 0);
  CHECK(x[1][0] == 0);
  CHECK(x[2][0] == 0);
  CHECK(x[3][0] == 0);
  CHECK(x[0][1] == 0);
  CHECK(x[1][1] == 0);
  CHECK(x[2][1] == 0);
  CHECK(x[3][1] == 0);
}
TEST_CASE("Test prostokat konstruktor 2")
{
  Prostokat x = Prostokat();
  double tab[2] = {2, 2};
  Vector poczatek = Vector(tab);
  x = Prostokat(poczatek, 30, 60);
  CHECK(x[0][0] == 2);
  CHECK(x[1][0] == 2);
  CHECK(x[2][0] == 62);
  CHECK(x[3][0] == 62);
  CHECK(x[0][1] == 2);
  CHECK(x[1][1] == 32);
  CHECK(x[2][1] == 32);
  CHECK(x[3][1] == 2);
}
TEST_CASE("test prostokat [] 1")
{
  Prostokat x = Prostokat();
  double tab[2] = {0, 0};
  Vector poczatek = Vector(tab);
  x = Prostokat(poczatek, 30, 60);
  std::ostringstream out0;
  out0 << x[0];
  std::cout << out0.str() << std::endl;
  CHECK("0 0" == out0.str());
  std::ostringstream out1;
  out1 << x[1];
  std::cout << out1.str() << std::endl;
  CHECK("0 30" == out1.str());
  std::ostringstream out2;
  out2 << x[2];
  std::cout << out2.str() << std::endl;
  CHECK("60 30" == out2.str());
  std::ostringstream out3;
  out3 << x[3];
  std::cout << out3.str() << std::endl;
  CHECK("60 0" == out3.str());
}
TEST_CASE("Test prostokat translacja 1")
{
  Prostokat x = Prostokat();
  Vector translacja = Vector();
  double tab[2] = {2, 2};
  Vector poczatek = Vector(tab);
  x = Prostokat(poczatek, 30, 60);
  translacja = Vector(tab);
  x = x + translacja;
  CHECK(x[0][0] == 4);
  CHECK(x[1][0] == 4);
  CHECK(x[2][0] == 64);
  CHECK(x[3][0] == 64);
  CHECK(x[0][1] == 4);
  CHECK(x[1][1] == 34);
  CHECK(x[2][1] == 34);
  CHECK(x[3][1] == 4);
}
TEST_CASE("Test prostokat translacja 2")
{
  Prostokat x = Prostokat();
  Vector translacja = Vector();
  double tab[2] = {2, 2};
  double tab1[2] = {-2, -2};
  Vector poczatek = Vector(tab);
  x = Prostokat(poczatek, 30, 60);
  translacja = Vector(tab1);
  x = x + translacja;
  CHECK(x[0][0] == 0);
  CHECK(x[1][0] == 0);
  CHECK(x[2][0] == 60);
  CHECK(x[3][0] == 60);
  CHECK(x[0][1] == 0);
  CHECK(x[1][1] == 30);
  CHECK(x[2][1] == 30);
  CHECK(x[3][1] == 0);
}
TEST_CASE("Test prostokat sprawdzanie długości 1")
{
  Prostokat x = Prostokat();
  Prostokat y = Prostokat();
  Vector poczatek;
  double tab[2] = {0, 0};
  double kat = 45;
  poczatek = Vector(tab);
  x = Prostokat(poczatek, 100, 200);
  y = Prostokat(poczatek, 300, 400);
  Matrix obrot = Matrix();
  obrot.przypisz_stopnie(kat);
  obrot.StopienNaRadian();
  obrot.Oblicz_Macierz_Obrotu();
  for (int i = 0; i < 360; ++i)
  {
    x = x * obrot;
  }
  for (long int j = 0; j < 36000000; ++j)
  {
    y = y * obrot;
  }
  x.dlugosc();
  y.dlugosc();
}