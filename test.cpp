#include <iostream>
using namespace std;

// 交换两个元素的位置
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 调整堆
void heapify(int arr[], int n, int i) {
    int largest = i; // 初始化最大元素为根节点
    int left = 2 * i + 1; // 左子节点的索引
    int right = 2 * i + 2; // 右子节点的索引

    // 如果左子节点大于根节点，则更新最大元素的索引
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于根节点，则更新最大元素的索引
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素的索引不是根节点，则交换根节点和最大元素
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 递归调整交换后的子树
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heapSort(int arr[], int n) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐个将堆顶元素移到末尾，并调整堆
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // 将当前最大元素移到末尾
        heapify(arr, i, 0); // 调整堆
    }
}

// 打印数组元素
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "原始数组: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "排序后的数组: ";
    printArray(arr, n);

    return 0;
}