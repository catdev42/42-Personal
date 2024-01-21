#include <stddef.h>
#include <stdio.h>

int positive_sum(const int *val, size_t len) {
    int res = 0;
    while (len --> 0) res += val[len] > 0 ? val[len] : 0;

    return res;
}
int main() {
  int arr[4] = {4,5,0,-1};
printf("%i",positive_sum(arr, 4));
  return 0;
}

/* 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *remove_char(char* dst, const char* src);

int main() {
  char dst[6];
  char *src = "animals";
  
  remove_char(dst, src);
  return 0;
}

char *remove_char(char* dst, const char* src) {
    src ++;
    strncpy(dst, src, strlen(src)-1);
    dst[strlen(src)-1] = '\0';
    return dst;
}
*/


// #include <stdio.h>      /* printf */
// #include <stdlib.h>     /* strtol */

// int main ()
// {
//   char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
//   char * pEnd;
//   long int li1, li2, li3, li4;
//   li1 = strtol (szNumbers,&pEnd,10);
//   li2 = strtol (pEnd,&pEnd,16);
//   li3 = strtol (pEnd,&pEnd,2);
//   li4 = strtol (pEnd,NULL,0);
//   printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
//   return 0;
// }