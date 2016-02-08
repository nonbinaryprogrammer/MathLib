#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

int pow(int n, int m) {
  int i, s;

  s = 1;

  for(i=0; i<m; i++) {
    s *= n;
  }

  return s;
}

class BigInt {
  private:
    int array[100000];
    int digits;

  public:
  /***************************************************************************
   * print number in big endian
   **************************************************************************/
  void print(void) {
    int i;

    for(i=digits-1; i>=0; i--) {
      printf("%d", array[i]);
    }
    printf("\n");

    if(digits == 0) {
      printf("0\n");
    }

    return;
  }

  /***************************************************************************
   * ASSIGNMENT OPERATOR OVERLOADS
   **************************************************************************/
  /***************************************************************************
   * begin =
   **************************************************************************/
  void operator=(int n) {
    int i;

    digits = 0;
    while(n != 0) {
      array[digits] = n%10;
      n = n/10;
      digits++;
    }

    for(i=digits; i<100000; i++) {
      array[i] = 0;
    }

    return;
  }

  void operator=(long n) {
    int i;

    digits = 0;
    while(n != 0) {
      array[digits] = n%10;
      n = n/10;
      digits++;
    }

    for(i=digits; i<100000; i++) {
      array[i] = 0;
    }

    return;
  }

  void operator=(string n) {
    int i;

    digits = 0;
    while(n != "") {
      array[digits] = (int)n[n.size()-1] - 48;
      n.erase(n.size()-1);
      digits++;
    }

    for(i=digits; i<100000; i++) {
      array[i] = 0;
    }

    return;
  }

  void operator=(const BigInt& n) {
    int i;

    digits = 0;
    while(digits < n.digits) {
      array[digits] = n.array[digits];
      digits++;
    }

    for(i=digits; i<100000; i++) {
      array[i] = 0;
    }

    return;
  }
  /***************************************************************************
   * end =
   **************************************************************************/

