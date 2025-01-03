//将自然数1～10以及它们的平方根写到名为number.txt的文本文档中，然后再顺序读出显示在屏幕上。

#include <stdio.h>
#include <math.h>

int main() {
    FILE* file;
    int i;
    double sqrt_value;

    // 1. 打开文件用于写入数据
    errno_t err = fopen_s(&file, "number.txt", "w"); // 使用 fopen_s 打开文件
    if (err != 0) {
        printf("无法打开文件进行写入\n");
        return 1; // 如果打开文件失败，退出程序
    }

    // 2. 写入自然数及其平方根到文件
    for (i = 1; i <= 10; i++) {
        sqrt_value = sqrt(i); // 计算平方根
        fprintf(file, "%d %.6f\n", i, sqrt_value); // 写入数字和其平方根
    }

    // 3. 关闭文件
    fclose(file);

    // 4. 打开文件进行读取并显示
    err = fopen_s(&file, "number.txt", "r"); // 使用 fopen_s 打开文件
    if (err != 0) {
        printf("无法打开文件进行读取\n");
        return 1; // 如果打开文件失败，退出程序
    }

    // 5. 读取并显示文件中的内容
    printf("自然数及其平方根:\n");
    while (fscanf_s(file, "%d %lf", &i, &sqrt_value) == 2) { // 使用 fscanf_s 读取文件
        printf("%d %.6f\n", i, sqrt_value);
    }

    // 6. 关闭文件
    fclose(file);

    return 0;
}
