#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;

	fp = fopen("file1.txt", "w");

	if(fp == NULL)
	{
		printf("Failed to open file\n");
		exit(1);
	}

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

	fclose(fp);

	fp = fopen("file1.txt", "r");

	if(fp == NULL)
	{
		printf("Failed to open file\n");
		exit(1);
	}

	printf("\nFile read operation\n\n");
	
	char c_out;
	while((c_out = fgetc(fp)) != EOF)
	{
		printf("%c", c_out);
	}

	printf("\n\n");

	fclose(fp);
}
