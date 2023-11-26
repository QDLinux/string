#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> a,b,c;
vector<int> mul(){
    vector<int> c(a.size()+b.size()+10,0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++)
        c[i+j]+=a[i]*b[j];
    }
    int sum=0;
    for(int i=0;i<c.size();i++){
        sum+=c[i];
        c[i]=sum%10;
        sum/=10;
    }
    
    while(c.size()>1&&c.back()==0)
	{
		c.pop_back();
	}
    return c;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    
    for(int i=s1.size()-1;i>=0;i--)
	{
		a.push_back(s1[i]-'0');
	}
    for(int i=s2.size()-1;i>=0;i--)
	{
		b.push_back(s2[i]-'0');
	}
	
	c=mul();
    for(int i=c.size()-1;i>=0;i--)
	{
		cout<<c[i];
	}
}

