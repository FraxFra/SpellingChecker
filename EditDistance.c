#include "EditDistance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define rest(x) (x + sizeof(char))

int min_three(int i, int j, int k)
{
        if(i <= j && i <= k)
        {
                return i;
        }
        else if(j < i && j <= k)
        {
                return j;
        }
        else if(k < i && k < j)
        {
                return k;
        }
        return 0;
}

int** allocate (int** mat, int len1, int len2)
{
        int i, j;
        mat = (int**) malloc(sizeof(int*) * ((size_t) len1 + 1));

        for(i = 0; i < len1 + 1; i++)
        {
                mat[i] = (int*) malloc(sizeof(int)* ((size_t) len2 + 1));
                for(j = 0; j < len2 + 1; j++)
                {
                        mat[i][j] = -1;
                }
        }
        return mat;
}

void release (int len1, int** mat)
{
        int i;

        for (i = 0; i < len1 + 1; i++)
        {
                free(mat[i]);
        }
        free(mat);
}

int edit_distance(char *s1, char *s2)
{
        if(strlen(s1) <= 0)
        {
                return strlen(s2);
        }
        else if(strlen(s2) <= 0)
        {
                return strlen(s1);
        }
        else
        {
                int no_op = s1[0] == s2[0] ? edit_distance(rest(s1), rest(s2)) : 10000;
                int remove = 1 + edit_distance(s1, rest(s2));
                int insert = 1 + edit_distance(rest(s1), s2);
                return min_three(no_op, insert, remove);
        }
}

int edit_distance_dyn(char *s1, char *s2)
{
        if(s1 == NULL)
        {
                exit(EXIT_FAILURE);
        }
        if(s2 == NULL)
        {
                exit(EXIT_FAILURE);
        }

        int **mat;
        mat = allocate(mat, strlen(s1), strlen(s2));
        int res = edit_distance_dynR(s1, s2, mat);
        release(strlen(s1), mat);
        return res;
}

int edit_distance_dynR(char *s1, char *s2, int **mat)
{
        if(strlen(s1) <= 0)
        {
                return strlen(s2);
        }
        else if(strlen(s2) <= 0)
        {
                return strlen(s1);
        }
        else
        {
                if(mat[strlen(s1)][strlen(s2)] != -1)
                {
                        return mat[strlen(s1)][strlen(s2)];
                }
                int no_op = s1[0] == s2[0] ? edit_distance_dynR(rest(s1), rest(s2), mat) : 10000;
                int remove = 1 + edit_distance_dynR(s1, rest(s2), mat);
                int insert = 1 + edit_distance_dynR(rest(s1), s2, mat);
                int res = min_three(no_op, insert, remove);
                mat[strlen(s1)][strlen(s2)] = res;
                return res;
        }
}
