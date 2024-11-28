#include <iostream>
using namespace std;

// ��ŵ���ݹ麯��
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "������ 1 �� " << source << " �ƶ��� " << target << endl;
        return;
    }
    // �� n-1 �����Ӵ�Դ���ƶ���������
    hanoi(n - 1, source, auxiliary, target);
    // ���� n �����Ӵ�Դ���ƶ���Ŀ���
    cout << "������ " << n << " �� " << source << " �ƶ��� " << target << endl;
    // �� n-1 �����ӴӸ������ƶ���Ŀ���
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int num;
    cout << "���������ӵ�����: ";
    cin >> num;

    cout << "��ŵ���ƶ���������: " << endl;
    hanoi(num, 'A', 'C', 'B'); // A: Դ��, C: Ŀ���, B: ������

    return 0;
}

