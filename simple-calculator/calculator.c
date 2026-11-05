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
    printf("A: ",num1);
    printf("B: ",num2);

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
            printf("Invalid choice\n");
    }
    printf("result: %.4f", result);
   
} while (operation!=0);
puts("Bye!");
return (0);
}
