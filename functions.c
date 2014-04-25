// functions.c
// Arthur Knapp
// AK146316

// Functions:



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "prototypes.h"
#include "constants.h"
#include "externs.h"
#include "structs.h"

LinkedList *pHead = NULL;
LinkedList *pTail = NULL;
// Define head and tail nodes for the Linked List

void findFiles(DIR *pDirectory)
{
    struct dirent *pDirent;
    // Points to the dirent struct
    struct stat fileStats;
    // Declare stat struct
    
    while ((pDirent = readdir(pDirectory)))
    // Loops through the directory while there entries to be read
    {
        if (pDirent -> d_ino != 0)
        // Checks the entry node number is valid
        {
            if (pDirent -> d_name[0] == '.')
            // Checks if the first charcter of the entry name is '.'. This is a hidden file.
            {
                if ((strcmp(pDirent -> d_name, ".") != 0) && (strcmp(pDirent -> d_name, "..")))
                // If entry name is not "." and "..", print entry name
                {
                    insert(pDirent -> d_name, 0);
                    // Insert file name and size into linked list
                }
            }
        }
    }
}

void insert(char *name, int size)
{
    if (pHead == NULL)
    // Checks to see if the head node is pointing to null and calls 'createNewList'.
    // If the head node is pointing to null, the list is empty and a new list must be created.
    {
        createNewList(name, size);
    }

    else
    // Runs if the list is note empty and inserts the new node at the end of the list
    {
        LinkedList *pNewNode = malloc(sizeof(LinkedList));
        // Creates new node to be inserted into the list
        LinkedList *pCurr = pHead;
        // Creates node to loop through the linked list

        if (pNewNode == NULL)
        // Checks if memory was properly allocated to the new node. If not, print 
        // an error message and close program.
        {
            fprintf(stderr, "Error: Memory Was Not Allocated To pNewNode\n");
            exit(1);
        }
        
        pNewNode -> name = malloc(sizeof(name));

        strcpy(pNewNode -> name, name);
        // Insert name into the new node
        pNewNode -> size = size;
        // Insert size into the new node

        if (pHead == pTail)
        // Checks to see if the new node is going to be the second node in the linked list.
        // If head and tail are the same, there is only one node
        {
            pHead -> next = pNewNode;
            // Have the head node point to the new node
            pTail = pNewNode;
            // Insert the new node into tail
            pTail -> next = NULL;
            // Have the tail node point to null signifying it is the last node in the list
        }

        else
        // If the node is not the second node to be inserted
        {
            while (pCurr != NULL)
            // Loop to the end of the list 
            {
                if (pCurr -> next == NULL)
                // If the current node points to null, insert the new node.
                {
                    pTail -> next = pNewNode;
                    // Point the tail node to the new node
                    pNewNode -> next  = NULL;
                    // Point the new node to null
                    pTail = pNewNode;
                    // Insert the new node into tail
                }

                pCurr = pCurr -> next;
                // Move current node pointer to next node
            }
        }
    }
}

void createNewList(char *name, int size)
{
    LinkedList *pNewNode = malloc(sizeof(LinkedList));
    // Creates new node to be inserted into the list

    if (pNewNode == NULL)
    // Checks if memory was properly allocated to the new node. If not, print 
    // an error message and close program.
    {
        fprintf(stderr, "Error: Memory Was Not Allocated To pNewNode\n");
        exit(1);
    }
    
    pNewNode -> name = malloc(sizeof(name));

    strcpy(pNewNode -> name, name);
    // Insert the string into the new node
    pNewNode -> size = size;
    // Insert the size into the new node

    pNewNode -> next = NULL;
    // Have the new node reference null
    pHead = pTail = pNewNode;
    // Set the head and tail equal to the new node because
    // there is only one node.
}

void printList()
{
    LinkedList *pCurr = pHead;
    // Create a node to loop through the list and assign pHead to it
    
    printf ("Directory Contents:\n");
    
    while (pCurr != NULL)
    {
        printf("File Name: %s\n", pCurr -> name);
        pCurr = pCurr -> next;
    }
}

