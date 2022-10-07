/* stra.c */
/* Anass Mountasser */

#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char first[], const char second[])
{
   int i;
   assert(first != NULL);
   assert(second != NULL);
   for(i=0; second[i] != '\0'; i++)
      first[i] = second[i];
   first[i] = '\0';
   return first;
}

char *Str_concat(char first[], const char second[])
{
   int i = 0;
   int j = 0;
   assert(first != NULL);
   assert(second != NULL);
   while(first[i] != '\0')
      i++;
   while(second[j] != '\0') {
      first[i] = second[j];
      i++;
      j++;
   }
   first[i] = '\0';
   return first;
}

int Str_compare(const char first[], const char second[]) {
   int i = 0;
   assert(first != NULL);
   assert(second != NULL);
   while(1) {
      if(first[i] > second[i])
         return 1;
      if(first[i] < second[i])
         return -1;
      if((first[i] == '\0') && (second[i] == '\0'))
         return 0;
      if(first[i] == second[i])
         i++;
   }
}

char *Str_search(const char first[], const char second[]) {
   int i = 0;
   int j = 1;
   assert(first != NULL);
   assert(second != NULL);
   /* checks corner case if second is empty, if it is then first 
    is returned */
   if(*second  ==  '\0')
      return (char*)(first);
   while(1) {
      while(first[i] != second[0]){
         if(first[i] == '\0')
            return NULL;
         i++;
      }
      /* situation where a char from first is equal to first char in
         second */
      while(second[j] != '\0') {
         if(first[i+j] == '\0')
            return NULL;
         /* sucess case of when all of the chars in the second 
            string were found in the first string */
         if((second[j+1] == '\0') && (first[i+j] == second[j]))
            return (char*)(first + i);
         if(first[i+j] == second[j])
            j++;
         else {
            i++;
            j = 0;
            break;
         }
      }
      /* corner case if the next entry in j was immediately null */
      if((second[j] == '\0') && (first[i] == second[j-1]))
         return (char*)(first + i);
   }
}

      
    
