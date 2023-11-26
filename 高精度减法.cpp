#include<iostream>
#include<vector>
using namespace std;
 
//比较A和B的大小，如果A>=B,那么返回true 
bool cmp(vector<int> &A,vector<int> &B){  
 
    //先比较A和B的位数。如果A的最高位高于B的最高位，那么A>B,返回true  
	if(A.size()!=B.size())return A.size()>B.size();
	
	//从A、B的最高位开始比较 
	for(int i=A.size()-1;i>=0;i--)
		if(A[i]!=B[i])return A[i]>B[i];
	
	//如果A=B，那么返回true 
	return true;
}
 
//计算A-B的值C 
vector<int> sub(vector<int> &A,vector<int> &B){
	vector<int> C;  
	int t=0;       //存储当前位数的计算结果 
	
	for(int i=0;i<A.size();i++){
		t+=A[i];                 
		if(i<B.size())t-=B[i];
	//这两行计算t=a[i]-b[i]+t	
		
		C.push_back((t+10)%10);  //+10是考虑到t为负数时的情况 
		if(t<0)t=-1;             //如果t<0，那么需要借位，即高位数-1 
		else t=0;                //如果t>=0，那么无需借位 
	} 
	
   //去除答案中处于最高位的0 
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}

void solve()
{
	//输入大整数 
	string a,b;
	cin>>a>>b;
	
	vector<int> A,B,C;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	
	//比较A和B的大小 
	if(cmp(A,B))C=sub(A,B);
	else{                     
		C=sub(B,A);        //如果A<B,则将B减去A 
		cout<<'-';         //并在结果前添加负号 
	}
	
	//输出结果 
	for(int i=C.size()-1;i>=0;i--)
	{
		cout<<C[i];
	}
	cout<<endl;
} 
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
