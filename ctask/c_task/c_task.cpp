

#include <stdio.h>

int main() {
    // 定义三个整数
    int a, b, c;

    // 输入三个整数
    printf("请输入三个整数 a, b, c: ");
    scanf_s("%d %d %d", &a, &b, &c);

    // 定义一个整型指针数组，用于存储 a, b, c 的地址
    int* arr[3];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    // 假设第一个元素最大，依次与后面的元素进行比较
    int* max = arr[0];
    for (int i = 1; i < 3; i++) {
        if (*arr[i] > *max) {
            max = arr[i];
        }
    }

    // 输出最大值
    printf("三个数中的最大值是: %d\n", *max);

    return 0;
}
