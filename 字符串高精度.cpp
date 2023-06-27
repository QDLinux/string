#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(const string a, const string b) {
    string sum;
    int carry = 0, i=0,j=0;//i = a.size() - 1, j = b.size() - 1;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
    while (i) {//i >= 0 || j >= 0 || carry > 0
        int ai = i >= 0 ? a[i--] - '0' : 0;
        int bj = j >= 0 ? b[j--] - '0' : 0;
        int s = ai + bj + carry;
        carry = s >= 10 ? 1 : 0;
        sum.push_back(s % 10 + '0');
    }

    reverse(sum.begin(), sum.end());
    return sum;
}

int main() {
    string a,b;
    cin>>a>>b;
    string c = add(a, b);
    cout << c << std::endl;

    return 0;
}


