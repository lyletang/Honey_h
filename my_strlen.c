//c语言字符串自定义长度计算
//Author: Jiahui Tang
//Time: 2016-12-11

#include <stdio.h>
#include <stdlib.h>

int My_strlen(const char *);
int my_strlen(const char *);

int main(int argc, char* argv[])
{
	int len1,len2;
	char str[80];
	
	fgets(str,80,stdin);
	len1 = My_strlen(str)-1;
	len2 = my_strlen(str)-1;
	printf("%d\n%d\n",len1,len2);

	return 0;
}

int my_strlen(const char *ps)
{
	if((ps==NULL||*ps=='\0'))
	{
		return 0;
	}
	else
	{
		return 1+my_strlen(++ps);
	}
}

int My_strlen(const char *ps)
{
	int len = 0;
	if(ps == NULL)
	{
		return 0;
	}
	for(;*ps++!='\0';)
	{
		len++;
		if(*ps == ' ')
			len--;
	}
	return len;
}
