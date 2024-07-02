#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
	int id;
	int age;
	char name[100];
};

// file open
FILE* fileOpen(char* filename, char *file_mode)
{
	FILE *fp = fopen(filename, file_mode);

        if(fp == NULL)
        {
                printf("Failed to open file\n");
                exit(1);
        }

	return fp;
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

// write to binary file
void binaryFileWrite(FILE *fp)
{
	struct employee e;

	char buff[100];

	char ch = 'y';

	while(ch != 'n')
	{
		printf("Enter employee id, age and name:\n");

		fgets(buff, sizeof(buff), stdin);

		sscanf(buff, "%d", &e.id);

		fgets(buff, sizeof(buff), stdin);

        	sscanf(buff, "%d", &e.age);

		fgets(e.name, sizeof(e.name), stdin);

		fwrite(&e, sizeof(e), 1, fp);

		printf("Do you want to continue? y or n\n");

		fgets(buff, sizeof(buff), stdin);

		sscanf(buff, "%c", &ch);
	}

	/*
	 * The following block of code doesn't work, why?
	 * fgets(buff, sizeof(buff), stdin);
	 * sscanf(buff, "%s", e.name);
	 * In name only first word is getting stored and not the full name
	 */
}

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

// read from binary file
void binaryFileRead(FILE *fp)
{
	struct employee e;

	while(fread(&e, sizeof(e), 1, fp) == 1)
	{
		printf("id = %d, age = %d, name = %s", e.id, e.age, e.name);
	}
}

void main()
{
	FILE *fp;

	char buff[100];

	int ch;

	char filename[50], readFilemode[10], writeFilemode[10];

	// Take input for text or binary file
	printf("1. Text file operation\n2. Binary file operation\nChoose 1 or 2:\n");

	fgets(buff, sizeof(buff), stdin);

	sscanf(buff, "%d", &ch);

	if(ch == 1)
	{
		strcpy(writeFilemode,"w");
		strcpy(readFilemode,"r");
	}
	else
	{
		strcpy(writeFilemode,"wb");
		strcpy(readFilemode,"rb");
	}

	// Take input for filename
	printf("Enter filename:\n");

	fgets(buff, sizeof(buff), stdin);

	sscanf(buff, "%s", filename);

	// open file for write operation
	fp = fileOpen(filename, writeFilemode);

	// perform file write
	if(ch == 1)
	{	
		textFileWrite(fp);
	}
	else
	{
		binaryFileWrite(fp);
	}
	
	// close file after write operation
	fclose(fp);

	// open file for read operation
	fp = fileOpen(filename, readFilemode);

	// perform file read
	if(ch == 1)
	{
		textFileRead(fp);
	}
	else
	{
		binaryFileRead(fp);
	}
	
	// close file after read operation
	fclose(fp);
}
