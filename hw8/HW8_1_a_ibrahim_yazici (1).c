/*******************************************************************/
/*Ibrahim Yazici 131044011   HW08 1a                               */
/*This program shows the binary representation of an integer number*/
/*******************************************************************/
#include <stdio.h>
#include <string.h>


#define SIZE 500

void intToBinary(int n, char binaryRep[]);
void reverseAString(char reverseIt[]);
int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    char binaryRep[SIZE];
    int number;

    /*Getting number from the user*/
    printf("Enter the integer number: ");
    scanf("%d", &number);

    /*Checking its validity*/
    if(number < 0)
        printf("Number must be a positive integer.Because binary representation of negative numbers changes with so many system\n");
    else
    {
        /*Calling our recursive function here*/
        intToBinary(number, binaryRep);
        /*Now we need to reverse the string binaryrep*/
        reverseAString(binaryRep);
        printf("The binary representation of %d is %s.\n",number, binaryRep);
    }

    return 0;
/*START_OF_MAIN*/
}

void intToBinary(int n, char binaryRep[])
{
    int temp;
    /*Simple case*/
    if(n == 0)
        sprintf(binaryRep,"%d",n);
    /*Out other simple case*/
    else if(n == 1)
        sprintf(binaryRep,"%d",n);
    /*Recursive step*/
    else
    {
        temp = n % 2;
        sprintf(binaryRep,"%d",temp);
        intToBinary(n/2,&binaryRep[1]);
    }
}

void reverseAString(char reverseIt[])
{
    int i=0, size;
    char temp;
    /*size-1 because we use an array here*/
    size = strlen(reverseIt) - 1;
    while(i < size)
    {
        /*Swapping here*/
        temp = reverseIt[i];
        reverseIt[i] = reverseIt[size];
        reverseIt[size] = temp;
        /*Increments to end while loop*/
        i++;
        size--;
    }
}
