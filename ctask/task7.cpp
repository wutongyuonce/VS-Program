//编写c语言程序求两个已知复数的和。如已知两个复数6，8 + 7.6i和3，4 + 5.2i, 求出它们的和。 具体要求如下 :
//(1)定义结构体类型
//(2)定义函数complex add(complex x, complexy), 求x + y的和。
//(3)在主函数中定义并初始化结构体类型变量xx和yy，调用函数add求xx + yy, 最后按以下格式输出和:(6.8 + 7.6i) - (3.4 + 5.2i) = 3.4 + 2.4i.

#include <stdio.h>

typedef struct {
    double re;  // 实部
    double im;  // 虚部
} complex;

// 复数加法函数
complex add(complex x, complex y) {
    complex result;
    result.re = x.re + y.re;  // 实部相加
    result.im = x.im + y.im;  // 虚部相加
    return result;
}

//int main() {
    complex xx, yy;

    // 从终端输入复数 xx 和 yy 的实部和虚部
    printf("请输入复数 xx 的实部和虚部: ");
    scanf_s("%lf %lf", &xx.re, &xx.im);  // 输入 xx.re 和 xx.im

    printf("请输入复数 yy 的实部和虚部: ");
    scanf_s("%lf %lf", &yy.re, &yy.im);  // 输入 yy.re 和 yy.im

    // 调用 add 函数计算和
    complex result = add(xx, yy);

    // 输出结果
    printf("(%.1f+%.1fi) + (%.1f+%.1fi) = %.1f+%.1fi\n", xx.re, xx.im, yy.re, yy.im, result.re, result.im);

    return 0;
}

