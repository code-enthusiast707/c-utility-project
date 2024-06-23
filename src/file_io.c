#include<stdio.h>
#include<stdlib.h>

// file open
FILE* fileOpen(char *file_mode)
{
	FILE *fp = fopen("file1.txt", file_mode);

        if(fp == NULL)
        {
                printf("Failed to open file\n");
                exit(1);
        }

	return fp;
}

// write to file
void fileWrite(FILE *fp)
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

// read from file
void fileRead(FILE *fp)
{
	printf("\nFile read operation\n\n");

        char buff[100];
        while(fgets(buff, sizeof(buff), fp) != NULL)
        {
                printf("%s", buff);
        }
}

void main()
{
	FILE *fp;

	// open file for write operation
	fp = fileOpen("w");

	// perform file write
	fileWrite(fp);
	
	// close file after write operation
	fclose(fp);

	// open file for read operation
	fp = fileOpen("r");

	// perform file read
	fileRead(fp);

	// close file after read operation
	fclose(fp);
}
