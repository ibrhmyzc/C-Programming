/********************************************/
/*Checking and parsing a text		    */
/*Ibrahim Yazici 131044011 hw6 	            */
/********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    FILE *inp;
    char line[MAX], *lineForTable;
    int counter=1, freq, i;

    /*Opening the file read only mode*/
    inp = fopen("token.txt","r");

    /*Checking if the file exists*/
    if(inp == NULL)
        printf("File error for token.txt\n");
    else
    {
        printf("------------------------------------------------------\n");
        printf("| #|               token                   |Frequency|\n");
        printf("------------------------------------------------------\n");
        while(fgets(line,100,inp) != NULL)
        {
            if(strstr(line,"=") == NULL)
                printf("invalid -> %s",line);
            else
            {
                lineForTable = strtok(line, "=");
                freq = atoi(lineForTable);
                printf("|%2d| %-37s|", counter, lineForTable);

                /*Getting the frequency*/
                lineForTable = strtok(NULL, " ");
                freq = atoi(lineForTable);
                printf("%10d|\n",freq);


            }
            /*Increasing the counter*/
            counter++;
        }
        printf("------------------------------------------------------\n\n\n");
    }
    fclose(inp);


    /*Now we do the same thing for token*/
    inp = fopen("emails.txt", "r");
    counter = 1;

    if(inp == NULL)
        printf("File error for emails.txt\n");
    else
    {
        while(fscanf(inp, "%s", line) != EOF)
        {
            if(strcmp(line, "<Body>") == 0 || strcmp(line, "</Body>") == 0
               || strcmp(line, "<email>") == 0 || strcmp(line, "</email>") == 0)
            {
                printf(" ");
            }
            else
            {
                if(strstr(line, "<Subject>") != NULL)
                {
                    if(strcmp(line,"<Subject>") == 0)
                    {
                        printf("\n\n*%d. Email Subject: ", counter);
                        fscanf(inp, "%s", line);
                        while(strstr(line, "</Subject>") == NULL)
                        {
                            if(strcmp(line, "<email>") != 0 && strcmp(line, "<Body>") != 0)
                                printf("%s ",line);
                            fscanf(inp, "%s", line);
                        }
                        printf("\n\n*%d. Email Body: ", counter);
                        printf("\n\t");
                        counter++;
                        fscanf(inp, "%s", line);
                    }
                    else if(strstr(line, "</Subject>") == NULL)
                    {
                        printf("\n\n*%d. Email Subject: ", counter);
                        while(strstr(line, "</Subject>") == NULL)
                        {
                            for(i = 9; i < strlen(line); ++i)
                            {
                                printf("%c", line[i]);
                            }
                            printf(" ");
                            fscanf(inp, "%s", line);

                        }
                        for(i = 0; i < strlen(line) - 10; ++i)
                        {
                            printf("%c", line[i]);
                        }

                        printf("\n\n*%d. Email Body: ", counter);
                        printf("\n\t");
                        counter++;
                        fscanf(inp, "%s", line);
                        }
                    printf("\n");
                }
                if(strcmp(line, "<email>") != 0 && strcmp(line, "<Body>") != 0 && strcmp(line, "</email>") && strcmp(line, "</Body>"))
                    printf("%s ", line);
            }


        }

    }

    return 0;
/*END_OF_MAIN*/
}
