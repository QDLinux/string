#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int len=1,t[10001],ans[10001],anslen,n;
void cheng(int v)
{
    for(int i=1;i<=len;i++)
    {
    	t[i]*=v;
	}
    
    int i=1;
    while(t[i]>9||i<len)
    {
        t[i+1]+=t[i]/10;
        t[i]%=10;
        i++;
    }
    len=i;
}
void jia()
{
    for(int i=1;i<=len;i++)
    {
        ans[i]+=t[i];
        if(ans[i]>9)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
            anslen=max(anslen,i+1);
        }
        anslen=max(anslen,i);
    }
}
int main()
{
    cin >> n; 
    t[len]=1;
    for(int i=1;i<=n;i++)
    {
    	cheng(i);
		jia();
	}
    
    for(int i=anslen;i>=1;i--)
    {
    	cout<<ans[i];
	}
    
    return 0;
}
