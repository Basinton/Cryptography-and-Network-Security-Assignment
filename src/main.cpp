#include "../headers/main.h"
#include <unistd.h>

using namespace std;
using namespace NTL;

// Euclide
ZZ gcd(ZZ number1, ZZ number2)
{
  if (number1 == 0)
    return number2;
  return gcd(number2 % number1, number1);
}

// Extended Euclide to find invert number
bool extendedEuclid(const ZZ &number1, const ZZ &number2, ZZ &t)
{
  /*
  Bézout's identity asserts that "number1" and "number2" are coprime if and only if there exist integers s and t such that
      number2*s + number1*t = 1
      Reducing this identity modulo number2 give:
      number1*t = 1 mod number2
      ===============> Phù hợp để tìm số nghịch đảo do Định nghĩa số nghịch đảo của w là w^(-1) với w^(-1) * w = 1
  */
  t = 0;
  ZZ newt(1);
  ZZ r;
  ZZ newr;
  ZZ quotient;

  r = number2;
  newr = number1;

  ZZ temp1, temp2;

  while (newr != 0)
  {
    quotient = r / newr;

    temp1 = t;
    t = newt;
    newt = temp1 - quotient * newt;

    temp2 = r;
    r = newr;
    newr = temp2 - quotient * newr;
  }

  if (r > 1)
    return 0;
  if (t < 0)
    t = t + number2;
  return 1;
}

ZZ modMul(const ZZ &number1, const ZZ &number2, const ZZ &mod)
{
  return (number1 * number2) % mod;
}

ZZ modPow(ZZ number, ZZ power, ZZ mod)
{
  assert(power >= long(0));
  ZZ result(1);
  while (power > long(0))
  {
    if ((power & 1) == 1)
    {
      result = modMul(result, number, mod);
    }
    number = modMul(number, number, mod);
    power = power >> 1;
  }
  return result;
}

bool MillerTest(const ZZ &number, const ZZ &d, long r, const ZZ &ran)
{
  // loop variable
  long i = 0;
  ZZ y;

  // Compute: x = pow(ran, d) % number
  ZZ x = modPow(ran, d, number);
  if (x == 1 || x == number - 1)
    return true;

  // Below loop mainly runs 'r-1' times.
  do
  {
    y = x;
    x = (y * y) % number;
    i += 1;
  } while (i < r && x != 1);

  return (x == 1) && (y == number - 1);
}

bool isPrime(const ZZ &number, long accurancy)
{
  if (number <= 1)
    return false;

  PrimeSeq seq;
  long check_num = seq.next();

  do
  {
    if (number % check_num == 0)
      return number == check_num;
    check_num = seq.next();
  } while (check_num < 2000);

  // if pass then Miller-Rabin check:
  ZZ d;
  long r;

  // number-1 = d* 2^r

  d = (number - 1) / 2;
  r = 1;

  do
  {
    r += 1;
    d /= 2;
  } while (d % 2 == 0);

  // then we had d and r
  ZZ ran; // random number from 0 to number-1
  for (int i = 0; i < accurancy; i += 1)
  {
    ran = RandomBnd(number);

    if (!MillerTest(number, d, r, ran))
      return 0;
  }

  return 1;
}

int main()
{
  ZZ n;
  cout << "Please enter n: ";
  cin >> n;
  cout << endl;

  // Example: Prime number is
  // 1000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000000000000000000000000000
  // 0000000000000000000000000000000000000000000000000174295123053

  if (isPrime(n, 10))
    cout << "\n"
         << n << " is probably prime\n";
  else
    cout << "\n"
         << n << " is composite\n";

  return 0;

  // Function to find invert of number

  // ZZ n2;
  // cout << "Please enter n2: ";
  // cin >> n2;
  // ZZ invert_n;
  // cout << extendedEuclid(n, n2, invert_n);
  // cout << endl << invert_n;
}
