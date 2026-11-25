#include <iostream>
#include <vector>
using namespace std;

// 调整堆，确保满足堆性质
void SiftDown(vector<int>& arr, int i, int n) {
    int largest = i;        // 初始化最大元素为根节点
    int left = 2 * i + 1;   // 左子节点索引
    int right = 2 * i + 2;  // 右子节点索引

    // 如果左子节点存在且大于根节点
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点存在且大于当前最大节点
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大元素不是根节点，则交换并递归调整
    if (largest != i) {
        swap(arr[i], arr[largest]);
        SiftDown(arr, largest, n);
    }
}

// 非递归的调整堆
// Q: 修改函数nonRecSiftDown中的代码，实现排序后的数按降序排列。
void nonRecSiftDown(vector<int>& arr, int start, int n) {
  int i = start, j = 2 * i + 1;
  int temp = arr[i];

  while (j < n){
    if (j+1 < n && arr[j] > arr[j + 1])
      j++;
    if (temp <= arr[j]) break;
    else {
      arr[i] = arr[j];
      i = j;
      j = 2 * i + 1;
    }
  }
  arr[i] = temp;
}

// 堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--) {
      nonRecSiftDown(arr, i, n);
    }

    // 逐个提取堆顶元素（最大值）并调整堆
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // 将当前最大值移到数组末尾
        nonRecSiftDown(arr, 0, i);    // 调整剩余元素为最大堆
    }
}

// 打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 主函数 - 测试堆排序
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7, 64, 34, 25};

    cout << "原始数组: ";
    printArray(arr);

    heapSort(arr);

    cout << "排序后数组: ";
    printArray(arr);

    return 0;
}
