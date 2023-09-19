/* Prints a table of  compound interest */

#include <stdio.h>

/*
  #define: This keyword is used to create a macro in C or C++.
  NUM_RATES: This is the name of the macro being defined.
  ((int)(sizeof(value) / sizeof(value[0]))): This is the value associated with the NUM_RATES macro.
      sizeof(value): This is the size of the value array in bytes.
      sizeof(value[0]): This is the size of the first element of the value array in bytes.
      (int): This is a type cast that converts the result of the division to an int.

  in this case, NUM_RATES is defined as the number of elements in the value array.
*/
#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
  int i, low_rate, num_years, year;
  double value[5];

  printf("Enter interest rate: ");
  scanf("%d", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);

  printf("\nYears");
  for (i = 0; i < NUM_RATES; i++)
  {
    printf("%6d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");

  for (year = 1; year <= num_years; year++)
  {
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++)
    {
      value[i] += (low_rate + i) / 100.0 * value[i];
      printf("%7.2f", value[i]);
    }
    printf("\n");
  }

  return 0;
}