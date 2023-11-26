#include<iostream>
#include<vector>
using namespace std;
 
//�Ƚ�A��B�Ĵ�С�����A>=B,��ô����true 
bool cmp(vector<int> &A,vector<int> &B){  
 
    //�ȱȽ�A��B��λ�������A�����λ����B�����λ����ôA>B,����true  
	if(A.size()!=B.size())return A.size()>B.size();
	
	//��A��B�����λ��ʼ�Ƚ� 
	for(int i=A.size()-1;i>=0;i--)
		if(A[i]!=B[i])return A[i]>B[i];
	
	//���A=B����ô����true 
	return true;
}
 
//����A-B��ֵC 
vector<int> sub(vector<int> &A,vector<int> &B){
	vector<int> C;  
	int t=0;       //�洢��ǰλ���ļ����� 
	
	for(int i=0;i<A.size();i++){
		t+=A[i];                 
		if(i<B.size())t-=B[i];
	//�����м���t=a[i]-b[i]+t	
		
		C.push_back((t+10)%10);  //+10�ǿ��ǵ�tΪ����ʱ����� 
		if(t<0)t=-1;             //���t<0����ô��Ҫ��λ������λ��-1 
		else t=0;                //���t>=0����ô�����λ 
	} 
	
   //ȥ�����д������λ��0 
	while(C.size()>1&&C.back()==0)C.pop_back();
	return C;
}

void solve()
{
	//��������� 
	string a,b;
	cin>>a>>b;
	
	vector<int> A,B,C;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
	
	//�Ƚ�A��B�Ĵ�С 
	if(cmp(A,B))C=sub(A,B);
	else{                     
		C=sub(B,A);        //���A<B,��B��ȥA 
		cout<<'-';         //���ڽ��ǰ��Ӹ��� 
	}
	
	//������ 
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
