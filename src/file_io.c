#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"text_file_io.h"
#include"binary_file_io.h"

struct userInput
{
	char filename[50];
	char writeFilemode[10];
	char readFilemode[10];
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
