/* Util.h */
extern int min_three(int x, int y, int z);
extern int edit_distance(char* str1, char* str2);
extern int edit_distance_dyn(char* str1, char* str2);
extern int edit_distance_dynR(char* str1, char* str2, int **mat);
extern int** allocate (int** mat, int len1, int len2);
extern void release (int len1, int** mat);