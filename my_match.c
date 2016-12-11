//c语言自定义字符串匹配
//Author: Jiahui Tang
//Time: 2016-12-11

#include <stdio.h>
#include <stdlib.h>

int my_find(const char s[], const char t[]);

int main(int argc, char* argv[])
{
	char s[80];
	char t[80];
		
	puts("input the s string:");
	fgets(s,80,stdin);
	puts("input the t string:");
	fgets(t,80,stdin);
	
	int num;
	num = my_find(s,t);

	printf("%d",num);

	return 0;
}

int my_find(const char s[],const char t[])
{
	int i,j=0;
	for(i=0;i<80;i++)
	{
		
		while(t[j]==s[i])
		{	
			static int flag=0;	
			flag++;
			i++;
			j++;
			if(t[j+1]=='\0')
				return i-flag+1;
		}
		
	}
	return 0;
}
