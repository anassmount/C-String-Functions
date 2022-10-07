/* str.h */
/* Anass Mountasser */

#ifndef STR_INCLUDED
#define STR_INCLUDED
#include <stddef.h>

/* Finds the length of the array, identified by the character array
pointer pcSrc. Takes any pointers that point to the array, and returns
its length */
size_t Str_getLength(const char pcSrc[]);


/* Changes everything in the first array such that it equals the 
second array. Takes a pointer to the first array, andn a pointer to
the second array, and returns a pointer to the first array */
char *Str_copy(char first[], const char second[]);


/* Adds the contents of the second array to the end of the contents
from the first array. Takes a pointer to the first array, and a pointer
to the second array, and returns a pointer to the first array */
char *Str_concat(char first[], const char second[]);


/* Compares the contents of the first array to that of the second 
array. If array 1 is greater, 1 is returned, if it is less, -1 is
returned, and if equal, 0 is returned. Takes a pointer from the first 
array, a pointer to the second array, and returns a pointer to the 
first array */
int Str_compare(char const  first[], const char second[]);

/* Searches for the second array in the first array, and if found, 
returns a pointer to the index at which the found second array begins
in the first one. Takes a pointer to both arrays, and returns a
pointer. If not found, the null pointer is returned */
char *Str_search(const char first[], const char second[]);

#endif
