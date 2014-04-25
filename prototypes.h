// prototypes.h
// Arthur Knapp
// AK146316

void findFiles(DIR *);
// Finds the proper file to insert into the linked list
void insert(char *, int);
// Inserts the name and the size of the file into the linked list
void createNewList(char *, int);
// Creates a new list if there are no nodes
void printList();
// Prints the linked list