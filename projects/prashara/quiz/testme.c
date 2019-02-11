#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	//The range is 32 to 126 where 32(space) and 126(~)
	char random = (rand() % 95) + 32;   // generate a random integer and assign it to char will cast integer to it's ASCII char value.
	return random;
}

char *inputString()
{
	static char newStr[6];		//This will store the string.
	int i = 0;

	//The range is 101(e) to 116(t)
	while (i < 5)                         // Since we want to last char to be null terminator. So we loop from 0 to 4.
	{
		newStr[i] = (rand() % 16) + 101; // newStr will be a string with letters from e to t.
		i++;
	}

	return newStr;
}


void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
