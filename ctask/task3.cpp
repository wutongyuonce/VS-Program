//编写一个函数，该函数可以统计一个长度为3的字符串在另一个字符串中出现的次数。如输入的字符串为"asdasasdfgasdaszx67asdmklo", 长度为3的字符串为asd”, 则应输出“n = 4”
#include <stdio.h>
#include <string.h>

int count_substring_occurrences(const char* str, const char* sub) {
    int count = 0;
    int sub_len = strlen(sub);
    int str_len = strlen(str);

    // 遍历主字符串
    for (int i = 0; i <= str_len - sub_len; i++) {
        // 比较从当前索引开始的子字符串与目标子字符串
        if (strncmp(str + i, sub, sub_len) == 0) {
            count++;
        }
    }
    return count;
}

//int main() {
    char str[100], sub[100];

    // 输入主字符串和子字符串
    printf("请输入主字符串 (str): ");
    fgets(str, sizeof(str), stdin);
    // 去掉字符串末尾的换行符
    str[strcspn(str, "\n")] = '\0';

    printf("请输入子字符串 (sub): ");
    fgets(sub, sizeof(sub), stdin);
    // 去掉字符串末尾的换行符
    sub[strcspn(sub, "\n")] = '\0';

    // 调用函数并输出结果
    int n = count_substring_occurrences(str, sub);
    printf("子字符串 '%s' 在主字符串中出现的次数是: %d\n", sub, n);

    return 0;
}
