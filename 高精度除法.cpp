//#include<iostream>
//#include<cstring>
//using namespace std;
//const int MAXN = 300+4; //������Ŀ�����ֵ��+4Ϊ�˷�ֹA+B���ֽ�λ
//string s1;//char s1[MAXN] = {};//�洢�ַ���
//string s2;//char s2[MAXN] = {};//�洢�ַ���
//int tmp[MAXN] = {};//�������ַ���
//int a[MAXN] = {};//�洢����A
//int b[MAXN] = {};//�洢����B
//int c[MAXN] = {};//�洢��B
//int compare(int a[], int b[]) {
//    //����Ϊ0������Ϊ���鳤��
//    if (a[0]>b[0]) {
//        return 1;
//    } else if (a[0]<b[0]) {
//        return -1;
//    }
// 
//    //��λ�Ƚ�
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
//    //���������ƣ�ʹ���������Ҷ˶��룬�β�q���鴢�����ƺ�Ľ��
//    for (int i=1;i<=a[0];i++) {
//        b[i+dest-1] =a[i];
//    }
//    b[0] = a[0]+dest-1;
//}
// 
//int main() {
//    scanf("%s %s", s1, s2);//�����ַ���
// 
//    //������
//    bool flaga = false;//����a�ķ���
//    if ('-'==s1[0]) {
//        flaga = true;
//        strcpy(s1, &s1[1]);//ɾ������
//    }
//    bool flagb = false;//����b�ķ���
//    if ('-'==s2[0]) {
//        flagb = true;
//        strcpy(s2, &s2[1]);//ɾ������
//    }
// 
//    //��������ĸ���
//    if (true==flaga && false==flagb) {
//        //��Ϊ����
//        printf("-");
//    }
// 
//    //�������1
//    int len = strlen(s1);
//    a[0] = len;
//    for (int i=0; i<len; i++) {
//        a[len-i]=s1[i]-'0';
//    }
// 
//    //�������2
//    len = strlen(s2);
//    b[0] = len;
//    for (int i=0; i<len; i++) {
//        b[len-i]=s2[i]-'0';
//    }
// 
//    if (0==compare(a,b)) {
//        //�������
//        printf("1\n0\n");
//        return 0;
//    } else if (-1==compare(a,b)) {
//        //������С��������
//        printf("0\n");//�������
//        if (true==flaga) {
//            printf("-");
//        }
//        printf("%s\n", s1);
//        return 0;
//    } else {
//        c[0] = a[0]-b[0]+1;
//        for (int i=c[0]; i>0; i--) {
//            memset(tmp, 0, sizeof(tmp));
//            //��λ����
//            numcpy(b,tmp,i);
// 
//            //
//            while (compare(a, tmp)>=0) {
//                c[i]++;
//                //����
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
//        //�������λ��0
//        while (c[0]>0 && c[c[0]]==0) {
//            c[0]--;
//        }
//    }
// 
//    //�����ӡ����̺�����
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
 
vector<int> div(vector<int> &A,int b,int &r){  //rΪ���� 
	vector<int> C;
	for(int i=A.size()-1;i>=0;i--){   //��λ���ߵ��͵�˳����� 
		r=r*10+A[i];
		C.push_back(r/b);             //C�����±�Խ��λ��Խ��        
		r%=b;
	}
	reverse(C.begin(),C.end());        //��תC��ʹ��C�����±�Խ��λ��Խ��
	
	while(C.size()>1&&C.back()==0)C.pop_back();   //ȥ�����λ��0 
	return C;
}
 
int main(){
	string a;
	int b,r=0;
	cin>>a>>b;
	
	vector<int> A,C;
	for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');  //A�����±�Խ��λ��Խ�� 
	
	C=div(A,b,r);
	
	for(int i=C.size()-1;i>=0;i--)cout<<C[i];
	cout<<endl;
	cout<<r;
	return 0;
} 
