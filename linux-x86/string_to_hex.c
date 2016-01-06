#include <stdio.h>
int main(int argc, char* argv[])
{
	int i,str_len,r,j,str_len_new;
	
	//usage display if no arguments passed
	if ( argc != 2 )
	{
		printf("\n usage: %s <string to convert>",argv[0]);
		return 1;
	}
	
	//printing the given string 
	printf("%s",argv[1]); 
	
	//length of the string 
	i=0;
	while (argv[1][i]!= '\0')
		i++;
	str_len=i;
	
	//length of the string including newline at the end
	str_len_new=str_len + 2; 
	
	//checking if string length is multiple of 4
	r=str_len%4;
	
	//adding new line and carriage return bytes
	if (r!=0)
	{
		printf("\npush 0x");
		for(i=0;i<4-r;i++)
		{
			if(r==1)
			{
				printf("200d0a");
				break;
			}
			else if(r==2)
			{
				printf("0d0a");
				break;
			}
			else if (r==3)
			{
				printf("2020200d");
				printf("\npush 0x0a");
				break;
			}
			printf("20");
		}
		for(i=r-1;i>=0;i--)
		{
			printf("%x",argv[1][str_len-r+i]);
		}
	}
	else
	{
		printf("\npush 0x20200d0a");
	}
	
	//processing the rest of the string 
	for (i=4;i<=str_len-r;i=i+4)
	{
		printf("\npush 0x");
		for(j=3;j>=0;j--)
		{
			printf("%x",argv[1][str_len-r-i+j]);
		}				
	}
	
	printf("\nlength of the given string: %d",str_len);	
    printf("\nlength of the given string with new line: %d",str_len_new);		
	return 0;
}
