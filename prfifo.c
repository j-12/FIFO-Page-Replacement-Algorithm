#include<stdio.h>
#include<stdlib.h>

int isExist(int n,int ar[3][2])
{
	int i;
	for(i=0;i<3;i++)
	{
		if(ar[i][0]==n)
			return 1;
	}
	return 0;
}
	
int main(int argc,char *argv)
{

	int i1,l1,k1,j,ph=0,pf=0,i,p[3][2],pc,k;
	int a[20]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}; //printf("Enter order: ");
	for(i=0;i<3;i++)
	{
		p[i][1]=0;
		p[i][0]=-1;
	}
	
	i=0;
	pc=0;
	
	while(i<20)
	{
		
		if(pc==0)
		{
			p[pc][0]=a[i];
			pc++;
			i++;
			pf++;
		}
	
		else if(isExist(a[i],p))
		{
			i++;
			ph++;
		}	
		else if(pc!=2 && !isExist(a[i],p))
		{
			p[pc][0]=a[i];
			pc++;
			i++;
			pf++;
		}
		else if(pc==2 && !isExist(a[i],p))
		{
			l1=p[0][1];
			k1=0;
			for(i1=1;i1<3;i1++)
			{
				if(l1<p[i1][1])
				{
					l1=p[i1][1];
					k1=i1;
				}
			}
		
			p[k1][0]=a[i];
			p[k1][1]=0;
			i++;
			pc=2;
			pf++;
		}



		for(j=0;j<3;j++)
		{
			if(p[j][0]!=-1)		
				p[j][1]++;
		}
			
	}

	printf("Page hit: %d",ph);
	printf("Page fault: %d",pf);

	return 0;

}

/*-----OUTPUT-----
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ gcc prfifo.c -o fifo
student@student-HP-ProOne-400-G1-AiO:~/Desktop$ ./fifo
Page hit: 5 Page fault: 15 student@student-HP-ProOne-400-G1-AiO:~/Desktop$ */
