/*-----------------------------------------------------*/
/*CS 102 HW1 Part2 Ibrahim Yazici 131044011            */
/*This program do calculations by input order          */
/*-----------------------------------------------------*/

#include <stdio.h>


int main()
{
/*START OF MAIN*/
    /*Variables*/
    int value;
    int result;
    char operation;

    /*Initial result mist be 0 before any calculation*/
    result = 0;


    printf("All numbers must be integer.This program follows the input order. a+b*c= will be calculated as (a+b)*c\n");
    printf("= after legal inputs will show the result\n");

    /*First value*/
    scanf("%d", &value);
    result = result + value;

    do
    {
        /*Getting the operation*/
        scanf(" %c", &operation);

        /*Depends on the operation*/
        if(operation == '+')
        {
            scanf("%d", &value);
            result = result + value;
        }
        else if(operation == '-')
        {
            scanf("%d", &value);
            result = result - value;
        }
        else if(operation == '*')
        {
            scanf("%d", &value);
            result = result * value;
        }
        else if(operation == '/')
        {
            scanf("%d", &value);
            result = result / value;
        }


    }while(operation != '=');

    printf("%d\n", result);
    return 0;
/*END OF MAIN*/
}
