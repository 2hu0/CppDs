#include <iostream>

void swap(int* a, int i, int j) {
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}
//冒泡排序
void bubbleSort(int* a, int len) {
    for (int i = len - 1; i > 0; i--) {
        bool isSwap = false;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
                isSwap = true;
            }
        }
        if (!isSwap) {
            break;
        }
    }
}

//插入排序
void InsertSort(int* a, int len) {
    int i, j;
    int insertVal;
    for (i = 1; i < len; i++) {
        //先保留 下标为i的值
        insertVal = a[i];
        for (j = i - 1; j >= 0; j--) {
            if (insertVal < a[j]) {
                a[j + 1] = a[j];
            } else {
                break;
            }
        }
        //更新
        a[j + 1] = insertVal;
    }
}
int partition(int* a, int low, int high) {
    //让随机节点当pivot
    int index = rand() % (high - low + 1) + low;
    //让中间节点当pivot
    // int index = (high - low) / 2 + low;
    int pivot = a[index];
    swap(a, low, index);
    int i = low, j = high + 1;
    while (i < j) {
        while (i < high && a[++i] < pivot)
            ;
        while (a[--j] > pivot)
            ;

        if (i < j) {
            swap(a, i, j);
        }
    }
    swap(a, low, j);
    return j;
}
//快速排序
void quickSort(int* a, int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = partition(a, low, high);
    quickSort(a, low, pivot - 1);
    quickSort(a, pivot + 1, high);
}
void merge(int* a, int start, int mid, int end) {
    int temp[100];
    // i 为temp数组索引下标
    int i = start;
    //{start，mid} {mid+1,end}
    int p1 = start;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= end) {
        if (a[p1] > a[p2]) {
            temp[i++] = a[p2++];
        } else {
            temp[i++] = a[p1++];
        }
    }
    while (p1 <= mid) {
        temp[i++] = a[p1++];
    }
    while (p2 <= end) {
        temp[i++] = a[p2++];
    }

    //更新 数组
    for (int j = start; j <= end; j++) {
        a[j] = temp[j];
    }
}
//归并排序
void mergeSort(int* a, int start, int end) {
    if (end <= start) {
        return;
    }
    //找到中点
    int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);

    //合并
    merge(a, start, mid, end);
}

void down(int* a, int index, int size) {
    int e = a[index];
    int half = size >> 1;
    while (index < half) {
        int childIndex = 2 * index + 1;
        int childVal = a[childIndex];
        int rightIndex = childIndex + 1;
        if (rightIndex < size && a[rightIndex] > childVal) {
            childIndex = rightIndex;
            childVal = a[childIndex];
        }
        if (e >= childVal) {
            break;
        } else {
            a[index] = childVal;
            index = childIndex;
        }
    }
    a[index] = e;
}
//堆排序
void heapSort(int* a, int size) {
    //建堆过程
    for (int i = size / 2 - 1; i >= 0; i--) {
        down(a, i, size);
    }
    while (size > 1) {
        //头部元素和尾部元素互换
        swap(a, 0, --size);
        //剩下 size-1个元素重新建堆即可
        down(a, 0, size);
    }
}
//选择排序
void selectSort(int* a, int len) {
    for (int i = 0; i < len; i++) {
        int index = i;
        int min = a[i];
        for (int j = i + 1; j < len; j++) {
            if (a[j] < min) {
                index = j;
                min = a[j];
            }
        }
        if (index != i) {
            swap(a, i, index);
        }
    }
}
//打印操作
void printArray(int* a, int len) {
    for (int* q = a; q != a + len; q++) {
        std::cout << *q << " ";
    }
    std::cout << std::endl;
}

int main() {
    int a[17] = {6, 2, 7, 34, 1, 5, 6, 3, 7, 3, 8, 0, 3, 6, -1, -3, 4};

    int len = sizeof(a) / sizeof(a[0]);
    // bubbleSort(a, len);
    // InsertSort(a,len);
    // quickSort(a, 0, len - 1);
    // mergeSort(a, 0, len - 1);
    // heapSort(a, len);
    // selectSort(a, len);
    printArray(a, len);
}
