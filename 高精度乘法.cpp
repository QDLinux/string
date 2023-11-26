#include<bits/stdc++.h>
using namespace std;
const int N = 3000;
int x[N],y[N];
string c;
string a,b;
int num;
void mults()
{ 
	num = a.size()+b.size()-1;
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<=i;j++)c[i] += x[j]*y[i-j];
		if(c[i]>=10)
		{
			c[i + 1] += c[i] / 10;
      		c[i] %= 10;	
		}
	}
	//去掉多余的前导零 
	for(int i=num;i>0;i--)
	{
		if(c[i] == 0)num--;
		else break;
	}
}
int main()
{
	cin>>a>>b;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(int i =a.size()-1;i>=0;i--)	x[a.size()-1-i]=a[i] -'0'; 	
	
	for(int i= b.size()-1;i>=0;i--) y[b.size()-1-i]=b[i] -'0'; 
	
	mults();
	
	for(int i=num;i>=0;i--)	 printf("%d",c[i]);
	return 0;
	
} 
