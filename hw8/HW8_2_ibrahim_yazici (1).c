/*******************************************************************/
/*Ibrahim Yazici 131044011   HW08 2                                */
/*This program draws the way out of a maze	                   */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/*Finds the square root of an integer*/
int findSquareRoot(int n);
/*Print the maze on the screen*/
void printMaze(char **maze, int size);
/*recursive function to find the path out of the maze*/
void findThePath(char **maze, int size, int row, int column);
/*make 1s * */
void change1s(char **maze, int size);

int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    int size=0, i, row, column;
    char **maze, temp;
    FILE *inp;

    inp = fopen("maze.txt", "r");

    if(inp == NULL)
    {
        printf("File error\n");
    }
    else
    {
        /*Here we find the size*/
        while(fscanf(inp, "%c", &temp) != EOF)
        {
            if(temp == '1' || temp == '0')
            size++;
        }
            

        fclose(inp);
        /*size of a line*/
        size = findSquareRoot(size);

        /*Now we create our array to hold the maze*/
        maze = (char**)malloc(sizeof(char*) * size);
        for(i = 0; i < size; ++i)
            maze[i] = (char*)malloc(sizeof(char) * size);

        /*Now storing the maze from text file to the array*/
        inp = fopen("maze.txt", "r");
        row = 0;
        column = 0;
        while(fscanf(inp, "%c", &temp) != EOF)
        {      
            if(temp == '1' || temp == '0')
            {
                if(column == size)
                {
                    column = 0;
                    row++;
                    if(row >= size)
                    {
                        /*Do nothing*/
                        printf(" ");
                    }
                    else
                        maze[row][column] = temp;
                }
                else
                    maze[row][column] = temp;
                column++;
            }
            
        }

        /*Printing the array*/
        printf("This is our maze!\n\n");
        printMaze(maze, size);
        
        /*First I changed all 1s to *s*/
        /*change1s(maze, size);
        printMaze(maze, size);*/
        

        for(i = 0; i < MAX; ++i)
            findThePath(maze, size, 0, 0);

        change1s(maze, size);
        printf("\nThis is the possible way out if the * are connected\n\n");
        printMaze(maze, size);
        
    }
    /*Closing the file*/
    fclose(inp);
    return 0;
/*END_OF_MAIN*/
}

void change1s(char **maze, int size)
{
    int i, j;
    for(i = 0; i < size; ++i)
        {
            for(j = 0; j < size; ++j)
            {
                if(maze[i][j] == '1')
                    maze[i][j] = '*';

            }
           
        }
}

void findThePath(char **maze, int size, int row, int column)
{
    if(column == size)
    {
        row++;
        column = 0;
    }
    if(row == size || column == size)
        printf(" ");
    else
    {
        if(maze[row][column] == '1')
        {
            if(row == 0 && column == 0)
            {
                if(maze[row+1][column] != '1' && maze[row][column+1] != '1')
                    maze[row][column] = '0';
            }
            else if(row == 0 && column == size-1)
            {
                if(maze[row+1][column] != '1' && maze[row][column-1] != '1')
                    maze[row][column] = '0';
            }
            else if(row == size -1 && column == 0)
            {
                if(maze[row-1][column] != '1' || maze[row][column+1] != '1')
                    maze[row][column] = '0';
            }
            else if(row == size-1 && column == size-1)
            {
                if(maze[row-1][column] != '1' && maze[row][column-1] != '1')
                    maze[row][column] = '0';
            }
            else if(row > 0 && row < size-1 && column > 0 && column < size-1)
            {
                if( maze[row][column+1] != '1' && maze[row+1][column] != '1')
                    maze[row][column] = '0';    
                
                if( maze[row][column+1] != '1' && maze[row-1][column] != '1'
                        && maze[row][column-1] != '1')
                    maze[row][column] = '0';
                if( maze[row][column+1] == '0' && maze[row-1][column] == '0'
                        && maze[row][column-1] == '0')
                    maze[row][column] = '0';
                if( maze[row][column-1] == '0' && maze[row+1][column] == '0'
                        && maze[row-1][column] == '0')
                    maze[row][column] = '0';
            }
            else if(column == size-1)
            {
                if( maze[row][column-1] != '1' && maze[row+1][column] != '1')
                    maze[row][column] = '0';   
                if( maze[row][column-1] == '0' && maze[row-1][column] == '0')
                    maze[row][column] = '0';   
            }
            else if(column == 0)
            {
                if( maze[row][column+1] != '1' && maze[row+1][column] != '1')
                    maze[row][column] = '0';  
                if(row < size-1)
                {
                    if( maze[row+1][column] == '0' && maze[row-1][column] == '0')
                        maze[row][column] = '0';  
                }
                       
            }
            else if(row == 0 && column != size-1)
            {
                if( maze[row][column+1] != '1' && maze[row+1][column] != '1' && maze[row][column-1] != '1')
                    maze[row][column] = '0';
                
                if( maze[row][column+1] != '1' || maze[row+1][column+1] != '1')
                    maze[row][column] = '0';
            }
            
        
            /*Recursive part*/
            findThePath(maze, size, row, column+1);
        }
        else
        {
            /*Recursive part*/
            findThePath(maze, size, row, column+1);
        }
    }
}

void printMaze(char **maze, int size)
{
    int i, j;
    printf("\n");
    for(i = 0; i < size; ++i)
        {
            for(j = 0; j < size; ++j)
            {
                printf("%c ",maze[i][j]);

            }
            printf("\n");
        }
    printf("\n\n");
}

int findSquareRoot(int n)
{
    int i, result;
    for(i = 0; i <= n; ++i)
    {
        if(i*i == n)
            result = i;
    }
    return result;
}
