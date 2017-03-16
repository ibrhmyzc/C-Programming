/*Ibrahim Yazici 131044011 Homework2Part2*/
/*Reading polynomials form a text and calculate their result*/

#include <stdio.h>
#include <math.h>

/*Returns the number of lines in the text*/
int howManyLines(FILE *inp);


int main()
{
/* START_OF_MAIN*/
    /*Variables*/
    double min=0;
    double max=0;
    double result=0;
    int degree=0;
    int position=0;
    int counter=0;
    int temp=0;
    int valueOfX=0;
    int i=0;
    int numberOfLine=0;
    int onetime=0;
    int initializeMin=0;
    FILE* inp;

    /*Opening file in read-only mode*/
    inp = fopen("polynomial.txt", "r");
    /*How many lines are in the text.We need to know for the while loop in my program*/
    numberOfLine  = howManyLines(inp);

    while(numberOfLine>0)
    {
        --numberOfLine;
        /*file pointer to the beginning*/
        fseek(inp,0,SEEK_SET);
        for(i = 0; i < position; ++i)
        {   /*this reads integers until the next line. We were not allowed to use malloc*/
            fscanf(inp,"%d",&temp);
        }

        /*degree shows us how many calculations we need to do*/
        fscanf(inp,"%d",&degree);
        counter = degree + 2;

        /*We read until the last integer in a line to find the value of x*/
        for(i = 0; i < counter; ++i)
            fscanf(inp,"%d",&temp);
        valueOfX = temp;

        /*Now we got the value of x and  are going back in the text to do calculations*/
        fseek(inp,0,SEEK_SET);
        /*THIS STEPS RUNS ONLY ONE TIME BECAUSE WE DO NOT NEED IT FOR THE FIRST LINE*/
        for(i = 0; i < position; ++i)
        {
            if(onetime > 0)
            {
                fscanf(inp,"%d",&temp);
            }
        }
        /*Ending one time(upper if statement) */
        onetime++;
        /*reads the degree that we already found to get rid of confusion in next step*/
        fscanf(inp,"%d",&temp);

        /*Here we have the integers written in the line EXCEPT degree and the value of x*/
        for(i = 0; i < counter - 1; ++i)
        {
            fscanf(inp,"%d",&temp);
            result += temp * pow(valueOfX,degree);
            --degree;
        }
        /*Setting positions for the next line*/
        position += counter + 1;
        /*We run this only one time for initializing min and max*/
        if(initializeMin == 0)
        {
            min = result;
            max = result;
            initializeMin++;
        }
        /*Changing max and min by results*/
        if(result > max)
            max = result;
        else if(result < min)
            min = result;

        result = 0;
    }
    /*Printing the value of max and min on the console screen*/
    printf("Max=%.0f,Min=%.0f\n",max,min);

    fclose(inp);
    return 0;
}


int howManyLines(FILE *inp)
{
    int numberOfLine=0;
    char line;

    inp = fopen("polynomial.txt", "r");
    /*Counts the new line until the end of file*/
    while(fscanf(inp,"%c",&line) != EOF)
    {
        if(line == '\n')
            numberOfLine++;
    }
    fclose(inp);
    return numberOfLine + 1;
}
