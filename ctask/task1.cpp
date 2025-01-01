//将两个字符串连接成一个字符串，并将连接后的字符串按升序排列。如字符串s1 的值为"pear", 字符串s2的值为"apple", 将s1和s2连接后得到的字符串"pearapple"存入字符数组s3, 排序后得到"aaeelpppr"。要求:排序用函数实现，使用冒泡排序或者选择排序。
//提示 : 字符串的连接可使用函数strcat，为了保证连接成功，字符串s1的长度应该足够容纳连接后的字符串，所以s1的长度应该定义得大一些，如s2的长度为20，s1的长度可以为60；字符串的有效长度可以使用函数strlen获得，排序不是对s1的60个字符排序，而是对s1的有效字符排序；排序和数值型数组排序类似，直接比较两字符的大小。

#include <stdio.h>
#include <string.h>

// 冒泡排序函数，用来对字符串中的字符按升序排序
void bubbleSort(char str[], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            // 如果前一个字符大于后一个字符，交换它们
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char s1[60], s2[20], s3[80];  // s1的长度要比s2大，以便容纳连接后的字符串

    // 输入两个字符串
    printf("请输入第一个字符串 s1: ");
    fgets(s1, sizeof(s1), stdin);
    // 去除换行符
    s1[strcspn(s1, "\n")] = '\0';

    printf("请输入第二个字符串 s2: ");
    fgets(s2, sizeof(s2), stdin);
    // 去除换行符
    s2[strcspn(s2, "\n")] = '\0';

    // 初始化s3为空字符串，以防止垃圾值
    s3[0] = '\0';

    // 将两个字符串连接到s3中
    strcat_s(s3, sizeof(s3), s1);  // 正确的用法，指定目标字符串和大小
    strcat_s(s3, sizeof(s3), s2);  // 正确的用法，指定目标字符串和大小

    // 打印连接后的字符串
    printf("连接后的字符串是: %s\n", s3);

    // 获取连接后的字符串的有效长度
    int length = strlen(s3);

    // 对连接后的字符串进行排序
    bubbleSort(s3, length);

    // 打印排序后的字符串
    printf("排序后的字符串是: %s\n", s3);

    return 0;
}

