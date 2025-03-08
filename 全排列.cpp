#include <iostream>
#include <vector>
using namespace std;

// �������������ڽ��洢�� vector �еĻ��ֽ���� a+b+c �ĸ�ʽ���������̨
void printPartition(const vector<int>& partition) {
    // �����洢���ֽ��������
    for (size_t i = 0; i < partition.size(); ++i) {
        // ������ǵ�һ��Ԫ�أ������һ���Ӻ�
        if (i > 0) {
            cout << "+";
        }
        // �����ǰԪ��
        cout << partition[i];
    }
    // �����һ�����ֽ������
    cout << endl;
}

// �ݹ麯���������������� n �����л��ֽ��
// n ��ʾ��ǰ��Ҫ���л��ֵ�����
// maxPart ��ʾ��ǰ����������ʹ�õ��������ȷ�����ֽ���ǲ�������
// currentPartition ��һ�����������ڴ洢��ǰ�������ɵĻ��ֽ��
// count ��һ���������͵ı��������ڼ�¼���ֽ��������
void partition(int n, int maxPart, vector<int>& currentPartition, int& count) {
    // �� n Ϊ 0 ʱ��˵���Ѿ������һ����Ч�Ļ���
    if (n == 0) {
        // ���� printPartition �������������ֽ��
        printPartition(currentPartition);
        // ���ֽ�������� 1
        count++;
        return;
    }
    // �� min(maxPart, n) ��ʼ�ݼ��� 1�����Խ�ÿ������Ϊ��ǰ���ֵ�һ����
    for (int i = min(maxPart, n); i >= 1; --i) {
        // ����ǰ�� i ���뵽��ǰ���ֽ����
        currentPartition.push_back(i);
        // �ݹ���� partition ����������ʣ����� n - i
        // ͬʱ���� maxPart Ϊ i����֤��������ʹ�õ��������ڵ�ǰ�� i
        partition(n - i, i, currentPartition, count);
        // ���ݲ������Ƴ��ո���ӵ��� i���Ա㳢����һ�����ܵĻ���
        currentPartition.pop_back();
    }
}

// ��װ���������ڳ�ʼ���������ֵĹ���
// n ��Ҫ���л��ֵ�����
void partition(int n) {
    // ���ڴ洢��ǰ�������ɵĻ��ֽ��
    vector<int> currentPartition;
    // ��ʼ�����ֽ���ļ�����
    int count = 0;
    // ���õݹ麯����ʼ�������� n �Ļ��ֽ��
    // ��ʼʱ����ʹ�õ������Ϊ n
    partition(n, n, currentPartition, count);
    // ������� n �Ļ��ֽ������
    cout << "���� " << n << " �Ļ���һ���� " << count << " �֡�" << endl;
}

int main() {
    // Ҫ���л��ֵ�����
    int num = 8;
    // ��ʾ��Ϣ��������������������� 8 �����л��ֽ��
    cout << "���� " << num << " �����л��ֽ�����£�" << endl;
    // ���� partition �������ɲ�������� 8 �Ļ��ֽ��������
    partition(num);
    return 0;
}
