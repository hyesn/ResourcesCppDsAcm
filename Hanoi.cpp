#include <iostream>
using namespace std;

// 汉诺塔递归函数
void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "将盘子 1 从 " << source << " 移动到 " << target << endl;
        return;
    }
    // 将 n-1 个盘子从源杆移动到辅助杆
    hanoi(n - 1, source, auxiliary, target);
    // 将第 n 个盘子从源杆移动到目标杆
    cout << "将盘子 " << n << " 从 " << source << " 移动到 " << target << endl;
    // 将 n-1 个盘子从辅助杆移动到目标杆
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int num;
    cout << "请输入盘子的数量: ";
    cin >> num;

    cout << "汉诺塔移动步骤如下: " << endl;
    hanoi(num, 'A', 'C', 'B'); // A: 源杆, C: 目标杆, B: 辅助杆

    return 0;
}

