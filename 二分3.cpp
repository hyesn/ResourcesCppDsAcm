#include <iostream>
using namespace std;

const int N = 1000010;

int q[N];

int findIndex(int q[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + right + 1 >> 1;
        
        if (q[mid] > mid) right = mid - 1;
		else left = mid; 
    }
    
    if(q[left]==left) return left;
    return -1; 
}

int main() {
    int x,index=0;
	while(cin>>x) q[index++]=x;
	int n=index;
    int result = findIndex(q, n);
    
    cout << result;
    return 0;
}

