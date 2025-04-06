//用结构体存储3个学生的成绩，每个学生有3门课的成绩，从键盘输入以上数据(括学号、姓名、三门课成绩)，计算出平均成绩，然后按照平均分的降序排列。

#include <stdio.h>
#include <string.h>

// 定义学生结构体类型
typedef struct {
    int num;             // 学号
    char name[20];       // 姓名
    int score1, score2, score3;  // 三门课成绩
    float average;       // 平均成绩
} student;

// 函数声明：排序函数
void sort(student st[], int n);

//int main() {
    student st[3];  // 定义3个学生
    int i;

    // 输入学生信息
    for (i = 0; i < 3; i++) {
        printf("请输入学生%d的资料:\n", i + 1);
        printf("学号为：");
        scanf_s("%d", &st[i].num);
        getchar();  // 清除缓冲区中的换行符
        printf("姓名是：");
        fgets(st[i].name, sizeof(st[i].name), stdin);
        // 去掉姓名中的换行符
        st[i].name[strcspn(st[i].name, "\n")] = 0;

        printf("第1门成绩是：");
        scanf_s("%d", &st[i].score1);
        printf("第2门成绩是：");
        scanf_s("%d", &st[i].score2);
        printf("第3门成绩是：");
        scanf_s("%d", &st[i].score3);

        // 计算平均成绩
        st[i].average = (st[i].score1 + st[i].score2 + st[i].score3) / 3.0;
    }

    // 排序函数：按平均成绩降序排列
    sort(st, 3);

    // 输出学生成绩表
    printf("\n学生成绩输出界面：\n");
    printf("学号\t姓名\t语文\t数学\t英语\t平均分\n");
    for (i = 0; i < 3; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%.2f\n", st[i].num, st[i].name, st[i].score1, st[i].score2, st[i].score3, st[i].average);
    }

    return 0;
}

// 排序函数：按照平均成绩降序排列
void sort(student st[], int n) {
    int i, j;
    student temp;

    // 冒泡排序算法
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (st[j].average < st[j + 1].average) {
                // 交换学生数据
                temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
}









