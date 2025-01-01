//通过指针输出某整型数组a[10]的所有元素、正数的个数、负数的个数及所有元素之和。
//提示 : 可定义一整型指针p，初始化为a。表示某元素时不使用a[i], 而使用“p”, 此时在循环的过程中p要自增1，如不想改变p的值，也可使用“(p + i)”或“p[i]”, i为元素的下标。
#include <stdio.h>

int main() {
    int a[10];  // 定义大小为10的整型数组a
    int* p = a;  // 定义指针p，指向数组a的第一个元素
    int positive_count = 0, negative_count = 0, sum = 0;  // 正数个数，负数个数和所有元素之和

    // 提示用户输入数组元素
    printf("请输入10个整数：\n");

    // 使用循环从用户输入数组元素
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", (p + i));  // 使用指针访问数组元素，并通过scanf输入
    }

    // 输出数组元素并统计正负数个数和元素之和
    printf("数组元素：\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(p + i));  // 使用指针访问元素
        sum += *(p + i);  // 累加元素的和
        if (*(p + i) > 0) {
            positive_count++;  // 正数个数
        }
        else if (*(p + i) < 0) {
            negative_count++;  // 负数个数
        }
    }

    // 输出结果
    printf("\n正数个数: %d\n", positive_count);
    printf("负数个数: %d\n", negative_count);
    printf("所有元素之和: %d\n", sum);

    return 0;
}


