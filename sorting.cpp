#include <iostream>
using namespace std;

const int N = 1000010;

int q[N];

void bubble_sort(int q[], int n)
{
    for (int i = n-1; i >= 1; i -- )
    {
        bool flag = true;
        for (int j = 1; j <= i; j ++ )
            if (q[j-1] > q[j])
            {
                swap(q[j-1], q[j]);
                flag = false;
            }
        if (flag) return;
    }
}

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);
    
    int k = 0;
    int i = l, j = mid + 1;
    int temp[N];
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) 
            temp[k++] = a[i++];
        else 
            temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    
    k = 0;
    for (int i = l; i <= r; i++) {
        a[i] = temp[k++];
    }
}
 

int main()
{
//    int n;
//    cin>>n; 

//    for (int i = 0; i < n; i ++ ) cin>>q[i];
	int x,index=0;
	while(cin>>x) q[index++]=x;
	int n=index;
	
    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) cout<<q[i]<<" ";

    return 0;
}

