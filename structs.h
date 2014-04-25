// structs.h
// Arthur Knapp
// AK146316

typedef struct list
{
    char *name;
    int size;
    
    struct list *next;
} LinkedList;