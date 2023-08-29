#include<iostream>
#include<algorithm>
#include<cstring>
#include <fstream>
using namespace std;
const double N=1e9;
//const int B=2000;
//int a[N];
//.0int b1[B],b2[B],b3[B],b4[B],b5[B],b6[B];

int wei(long long x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x/=10;
	}
	return ans;
}
bool prime(int x)
{
	bool a=true;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			a=false;
			break;
		}
	}
	return a;
}
int main()
{
	ofstream fout("C:\\Users\\zhbing\\Desktop\\IDEA\\shiyan5\\1.in.txt");
	int idx=1;
	for(long long i=1;i<=100;i++)
	{
		/*int i1=i%10;
		int i2=i/10 %10;
		int i3=i/100 %10;
		int i4=i/1000 %10;
		int i5=i/10000 %10;
		int i6=i/100000 %10;
		int i7=i/1000000 %10;
		int i8=i/10000000 %10;
		int i9=i/100000000 %10;
		int i10=i/1000000000 %10;
		int i11=i/10000000000 %10;
		int i12=i/100000000000 %10;
		
		
		int w=wei(i);
		if(w==1)
		{
			fout<<i<<",";
		}
		else if(w==2)
		{
			if(abs(i1-i2)<=1)
			{
				fout<<i<<",";
		 	} 
		}
		else if(w==3)
		{
			if(abs(i1-i2)<=1&&abs(i2-i3)<=1)
		{
			fout<<i<<",";
		 } 
		}
		else if(w==4)
		{
			if(abs(i1-i2)<=1&&abs(i2-i3)<=1&&abs(i3-i4)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==5)
		{
			if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==6)
		{
			if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==7)
		{
				if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1
		&&abs(i6-i7)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==8)
		{
				if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1
		&&abs(i6-i7)<=1&&abs(i7-i8)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==9)
		{
				if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1
		&&abs(i6-i7)<=1&&abs(i7-i8)<=1&&abs(i8-i9)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==10)
		{
				if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1
		&&abs(i6-i7)<=1&&abs(i7-i8)<=1&&abs(i8-i9)<=1
		&&abs(i9-i10)<=1)
		{
			fout<<i<<",";
			
		 } 
		}
		else if(w==11)
		{
				if(abs(i1-i2)<=1&&abs(i2-i3)<=1
		&&abs(i3-i4)<=1&&abs(i4-i5)<=1&&abs(i5-i6)<=1
		&&abs(i6-i7)<=1&&abs(i7-i8)<=1&&abs(i8-i9)<=1
		&&abs(i9-i10)<=1&&abs(i10-i11)<=1)
		{
			fout<<i<<",";
			
		 } 
		}*/
		//if(prime(i)) fout<<i<<",";
		fout<<i<<" ";
		if(i%10==0) fout<<endl;
		
	}
	/*fout << "ans[] = {";
	
	fout << "}"
	/*int n;
	cin >>n;
	cout<<b[n];*/
	return 0;
} 
