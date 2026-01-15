/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;
struct List
{
    E* array;     // 指向顺序表的底层数组
    int capacity; // 数组的容量
    int size;     // 表中的元素数量
};

typedef struct List* ArrayList;

bool initList(ArrayList list)
{
    list->array = (E*)(malloc(sizeof(int) * 10));
    if (list->array == NULL)
        return 0; 
    // 需要判断如果申请的结果为NULL的话表示内存空间申请失败
    list->capacity = 10;
    list->size = 0;
    return 1; // 正常情况下返回true也就是1
}

bool insertList(ArrayList list, E element, int index) {
    if (index < 1 || index > list->size + 1) return 0;   //如果在非法位置插入，返回0表示插入操作执行失败
    if (list->size == list->capacity) {   //如果size已经到达最大的容量了，肯定是插不进了，那么此时就需要扩容了
        int newCapacity = list->capacity + (list->capacity >> 1);   //我们先计算一下新的容量大小，这里我取1.5倍原长度(>>n二进制右移n位即除以2），当然你们也可以想扩多少扩多少
        E* newArray = (E*)(realloc(list->array, sizeof(E) * newCapacity));  //这里我们使用新的函数realloc重新申请更大的内存空间
        if (newArray == NULL) return 0;   //如果申请失败，那么就确实没办法插入了，只能返回0表示插入失败了
        list->array = newArray;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index - 1; i--)  
        //先使用for循环将待插入位置后续的元素全部丢到后一位
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;    
    //挪完之后，位置就腾出来了，直接设定即可
    list->size++;   
    //别忘了插入之后相当于多了一个元素，记得size + 1
    return 1;
}

bool deleteList(ArrayList list, int index) {
    if (index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];   //实际上只需要依次把后面的元素覆盖到前一个即可
    list->size--;   //最后别忘了size - 1
    return 1;
}

int sizeList(ArrayList list) {
    return list->size;   //直接返回size就完事
}

E getList(ArrayList list, int index) {
    if (index < 1 || index > list->size) return NULL;   //如果超出范围就返回NULL
    return list->array[index - 1];
}

void printList(ArrayList list)
{                                        // 编写一个函数用于打印表当前的数据
    for (int i = 0; i < list->size; ++i) // 表里面每个元素都拿出来打印一次
        printf("%d ", list->array[i]);
    printf("\n");
}

int main()
{
    struct List list; // 创建新的结构体变量
    if (initList(&list))
    {                              // 对其进行初始化，如果失败就直接结束
        insertList(&list, 666, 1); // 每次插入操作后都打印一下表，看看当前的情况
        printList(&list);
        insertList(&list, 777, 1);
        printList(&list);
        insertList(&list, 888, 2);
        printList(&list);
        if (insertList(&list, 666, -1)) {
            printList(&list);
        }
        else {
            printf("插入失败！");
        }
    }
    else
    {
        printf("顺序表初始化失败，无法启动程序！");
    }
    for (int i = 0; i < 10; ++i)  //先插10个
        insertList(&list, i, i);
    deleteList(&list, 5);   //这里删除5号元素
    printList(&list);
    printf("%d",getList(&list, 3));
}
*/