  /***************************************************************************
   * begin +=
   **************************************************************************/
  void operator+=(int n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(long n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(string n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  void operator+=(const BigInt& n) {
    BigInt s;

    s = (*this) + n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end +=
   **************************************************************************/

  /***************************************************************************
   * begin -=
   **************************************************************************/
  void operator-=(int n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(long n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(string n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  void operator-=(const BigInt& n) {
    BigInt s;

    s = (*this) - n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end -=
   **************************************************************************/

  /***************************************************************************
   * begin *
   **************************************************************************/
  void operator*=(int n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(long n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(string n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  void operator*=(const BigInt& n) {
    BigInt s;

    s = (*this) * n;
    digits = 0;
    (*this) = s;

    return;
  }
  /***************************************************************************
   * end *
   **************************************************************************/

  /***************************************************************************
   * END ASSIGNMENT OPERATOR OVERLOADS
   **************************************************************************/
  
  /***************************************************************************
   * ARITHMETIC OPERATOR OVERLOADS
   **************************************************************************/
  /***************************************************************************
   * begin +
   **************************************************************************/
  BigInt operator+(int n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(long n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(string n) {
    BigInt sol;
    int i;

    sol = n;
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(const BigInt &n) {
    BigInt sol;
    int d, t, carry;

    if(digits > n.digits) {
      t = digits;
    } else {
      t = n.digits;
    }

    carry = 0;
    sol = 0;

    for(d=0; d<t; d++) {
      sol.digits++;

      //printf("%d + %d + carry(%d) = ", array[d], n.array[d], carry);
      sol.array[d] += array[d] + n.array[d] + carry;
      //printf("%d\n", sol.array[d]);
      //sol.print();

      if(sol.array[d] > 9) {
        carry = 1;
        sol.array[d] %= 10;
      } else {
        carry = 0;
      }
      //sol.print();
      //printf("sol.digits=%d\n", sol.digits);
    }

    if(carry == 1) {
      sol.array[sol.digits] = 1;
      sol.digits++;
    }

    while(sol.array[sol.digits-1] == 0 && sol.digits != 0) {
      sol.digits = sol.digits - 1;
    }

    //sol.print();

    return sol;
  }
  /***************************************************************************
   * end +
   **************************************************************************/

  /***************************************************************************
   * begin -
   **************************************************************************/
  BigInt operator-(int n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(long n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(string n) {
    BigInt sol;

    sol = n;
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(const BigInt &n) {
    BigInt sol;
    int i, borrow;

    sol = (*this);
    borrow = 0;
    for(i=0; i<digits; i++) {
      sol.array[i] -= borrow;
      borrow = 0;
      if(i < n.digits) {
        sol.array[i] -= n.array[i];
      }
      if(sol.array[i] < 0) {
        sol.array[i] += 10;
        borrow = 1;
      }
    }
    while(sol.array[sol.digits-1] == 0) {
      sol.digits--;
    }

    return sol;
  }
  /***************************************************************************
   * end -
   **************************************************************************/

  /***************************************************************************
   * begin *
   **************************************************************************/
  BigInt operator*(int n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(long n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(string n) {
    BigInt sol;

    sol = n;
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(const BigInt &multiplier) {
    BigInt sol;
    int i, j, temp, offset;

    sol = 0;
    if(multiplier == 0) {
      return sol;
    }
    for(i=0; i<multiplier.digits; i++) {
      offset = pow(10, i);
      for(j=0; j<digits; j++) {
        if(j != 0) {
          offset *= 10;
        }
        temp = array[j] * multiplier.array[i];
        temp *= offset;
        sol = sol + temp;
      }
    }
    while(sol.array[sol.digits-1] == 0 && sol.digits != 0) { sol.digits = sol.digits - 1; }

    return sol;
  }
  /***************************************************************************
   * end *
   **************************************************************************/

  /***************************************************************************
   * begin arithmetic on digits
   **************************************************************************/
  bool isprime(void) {
    return 1;
  }

  BigInt sumdigits(void) {
    BigInt sum;
    int i;

    sum = 0;
    for(i=0; i<digits; i++) {
      sum += array[i];
    }

    return sum;
  }

  BigInt proddigits(void) {
    BigInt product;
    int i;

    product = 1;
    for(i=0; i<digits; i++) {
      product *= array[i];
    }

    return product;
  }
  /***************************************************************************
   * end arithmetic on digits
   **************************************************************************/

  /***************************************************************************
   * END ARITHMETIC OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * BEGIN LOGICAL OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * begin ==
   **************************************************************************/
  inline bool operator==(const int n) const {
    BigInt i;
    int j;

    i = n;

    return ((*this) == i);
  }

  inline bool operator==(const long n) const {
    BigInt i;
    int j;

    i = n;

    return ((*this) == i);
  }

  inline bool operator==(const string n) const {
    BigInt i;
    int j;

    i = n;

    return ((*this) == i);
  }

  inline bool operator==(const BigInt &i) const {
    int j;

    if(digits != i.digits) {
      return 0;
    }

    for(j=0; j<digits; j++) {
      if(array[j] != i.array[j]) {
        return 0;
      }
    }

    return 1;
  }

  /***************************************************************************
   * end ==
   **************************************************************************/

  /***************************************************************************
   * begin !=
   **************************************************************************/
  inline bool operator!=(const int n) const {
    BigInt i;

    i = n;

    return !((*this) == i);
  }

  inline bool operator!=(const long n) const {
    BigInt i;

    i = n;

    return !((*this) == i);
  }

  inline bool operator!=(const string n) const {
    BigInt i;

    i = n;

    return !((*this) == i);
  }

  inline bool operator!=(const BigInt &n) const {
    return !((*this) == n);
  }

  /***************************************************************************
   * end !=
   **************************************************************************/

  /***************************************************************************
   * begin >
   **************************************************************************/
  /***************************************************************************
   * end >
   **************************************************************************/

  /***************************************************************************
   * END LOGICAL OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * BEGIN ACCESSORS 
   **************************************************************************/
  int asint(void) {
    int s, offset;

    s = 0;
    digits = digits - 1;
    offset = pow(10, digits);

    while(digits >= 0) {
      s += (array[digits] * offset);
      digits = digits - 1;
      offset /= 10;
    }
  }
  /***************************************************************************
   * END ACCESORS
   **************************************************************************/
};

int main() {
  int i = 2000;
  BigInt b, c;

  printf("testing assignment (=):\n");
  b = i;
  printf("expected: %d, actual: ", 2000);
  b.print();
  c = b;
  printf("expected: %d, actual: ", 2000);
  c.print();
  b = (long)i;
  printf("expected: %d, actual: ", 2000);
  b.print();
  b = "2000";
  printf("expected: %d, actual: ", 2000);
  b.print();
  printf("\n");

  printf("testing +=:\n");
  c = i;
  c += (int)2111;
  printf("expected: %d, actual: ", 4111);
  c.print();
  c += (long)2111;
  printf("expected: %d, actual: ", 6222);
  c.print();
  c += "2111";
  printf("expected: %d, actual: ", 8333);
  c.print();
  b = 999;
  c += b;
  printf("expected: %d, actual: ", 9332);
  c.print();
  c += b;
  printf("expected: %d, actual: ", 10331);
  c.print();
  printf("\n");

  printf("testing +:\n");
  c = i;
  c = c + (int)2111;
  printf("expected: %d, actual: ", 4111);
  c.print();
  c = c + (long)2111;
  printf("expected: %d, actual: ", 6222);
  c.print();
  c = c + "2111";
  printf("expected: %d, actual: ", 8333);
  c.print();
  b = 999;
  c = c + b;
  printf("expected: %d, actual: ", 9332);
  c.print();
  c = c + b;
  printf("expected: %d, actual: ", 10331);
  c.print();
  printf("\n");

  printf("testing -:\n");
  c = 1000;
  b = 999;
  c = c - b;
  printf("expected: %d, actual: ", 1);
  c.print();
  b = b - 123;
  printf("expected: %d, actual: ", 876);
  b.print();
  b = b - (long)123;
  printf("expected: %d, actual: ", 753);
  b.print();
  b = b - "123";
  printf("expected: %d, actual: ", 630);
  b.print();
  printf("\n");

  printf("testing -=:\n");
  c = 1000;
  b = 999;
  c -= b;
  printf("expected: %d, actual: ", 1);
  c.print();
  b -= 123;
  printf("expected: %d, actual: ", 876);
  b.print();
  b -= (long)123;
  printf("expected: %d, actual: ", 753);
  b.print();
  b -= "123";
  printf("expected: %d, actual: ", 630);
  b.print();
  printf("\n");

  printf("testing *:\n");
  b = 4;
  c = 3;
  b = c * b;
  printf("expected: %d, actual: ", 12);
  b.print();
  b = c * b;
  printf("expected: %d, actual: ", 36);
  b.print();
  b = c * b;
  printf("expected: %d, actual: ", 108);
  b.print();
  printf("\n");

  printf("testing *=:\n");
  b = 4;
  c = 3;
  b *= c;
  printf("expected: %d, actual: ", 12);
  b.print();
  b *= c;
  printf("expected: %d, actual: ", 36);
  b.print();
  b *= c;
  printf("expected: %d, actual: ", 108);
  b.print();
  printf("\n");

  printf("testing sumdigits()\n");
  c = 123456789;
  b = c.sumdigits();
  printf("expected: %d, actual: ", 45);
  b.print();
  printf("\n");

  printf("testing proddigits()\n");
  c = 123456789;
  b = c.proddigits();
  printf("expected: %d, actual: ", 362880);
  b.print();

  return 0;
}
