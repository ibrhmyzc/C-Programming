/********************************************/
/*Ibrahim Yazici 131044011 HW09 part1       */
/*Doubly and Circular Linked Lists          */
/********************************************/
#include <stdio.h>
#include "DoubleList.h"

int main()
{
/*START_OF_MAIN*/

    /*DoubleLinked List part*/
    display_list();
    printf("\nsize of the list is %d\n",size_list());
    printf("*******************\n");

    insert_node("AC",200,1);
    display_list();
    printf("*******************\n");

    insert_node("AC",180,1);
    display_list();
    printf("*******************\n");

    insert_node("AC",160,1);
    display_list();
    printf("*******************\n");

    insert_node("AC",140,2);
    display_list();
    printf("*******************\n");

    insert_node("DC",141,6);
    display_list();
    printf("\nSize of the list is %d\n",size_list());
    printf("*******************\n");
    /*End of DoublyLinked List part*/


    /*Circular Linked List part*/

    /*End of Circular Linked List part*/
    return 0;
/*END_OF_MAIN*/
}
