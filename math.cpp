#include "mathlib.h"

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

  printf("testing /:\n");
  b = 444;
  c = 2;
  b = b/c;
  printf("expected: 222, actual: ");
  b.print();

  b = 444;
  b = b/2;
  printf("expected: 222, actual: ");
  b.print();

  printf("\n");

  printf("testing ==:\n");
  b = 3;
  c = 3;
  if(b == c) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 4;
  if(b == c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }
  printf("\n");

  printf("testing !=:\n");
  b = 4;
  c = 3;
  if(b != c) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b != c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }
  printf("\n");

  printf("testing >:\n");
  b = 4;
  c = 3;
  if(b > c) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b > c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b > c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b > 3) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b > 3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b > 3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b > (long)3) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b > (long)3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b > (long)3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b > "3") {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b > "3") {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b > "3") {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }
  printf("\n");

  printf("testing sumdigits()\n");
  c = 123456789;
  b = c.sumdigits();
  printf("expected: %d, actual: ", 45);
  b.print();
  printf("\n");

  printf("testing <:\n");
  c = 4;
  b = 3;
  if(b < c) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  c = 3;
  if(b < c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  c = 2;
  if(b < c) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b < 5) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b < 3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b < 1) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b < (long)5) {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b < (long)3) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b < (long)1) {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 4;
  if(b < "5") {
    printf("expected: 1, actual: 1\n");
  } else {
    printf("expected: 1, actual: 0\n");
  }

  b = 3;
  if(b < "3") {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  b = 2;
  if(b < "1") {
    printf("expected: 0, actual: 1\n");
  } else {
    printf("expected: 0, actual: 0\n");
  }

  printf("\n");

  printf("testing proddigits()\n");
  c = 123456789;
  b = c.proddigits();
  printf("expected: %d, actual: ", 362880);
  b.print();

  return 0;
}
