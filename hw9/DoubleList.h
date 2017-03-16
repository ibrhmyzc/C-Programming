#ifndef DOUBLIST_H
#define DOUBLIST_H



typedef struct Circuit
{
    char current[3];
    int volts;
    struct Circuit *prevp;
    struct Circuit *nextp;
}node;



void insert_node(char *current, int volts, int position);
void delete_node(node *n);
void display_list();
int size_list();


#endif
