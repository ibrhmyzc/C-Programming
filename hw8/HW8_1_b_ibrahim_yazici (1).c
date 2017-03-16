/*******************************************************************/
/*Ibrahim Yazici 131044011   HW08 1b                               */
/*This program calculates a function recursively                   */
/*******************************************************************/
#include <stdio.h>

/*The function we are required to implement in our homework*/
double f(double x, double y);


int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    int x, y;
    double result;
    /*Getting the input from the user*/
    printf("Please enter the value of x:");
    scanf("%d",&x);

    printf("Please enter the value of y:");
    scanf("%d",&y);

    /*Storing the result*/
    result = f(x, y);
    /*Printing the result*/
    printf("f(x,y) = %.2f\n", result);

    return 0;
/*END_OF_MAIN*/
}

double f(double x, double y)
{
    double result=0;

    /*Simple case to end the recursive function*/
    if(x <=0 || y <=0)
        return 0;
    else
    {
        /*Recursive part*/
        result = result + f(x-1, y) + f(x, y-1) + x + y;
    }
    return result;
}
