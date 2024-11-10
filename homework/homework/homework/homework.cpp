#include <stdio.h>
#include <math.h>

int main() {
    int g;
    char s;
    printf("请输入一个整数表示的百分制成绩：");
    scanf_s("%d", &g);
    switch (g/10) {
        case 10:
        case 9:s = 'A';break;
        case 8:s = 'B';break;
        case 7:
        case 6:s = 'C';break;
        default:s = 'E';break;
    }
    printf("转换后的五分制成绩为：%c\n",s);
    return 0;
}
