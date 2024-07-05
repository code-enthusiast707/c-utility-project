#include<stdio.h>
#include"text_file_io.h"

// read from text file
void textFileRead(FILE *fp)
{
        printf("\nFile read operation\n\n");

        char buff[100];
        while(fgets(buff, sizeof(buff), fp) != NULL)
        {
                printf("%s", buff);
        }
}

// write to text file
void textFileWrite(FILE *fp)
{
        printf("File write operation\n\n");

        char choice = 'y';

        while(choice != 'n')
        {
                printf("1. Enter a sentence to be written to the file\n");
                char buff[100], buff1[10];

                fgets(buff, sizeof(buff), stdin);

                printf("2. Do you want to continue? y or n\n");

                fputs(buff, fp);

                fgets(buff1, sizeof(buff1), stdin);

                sscanf(buff1, "%c", &choice);
        }
}
