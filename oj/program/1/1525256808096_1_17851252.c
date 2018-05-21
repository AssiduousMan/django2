#include<stdio.h>
void main()
{
	char a[3],b[3],c[3],t;
	int i=0,j=0;
	gets(a);
	gets(b);
	gets(c);

		for(i=1;i<3;i++)
		for(j=0;j<3-i;j++)
	{
		if(b[j]>b[j+1])
		{
			t=b[j];
			b[j]=b[j+1];
			b[j+1]=t;
		}
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
		if(c[j]>c[j+1])
		{
			t=c[j];
			c[j]=c[j+1];
			c[j+1]=t;
		}
	}
	
		for(i=0;i<3;i++)
			printf("%c ",a[i]);
			for(i=0;i<3;i++)
			printf("%c ",b[i]);
		printf("\n");
			for(i=0;i<3;i++)
			printf("%c ",c[i]);
		printf("\n");
	
}
