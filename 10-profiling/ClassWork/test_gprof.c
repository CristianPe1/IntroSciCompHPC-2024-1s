#include<stdio.h>

// Declaration of functions used in this program.
void new_func1(void); // Prototype for new_func1
void func1(void); // Prototype for func1
static void func2(void); // Prototype for func2, static indicates it's only visible within this file
void new_func1(void); // Duplicate prototype for new_func1 (redundant)

// Main function: Entry point of the program.
int main(void)
{
  printf("\n Inside main()\n"); // Print a message indicating execution is inside main()
  int i = 0;

  // Loop to simulate a delay or a time-consuming operation.
  for(;i<0xffffff;i++);
  func1(); // Call func1 which performs its own operations and calls new_func1
  func2(); // Call func2 which is a static function performing its operations

  return 0; // Return 0 to indicate successful execution
}

// Duplicate declaration of new_func1 (unnecessary and should be removed)

// Implementation of func1: prints a message and simulates a time-consuming operation.
void func1(void)
{
  printf("\n Inside func1 \n"); // Print a message indicating execution is inside func1
  int i = 0;

  // Loop to simulate a delay or a time-consuming operation, longer than in main.
  for(;i<0xffffffff;i++);
  new_func1(); // Call new_func1 which performs its own operations

  return;
}

// Implementation of func2: a static function that prints a message and simulates a time-consuming operation.
static void func2(void)
{
  printf("\n Inside func2 \n"); // Print a message indicating execution is inside func2
  int i = 0;

  // Loop to simulate a delay or a time-consuming operation, specific value for the delay.
  for(;i<0xffffffaa;i++);
  return;
}

// Implementation of new_func1: prints a message and simulates a time-consuming operation.
void new_func1(void)
{
  printf("\n Inside new_func1()\n"); // Print a message indicating execution is inside new_func1
  int i = 0;

  // Loop to simulate a delay or a time-consuming operation, specific value for the delay.
  for(;i<0xffffffee;i++);

  return;
}
