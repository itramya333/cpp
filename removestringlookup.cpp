#include <stdio.h>
#include <stdlib.h>
#define NO_OF_CHARS 256
#include<iostream>
using namespace std;
 
/* Returns an array of size 256 containg count
   of characters in the passed char array */
int *getCharCountArray(char *str)
{
   //int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
   int*count = new int[256];
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;
      //count[*(str+i)] =1;
      cout << count['m']<<count['a']<< count[97]<< endl;
   return count;
}

/* removeDirtyChars takes two string as arguments: First
string (str)  is the one from where function removes dirty
characters. Second  string is the string which contain all
dirty characters which need to be removed  from first string */
char *removeDirtyChars(char *str, char *mask_str)
{
  int *count  = getCharCountArray(mask_str);
  int ip_ind  = 0, res_ind = 0;
  while (*(str + ip_ind))
  {
    char temp = *(str + ip_ind);
    if (count[temp] == 0)
    {
        *(str + res_ind) = *(str + ip_ind);
        res_ind++;
    }
    ip_ind++;
  }    
 
  /* After above step string is ngring. 
    Removing extra "iittg" after string*/
  *(str+res_ind) = '\0';    
 
  return str;
}
 
/* Driver program to test getCharCountArray*/
int main()
{
    char str[]         = "geeksforgeeks";
    char mask_str[]  = "maask";
    printf("%s", removeDirtyChars(str, mask_str));
    return 0;
}


