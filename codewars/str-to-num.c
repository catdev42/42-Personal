#include <stdlib.h>

//learned strtol function - a more thorough function that can take a starting and ending point as well as base number and read the first chars to determing base 8 and base 16 is base is provided as 0 or not provided... Somone in comments mentioned that strtol is what should be used in production instead of atol. Glad to learn of it. 

int string_to_number(const char *src) 
{
return (int)strtol(src, NULL, 10);
}



/* 
//My Solution

int string_to_number(const char *src) {
  int num = 0;
  int i = 0;
  int sign = 1;
  if (src[0] == '-')
    {
      sign = -1;
      i++;
     }
  while(src[i])
  {
    num=num*10+(src[i]-48);
    i++;
  }
  return (num*sign);
}
*/

