//万年历，输入年份和月份，显示该年该月日历
//Author: Jiahui Tang
//Date: 2016-12-13

//import the necessary packages
#include <stdio.h>
#include <stdlib.h>

//平闰年的判断
int leap(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

//计算该月天数
int days_mouth(int mouth, int year)
{
	if(mouth==1 || mouth==3 || mouth==5 || mouth==7 || mouth==8 || mouth==10 || mouth==12)
		return 31;
	else if(mouth == 2)
	{
		if(leap(year))
			return 29;
		else
			return 28;
	}
	else
		return 30;
}

//蔡勒公式求首日
int firstday(int mouth, int year)
{
	int w;    //星期
	int c;    //世纪
	int y;    //年（2位）
	c = year / 100;
	y = year % 100;
	
	w = y + (y / 4) + (c / 4) - 2 * c + (26 * (mouth + 2 + 1) / 10);
	
	return w;
}

//main
int main(int argc, char **argv)
{
	int mouth, year, i, j;
	int a, b;
	printf("Please input the year:\n");
	scanf("%d", &year);
	printf("Please input the mouth:\n");
	scanf("%d", &mouth);
	
	b = days_mouth(mouth, year);
	a = firstday(mouth, year);
	

	puts("SUN MON TUE WEN THU FRI SAT");

	if(a % 7 == 0)
	{
		for(i=1; i<=b; i++)
		{
			printf("%3d ", i);
			
			if(i % 7 == 0)
				puts("\n");
		}
		puts("\n");	
	}
	else
	{
		for(i = 1; i <= a * 4; i++)
			printf(" ");
		for(i = 1; i <= b; i++)
		{
			printf("%3d ", i);
			
			if((i + a) % 7 == 0)
				printf("\n");
		}
		puts("\n");
	}

	exit(EXIT_SUCCESS);
}
