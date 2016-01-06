#include <stdio.h>
char shellcode[]=
  "place your shellcode here"
  "\x..\x..\x..\x..";
int main();
{
  //two ways to execute your shellcode
  //first method
  int *ret;
  ret = (int *)&ret + 2;
  (*ret) = (int)shellcode;
  //second method
  /*
  int (*function)();
  function= (int (*) ()) shellcode;
  function();
  */
}
