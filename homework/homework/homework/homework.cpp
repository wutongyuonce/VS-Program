#include <stdio.h>

int main() {
    // 定义一个二维数组并初始化
    int arr[4][5] = {
        {12, 20, 30, 25, 52},
        {36, 65, 22, 26, 60},
        {70, 54, 12, 14, 6},
        {2, 7, 8, 12, 15}
    };

    // 存储每列平均值的一维数组
    float averages[5];

    // 计算每列的平均值
    for (int col = 0; col < 5; col++) {
        int sum = 0;
        // 计算当前列所有行的和
        for (int row = 0; row < 4; row++) {
            sum += arr[row][col];
        }
        // 计算平均值
        averages[col] = (float)sum / 4;
    }

    // 输出二维数组各元素的值
    printf("二维数组的元素值（按行列格式）：\n");
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 5; col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }

    // 输出一维数组各列的平均值
    printf("\n各列的平均值：\n");
    for (int col = 0; col < 5; col++) {
        printf("第 %d 列的平均值: %.2f\n", col + 1, averages[col]);
    }

    return 0;
}
