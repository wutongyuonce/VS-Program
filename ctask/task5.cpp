//用c语言编写一个函数，使一维数组(长度为m)元素循环右移一位，函数原型为 void rmove(int p, int m) :
//提示:数组元素循环右移一位的意思是:最后一个元素移到第一个，其他元素整体右移一个位置，如(1, 2, 3, 4)}循环右移一位后变成(4, 1, 2, 3}。

#include <stdio.h>
#include <stdlib.h>

// 循环右移一位的函数
void rmove(int* p, int m) {
    if (m <= 0) return;  // 如果数组长度不大于0，直接返回

    int t = *(p + m - 1);  // 保存最后一个元素的值
    for (int i = m - 1; i > 0; i--) {
        *(p + i) = *(p + i - 1);  // 右移元素
    }
    *p = t;  // 将最后一个元素放到数组的第一个位置
}

// 打印数组的函数
void printArray(int* p, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

int main() {
    int m;

    // 获取用户输入的数组长度
    printf("请输入数组的长度: ");
    scanf_s("%d", &m);

    // 动态分配数组内存
    int* a = (int*)malloc(m * sizeof(int));
    if (a == NULL) {
        printf("内存分配失败!\n");
        return 1;  // 退出程序
    }

    // 获取用户输入的数组元素
    printf("请输入数组的 %d 个元素:\n", m);
    for (int i = 0; i < m; i++) {
        scanf_s("%d", &a[i]);
    }

    printf("原数组: ");
    printArray(a, m);  // 打印原数组

    rmove(a, m);  // 调用函数，循环右移一位

    printf("循环右移后的数组: ");
    printArray(a, m);  // 打印右移后的数组

    // 释放动态分配的内存
    free(a);

    return 0;
}





