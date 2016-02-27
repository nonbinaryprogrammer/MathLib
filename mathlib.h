#include <stdio.h>
#include <sstream>
#include <string>

using namespace std;

/***************************************************************************
 * regular power function
 **************************************************************************/
int pow(int base, int power) {
  int iterator, solution;

  solution = 1;

  //multiply the base by iteself <power> number of times
  for(iterator=0; iterator<power; iterator++) {
    solution *= base;
  }

  return solution;
}

/***************************************************************************
 * BigInt Class
 * This is a class for storing positive integers of up to 100000 digits in
 * length. BigInts are stored as an array of integers, in Little Endian. They
 * have the additional property of digit count.
 **************************************************************************/
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

    //prints each digit in the array starting with the most significant bit,
    //which is stored in the highest index, at digits-1
    for(i=digits-1; i>=0; i--) {
      printf("%d", array[i]);
    }

    //if the BigInt == 0, then nothing would get printed by the above loop since
    //the digit count is set to 0, so this prints a 0 if the digit count is 0.
    if(digits == 0) {
      printf("0");
    }
    printf("\n");   //add a newline character

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

    //init the digit count to zero
    digits = 0;
    //when all of the number, n, has been stored, it will be equal to 0
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
   * begin *=
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
   * end *=
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
   * begin /
   **************************************************************************/
  BigInt operator/(const int n) {
    BigInt sol, i;

    i = (*this);
    sol = 0;

    while(i > n || i == n) {
      i -= n;
      sol += 1;
    }

    return sol;
  }

  BigInt operator/(const long n) {
    BigInt sol, i;

    i = (*this);
    sol = 0;

    while(i > n || i == n) {
      i -= n;
      sol += 1;
    }

    return sol;
  }

  BigInt operator/(const string n) {
    BigInt sol, i;

    i = (*this);
    sol = 0;

    while(i > n || i == n) {
      i -= n;
      sol += 1;
    }

    return sol;
  }

  BigInt operator/(const BigInt &n) {
    BigInt sol, i;

    i = (*this);
    sol = 0;

    while(i > n || i == n) {
      i -= n;
      sol += 1;
    }

    return sol;
  }

  /***************************************************************************
   * end /
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
  inline bool operator> (const int m) const {
    int i;
    BigInt n;

    n = m;

    i = digits - 1;

    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      if(array[i] > n.array[i]) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  inline bool operator> (const long m) const {
    int i;
    BigInt n;

    n = m;

    i = digits - 1;

    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      if(array[i] > n.array[i]) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  inline bool operator> (const string m) const {
    int i;
    BigInt n;

    n = m;

    i = digits - 1;

    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      if(array[i] > n.array[i]) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  inline bool operator> (const BigInt &n) const {
    int i;

    i = digits - 1;

    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      if(array[i] > n.array[i]) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  /***************************************************************************
   * end >
   **************************************************************************/

  /***************************************************************************
   * begin <
   **************************************************************************/
  inline bool operator< (const int n) const {
    BigInt i;
    bool sol;

    i = n;

    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const long n) const {
    BigInt i;
    bool sol;

    i = n;

    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const string n) const {
    BigInt i;
    bool sol;

    i = n;

    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const BigInt &n) const {
    bool sol;

    sol = n > (*this);

    return sol;
  }

  /***************************************************************************
   * end <
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
