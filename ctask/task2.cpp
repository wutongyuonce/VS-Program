#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 判断一个字符是否是合法的标识符字符
int isValidIdentifier(char str[]) {
    // 如果字符串为空，返回0
    if (str[0] == '\0') {
        return 0;
    }

    // 第一个字符必须是字母或下划线
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0;
    }

    // 后续字符必须是字母、数字或下划线
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0;
        }
    }

    // 如果所有条件都通过，则为合法标识符
    return 1;
}

//int main() {
    char str[100];  // 存储输入的字符串

    // 输入一个字符串
    printf("请输入一个字符串：");
    fgets(str, sizeof(str), stdin);
    // 去除字符串末尾的换行符
    str[strcspn(str, "\n")] = '\0';

    // 判断字符串是否为合法标识符
    if (isValidIdentifier(str)) {
        printf("%s是一个合法的标识符！\n", str);
    }
    else {
        printf("%s不是一个合法的标识符！\n", str);
    }
    return 0;
}