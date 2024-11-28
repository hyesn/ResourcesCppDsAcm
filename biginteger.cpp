#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string& s1,const string& s2) {
    string result;
    int sum=0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
        
    while (i >= 0 || j >= 0 || sum) {
        if (i >= 0) sum += s1[i--] - '0';
        if (j >= 0) sum += s2[j--] - '0';
        result += to_string(sum % 10);
        sum/=10;
    }
        
    reverse(result.begin(), result.end());
    return result;
}

string subtract(const string& s1,const string& s2) {
    string result;
    int borrow = 0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
        
    while (i >= 0) {
        int diff = s1[i] - '0' - borrow;
        if (j >= 0) diff -= s2[j--] - '0';
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += to_string(diff);
        i--;
    }
        
    int len=result.length()-1;
    while(len>0&&result[len]=='0'){
        result.erase(len--);
	}
    reverse(result.begin(), result.end());
    return result;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<add(a,b)<<endl<<subtract(a,b) ;
}
