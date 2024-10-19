#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Please supply a 1 source file and 2 destination files\n");
        exit(1);
    }

    FILE *src = fopen(argv[1], "r");
    if (!src)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    FILE *dest1 = fopen(argv[2], "w");
    if (!dest1)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }
    FILE *dest2 = fopen(argv[3], "w");
    if (!dest2)
    {
        printf("Can't open %s for writing\n", argv[3]);
        exit(1);
    }

    char line[1000];
    int numLinesDest1 = 0;
    int numLinesDest2 = 0;

    while (fgets(line, 1000, src) != NULL)
    {
        if (strlen(line) < 20)
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = toupper(line[i]);
            }
            fprintf(dest1, "%s", line);
            numLinesDest1++;
        }
        else 
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                line[i] = tolower(line[i]);
            }
            fprintf(dest2, "%s", line);
            numLinesDest2++;
        }
    }

    fclose(src);
    fclose(dest1);
    fclose(dest2);

    printf("%d lines written to %s\n", numLinesDest1, argv[2]);
    printf("%d lines written to %s\n", numLinesDest2, argv[3]);
}