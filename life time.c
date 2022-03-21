#include <stdio.h>
#include <time.h>

int partone_day(int year,int month,int day);
int long_day(int year,int now_year);
int thisyear_day(int now_year,int now_month,int now_day);

int main(void)
{
	int year,month,day,now_year,now_month,now_day,a,b,c,living_day;
	time_t timep;
	struct tm *p;
	
	time (&timep);
	p=gmtime(&timep);
	
	
	now_year=1900+p->tm_year;
	now_month=1+p->tm_mon;
	now_day=p->tm_mday;
	printf("Please enter your birthday:\n");
	scanf("%d %d %d",&year,&month,&day);
	printf("Your birthday is%d/%d/%d\n",year,month,day);
	printf("Today is %d/%d/%d\n",now_year,now_month,now_day);
/*	partone_day(year,month,day);
	printf("partone_day is %d\n",partone_day(year,month,day));
	long_day(year,now_year);
	printf("long_day is %d\n",long_day(year,now_year));
	thisyear_day(now_year,now_month,now_day);
	printf("thisyear_day is %d\n",thisyear_day(now_year,now_month,now_day));*/
	a=partone_day(year,month,day);
	b=long_day(year,now_year);
	c=thisyear_day(now_year,now_month,now_day);
	living_day=a+b+c;
	printf("恭喜你，你已在人类社会中生存了%d天\n",living_day);
	printf("距离你40岁仅剩%d天，你想好自己要做什么了吗？",14610-living_day);
	
	return 0;
 } 


/*计算第一年剩余天数*/
int partone_day(int year,int month,int day)
{
	const int moon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int partone_day=0;
	int i;
	
	for (i=0;i<month-1;i++)
	{ 
		partone_day+=moon[i];
	}
	partone_day=365-(partone_day+day);
	if (year%4==0&&year%100!=0||year%400==0)
		{if (month<2)
			partone_day=partone_day+1;
		}
	return partone_day;
}


/*计算中间年份的存活天数*/
int long_day(int year,int now_year)
{
	int long_day=0;
	
	long_day=(now_year-year-1)*365;
	int i=0,j=0;
	
	for (j=year+1;j<now_year;j++)
	{
		if (j%4==0&&j%100!=0||j%400==0)
		i+=1;
	}
	long_day+=i;
	
	return long_day; 
}


/*计算今年截至今天的天数*/ 
int thisyear_day(int now_year,int now_month,int now_day)
{
	const int moon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int thisyear_day=0;
	int i=0;
	
	for (i=0;i<now_month-1;i++){
		thisyear_day+=moon[i];
	}
	thisyear_day+=now_day;
	if (now_year%4==0&&now_year%100!=0||now_year%400==0)
		{if (now_month>2)
			thisyear_day+=1;
		}
	return thisyear_day;
}


