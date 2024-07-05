#include"binary_file_io.h"

// read from binary file
void binaryFileRead(FILE *fp)
{
        struct employee e;

        while(fread(&e, sizeof(e), 1, fp) == 1)
        {
                printf("id = %d, age = %d, name = %s\n", e.id, e.age, e.name);
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
