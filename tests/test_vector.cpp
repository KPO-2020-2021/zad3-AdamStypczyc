#include "../tests/doctest/doctest.h"
#include "Prostokat.hh"

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
TEST_CASE("test mnozenie vector razy macierz 1")
{
  Vector x, wynik;
  double tab1[2] = {0, 2}, tab2[2] = {-2, 0};
  Matrix obrot = Matrix();
  obrot.przypisz_stopnie(90);
  obrot.StopienNaRadian();
  obrot.Oblicz_tablice();
  x = Vector(tab1);
  x = obrot * x;
  wynik = Vector(tab2);
  CHECK(wynik == x);
}
TEST_CASE("test mnozenie vector razy macierz 2")
{
  Vector x, wynik;
  double tab1[2] = {2, 0}, tab2[2] = {sqrt(2), sqrt(2)};
  Matrix obrot = Matrix();
  obrot.przypisz_stopnie(45);
  obrot.StopienNaRadian();
  obrot.Oblicz_tablice();
  x = Vector(tab1);
  x = obrot * x;
  wynik = Vector(tab2);
  CHECK(wynik == x);
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

TEST_CASE("test wczytywanie vector standard"){
    Vector x;

    std::istringstream in("21 37");
    in >> x;
    std::ostringstream out;
    out << x;
    std::cout << out.str()<<std::endl;
    CHECK("21 37"== out.str());
}
