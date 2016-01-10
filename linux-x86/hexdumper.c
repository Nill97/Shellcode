/* created by Nill
  this program takes a binary file as an argument 
  it read that file and print it in hexadecimal
  like below format
  \x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20
  \x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20
  \x20\x20\x20\x20\x20\x20
  which we can use in our shellcode development
*/  
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ( int argc, char *argv[] )
{
   int check,fd,count=1,i=1;
   char buf[1];
   if (argc != 2)
      printf("\nusage: %s <file>",argv[0]);
   fd=open(argv[1],O_RDONLY);
   check=read(fd, buf, count);
   while(check==1)
   {  
      printf("\\x%02x",(unsigned char)buf[0]);
      if(i%16==0)
         printf("\n");
      check=read(fd, buf, count);
      i=i+1;
   }   
   return 0;
}   
