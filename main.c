#include <stdio.h>
#include <string.h>

//  Prepare input String for Palindrome Checking...
//  Only keeps alphabet and make them lowercase...

char *myConvert(char arr[])
{
    int i,j;

    for(i = 0; arr[i] != '\0'; ++i)
    {
        while (!((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i]<= 'Z' || arr[i] == '\0')))
        {
            for (j = i; arr[j] != '\0'; ++j)
            {
                arr[j] = arr[j+1];
            }
            arr[j] = '\0';
        }
    }
    return strlwr(arr);
}
// This Function check for palindrome using POINTERS!

int isPalindrome(char *str)
{
    char *last, *first;

    last = str;

    while (*last != '\0')
    {
        ++last;
    }
    --last;

    for (first = str; last >= first;)
    {
        if (*last == *first)
        {
            --last;
            first++;
        }
        else
            break;
    }

    if (first > last)
        return 1;
    else
        return 0;
}


int main ()
{
   int result;

   char myString[80];
   char myTemp[80];

   if( fgets (myString, 80, stdin)!= NULL )
   {
      result = isPalindrome(strcpy(myTemp,myConvert(myString)));
   }

   if(result == 1)
   {
       printf("palindrome");
   }
   else
   {
       printf("not a palindrome");
   }

   return(0);
}
