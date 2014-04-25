// main.c
// Arthur Knapp
// AK146316

// Program-5A:
// This program will print information about hidden files in a specified directory. When the program is executed, it will print
// the file name, size, and the last date of modification.
// The program will take in two command line arguments; "Path Name" and "Optional Flag". "Path Name" will be the path of a
// specifieddirectory and "Optional Flag" will be dictate the structure of how the file information is printed. "Optional Flag" only
// takes in the flag "-s" and does not require a flag to be entered. If no flag is entered, the order of how the files are printed
// does not matter. Likewise, if the flag is "-s", the files must be printed in increasing order of the file size.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "prototypes.h"
#include "constants.h"
#include "externs.h"

int main(int argc, const char * argv[])
{
    DIR *pDirectory;
    // Points to the opened directory
    
    if (argc != TWO_ARGS)
    // Checks if there are not exactly 2 arguments.
    {
        if (argc != THREE_ARGS)
        // Checks if there are exactly 3 arguments. If there are not 3 arguments, an error message will
        // be printed and the program will be closed.
        {
            fprintf(stderr, "Error: Incorrect Number Of Command Line Arguments\n");
            exit(1);
        }
        
        else
        // If there are exactly 3 arguments
        {
            if (strcmp(argv[SECOND_ARG], "-s") != 0)
            // Checks if the second argument is not "-s". If it is not "-s", an error message will print
            // and the program will be closed.
            {
                fprintf(stderr, "Error: The Second Argument Is Incorrect\n");
                exit(1);
            }
        }
    }
    
    if ((pDirectory = opendir(argv[FIRST_ARG])) == NULL)
    // Checks if the directory could not be opened. If true, an error message will be printed and
    // the program is closed.
    {
        fprintf(stderr, "Error: Specified Directory Could Not Be Opened");
        exit(1);
    }
    
    findFiles(pDirectory);
    printList();
        
    if (closedir(pDirectory) != 0)
    // Checks if the directory could not be closed. If true, an error message will be printed and
    // the program is closed.
    {
        fprintf(stderr, "Error: Specified Directory Could Not Be Closed");
        exit(1);
    }
}

