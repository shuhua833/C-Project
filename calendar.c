/*CALENDAR APPLICATION PROGRAM*/

#include<stdio.h>
#include<stdlib.h>
int first_weekday(int year);
int main()
{
system ("color 0D");
FILE *fp;
int year,day=0,dayInMonth,weekday=0;
int startingday,mname;
printf("Enter your desired year");
scanf("%d",&year);
char *month[]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthdays[]={31,28,31,30,31,30,31,31,30,31,30,31};
/* for leap year*/
if((year%4==0&&year%100!=0||year%400==0))
{
	monthdays[1]=29;
}
startingday=first_weekday(year); 
for(mname=0;mname<12;mname++)
{
	dayInMonth=monthdays[mname]+1;
	printf("\n\n \t-----------------------%s-----------------------",month[mname]);
	printf("\n \n\tsun\t mon\t tue\t wed\t thur\t fri\t sat\n");
	for(weekday=0;weekday<startingday;weekday++)
	{
		printf("        ");
	}
	for(day=1;day<dayInMonth;day++)
	{
		printf(" \t%3d",day);
		if(++weekday>6)
		{
			printf("\n");
			weekday=0;
		}
		startingday=weekday;
	}
}
fp=fopen("e://calendar.txt","a+");
fprintf(fp,"\n\n                                                             YEAR     %d",year);
startingday=first_weekday(year); 
for(mname=0;mname<12;mname++)
{
		dayInMonth=monthdays[mname]+1;
	fprintf(fp,"\n\n\t--------------------------------------%s-----------------------------------------",month[mname]);
	fputs("\n \n\tsun\t mon\t tue\t wed\t thur\t fri\t sat\n",fp);
		for(weekday=0;weekday<startingday;weekday++)
	{
		fprintf(fp,"\t   ");
	}
		for(day=1;day<dayInMonth;day++)
	{
		fprintf(fp," \t%3d",day);
		if(++weekday>6)
		{
			fprintf(fp,"\n");
			weekday=0;
		}
		startingday=weekday;
	}

}
fclose(fp);
return 0;
}
/*to get the first day of given year  */
int first_weekday(int year)
{
	int day;
	day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
	return day;
}
