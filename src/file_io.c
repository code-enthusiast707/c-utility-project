#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct userInput
{
	char filename[50];
	char writeFilemode[10];
	char readFilemode[10];
};

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

		sscanf(buff, "%d %d %[^\n]", &e.id, &e.age, e.name);

		fwrite(&e, sizeof(e), 1, fp);

		printf("Do you want to continue? y or n\n");

		fgets(buff, sizeof(buff), stdin);

		sscanf(buff, "%c", &ch);
	}
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
		printf("id = %d, age = %d, name = %s\n", e.id, e.age, e.name);
	}
}

void init(struct userInput *ui)
{
	char buff[100];

        int ch;

        char filename[50], readFilemode[10], writeFilemode[10];

        // Take input for text or binary file
        printf("1. Text file operation\n2. Binary file operation\nChoose 1 or 2:\n");

        fgets(buff, sizeof(buff), stdin);

        sscanf(buff, "%d", &ch);

        if(ch == 1)
        {
                strcpy(ui->writeFilemode,"w");
                strcpy(ui->readFilemode,"r");
        }
        else
        {
                strcpy(ui->writeFilemode,"wb");
                strcpy(ui->readFilemode,"rb");
        }

        // Take input for filename
        printf("Enter filename:\n");

        fgets(buff, sizeof(buff), stdin);

        sscanf(buff, "%s", ui->filename);
}

void fileWrite(struct userInput ui)
{
	FILE *fp;

	// open file for write operation
        fp = fileOpen(ui.filename, ui.writeFilemode);

        // perform file write
        if(strcmp(ui.writeFilemode, "w") == 0)
        {       
                textFileWrite(fp);
        }
        else
        {
                binaryFileWrite(fp);
        }
        
        // close file after write operation
        fclose(fp);
}

void fileRead(struct userInput ui)
{
	FILE *fp;

	// open file for read operation
        fp = fileOpen(ui.filename, ui.readFilemode);

        // perform file read
        if(strcmp(ui.readFilemode,"r") == 0)
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

void main()
{
	struct userInput ui;

	// take user input and initialise the data
	init(&ui);

	// perform file write operation
	fileWrite(ui);

	// perform file read operation
	fileRead(ui);

}
