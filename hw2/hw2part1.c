/*Ibrahim Yazici 131044011 homework2part1*/
/*This program draws wished shapes on the  console screen*/

#include <stdio.h>

/* draws equilateral triangle */
void Draw_Triangle(int starting_point, int length, int layer_type);
/* draws a rectangle*/
void Draw_Rectagle(int starting_point, int length, int width, int layer_type);
 /*draws a circle*/
void Draw_Circle(int center, int radius, int layer_type);

int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    char choice;
    int starting_point;
    int length;
    int width;
    int radius;
    int center;
    int layer_type;

    /*Asking users for which shape they desire to see on the console screen*/
    printf("Please enter which shape you wish to draw on the screen T for triangle, R for rectangle and C for circle \n");
    scanf("%c", &choice);

    /*All of the choices are case-sensitive-free by manual*/
    if(choice == 'T' || choice == 't')
    {
        printf("Please enter the starting point:");
        scanf(" %d", &starting_point);

        printf("Please enter the length:");
        scanf(" %d", &length);

        printf("Please enter the layer_type(1 or 2):");
        scanf(" %d", &layer_type);

        Draw_Triangle(starting_point, length, layer_type);

    }
    else if(choice == 'R' || choice == 'r')
    {
        printf("Please enter the starting point:");
        scanf(" %d", &starting_point);

        printf("Please enter the length:");
        scanf(" %d", &length);

        printf("Please enter the width:");
        scanf(" %d", &width);

        printf("Please enter the layer_type(1 or 2):");
        scanf(" %d", &layer_type);

        Draw_Rectagle(starting_point, length, width, layer_type);

    }
    else if(choice == 'C' || choice == 'c')
    {
        printf("Please enter the center:");
        scanf(" %d", &center);

        printf("Please enter the radius:");
        scanf(" %d", &radius);

        printf("Please enter the layer_type(1 or 2):");
        scanf(" %d", &layer_type);

        if(center < radius)
            printf("Center can not be smaller than radius...\n");
        else
            Draw_Circle(center, radius, layer_type);
    }
    else
    {
        printf("Unknown input... \n");
    }
    return 0;

/*END_OF_MAIN*/
}
void Draw_Circle(int center, int radius, int layer_type)
{
    /*Variables*/
    int i, j, temp, space;

    temp = radius / 2 + 1;
    space = radius - 1;

    for(i = 0; i < radius * 2 + 1; ++i)
    {
        for(j = 0; j < center - radius; ++j)
            printf(" ");

        if(i == 0 || i == radius * 2)
        {
            for(j = 0; j < radius; ++j)
                printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");
        }
        if( i == radius)
        {
            for(j = 0 ; j < layer_type; ++j)
                printf("*");
            if(layer_type == 1)
                    for(j = 0; j < radius * 2 - 1; ++j)
                        printf(" ");
            else
                for(j = 0; j < radius * 2 - 2; ++j)
                    printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");

                temp++;
                space -= 2;
        }

        if(i < 3 && i > 0)
        {
            for(j = 0; j < temp - 1; ++j)
                printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");
            if(layer_type == 1)
                for(j = 0; j < space + 1; ++j)
                    printf(" ");
            else
                for(j = 0; j < space; ++j)
                    printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");

            temp--;
            space += 2;
        }

        if(i > radius * 2 - 3 && i < radius * 2)
        {
            for(j = 0; j < temp - 1; ++j)
                printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");
            if(layer_type == 1)
                for(j = 0; j < space + 1; ++j)
                    printf(" ");
            else
                for(j = 0; j < space; ++j)
                    printf(" ");
            for(j = 0 ; j < layer_type; ++j)
                printf("*");

            temp++;
            space -= 2;
        }
        printf("\n");
    }
}

void Draw_Rectagle(int starting_point, int lenght, int width, int layer_type)
{
    /*Variables*/
    int i, j;

    for(i = 0; i < lenght; ++i)
    {
        for(j = 0; j < starting_point; ++j)
            printf(" ");

        if(i < layer_type || i >= lenght - layer_type)
            for(j = 0; j < width; ++j)
                printf("*");
        else
        {
            for(j = 0; j < width; ++j)
            {
                 if( j < layer_type)
                    printf("*");
                 else if (j > width - layer_type - 1)
                    printf("*");
                 else
                    printf(" ");
            }
        }
        printf("\n");
    }
}
void Draw_Triangle(int starting_point, int lenght, int layer_type)
{
    /*Variables*/
    int i, j;
    int counter;
    int space;

    space = 1;
    counter = lenght - 1;

    if(layer_type == 1)
    {
        for(i = 0; i < lenght; ++i)
        {
            for(j = 0; j < starting_point; ++j)
                printf(" ");
            if(i == 0)
            {
                for(j = 0; j < counter; ++j)
                    printf(" ");
                printf("*");
                counter--;
            }
            else if(i == lenght - 1 )
            {
                for(j = 0; j < lenght * 2 - 1; ++j)
                    printf("*");
            }
            else
            {
                for(j = 0; j < counter; ++j)
                    printf(" ");
                printf("*");
                counter--;
                for(j = 0; j < space; ++j)
                    printf(" ");
                printf("*");
                space += 2;
            }
            printf("\n");
        }
    }
    else
    {
        for(i = 0; i < lenght; ++i)
        {
            for(j = 0; j < starting_point; ++j)
                printf(" ");
            if(i == 0)
            {
                for(j = 0; j < counter; ++j)
                    printf(" ");
                printf("**");
                counter--;
            }
            else if(i == lenght - 2)
            {
                printf(" ");
                for(j = 0; j < lenght * 2 - 1; ++j)
                    printf("*");
            }
            else if(i == lenght - 1)
            {
                for(j = 0; j < lenght * 2 + 1; ++j)
                    printf("*");
            }
            else
            {
                for(j = 0; j < counter; ++j)
                    printf(" ");
                printf("**");
                counter--;
                for(j = 0; j < space; ++j)
                    printf(" ");
                printf("**");
                space += 2;
            }
            printf("\n");
        }
    }
}
