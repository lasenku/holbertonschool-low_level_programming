#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int operation =0;
    double num1=0.0;
    double num2=0.0;
    double result=0.0;
    do {

    puts("Simple Calculator\n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
    printf("Choice: ");
    scanf("%d", &operation);

    if(operation==0){
    break;
    }

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);


     switch(operation){
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if(num2 == 0){
                printf("You can't divide by zero!\n");
            }
            else{
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid entry\n");
    }
    printf("result: %.4f", result);
   
} while (operation!=0);
puts("Bye!");
return (0);
}


/*******************************************************************************
*
* Program: Switch Menu
*
* Description: Example of creating a menu using a switch statement in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=eStBZCSL-gQ
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  double balance = 0, amount = 0;
  int choice = 0;

  // repeatedly present an "ATM Machine" menu to the user
  while (true)
  {
    // present the menu, accept the user's choice
    printf("1) Deposit\n");
    printf("2) Withdraw\n");
    printf("3) Print Balance\n");
    printf("4) Print Balance And Quit\n");
    printf("0) Quit\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    // decide what action to carry out based on the user's choice
    switch (choice)
    {
      // deposit money
      case 1:
        printf("Enter Amount: ");
        scanf("%lf", &amount);
        balance += amount;
        break;

      // withdraw money
      case 2:
        printf("Enter Amount: ");
        scanf("%lf", &amount);
        balance -= amount;
        break;

      // print balance
      case 3:
        printf("%.2f\n", balance);
        break;

      // print balance AND quit by using fall-through logic... the lack of a
      // break at the end of this case means that execution will "fall through"
      // to the statements of the next case... where we're going to quit anyways
      case 4:
        printf("%.2f\n", balance);

      // quit
      case 0:
        exit(0);
    }

  }

  return (0);
}
