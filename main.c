#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h> //pow(int x,int y)计算x的y次方 返回double数据


//abcdef
//fedcba  一个一个颠倒
void reverse_string(char *str) {

    int len = strlen(str);
    char *left = str;
    char *right = str + len - 1;

    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;


        left++;
        right--;
    }

}

int main1() {

    char arr[256] = {0};
    scanf("%s", arr);

    reverse_string(arr);

    printf("%s\n", arr);
    return 0;
}

int main2() {
    //求和sn=a+aa+aaa+aaaa+aaaaa
    int a = 0;
    int n = 0;
    int sum = 0;
    scanf("%d%d", &a, &n);
    //2 5
    //sn = 2+22+222+2222+22222 //a的值一直是2
    //a+   前一项*10+a  + 前一项*10+a
    //a*10^n+a
    int i = 0;
    //此时n表示有几位数
    int num = 0;
    for (i = 0; i < n; i++) {
        //每一次的num不同  num= 2+22+2  22
        //前一项*10+a
        num = num * 10 + a;
        sum += num;

    }

    printf("%d\n", sum);
    return 0;


}

int main3() {
//    花数（Narcissistic number）也被称为超完全数字不变数、自恋数、自幂数、
//    水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153。

    int i = 0;
    for (i = 0; i <= 100000; i++) {
        //1:判断是否为水仙花数
        int n = 1; //n为一个数的每一位 代表几位数
        //123/10 n++
        //12/10  n++
        //1/10
        int num = i; //i当前数字 不能修改 可能造成死循环
        int sum = 0;


        while (num / 10 != 0) {
            n++;
            num /= 10;
        }

        //2:判断i的每一位的n次方之和 sum
        num = i; //当前数字



        while (num) {

            //pow(int x,int y)计算x的y次方
            sum += (int) pow(num % 10, n); //那最低位的n次
            num = num / 10; // 每一次拿掉一个位数
        }


        if (sum == i) {
            printf("yes! %d\n", sum);
        }

    }

    return 0;
}

