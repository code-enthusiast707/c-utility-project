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
                printf("1. Insert a character to be written to the file\n2. Do you want to insert another character? y or n\n");
                char buff[100];

                fgets(buff, sizeof(buff), stdin);

                char c_in;

                sscanf(buff, "%c %c", &c_in, &choice);

                fputc(c_in, fp);
        }
}

// read from file
void fileRead(FILE *fp)
{
	printf("\nFile read operation\n\n");

        char c_out;
        while((c_out = fgetc(fp)) != EOF)
        {
                printf("%c", c_out);
        }

        printf("\n\n");
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
