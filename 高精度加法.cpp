#include<iostream>
#include<vector>
using namespace std;
vector<int> A,B,C;
const int N=1e3+5;
int a1[N],b1[N],c1[N];
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.length(),l2=s2.length();
	int l3=max(l1,l2);
	for(int i=1;i<=l1;i++)
	{
		a1[i]=s1[l1-i]-'0';
	}
	for(int i=1;i<=l2;i++)
	{
		b1[i]=s2[l2-i]-'0';
	}
	
	for(int i=1;i<=l3;i++)
	{
		c1[i]+=a1[i]+b1[i];
		c1[i+1]+=c1[i]/10;
		c1[i]%=10;
	}
	while(!c1[l3] && l3>1) l3--;//去前导0
	for(int i=l3;i>=1;i--)
	{
		cout<<c1[i];
	}
	return 0;
}
//void add(){
//	int t=0;         //用t存储当前计算的值 
//	
//	for(int i=0;i<A.size()||i<B.size();i++){ 
//		if(i<A.size())t+=A[i];
//		if(i<B.size())t+=B[i];
//		C.push_back(t%10);
//		t/=10;
//	} 
//	if(t)C.push_back(t);   //如果t不为0，则进一位 
//	//return C;
//}
// 
//int main(){
//	//输入大整数
//	string a,b;
//	cin>>a>>b;
//	
//	//将大整数按位存储到数组中
//	
//	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');  //注意字符串和数字间的转化 
//	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
//	
//	add();
//	int idx=C.size()-1;
//	for(int i=C.size()-1;i>=0;i--)
//	{
//		if( C[i]!=0 ) 
//		{
//			idx=i;
//			break;
//		}
//	}
//	for(int i=idx;i>=0;i--)
//	{
//		cout<<C[i];
//	}
//	cout<<endl;
//	return 0;
//}




