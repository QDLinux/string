#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e4 + 10;
int a[N], b[N], c[N];
string s1, s2;
bool cmp()
{
	if(s1.length() != s2.length()) 
		return s1.length() > s2.length();
	for(int i = 0; i < s1.length(); i++)
	{
		if(s1[i] != s2[i]) return s1[i] > s2[i];
	}
	return true;
}

int main()
{    
	int n;
	cin >> n;
	while(n--)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		cin >> s1 >> s2;
		int len1 = s1.length(), len2 = s2.length();
		int len3 = max(len1, len2);
		int flag = 0;
		if(!cmp())
		{
			flag = 1;
			swap(s1, s2);
		}
		for(int i = 1; i <= len1; i++)
		{
			a[i] = s1[len1 - i] - '0';
		}

		for(int i = 1; i <= len2; i++)
		{
			b[i] = s2[len2 - i] - '0';
		}
		
//		for(int i = 1; i <= len3; i++)
//		{
//			if(a[i] < b[i])
//			{
//				a[i + 1]--;
//				a[i] += 10;
//			}
//			c[i] += a[i] - b[i];
//		}
		int t=0;       //存储当前位数的计算结果 
	
		for(int i=1;i<=len3;i++){
			t+=a[i];                 
			if(i<b.size())t-=b[i];
		//这两行计算t=a[i]-b[i]+t	
			
			c[i]=(t+10)%10;  		 //+10是考虑到t为负数时的情况 
			if(t<0)t=-1;             //如果t<0，那么需要借位，即高位数-1 
			else t=0;                //如果t>=0，那么无需借位 
		} 
		
		while(!c[len3] && len3 > 1) len3--;
		if(flag) cout << "-";
		for(int i = len3; i >= 1; i--)
		{
			cout << c[i];
		}
		cout << '\n';
	}	
	return 0;
 }

