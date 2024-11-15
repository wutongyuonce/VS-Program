#include <stdio.h>

int main() {
	int count = 0; // 计数器，用于每行输出5个闰年

	// 遍历1900到2018年之间的所有年份
	for (int year = 1900; year <= 2018; year++) {
		// 判断是否是闰年
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			printf("%d ", year); // 输出闰年
			count++; // 计数器增加

			// 如果输出了5个闰年，换行
			if (count % 5 == 0) {
				printf("\n");
			}
		}
	}

	// 如果最后一行没有满5个闰年，打印换行
	if (count % 5 != 0) {
		printf("\n");
	}

	return 0;
}