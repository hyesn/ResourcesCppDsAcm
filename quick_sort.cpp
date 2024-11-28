#include <iostream>
using namespace std;

const int N = 1000010;

int q[N];

void bubble_sort()
{
    for (int i = n-1; i >= 1; i -- )
    {
        bool flag = true;
        for (int j = 1; j <= i; j ++ )
            if (a[j-1] > a[j])
            {
                swap(a[j-1], a[j]);
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

int main()
{
    int n;
    cin>>n; 

    for (int i = 0; i < n; i ++ ) cin>>q[i];

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) cout<<q[i];

    return 0;
}

