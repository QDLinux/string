//#include<iostream>
//#include<cstring>
//using namespace std;
//const int MAXN = 300+4; //根据题目的最大值。+4为了防止A+B出现进位
//string s1;//char s1[MAXN] = {};//存储字符串
//string s2;//char s2[MAXN] = {};//存储字符串
//int tmp[MAXN] = {};//交换用字符串
//int a[MAXN] = {};//存储加数A
//int b[MAXN] = {};//存储加数B
//int c[MAXN] = {};//存储和B
//int compare(int a[], int b[]) {
//    //索引为0的数据为数组长度
//    if (a[0]>b[0]) {
//        return 1;
//    } else if (a[0]<b[0]) {
//        return -1;
//    }
// 
//    //逐位比较
//    for (int i=a[0]; i>0; i--) {
//        if (a[i]>b[i]) {
//            return 1;
//        } else if (a[i]<b[i]) {
//            return -1;
//        }
//    }
// 
//    return 0;
//}
// 
//void numcpy(int a[],int b[],int dest) {
//    //将数组右移，使两个数组右端对齐，形参q数组储存右移后的结果
//    for (int i=1;i<=a[0];i++) {
//        b[i+dest-1] =a[i];
//    }
//    b[0] = a[0]+dest-1;
//}
// 
//int main() {
//    scanf("%s %s", s1, s2);//读入字符串
// 
//    //处理负数
//    bool flaga = false;//乘数a的符号
//    if ('-'==s1[0]) {
//        flaga = true;
//        strcpy(s1, &s1[1]);//删除负号
//    }
//    bool flagb = false;//乘数b的符号
//    if ('-'==s2[0]) {
//        flagb = true;
//        strcpy(s2, &s2[1]);//删除负号
//    }
// 
//    //处理输出的负号
//    if (true==flaga && false==flagb) {
//        //商为负数
//        printf("-");
//    }
// 
//    //处理乘数1
//    int len = strlen(s1);
//    a[0] = len;
//    for (int i=0; i<len; i++) {
//        a[len-i]=s1[i]-'0';
//    }
// 
//    //处理乘数2
//    len = strlen(s2);
//    b[0] = len;
//    for (int i=0; i<len; i++) {
//        b[len-i]=s2[i]-'0';
//    }
// 
//    if (0==compare(a,b)) {
//        //两数相等
//        printf("1\n0\n");
//        return 0;
//    } else if (-1==compare(a,b)) {
//        //被除数小，除数大
//        printf("0\n");//输出除数
//        if (true==flaga) {
//            printf("-");
//        }
//        printf("%s\n", s1);
//        return 0;
//    } else {
//        c[0] = a[0]-b[0]+1;
//        for (int i=c[0]; i>0; i--) {
//            memset(tmp, 0, sizeof(tmp));
//            //高位对齐
//            numcpy(b,tmp,i);
// 
//            //
//            while (compare(a, tmp)>=0) {
//                c[i]++;
//                //减法
//                for (int j=1; j<=a[0]; j++) {
//                    if (a[j]<tmp[j]) {
//                        a[j+1]--;
//                        a[j]+=10;
//                    }
//                    a[j]-=tmp[j];
//                }
// 
//                int k=a[0];
//                while (a[k]==0) {
//                    k--;
//                }
//                a[0]=k;
//            }
//        }
// 
//        //控制最高位的0
//        while (c[0]>0 && c[c[0]]==0) {
//            c[0]--;
//        }
//    }
// 
//    //逆序打印输出商和余数
//    for (int i=c[0]; i>0; i--) {
//        printf("%d", c[i]);
//    }
//    printf("\n");
//    if (0==a[0]) {
//        printf("0\n");
//    } else {
//        if (true==flaga) {
//            printf("-");
//        }
//        for (int i=a[0]; i>0; i--) {
//            printf("%d", a[i]);
//        }
//        printf("\n");
//    }
// 
//    return 0;
//}
// 
//
// 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
vector<int> div(vector<int> &A,int b,int &r){  //r为余数 
	vector<int> C;
	for(int i=A.size()-1;i>=0;i--){   //从位数高到低的顺序遍历 
		r=r*10+A[i];
		C.push_back(r/b);             //C数组下标越大，位数越低        
		r%=b;
	}
	reverse(C.begin(),C.end());        //翻转C，使得C数组下标越大，位数越高
	
	while(C.size()>1&&C.back()==0)C.pop_back();   //去除最高位的0 
	return C;
}
 
int main(){
	string a;
	int b,r=0;
	cin>>a>>b;
	
	vector<int> A,C;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');  //A数组下标越大，位数越高 
	
	C=div(A,b,r);
	
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
	cout<<endl;
	cout<<r;
	return 0;
} 
