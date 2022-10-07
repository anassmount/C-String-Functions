/* stra.c */
/* Anass Mountasser */

#include <assert.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc)
{
   const char *len = pcSrc;
   assert(pcSrc != NULL);
   while(*len)
      len++;
   return (size_t) (len - pcSrc);
}

char *Str_copy(char *first, const char *second)
{
   char *counter = first;
   assert(first != NULL);
   assert(second != NULL);
   while((*counter++ = *second++))
      ;
   return first;
}

char *Str_concat(char *first, const char *second)
{
   char *counter = first;
   assert(first != NULL);
   assert(second != NULL);
   while(*counter)
      counter++;
   while((*counter++ = *second++))
      ;
   return first;
}

int Str_compare(const char *first, const char *second) {
   char *counterOne = (char*)first;
   char *counterTwo = (char*)second;
   assert(first != NULL);
   assert(second != NULL);
   while(1) {
      if(*counterOne > *counterTwo)
         return 1;
      if(*counterOne < *counterTwo)
         return -1;
      if((*counterOne == '\0') && (*counterTwo == '\0'))
         return 0;
      if(*first == *second) {
         counterOne++;
         counterTwo++;
      }
   }
}

char * Str_search(const char *first, const char *second) {
   char *counterOne = (char*)first;
   char *counterTwo = (char*)second;
   char *tempOne = (char*)first;
   char *tempTwo = (char*)second;
   assert(first != NULL);
   assert(second != NULL);
   /* if the needle is empty, the the first array is the answer */
   if(*counterTwo == '\0')
      return (char*)(counterOne);
   while(1) {
      while(*counterOne != *counterTwo) {
         if(*counterOne == '\0')
            return NULL;
         counterOne++;
      }
      /* temporary pointers increment to see if the strings are the
         same, while the original pointers will keep track where to
         return if this is the case */
      tempOne = counterOne + 1;
      tempTwo = counterTwo + 1;
      while(*tempTwo != '\0') {
         if(*tempOne == '\0')
            return NULL;
         if(*tempOne == *tempTwo) {
            tempOne++;
            tempTwo++; }
         else {
            counterOne++;
            break; }
      }
      /* This part checks if the while loop being broken was due to 
         the needle having reached the end, or if it was because the
         substrings were different */
      --tempOne;
      --tempTwo;
      if((*(tempTwo + 1)  == '\0') && (*tempOne == *tempTwo))
         return (char*)(counterOne);
   }
}
         
         
         
      