//打印菱形
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//看成两部分  shangsanji
int main4() {
    //打印n行
    int i = 0;
    int line = 0;
    scanf("%d", &line);
    //上半部分
    for (i = 1; i <= line; i++) {
        //打印空格

        //假设有7行
        // 第一行的空格有6
        // 第二行的空格有5     空格数就是总行数-当前是第几行  第n行就有 line-n个空格
        int j = 0;
        for (j = 0; j < line - i; j++) {
            printf(" ");
        }
        //打印*
        //第一行有1个
        //第二行有3个
        //第三行有5个   2*i-1

        j = 0;
        for (j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }
    //下半部分
    // ***********
    //  *********
    //   *******
    //    *****
    for (i = 1; i < line; i++) {
        //打印空格
        int j = 0;
        //第一行1个空格
        //第二行2个空格
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        //打印*号
        //假设有7行
        //第一行有11个
        //第二行有9个  第n行就有 2*(line-1-i)+1

        j = 0;
        for (j = 0; j < (2 * (line - i - 1) + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

}

//编程： 喝汽水 一瓶汽水一元，2个空瓶可以换一个汽水，给20元，可以多少汽水？
int main5() {

    int rmb = 20;
    int total = 0;
    int empty = 0; //空瓶子

    //买回来的汽水
    total = rmb;
    empty = rmb;


    while (empty >= 2) {
        //可以换的汽水
        total += empty / 2;
        //当前总余下的空瓶
        empty = empty / 2 + empty % 2;  //可能剩余一个不够置换，记得加上
    }
    printf("total = %d\n", total);
}

void my_strcpy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src; //cpy \0字符
}

//使用指针获取数组元素个数
int my_strlen(char *arr) {

    char *start = arr;
    char *end = arr; //指向第一个元素

    while (*end != '\0') {
        end++; //指针向后递进
    }
    //指针-指针：中间的元素个数
    return end - start;
}

//调整数组，使得数组中所有的奇数谓语数组的前半部分，偶数位数数组的后半部分
void adjust_arr(int arr[], int sz) {
    //int arr[] = {1,2,3,4,5,6,7,8,9,10}
    //从前找 找到以为偶数  和 从后找， 找到一个奇数进行调换位置
    int left = 0;

    //arr[0]
    int right = sz - 1;
    for (left = 0; left < sz; left++) {
        //如果左边是一个偶数， 寻找后边
        if (arr[left] % 2 == 0) {
            for (right = sz - 1; right >= 0; right--) {
                //如果右边是一个奇数，调换位置
                if (arr[right] % 2 != 0) {
                    //交换
                    int temp = arr[right];
                    arr[right] = arr[left];
                    arr[left] = temp;
                }
            }
        }

    }
}

void move_arr(int arr[], int sz) {
    int left = 0;
    int right = sz - 1;

    while (left < right) {


        //左边找偶数
        while ((left < right) && (arr[left] % 2 == 1)) {
            //奇数 进入循环，当前如果是偶数 跳出
            left++;
        }
        //右边找奇数
        while ((left < right) && (arr[right] % 2 == 0)) {
            right--;
        }
        if (left < right) {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
}

int main6() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);

    move_arr(arr, sz);


    int i = 0;
    for (i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}

//实现一个函数，可以左旋字符串中k个字符
//eg: ABCD 左旋一个 BCDA
void left_move(char *arr, int k) {


    assert(arr);
    int sz = strlen(arr);

    int i = 0;
    for (i = 0; i < k; i++) {
        //1：拿出第一个字符
        char temp = *arr;
        //2：将后面的元素前挪
        int j = 0;
        for (j = 0; j < sz - 1; j++) {
            //相邻元素
            *(arr + j) = *(arr + j + 1);
        }
        //3: 将最后一个元素 重新赋值
        *(arr + sz - 1) = temp;
    }


}

//2:三部反转法
//ab cdef  逆序
//ba fedc 逆序
//cdefab
void reverse(char *left, char *right) {
    //交换元素
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

void arr_move(char *arr, int k) {
    assert(arr);
    int len = strlen(arr);
    assert(k <= len);
    reverse(arr, arr + k - 1); //逆序左边
    reverse(arr + k, arr + len - 1); // 逆序右边
    reverse(arr, arr + len - 1); //逆序整体


}

int main7() {
    char arr[] = "abcdef";
    printf("%s\n", arr);
    int k = 2;

    arr_move(arr, k);
    printf("%s\n", arr);
}
/*int is_same(char* s1,char* s2)
{
    while (*s1 != '\0')
    {
        if(*s1 != *s2)
        {
            return 0;
        }else
        {
            s1++;
            s2++;
        }
    }
    return 1;
}*/
//判断一个字符串是否为另一个字符循环之后得来的
//eg: s1=ABCDE s2 = BCDEA 返回1
int is_left_move(char *s1, char *s2) {
    //旋转n次，判断前后字符串是否相同
    //只要可能旋转len次
    int len = strlen(s1);
    int i = 0;
    for (i = 0; i < len; i++) {

        arr_move(s1, 1); // 旋转之后 s1发生了改变 旋转一次
        //判断是否相同
        /* if(is_same(s1,s2))
         {
             return 1;
         }*/

        int ret = strcmp(s1, s2);
        if (ret == 0) {
            return 1;
        }
    }
    //不相等
    return 0;

}

int is_left_move_change(char *s1, char *s2) {
    int len = strlen(s1);
    int len2 = strlen(s1);
    if (len != len2) {
        return 0;
    }

    //1：在str字符串中追加一盒str1字符串
    strncat(s1, s1, len); //abcdef abcdef
    //2：判断str2 指向的字符串是否是str1 指向的字符串的字串
    //strstr-找字串
    char *ret = strstr(s1, s2); //在s1中找字串s2 找不到返回NULL
    if (ret == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int main22() {
    char arr1[] = "abcdef";
    char arr2[] = "cdefab";

    int flag = is_left_move_change(arr1, arr2);
    if (flag) {
        printf("Yes");
    } else {
        printf("no");
    }
    return 0;
}


int main33() {
    char arr1[30] = "abc";
    char arr2[] = "def";
    strcat(arr1, arr2);  //将s2追加到s1上

    printf("%s", arr1);
}

//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，从上到下是递增的，请编写程序查询某个数字是
//要求时间复杂度小于o(N)
//1 2 3
//4 5 6
//7 8 9
/*int findNum(int arr[3][3], int k, int row, int col) {
    //锁定上一行数据
    int x = 0;
    int y = col - 1; //标记为一行中最后一个元素
    //x最大在最后一行，y肯定大于0 因为从最后一个元素向前缩进
    while (x <= row - 1 && y >= 0) {

        //大于 说明 k在上一行
        if (arr[x][y] > k) {
            y--;
        } else if (arr[x][y] < k) //说明在右边
        {
            x++;
        } else {
            return 1; // 找到了
        }

    }
    return 0;


}*/
int findNum(int arr[3][3], int k, int* px, int* py) {
    //锁定上一行数据
    int x = 0;
    int y = *py - 1; //标记为一行中最后一个元素
    //x最大在最后一行，y肯定大于0 因为从最后一个元素向前缩进
    while (x <= *px - 1 && y >= 0) {

        //大于 说明 k在上一行
        if (arr[x][y] > k) {
            y--;
        } else if (arr[x][y] < k) //说明在右边
        {
            x++;
        } else {
            //返回型参数
            *px = x;
            *py = y;
            return 1; // 找到了
        }

    }
    *px = -1;
    *py = -1;
    return 0;


}
int main() {
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int k = 7;
    int x = 3;
    int y = 3;
    int ret = findNum(arr, k, &x, &y);

    if (ret == 1) {
        printf("找到了%d %d \n",x,y);
    } else {
        printf("未找到\n");
    }
    return 0;

}



