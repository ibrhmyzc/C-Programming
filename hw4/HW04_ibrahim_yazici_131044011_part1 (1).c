/********************************************/
/*Checking moves fora sudoku game from file */
/*Ibrahim Yazici 131044011 hw4 part1        */
/********************************************/

#include <stdio.h>

#define TABLE_SIZE 9

/*this function will initialize the sudoku array to zero*/
void init(int S[][9]);

/*checking it is a legal move*/
int is_legal(int S[][9], int r, int c, int x);

/*if the move valid */
void place(int S[][9], int r, int c, int x);

/*reads the array from file and call is_legal function*/
void read_from_file(FILE *file_pointer, int S[][9]);

/*writes the array in the text file*/
void write_to_the_file(FILE *file_pointer, int S[][9]);

/*Prints sudoku table*/
void sudokuPrint(int S[][9]);

int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    int sudoku[TABLE_SIZE][TABLE_SIZE];
    FILE *input, *output;

    input = fopen("sudoku.txt","r");
    output = fopen("sudokuWritten.txt","w");

    init(sudoku);
    read_from_file(input, sudoku);
    write_to_the_file(output, sudoku);

    sudokuPrint(sudoku);

    fclose(input);
    fclose(output);

    return 0;
/*END_OF_MAIN*/
}

void init(int S[][9])
{
    int i, j;

    for(i = 0; i < TABLE_SIZE; ++i)
        for(j = 0; j < TABLE_SIZE; ++j)
            S[i][j] = 0;
}

void read_from_file(FILE *file_pointer, int S[][9])
{
    int arrayForValidation[TABLE_SIZE][TABLE_SIZE];
    int i, j;

    for(i = 0; i < TABLE_SIZE; i++)
        for(j = 0; j < TABLE_SIZE; j++)
        {
            fscanf(file_pointer,"%d",&arrayForValidation[i][j]);
            if(is_legal(S,i,j,arrayForValidation[i][j]) == 0)
            {
                i =TABLE_SIZE;
                j = TABLE_SIZE;
                printf("Input error\n");
            }
            else
            {

            }
        }

}

void write_to_the_file(FILE *file_pointer, int S[][9])
{
    int i, j;
    for(i = 0; i < TABLE_SIZE; ++i)
        for(j = 0; j < TABLE_SIZE; ++j)
        {
            fprintf(file_pointer,"%d ",S[i][j]);
            if(j == TABLE_SIZE - 1)
                fprintf(file_pointer,"\n");
        }

}

int is_legal(int S[][9], int r, int c, int x)
{
    int i,j;

    if( S[r][c] != 0)
    {

    }
    if( x < 0  || x > 9)
    {
        printf("Number must be between 1 and 9\n");
        return 0;
    }


    for(i = 0; i < TABLE_SIZE; ++i)
        if(S[r][i] == x && x != 0)
        {
             printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
             printf("Same number is found in the same line\n");
             return 0;
        }


    for(i = 0; i < TABLE_SIZE; ++i)
        if(S[i][c] == x && x != 0)
        {
            printf("Same number is found in the same column\n");
            return 0;
        }

    if(r >= 0 && r <=2 && c >=0 && c <=2)
    {
        for(i = 0; i < 3; ++i)
            for(j = 0; j < 3; ++j)
                if(S[i][j] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >= 0 && r <=2 && c >=3 && c <=5)
    {
        for(i = 0; i < 3; ++i)
            for(j = 3; j < 6; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >= 0 && r <=2 && c >=6 && c <=8)
    {
        for(i = 0; i < 3; ++i)
            for(j = 6; j < 9; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
     else if(r >= 3 && r <=5 && c >=0 && c <=2)
    {
        for(i = 3; i < 6; ++i)
            for(j = 0; j < 3; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >= 3 && r <=5 && c >=3 && c <=5)
    {
        for(i = 3; i < 6; ++i)
            for(j = 3; j < 6; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >=3  && r <=5 && c >=6 && c <=8)
    {
        for(i = 3; i <6; ++i)
            for(j = 6; j < 9; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
     else if(r >=6 && r <8 && c >=0 && c <=2)
    {
        for(i = 6; i < 9; ++i)
            for(j = 0; j < 3; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >=6 && r <=8 && c >=3 && c <=5)
    {
        for(i = 6; i < 9; ++i)
            for(j = 3; j < 6; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    else if(r >=6 && r <=8 && c >=6 && c <=8)
    {
        for(i = 6; i < 9; ++i)
            for(j = 6; j < 9; ++j)
                if(S[r][i] == x && x != 0)
                {
                     printf("(%d,%d)= %d = %d\n",r,i,S[r][i],x);
                     printf("Same number is found in the same square box\n");
                     return 0;
                }
    }
    place(S, r, c, x);

    return 1;
}

void sudokuPrint(int S[][9])
{
    int i, j;
    printf("\tSUDOKU \n\n");
    printf("-----------------------\n");
    for(i = 0; i < TABLE_SIZE; ++i)
    {
        printf("| ");
        for(j = 0; j < TABLE_SIZE; ++j)
        {
            printf("%d ",S[i][j]);
            if(j != TABLE_SIZE - 1 && (j+1)%3 == 0)
                printf("|");
            if(j == TABLE_SIZE - 1)
            {
                printf("|\n");
            }
        }
        if((i+1)%3 == 0)
            printf("-----------------------\n");

    }

}

void place(int S[][9], int r, int c, int x)
{
    S[r][c] = x;
}




