#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void block_(char*string,unsigned char*result,unsigned char*result1,unsigned long * counter)
{
 while(*string)
 {
  for(unsigned short i = 8;i--;)
  {
   *result^=(*string^*(string+1) & 0xFF);
   string+=2;
   *counter+=2;
  }
  *result1+=*result;
 }

}

void first(char*string)
{

 unsigned char result __attribute__((aligned(8)));
 unsigned char result1 __attribute__((aligned(8)));
 unsigned long counter_string_size=0;
 block_(string,&result,&result1,&counter_string_size);
 result=(result|result1) & 0xFF;
 *string++=result;
for(counter_string_size;counter_string_size--;)
  *string++=0;
*string='\0';
}

void second(char*string)
{

}

void final(char*string)
{

}

void main(void)
{
unsigned char * buffer = strdup("Test String");
first(buffer);
printf("Result: %d\n",*buffer);
}
