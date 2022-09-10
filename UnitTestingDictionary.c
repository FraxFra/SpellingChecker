#include "EditDistance.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
        char correggi[40];
        char dizionario[40];
        char soluzioni[10][40];

        int i = 50;
        int j, w;

        FILE *dictionary;
        FILE *correctme;

        correctme = fopen("correctme.txt","r");
        dictionary = fopen("dictionary.txt","r");

        if (correctme == NULL)
        {
                printf("Error: cannot open correctme");
                exit(EXIT_FAILURE);
        }

        if (dictionary == NULL)
        {
                printf("Error: cannot open dictionary");
                exit(EXIT_FAILURE);
        }

        while(!feof(correctme))
        {
                i = 50;
                fscanf(correctme, "%s", &correggi);
                correggi[0] = tolower(correggi[0]);
                int a = strlen(correggi) - 1;
                char x = correggi[a];
                if(x == '!' || x == '?' || x== '.' || x == ',' || x== ':' || x == ';')
                {
                        correggi[a] = '\0';
                }

                while (!feof(dictionary) && i != 0)
                {
                        fgets(dizionario, 40, dictionary);
                        int temp = edit_distance_dyn(dizionario, correggi);
                        if(i > temp)
                        {
                                i = temp;
                                for (w = 0; w < 10; w++)
                                {
                                        *soluzioni[w] = '\0';
                                }
                                j = 0;
                                strcpy(soluzioni[j], dizionario);
                                j++;
                        }
                        else if(i == temp)
                        {
                                if(j == 10)
                                {
                                        j = 0;
                                }
                                strcpy(soluzioni[j], dizionario);
                                j++;
                        }
                }
                j = 0;
                printf("The word %s can be replaced by:\n", correggi);
                while(j <= 9)
                {
                        if(soluzioni[j][0] != '\0')
                        printf("--- %s\n", soluzioni[j]);
                        j++;
                }
                rewind(dictionary);
        }
        fclose(correctme);
        fclose(dictionary);
        return 0;
}
