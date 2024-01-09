#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1010;
int a[MAX],b[MAX],ans[MAX];
bool judge(int* a,int* b,int len){ //判断len长度的 b 是否可以被 a 除  
	if(a[len]>0) return true; //如果 a 比 b 长, 一定可以除 
	for(int i=len-1;i>=0;i--){//从 a 的最高位开始比 
		if(a[i]>b[i]) return true;//除去相等位的最高位大于b,说明a比b大,可以除 
		else if(a[i]<b[i]) return false;//除去相等位的最高位小于b,说明a比b小，不可以除 
	}
	return true;//a和b完全一样,可以除 
}
void solve()
{
	string s1,s2;
	
	int i,j,len1,len2,len;
	cin>>s1>>s2;
	
//	if(s2=="0"){//除数不能为0 
//		cout<<"除数不能为0"<<endl;
//		return 0; 
//	}
	
	len1=s1.length();//计算 a和 b的长度 
	len2=s2.length();
	len=len1-len2; //结果最开始的下标 
	
	for(i=0;i<len1;i++) a[i]=s1[len1-1-i]-'0';//字符型转int型 
	for(i=0;i<len2;i++) b[i]=s2[len2-1-i]-'0';
	
	for(i=len1-len2;i>=0;i--){
		while(judge(a+i,b,len2))
		{//当a可以被b减的时候一直进行，直到不能被减,即得到最终的商 
			ans[i]++; //记录a被b减的次数，即为除法的结果 
			for(j=0;j<=len2-1;j++)
			{//高精度减法的实现方法 
				if(a[i+j]<b[j])
				{
					a[i+j+1]--;
					a[i+j]+=10;
				}
				a[i+j]-=b[j];
			}
		}
	}
	
	while(a[len1]==0&&len1>0) len1--;//去掉前缀无用的零 
	while(ans[len]==0&&len>0) len--;
	
	for(i=len;i>=0;i--)
	{
		cout<<ans[i];//输出结果 
	}
	if(len<0) cout<<"0";//当被除数短于除数时,len<0不进行上一条语句,单独输出一个零 
//	if(len_a>1||a[0]>0){
//		//a最后没有减完的部分成为余数，余数为0就不输出 
//		cout<<"余";
//		for(i=len_a;i>=0;i--) cout<<a[i];
//	} 
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(ans,0,sizeof(ans));
		solve();
	}
	return 0;
}

