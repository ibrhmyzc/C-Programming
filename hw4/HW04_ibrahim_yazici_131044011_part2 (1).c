/********************************************/
/*Searchs for a word in a given puzzle	    */
/*Ibrahim Yazici 131044011 hw4 part1        */
/********************************************/
#include <stdio.h>

#define Max_N 8
#define Max_R 3

/*trying to find the word*/
int find (char Puzzle[][Max_N],int row , int column ,char orientation, char *word);
/*prints the array to the screen*/
void printPuzzle(char Puzzle[][Max_N], int rowSize , int columnSize);
/*for orientation r*/
int controlRTL(char Puzzle[][Max_N], int row, int column,  char *word);
/*for orientation l*/
int controlLTR(char Puzzle[][Max_N], int row, int column, char *word);
/*for orientation t*/
int controlTTB(char Puzzle[][Max_N], int row, int column, char *word);
/*for orientation b*/
int controlBTT(char Puzzle[][Max_N], int row, int column, char *word);

int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    char myPuzzle[][Max_N]={
        {'I','N','E','U','E','L','G','C' },
        {'T','L','E','M','O','N','E','O'},
        {'S','C','H','E','R','R','Y','T'}};

    char string[Max_N];
    char orientation;

    int row, column, control, exitValue = 0;


    printPuzzle(myPuzzle, Max_R, Max_N);


    while(exitValue != -1)
    {
        printf("\nEnter the word you wish to find in >uppercase< :");
        scanf(" %s", string);

        printf("Enter the orientation:");
        scanf(" %c", &orientation);

        printf("Enter the words start location as in an array. It starts from the location (0,0)\n");
        printf("For example 1 4 or 2 2 or 0 1 or 0 3 etc.. :");
        scanf("%d %d",&row, &column);

        if(row>=0 && row<Max_R && column>=0 && column<Max_N)
            control = find(myPuzzle, row, column, orientation, string);
        else
        {
            printf("invalid row and column\n");
            exitValue = -1;
        }

        if(control == 1 && exitValue != -1)
            printf("%s is found! \n",string);
        else
           printf("%s is  NOT found! \n",string);

        printf("Press -1 to exit or any NUMBER to continue \n");
            scanf("%d", &exitValue);
    }

    return 0;
/*END_OF_MAIN*/
}
int find (char Puzzle[][Max_N],int row , int column ,char orientation, char *word)
{
    int controlValue = -1;

    if(orientation == 'R' || orientation == 'r')
        controlValue = controlRTL(Puzzle, row, column, word);
    else if(orientation == 'l' || orientation == 'L')
        controlValue = controlLTR(Puzzle, row, column, word);
    else if(orientation == 'T' || orientation == 't')
        controlValue = controlTTB(Puzzle, row, column, word);
    else if(orientation == 'b' || orientation == 'B')
        controlValue = controlBTT(Puzzle, row, column, word);

    return controlValue;

}
void printPuzzle(char Puzzle[][Max_N],int rowSize , int columnSize)
{
     int i,j;

     printf("  ");
     for(i = 0; i < columnSize; ++i)
     {
         printf("%d ",i);
     }
     printf("\n");
     printf("  ");
     for(i = 0; i < columnSize; ++i)
     {
         printf("--");
     }
     printf("\n");
     for(i = 0; i < rowSize; ++i)
     {
        printf("%d|",i);
        for(j = 0; j < columnSize; ++j)
        {
            printf("%c ",Puzzle[i][j]);
        }
        printf("\n");
     }
}
int controlBTT(char Puzzle[][Max_N], int row, int column, char* word)
{
    int i, j;

    for(i=0; word[i] != '\0';++i);

    if(row-i < -1)
    {
        printf("Words you enter does not fit in the puzzle\n");
        return 0;
    }
    else
    {
        for(j = 0; j < i; ++j)
            if(Puzzle[row-j][column] != word[j])
                return 0;
    }
    return 1;
}
int controlTTB(char Puzzle[][Max_N], int row, int column, char* word)
{
    int i,j;

    for(i=0; word[i] != '\0';++i);

    if(row+i < -1)
    {
        printf("Words you enter does not fit in the puzzle\n");
        return 0;
    }
    else
    {
        for(j = 0; j < i; ++j)
            if(Puzzle[row+j][column] != word[j])
                return 0;
    }
    return 1;
}
int controlRTL(char Puzzle[][Max_N], int row, int column, char* word)
{
    int i,j;

    for(i=0; word[i] != '\0';++i);

    if(column+i > Max_N)
    {
       printf("Words you enter does not fit in the puzzle\n");
        return 0;
    }
    else
    {
        for(j = 0; j < i; ++j)
            if(Puzzle[row][column+j] != word[j])
                return 0;
    }
    return 1;
}
int controlLTR(char Puzzle[][Max_N], int row, int column, char* word)
{
    int i,j;

    for(i=0; word[i] != '\0';++i);

    if(column-i < -1)
    {
        printf("Words you enter does not fit in the puzzle\n");
        return 0;
    }
    else
    {
        for(j = 0; j < i; ++j)
            if(Puzzle[row][column-j] != word[j])
                return 0;
    }
    return 1;
}

