#include <iostream>
#include <vector>
using namespace std;

// 辅助函数，用于将存储在 vector 中的划分结果以 a+b+c 的格式输出到控制台
void printPartition(const vector<int>& partition) {
    // 遍历存储划分结果的向量
    for (size_t i = 0; i < partition.size(); ++i) {
        // 如果不是第一个元素，先输出一个加号
        if (i > 0) {
            cout << "+";
        }
        // 输出当前元素
        cout << partition[i];
    }
    // 输出完一个划分结果后换行
    cout << endl;
}

// 递归函数，用于生成整数 n 的所有划分结果
// n 表示当前需要进行划分的整数
// maxPart 表示当前划分中允许使用的最大数，确保划分结果是不递增的
// currentPartition 是一个向量，用于存储当前正在生成的划分结果
// count 是一个引用类型的变量，用于记录划分结果的总数
void partition(int n, int maxPart, vector<int>& currentPartition, int& count) {
    // 当 n 为 0 时，说明已经完成了一个有效的划分
    if (n == 0) {
        // 调用 printPartition 函数输出这个划分结果
        printPartition(currentPartition);
        // 划分结果总数加 1
        count++;
        return;
    }
    // 从 min(maxPart, n) 开始递减到 1，尝试将每个数作为当前划分的一部分
    for (int i = min(maxPart, n); i >= 1; --i) {
        // 将当前数 i 加入到当前划分结果中
        currentPartition.push_back(i);
        // 递归调用 partition 函数，处理剩余的数 n - i
        // 同时更新 maxPart 为 i，保证后续划分使用的数不大于当前数 i
        partition(n - i, i, currentPartition, count);
        // 回溯操作，移除刚刚添加的数 i，以便尝试下一个可能的划分
        currentPartition.pop_back();
    }
}

// 包装函数，用于初始化整数划分的过程
// n 是要进行划分的整数
void partition(int n) {
    // 用于存储当前正在生成的划分结果
    vector<int> currentPartition;
    // 初始化划分结果的计数器
    int count = 0;
    // 调用递归函数开始生成整数 n 的划分结果
    // 初始时允许使用的最大数为 n
    partition(n, n, currentPartition, count);
    // 输出整数 n 的划分结果总数
    cout << "整数 " << n << " 的划分一共有 " << count << " 种。" << endl;
}

int main() {
    // 要进行划分的整数
    int num = 8;
    // 提示信息，表明接下来将输出整数 8 的所有划分结果
    cout << "整数 " << num << " 的所有划分结果如下：" << endl;
    // 调用 partition 函数生成并输出整数 8 的划分结果及总数
    partition(num);
    return 0;
}