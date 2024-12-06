#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string& s1,const string& s2) {
    int sum=0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int len=max(s1.length(),s2.length());
    int k=len-1;
	string result(len, '0');
	    
    while (i >= 0 || j >= 0) {
        if (i >= 0) sum += s1[i--] - '0';
        if (j >= 0) sum += s2[j--] - '0';
        result[k--] = sum % 10 + '0';
        sum/=10;
    }
    
    if(sum!=0) result=to_string(sum)+result;
    
    return result;
}

string subtract(const string& s1,const string& s2) {
    string result(s1.length(), '0');
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
        result[i--]=diff+'0';
    }
        
    int k=0;
    while(k<result.length()-1&&result[k]=='0'){
        k++;
	}
	result=result.substr(k,result.length());
	
    return result;
}

string multiply(const string& s1,const string& s2) {
	int len=s1.length() + s2.length();
    string result(len, '0');

    for (int i = s1.length() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = s2.length() - 1; j >= 0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0') + carry + (result[i + j + 1] - '0');
            result[i + j + 1] = mul % 10 + '0';
            carry = mul / 10;
        }
        result[i] += carry;
    }
    
    int k=0;
    while(k<result.length()-1&&result[k]=='0'){
        k++;
	}
	result=result.substr(k,result.length());
	
    return result;
}

int compare(const string& s1, const string& s2) {
    if (s1.size() > s2.size()) return 1;
    if (s1.size() < s2.size()) return -1;
    return s1.compare(s2);
}
string divide(const string& s1,const string& s2) {
    string quotient;
    string remainder;

    for (int i = 0; i < s1.length(); ++i) {
        remainder = add(multiply(remainder,"10"),string(1, s1[i]));
        int count = 0;
        while (compare(remainder,s2)>=0) {
            remainder = subtract(remainder,s2);
            ++count;
        }
        quotient = add(multiply(quotient,"10"),to_string(count));
    }

    return quotient;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<divide(a,b);
}
