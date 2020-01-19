#include <stdio.h>

void init(int* result,int Size)
{
	int i;
	for(i=0;i<Size;i++)
		result[i]=0;
}
int c[10][1000000];
int multiply(int a[],int a_size,int b[],int b_size)
{
	int i,j;
	for(i=0;i<a_size;i++)
		init(c[i],1e6);
	int carry=0;
	
	for(i=0;i<a_size;i++)
	{
		carry=0;
		for(j=0;j<i;j++)
			c[i][j]=0;
		for(j=0;j<b_size;j++)
		{
			int x=a[i]*b[j]+carry;
			c[i][i+j]=x%10;
			carry=x/10;
		}
		if(carry!=0)
			c[i][i+b_size]=carry;
		else
			c[i][i+b_size]=0;
	}
	int last=0;
	carry=0;
	for(i=0;i<1e6;i++)
	{
		b[i]=0;
		int x=carry;
		for(j=0;j<a_size;j++){
			x+=c[j][i];
		}
		b[i]=x%10;
		carry=x/10;
		if(b[i]!=0){
			last=i;
		}
	}
	return last+1;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[100];
	int copy;
	int idx=0;
	int result[1000000];
	init(result,1e6);
	result[0]=1;
	int last=1;
	for(j=1;j<=n;j++)
	{
		copy=j;
		idx=0;
		for(i=0;copy!=0;i++)
		{
			a[idx]=copy%10;
			copy/=10;
			idx++;
		}
		last=multiply(a,idx,result,last);
	}
	int flag=0;
	for(i=1000000-1;i>=0;i--)
	{
		if(result[i]!=0)
		{
			flag=1;
		}
		if(flag==1)
			printf("%d",result[i]);
	}

	return 0;
}
