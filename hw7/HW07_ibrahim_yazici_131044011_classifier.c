/**************************************/
/*131044011 Ibrahim Yazici HW07       */
/*This program reads from text files  */
/*to find if it is a spam email or not*/
/**************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100


int main()
{
/*START_OF_MAIN*/
    /*Variables*/
    FILE *inp;
    char line[MAX], listOfTokens[MAX][MAX], *lineForTable, *lineForToken, check, email[10][5000], search[MAX], *occ;
    int counter=1, tokenValues[MAX], counterForValidTokens=0, counterForEmails=0, freq, i, j, k, nTimes=0, nTypes=0, checkSpam = 0;

    /*Opening the file read only mode*/
    inp = fopen("token.txt","r");

    /*Checking if the file exists*/
    if(inp == NULL)
        printf("File error for token.txt\n");
    else
    {
        printf("----------------------------------------------------------------\n");
        printf("| #|               token                             |Frequency|\n");
        printf("----------------------------------------------------------------\n");
        while(fgets(line, MAX, inp) != NULL)
        {       
            if(strstr(line,"=") == NULL)
                printf("|%2d| *invalid or empty line\n",counter);
            else
            {
                lineForTable = strtok(line, "=");
                freq = atoi(lineForTable);
                
                
                printf("|%2d| %-37s|", counter, lineForTable);
                
  
                /*Getting the frequency*/
                lineForTable = strtok(NULL, " ");
                freq = atoi(lineForTable);
                if(freq == 0)
                {
                    check = lineForTable[0];
                    /*Checking if it is a valid number*/
                    if(check >= '0' && check <= '9')
                    {
                        printf("%20d|\n",freq);
                        
                    }     
                    else
                        printf("*invalid frequency  |\n");  
                }
                else
                {
                    printf("%20d|\n",freq);
                     /*Creating a list of tokens to be used later in the homework*/
                    lineForToken = strtok(line,"=");
                    for(i = 0; line[i] != '='; ++i)
                    {
                        listOfTokens[counterForValidTokens][i] = lineForToken[i];
                        tokenValues[counterForValidTokens] = freq;
                    }
                    counterForValidTokens++;
                }
                
            }
            /*Increasing the counter*/
            counter++;   
        }
        printf("----------------------------------------------------------------\n\n\n");
    }
    fclose(inp);
    
    /*Now openning emails.txt*/
    
    inp = fopen("emails.txt", "r");
    
    /*Checking the email*/
    if(inp == NULL)
        printf("File error for emails.txt");
    {
        
        fscanf(inp,"%s", line);
        strcat(email[counterForEmails],line);
        strcat(email[counterForEmails]," ");
        
        while(fscanf(inp,"%s", line) != EOF)
        {
            if(strcmp(line,"</email>") != 0 )
            {
                if(strcmp(line,"<email>") == 0 )
                {
                    if(strstr(email[counterForEmails], "subject") != NULL)
                    {
                        strcat(email[counterForEmails],line);
                        counterForEmails++;
                    }
                    
                }
                strcat(email[counterForEmails],line);
                strcat(email[counterForEmails]," ");
            } 
            else 
            {      
                strcat(email[counterForEmails],line);
                counterForEmails++;
            }
        }
              
    }

              
    printf("Valid emails are shown below:\n\n");    
    /*Checking emails for spam*/
    for(i = 0; i < counterForEmails; ++i)
    {
        
        if(strstr(email[i], "<email>") != NULL && strstr(email[i], "<body>") != NULL
               && strstr(email[i], "</email>") != NULL   && strstr(email[i], "</body>") != NULL
                  && strstr(email[i], "<subject>") != NULL  && strstr(email[i], "</subject>") != NULL
                     )
        {    
            printf("%s\n\n",email[i]);  
            printf(">Checking for spam for valid tokens<\n\n");
            for(j = 0; j < counterForValidTokens; ++j)
            {
                
                strcpy(search, listOfTokens[j]);
                /*I am getting rid of the empty space at the end of the word*/
                k = strlen(search);
                search[k-1] = '\0';
                
                nTimes = 0;
                if(strstr(email[i], search) != NULL)
                {
                    /*Here we find how many times it is found in the email*/
                    occ = email[i];
                    while( (occ = strstr(occ, search)) )
                    {
                        nTimes++;
                        occ++;
                    }
                    /*For bonus part*/
                    printf("token    <%s>   is found %d times\n",search, nTimes);
                    nTypes++;
                   
                }
                if(tokenValues[j] <= nTimes)
                {
                    /*printf("\t%s  is found %d times\n",search, nTimes);*/
                    checkSpam = 1;
                }
                if(j == counterForValidTokens - 1)
                {
                     if(checkSpam == 1 || nTypes >=3)
                        printf("\n*** THIS EMAIL IS A SPAM***\n");
                    else
                        printf("\n*** THIS EMAIL IS NOT A SPAM***\n"); 
                    printf("\n*For the BONUS part of the homework: ");
                    printf("%d types of tokens are found\n",nTypes);
                    printf("\n************************************************************\n");
                    nTypes = 0;
                    checkSpam = 0;
                }
            }
        }
       
    }
    

    return 0;
/*END_OF_MAIN*/
}

