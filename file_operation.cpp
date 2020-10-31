#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/time.h>
#include<unistd.h>
using namespace std;
int main()
{ 
	int i,j,k,t,n,u;
	FILE *f,*p;
	f=fopen("text.bin","wb+");
	i=100;
	fwrite(&i,sizeof(int),i,f);
	fclose(f);
	p=fopen("log.txt","w+");
	if(p)
	{
	fprintf(p,"PPID\t\tPID\t\tSECOND\t\tMILI-SECOND\t\tINITIAL\t\tFINAL\n");
	fclose(p);
	}
	for(i=0;i<=200;i++)
   	{
		struct timeval tv;
    		p=fopen("text.bin","rb+");
    		fread(&k,sizeof(int),1,p);
    		j=i+200;
    		fclose(f);
    		p=fopen("text.bin","wb+");
    		fwrite(&j,sizeof(int),1,p);
    		fclose(p);
    		p=fopen("text.bin","rb+");
    		fread(&u,sizeof(int),1,p);
			fclose(p);
			sleep(rand()%100);
			FILE *p;
			p=fopen("log.txt","a+");
			fprintf(p,"%u\t\t%u\t\t%d\t\t%d\t\t%d\t\t%d\n",getppid(),getpid(),tv.tv_sec,tv.tv_usec,k,u);
			fclose(p);
	}
	return 0;
}
