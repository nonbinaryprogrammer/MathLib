#include <assert.h>
#include "string.h"
#include "mathlib.h"

template<typename T>
void Assert_BigInt_Equals(const BigInt& tested, T expected, const char* msg=NULL)
{
	if(msg)
	{
		printf(msg,expected);
		tested.print();
	}
	assert(tested==expected);
}

template<typename T>
void Assert(T tested, T expected, const char* msg=NULL)
{
	if(msg)
	{
		printf(msg,expected,tested);
	}
	assert(tested==expected);
}

char buffer[128]={0};
char* IntToString(int a)
{
	memset(buffer,0,128);
	sprintf(buffer,"%d",a);
	return buffer;
}

const int test_value[9]={2000,2111,999,1000,123,4,3,444,2};

int main() {
  int i = test_value[0];
  BigInt b, c;

  printf("testing assignment (=):\n");
  b = i;
  Assert_BigInt_Equals( b, test_value[0], "expected: %d, actual: " );
  c = b;
  Assert_BigInt_Equals( c, test_value[0], "expected: %d, actual: " );
  b = (long)i;
  Assert_BigInt_Equals( b, test_value[0], "expected: %d, actual: " );
  b = IntToString(test_value[0]);
  Assert_BigInt_Equals( b, test_value[0], "expected: %d, actual: " );
  printf("\n");

  printf("testing +=:\n");
  c = i;
  c += (int)test_value[1];
  Assert_BigInt_Equals( c, test_value[0]+1*test_value[1], "expected: %d, actual: " );
  c += (long)test_value[1];
  Assert_BigInt_Equals( c, test_value[0]+2*test_value[1], "expected: %d, actual: " );
  c += IntToString(test_value[1]);
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1], "expected: %d, actual: " );
  b = test_value[2];
  c += b;
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1]+1*test_value[2], "expected: %d, actual: " );
  c += b;
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1]+2*test_value[2], "expected: %d, actual: " );
  printf("\n");

  printf("testing +:\n");
  c = i;
  c = c + (int)test_value[1];
  Assert_BigInt_Equals( c, test_value[0]+1*test_value[1], "expected: %d, actual: " );
  c = c + (long)test_value[1];
  Assert_BigInt_Equals( c, test_value[0]+2*test_value[1], "expected: %d, actual: " );
  c = c + IntToString(test_value[1]);
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1], "expected: %d, actual: " );
  b = test_value[2];
  c = c + b;
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1]+1*test_value[2], "expected: %d, actual: " );
  c = c + b;
  Assert_BigInt_Equals( c, test_value[0]+3*test_value[1]+2*test_value[2], "expected: %d, actual: " );
  printf("\n");

  printf("testing -:\n");
  c = test_value[3];
  b = test_value[2];
  c = c - b;
  Assert_BigInt_Equals( c, test_value[3]-test_value[2], "expected: %d, actual: " );
  b = b - test_value[4];
  Assert_BigInt_Equals( b, test_value[2]-1*test_value[4], "expected: %d, actual: " );
  b = b - (long)test_value[4];
  Assert_BigInt_Equals( b, test_value[2]-2*test_value[4], "expected: %d, actual: " );
  b = b - IntToString(test_value[4]);
  Assert_BigInt_Equals( b, test_value[2]-3*test_value[4], "expected: %d, actual: " );
  printf("\n");

  printf("testing -=:\n");
  c = test_value[3];
  b = test_value[2];
  c -= b;
  Assert_BigInt_Equals( c, test_value[3]-test_value[2], "expected: %d, actual: " );
  c.print();
  b -= test_value[4];
  Assert_BigInt_Equals( b, test_value[2]-1*test_value[4], "expected: %d, actual: " );
  b.print();
  b -= (long)test_value[4];
  Assert_BigInt_Equals( b, test_value[2]-2*test_value[4], "expected: %d, actual: " );
  b.print();
  b -= IntToString(test_value[4]);
  Assert_BigInt_Equals( b, test_value[2]-3*test_value[4], "expected: %d, actual: " );
  b.print();
  printf("\n");

  printf("testing *:\n");
  b = test_value[5];
  c = test_value[6];
  b = c * b;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6], "expected: %d, actual: " );
  b = c * b;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6]*test_value[6], "expected: %d, actual: " );
  b = c * b;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6]*test_value[6]*test_value[6], "expected: %d, actual: " );
  printf("\n");

  printf("testing *=:\n");
  b = test_value[5];
  c = test_value[6];
  b *= c;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6], "expected: %d, actual: " );
  b *= c;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6]*test_value[6], "expected: %d, actual: " );
  b *= c;
  Assert_BigInt_Equals( b, test_value[5]*test_value[6]*test_value[6]*test_value[6], "expected: %d, actual: " );
  printf("\n");

  printf("testing /:\n");
  b = test_value[7];
  c = test_value[8];
  b = b/c;
  Assert_BigInt_Equals( b, test_value[7]/test_value[8], "expected: %d, actual: " );

  b = test_value[7];
  b = b/test_value[8];
  Assert_BigInt_Equals( b, test_value[7]/test_value[8], "expected: %d, actual: " );

  printf("\n");

  printf("testing ==:\n");
  b = test_value[6];
  c = test_value[6];
  Assert( b==c, true, "expected: %d, actual: %d\n" );

  b = test_value[5];
  Assert( b==c, false, "expected: %d, actual: %d\n" );
  printf("\n");

  printf("testing !=:\n");
  b = test_value[5];
  c = test_value[6];
  Assert( b!=c, true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b!=c, false, "expected: %d, actual: %d\n" );
  printf("\n");

  printf("testing >:\n");
  b = test_value[6]+1;
  c = test_value[6];
  Assert( b>c, true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );

  printf("\n");

  printf("testing <:\n");
  b = test_value[6]-1;
  c = test_value[6];
  Assert( b<c, true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );

  printf("\n");

  printf("Testing >=:\n");
  b = test_value[6]+1;
  c = test_value[6];
  Assert( b>=c, true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>=c, true, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>=c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>=test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>=test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>=test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>=(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>=(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>=(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b>=IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b>=IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b>=IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );
  printf("\n");

  printf("Testing <=:\n");
  b = test_value[6]-1;
  c = test_value[6];
  Assert( b<=c, true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<=c, true, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<=c, false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<=test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<=test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<=test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<=(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<=(long)test_value[6], true, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<=(long)test_value[6], false, "expected: %d, actual: %d\n" );

  b = test_value[6]-1;
  Assert( b<=IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6];
  Assert( b<=IntToString(test_value[6]), true, "expected: %d, actual: %d\n" );

  b = test_value[6]+1;
  Assert( b<=IntToString(test_value[6]), false, "expected: %d, actual: %d\n" );
  printf("\n");

  printf("testing sumdigits()\n");
  c = 123456789;
  Assert_BigInt_Equals( c.sumdigits(), 45, "expected: %d, actual: " );
  printf("\n");

  printf("testing proddigits()\n");
  c = 123456789;
  Assert_BigInt_Equals( c.proddigits(), 362880, "expected: %d, actual: " );
  printf("\n");

  printf("testing push:\n");
  c = 3;
  c.push(4);
  Assert_BigInt_Equals( c, 43, "expected: %d, actual: " );
  printf("\n");

  printf("testing peek:\n");
  Assert( c.peek(), 4, "expected: %d, actual: %d\n" );
  printf("\n");

  printf("testing pop:\n");
  Assert( c.pop(), 4, "expected: %d, actual: %d\n" );
  Assert_BigInt_Equals( c, 3, "expected: %d, actual: " );
  printf("\n");

  return 0;
}
