#include <stdio.h>

int main() {
	// 数字1、2、3、4
	int digits[] = { 1, 2, 3, 4 };

	// 使用三重循环生成所有三位数
	for (int i = 0; i < 4; i++) { // 百位
		for (int j = 0; j < 4; j++) { // 十位
			for (int k = 0; k < 4; k++) { // 个位
				// 保证百位、十位、个位的数字不重复
				if (i != j && j != k && i != k) {
					// 输出符合条件的三位数
					printf("%d%d%d\n", digits[i], digits[j], digits[k]);
				}
			}
		}
	}

	return 0;
}