/*NAME: Suraj Modi
ROLL NO: 17CS8020*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
char str[100];
int s;
int ans1=0,ans2=0;
void *addexp( void *ptr );

int main()
{
     pthread_t thread1, thread2;
     int one=0,two;
     int  i,iret1, iret2;

    /* Create independent threads each of which will execute function */
	scanf("%s",str);
	int cnt=1;
	for(i=0;str[i];i++)
	{
		if(!(str[i]>='0'&& str[i]<='9'))
			cnt++;
	}
	//printf("%d %d",cnt,c);
	int c=cnt/2,c2=1;
	s=c;
	//printf("%d %d",cnt,c);
	for(i=0;str[i]&& c2<=c;i++)
	{
		if(!(str[i]>='0'&& str[i]<='9'))
			c2++;
	}
	two=i;

     iret1 = pthread_create( &thread1, NULL, addexp, (void*) (&one));
     iret2 = pthread_create( &thread2, NULL, addexp, (void*) (&two));

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 
	printf("Sum of the first half is %d\nSum of the second half is %d\n",ans1,ans2);
	printf("total sum %d\n",ans1+ans2);
     
     exit(0);
}

void *addexp( void *ptr )
{
     int *i=(int*)ptr;
	int temp=*i;
	int j,cnt=1,num=0;
	int flag=0;
	if(temp>0 && !(str[temp-1]>='0'&& str[temp-1]<='9'))
	{
		if(str[temp-1]=='+')
			flag=0;
		else
			flag=1;
	}
	//printf("%d  %d\n",temp,*i);
   	if(*i==0)
	{
		for(j=0;str[j]&& cnt<=s;j++)
		{
			if(!(str[j]>='0'&& str[j]<='9'))
			{
				if(flag==0)
					ans1+=num;
				else
					ans1-=num;

				num=0;
				cnt++;
				if(str[j]=='+')
					flag=0;
				else
					flag=1;
			}
			else
			{
				num=num*10+(str[j]-'0');
			}
		}
		if(flag==0)
			ans1+=num;
		else
			ans1-=num;
	}
	else
	{
		j=temp;
		for( ;str[j] ;j++)
		{
			if(!(str[j]>='0'&& str[j]<='9'))
			{
				if(flag==0)
					ans2+=num;
				else
					ans2-=num;

				num=0;
				//cnt++;
				if(str[j]=='+')
					flag=0;
				else
					flag=1;
			}
			else
			{
				num=num*10+(str[j]-'0');
			}
		}
		if(flag==0)
			ans2+=num;
		else
			ans2-=num;
	}
}
