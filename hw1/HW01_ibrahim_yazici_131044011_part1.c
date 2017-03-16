/*-----------------------------------------------------*/
/*CS 102 HW1 Part1 Ibrahim Yazici 131044011            */
/*This program calculates the average grade of students*/
/*-----------------------------------------------------*/

#include <stdio.h>


int main()
{
/*START OF MAIN*/
    /*Variables*/
    int count;
    int grade;
    int totalGrade;
    int average;
    int check;

    /*totalGrade must be 0 before any input*/
    totalGrade = 0;
    /*Initial vlaue of average is 0*/
    average = 0;
    /*Initial number of grades*/
    count = 0;
    /*Unless an illegal integer is entered*/
    check = 0;

    printf("Enter the students grade as an integer (in the range of [0,100]) value. -1 for exit\n");
    /*do-while loop for the conversion and calculation*/
    do
    {
        scanf("%d", &grade);

        if(grade > 100)
        {
            printf("\nGrade can not exteed 100.Now exiting the program\n");
            check = -1;

        }
        else if(grade <= 100 && grade >= 90)
            printf("A\n");
        else if(grade < 90 && grade >= 80)
            printf("B\n");
        else if(grade < 80 && grade >= 70)
            printf("C\n");
        else if(grade < 70 && grade >= 60)
            printf("D\n");
        else if(grade < 60 && grade >=0)
            printf("F\n");
        else if( grade < -1)
        {
            printf("Grade can not be lower than 0.Now exiting the program\n");
            check = -1;
        }

        if(grade != -1 && check != -1 )
        {
            /*Adding new grades to total grade*/
            count++;
            totalGrade = totalGrade + grade;
        }

    }while(grade != -1 && check != -1);


    if(check == -1)
    {
        printf("Due to an invalid grade is entered, operation could not find the average\n");
    }
    else
    {
        /*Finding the average by using a simple arithmetic calculation*/
        /*If count is 0, we will not divide a number by zero*/
        if(count != 0)
            average = totalGrade / count;

        if(average >= 90)
            printf("%d A\n", average);
        else if(average < 90 && average >= 80)
            printf("%d B\n", average);
        else if(average < 80 && average >= 70)
            printf("%d C\n", average);
        else if(average < 70 && average >= 60)
            printf("%d D\n", average);
        else if(average < 60 && average >=0)
            printf("%d F\n", average);
    }

    return 0;
/*END OF MAIN*/
}
