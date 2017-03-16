#include "DoubleList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*head pointer*/
node *headp = NULL;
/*tail pointer*/
node *tailp = NULL;

void insert_node(char *current, int volts, int position)
{
    node *newp, *countp, *temp, *currentp;
    int i, counter = 1;
    newp = (node*)malloc(sizeof(node));

    for(countp = headp; countp != NULL; countp = countp->nextp)
    {
        counter++;
    }

    if(position == 1)
    {
        if(headp == NULL)
        {
            newp->prevp = headp;
            newp->nextp = NULL;
            strcpy(newp->current,current);
            newp->volts = volts;
            headp = newp;
            tailp = newp;
        }
        else
        {
            temp = (node*)malloc(sizeof(node));
            /*Temp is what head points*/
            temp = headp;
            temp->prevp = newp;
            /*Copying elements*/
            strcpy(newp->current,current);
            newp->volts = volts;
            /*Setting the new node's next to null*/
            newp->nextp = headp;
            headp = newp;
            /*Setting the new node's prev to null*/
            newp->prevp = headp;
            /*Previous node's next points the last added node*/

        }
    }
    else if(position > counter || position <= 0)
    {
        printf("\nInvalid position\n");
    }
    else if(headp != NULL)
    {
        currentp = (node*)malloc(sizeof(node));
        currentp = headp;


        for(i=1; i<position-1; ++i)
            currentp=currentp->nextp;


        strcpy(newp->current,current);
        newp->volts = volts;

        newp->nextp = currentp->nextp;
        currentp->nextp = newp;
        currentp->nextp->prevp = newp;
        newp->prevp = currentp;

    }
    else
    {
        printf("Invalid position\n");
    }


}

void delete_node(node *n)
{

}

void display_list()
{
    node *now;
    now = (node*)malloc(sizeof(node));
    printf("*******************\n");
    printf("Displaying the list\n");
    if(headp == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        for(now = headp; now != NULL; now = now->nextp)
        {
            printf("\n%s %d\n",now->current, now->volts);
        }
    }

}

int size_list()
{
    node *now;
    int counter=0;

    if(headp == NULL)
        return 0;
    else
    {
        for(now = headp; now != NULL; now = now->nextp)
            counter++;
    }
    return counter;
}
