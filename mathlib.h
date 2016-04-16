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
      //get the lsb from the number by modding by 10 and stick it in the msb
      array[digits] = n%10;
      //save that removal of lsb
      n = n/10;
      //add to the digit count
      digits++;
    }

    //fill the rest of the array with 0's
    for(i=digits; i<100000; i++) {
      array[i] = 0;
    }

    return;
  }

  //repeat process from ints for longs
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

  //repeat process from ints for strings
  void operator=(string n) {
    int i;

    digits = 0;
    //intsead of being 0 like the ints, the string will be empty when all the
    //digits have been read in
    while(n != "") {
      //get the lsb from the end of the string, and convert it to an integer 0-9
      array[digits] = (int)n[n.size()-1] - 48;
      //erase the lsb from the string
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
    //for each digit in the bigint, copy it
    while(digits < n.digits) {
      //copy the digit over
      array[digits] = n.array[digits];
      digits++;
    }

    //fill in the rest of the array with 0's
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

    //convert n to a BigInt using the assignment operator
    s = n;
    //add the two numbers
    s = (*this) + s;
    //assign the solution to "this" number
    (*this) = s;

    return;
  }

  //repeat like int but for long
  void operator+=(long n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  //repeat like int but for string
  void operator+=(string n) {
    BigInt s;

    s = n;
    s = (*this) + s;
    (*this) = s;

    return;
  }

  //repeat like int but for BigInt
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
  //repeat like += but with subtraction
  void operator-=(int n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  //repeat like += but with subtraction
  void operator-=(long n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  //repeat like += but with subtraction
  void operator-=(string n) {
    BigInt s;

    s = n;
    s = (*this) - s;
    (*this) = s;

    return;
  }

  //repeat like += but with subtraction
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
  //repeat like += but with multiplication
  void operator*=(int n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  //repeat like += but with multiplication
  void operator*=(long n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  //repeat like += but with multiplication
  void operator*=(string n) {
    BigInt s;

    s = n;
    s = (*this) * s;
    (*this) = s;

    return;
  }

  //repeat like += but with multiplication
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

    //convert to BigInt by assignment
    sol = n;
    //use BigInt implementation of addition
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(long n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //use BigInt implementation of addition
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(string n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //use BigInt implementation of addition
    sol = (*this) + sol;

    return sol;
  }

  BigInt operator+(const BigInt &n) {
    BigInt sol;
    int d, t, carry;

    //store the larger number of digits in the iterator, t
    if(digits > n.digits) {
      t = digits;
    } else {
      t = n.digits;
    }

    //carry bit will tell whether the two digits added together >9
    carry = 0;
    //BigInt to store the solution
    sol = 0;

    //repeat for each digit in the longer number
    for(d=0; d<t; d++) {
      //add one to the solution's digit count
      sol.digits++;

      //add the two digits and the carry bit
      sol.array[d] += array[d] + n.array[d] + carry;

      //check if the carry bit needs to be set or reset
      if(sol.array[d] > 9) {
        //set the carry bit if the current digit is >9
        carry = 1;
        //store the digit%10 to get the last digit
        //if sol.array[d] == 12, sol.array[d] %= 10 == 2
        sol.array[d] %= 10;
      } else {
        //reset the carry bit if the digit is less than 10
        carry = 0;
      }
    }

    //once all of the digits have been iterated through, there may still be a
    //carry
    if(carry == 1) {
      //if there is a carry, put a 1 in the msb of the number
      sol.array[sol.digits] = 1;
      //add 1 to the digits
      sol.digits++;
    }

    //double checks that the digit count is correct by checking that the msb is
    //not 0 and decrementing the digit count until it is found that the number
    //is 0 or until the real msb is retrieved
    while(sol.array[sol.digits-1] == 0 && sol.digits != 0) {
      sol.digits = sol.digits - 1;
    }

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

    //convert to BigInt by assignment
    sol = n;
    //perform subtraction using BigInt implementation
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(long n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //perform subtraction using BigInt implementation
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(string n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //perform subtraction using BigInt implementation
    sol = (*this) - sol;

    return sol;
  }

  BigInt operator-(const BigInt &n) {
    BigInt sol;
    int i, borrow;

    //init solution to the left hand operand
    sol = (*this);
    //init the borrow bit to 0
    borrow = 0;
    //repeat for each digit in left operand
    for(i=0; i<digits; i++) {
      //subtract the borrow from the digit
      sol.array[i] -= borrow;
      //reset borrow bit
      borrow = 0;
      //subtract the digit of right operand from digit of left operand if there
      //is a right operand digit (there wouldn't be in this operation: 102 -
      //002 for the 2nd or 3rd iteration
      if(i < n.digits) {
        sol.array[i] -= n.array[i];
      }
      //borrow if the digit is less than 0
      if(sol.array[i] < 0) {
        //add 10
        sol.array[i] += 10;
        //set the borrow bit
        borrow = 1;
      }
    }
    //get rid of 0 msb's
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

    //convert to BigInt by assignment
    sol = n;
    //perform multiplication using BigInt implementation
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(long n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //perform multiplication using BigInt implementation
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(string n) {
    BigInt sol;

    //convert to BigInt by assignment
    sol = n;
    //perform multiplication using BigInt implementation
    sol = (*this) * n;

    return sol;
  }

  BigInt operator*(const BigInt &multiplier) {
    BigInt sol;
    int i, j, temp, offset;

    //init solution to 0
    sol = 0;
    //special case if multiplier is 0 or 1
    if(multiplier == 0) {
      return sol;
    } else if(multiplier == 1) {
      return (*this);
    }
    //special case is multiplied number is 1 or 0
    if((*this) == 0) {
      return sol;
    } else if((*this) == 1) {
      return multiplier;
    }

    //repeat for each digit of the multiplier
    for(i=0; i<multiplier.digits; i++) {
      //calculate how many 0's to add after the number based on what digit we
      //are at
      offset = pow(10, i);
      //repeat for each of the digits in the multiplied number
      for(j=0; j<digits; j++) {
        //for all but the first digit, add a 0 to the offset
        if(j != 0) {
          offset *= 10;
        }
        //multiply the two digits
        temp = array[j] * multiplier.array[i];
        //offset the number
        temp *= offset;
        //add it to the total
        sol = sol + temp;
      }
    }

    //get rid of leading 0's in digit count
    while(sol.array[sol.digits-1] == 0 && sol.digits != 0) { sol.digits = sol.digits - 1; }

    return sol;
  }
  /***************************************************************************
   * end *
   **************************************************************************/

  /***************************************************************************
   * begin /
   * TODO: Fix division algorithm. Sometimes segfaults
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
  //TODO: implement isprime. dependent on addition
  bool isprime(void) {
    return 1;
  }

  //sums the digits
  BigInt sumdigits(void) {
    BigInt sum;
    int i;

    //init sum to 0
    sum = 0;
    //repeat for each digit
    for(i=0; i<digits; i++) {
      //add the digit to the sum
      sum += array[i];
    }

    return sum;
  }

  //product of the digits
  BigInt proddigits(void) {
    BigInt product;
    int i;

    //init product to 1
    product = 1;
    //repeat for each digit
    for(i=0; i<digits; i++) {
      //multiply the digit by the product
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

    //convert to BigInt by assignment
    i = n;

    //use BigInt implementation
    return ((*this) == i);
  }

  inline bool operator==(const long n) const {
    BigInt i;

    //convert to BigInt by assignment
    i = n;

    //use BigInt implementation
    return ((*this) == i);
  }

  inline bool operator==(const string n) const {
    BigInt i;

    //convert to BigInt by assignment
    i = n;

    //use BigInt implementation
    return ((*this) == i);
  }

  inline bool operator==(const BigInt &i) const {
    int j;

    //special case
    //if the number of digits in the number are not equal, they are not the same
    //numbers
    if(digits != i.digits) {
      return 0;
    }

    //repeat for each digit
    for(j=0; j<digits; j++) {
      //if two digits are not the same, return false
      if(array[j] != i.array[j]) {
        return 0;
      }
    }

    //everything matches and returns true
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

    //convert to BigInt by assignment
    i = n;

    //return the opposite of the BigInt check for equality
    return !((*this) == i);
  }

  inline bool operator!=(const long n) const {
    BigInt i;

    //convert to BigInt by assignment
    i = n;

    //return the opposite of the BigInt check for equality
    return !((*this) == i);
  }

  inline bool operator!=(const string n) const {
    BigInt i;

    //convert to BigInt by assignment
    i = n;

    //return the opposite of the BigInt check for equality
    return !((*this) == i);
  }

  inline bool operator!=(const BigInt &n) const {
    //return the opposite of the BigInt check for equality
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

    //convert to BigInt by assignment
    n = m;

    //get index of left operand msb
    i = digits - 1;

    //special case if the digits are not equal, the one with more digits is
    //bigger
    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      //if digits are equal, loop over each digit starting with msb until they
      //are not equal
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      //return based on digit's inequality
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

    //convert to BigInt by assignment
    n = m;

    //get index of left operand msb
    i = digits - 1;

    //special case if the digits are not equal, the one with more digits is
    //bigger
    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      //if digits are equal, loop over each digit starting with msb until they
      //are not equal
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      //return based on digit's inequality
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

    //convert to BigInt by assignment
    n = m;

    //get index of left operand msb
    i = digits - 1;

    //special case if the digits are not equal, the one with more digits is
    //bigger
    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      //if digits are equal, loop over each digit starting with msb until they
      //are not equal
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      //return based on digit's inequality
      if(array[i] > n.array[i]) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  inline bool operator> (const BigInt &n) const {
    int i;

    //get index of left operand msb
    i = digits - 1;

    //special case if the digits are not equal, the one with more digits is
    //bigger
    if(digits > n.digits) {
      return 1;
    } else if(digits < n.digits) {
      return 0;
    } else {
      //if digits are equal, loop over each digit starting with msb until they
      //are not equal
      while(array[i] == n.array[i] && i > 0) {
        i--;
      }

      //return based on digit's inequality
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

    //convert to BigInt by assignment
    i = n;

    //use implementation of > and reverse left and right operands
    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const long n) const {
    BigInt i;
    bool sol;

    //convert to BigInt by assignment
    i = n;

    //use implementation of > and reverse left and right operands
    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const string n) const {
    BigInt i;
    bool sol;

    //convert to BigInt by assignment
    i = n;

    //use implementation of > and reverse left and right operands
    sol = i > (*this);

    return sol;
  }

  inline bool operator< (const BigInt &n) const {
    bool sol;

    //use implementation of > and reverse left and right operands
    sol = n > (*this);

    return sol;
  }

  /***************************************************************************
   * end <
   **************************************************************************/

  /***************************************************************************
   * begin >=
   **************************************************************************/
  inline bool operator >=(const int n) const {
    //use implementations of > and ==
    return ((*this)>n)||((*this)==n);
  }

  inline bool operator >=(const long n) const {
    //use implementations of > and ==
    return ((*this)>n)||((*this)==n);
  }

  inline bool operator >=(const string n) const {
    //use implementations of > and ==
    return ((*this)>n)||((*this)==n);
  }

  inline bool operator >=(const BigInt &n) const {
    //use implementations of > and ==
    return ((*this)>n)||((*this)==n);
  }
  /***************************************************************************
   * end >=
   **************************************************************************/

  /***************************************************************************
   * begin <=
   **************************************************************************/
  inline bool operator <=(const int n) const {
    //use implementations of < and ==
    return ((*this)<n)||((*this)==n);
  }

  inline bool operator <=(const long n) const {
    //use implementations of < and ==
    return ((*this)<n)||((*this)==n);
  }

  inline bool operator <=(const string n) const {
    //use implementations of < and ==
    return ((*this)<n)||((*this)==n);
  }

  inline bool operator <=(const BigInt &n) const {
    //use implementations of < and ==
    return ((*this)<n)||((*this)==n);
  }
  /***************************************************************************
   * end <=
   **************************************************************************/

  /***************************************************************************
   * END LOGICAL OPERATOR OVERLOADS
   **************************************************************************/

  /***************************************************************************
   * BEGIN ACCESSORS
   **************************************************************************/
  //returns the BigInt as a regular int
  //may overflow
  int asint(void) {
    int s, offset;

    //init solution to 0
    s = 0;
    //decrement digits to point to msb
    digits = digits - 1;
    //init offset for msb
    offset = pow(10, digits);

    //repeat for each digit
    while(digits >= 0) {
      //add the digit time the offset to solution
      s += (array[digits] * offset);
      //decrement digits and offset
      digits = digits - 1;
      offset /= 10;
    }
    return s;
  }

  //pops msb
  int pop(void) {
    int sol;

    //decrement digit count
    digits--;
    //store msb
    sol = array[digits];
    //remove msb from array
    array[digits] = 0;

    //return stored msb
    return sol;
  }

  //return msb
  int peek(void) {
    return array[digits-1];
  }

  //pushes new digit at msb
  void push(int n) {
    array[digits] = n;
    digits++;
  }
  /***************************************************************************
   * END ACCESORS
   **************************************************************************/
};
