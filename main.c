#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h> //pow(int x,int y)����x��y�η� ����double����


//abcdef
//fedcba  һ��һ���ߵ�
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
    //���sn=a+aa+aaa+aaaa+aaaaa
    int a = 0;
    int n = 0;
    int sum = 0;
    scanf("%d%d", &a, &n);
    //2 5
    //sn = 2+22+222+2222+22222 //a��ֵһֱ��2
    //a+   ǰһ��*10+a  + ǰһ��*10+a
    //a*10^n+a
    int i = 0;
    //��ʱn��ʾ�м�λ��
    int num = 0;
    for (i = 0; i < n; i++) {
        //ÿһ�ε�num��ͬ  num= 2+22+2  22
        //ǰһ��*10+a
        num = num * 10 + a;
        sum += num;

    }

    printf("%d\n", sum);
    return 0;


}

int main3() {
//    ������Narcissistic number��Ҳ����Ϊ����ȫ���ֲ�����������������������
//    ˮ�ɻ�����ָһ�� 3 λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵������������磺1^3 + 5^3+ 3^3 = 153��

    int i = 0;
    for (i = 0; i <= 100000; i++) {
        //1:�ж��Ƿ�Ϊˮ�ɻ���
        int n = 1; //nΪһ������ÿһλ ����λ��
        //123/10 n++
        //12/10  n++
        //1/10
        int num = i; //i��ǰ���� �����޸� ���������ѭ��
        int sum = 0;


        while (num / 10 != 0) {
            n++;
            num /= 10;
        }

        //2:�ж�i��ÿһλ��n�η�֮�� sum
        num = i; //��ǰ����



        while (num) {

            //pow(int x,int y)����x��y�η�
            sum += (int) pow(num % 10, n); //�����λ��n��
            num = num / 10; // ÿһ���õ�һ��λ��
        }


        if (sum == i) {
            printf("yes! %d\n", sum);
        }

    }

    return 0;
}

//��ӡ����
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//����������  shangsanji
int main4() {
    //��ӡn��
    int i = 0;
    int line = 0;
    scanf("%d", &line);
    //�ϰ벿��
    for (i = 1; i <= line; i++) {
        //��ӡ�ո�

        //������7��
        // ��һ�еĿո���6
        // �ڶ��еĿո���5     �ո�������������-��ǰ�ǵڼ���  ��n�о��� line-n���ո�
        int j = 0;
        for (j = 0; j < line - i; j++) {
            printf(" ");
        }
        //��ӡ*
        //��һ����1��
        //�ڶ�����3��
        //��������5��   2*i-1

        j = 0;
        for (j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n");
    }
    //�°벿��
    // ***********
    //  *********
    //   *******
    //    *****
    for (i = 1; i < line; i++) {
        //��ӡ�ո�
        int j = 0;
        //��һ��1���ո�
        //�ڶ���2���ո�
        for (j = 0; j < i; j++) {
            printf(" ");
        }

        //��ӡ*��
        //������7��
        //��һ����11��
        //�ڶ�����9��  ��n�о��� 2*(line-1-i)+1

        j = 0;
        for (j = 0; j < (2 * (line - i - 1) + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

}

//��̣� ����ˮ һƿ��ˮһԪ��2����ƿ���Ի�һ����ˮ����20Ԫ�����Զ�����ˮ��
int main5() {

    int rmb = 20;
    int total = 0;
    int empty = 0; //��ƿ��

    //���������ˮ
    total = rmb;
    empty = rmb;


    while (empty >= 2) {
        //���Ի�����ˮ
        total += empty / 2;
        //��ǰ�����µĿ�ƿ
        empty = empty / 2 + empty % 2;  //����ʣ��һ�������û����ǵü���
    }
    printf("total = %d\n", total);
}

void my_strcpy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src; //cpy \0�ַ�
}

//ʹ��ָ���ȡ����Ԫ�ظ���
int my_strlen(char *arr) {

    char *start = arr;
    char *end = arr; //ָ���һ��Ԫ��

    while (*end != '\0') {
        end++; //ָ�����ݽ�
    }
    //ָ��-ָ�룺�м��Ԫ�ظ���
    return end - start;
}

//�������飬ʹ�����������е�����ν�������ǰ�벿�֣�ż��λ������ĺ�벿��
void adjust_arr(int arr[], int sz) {
    //int arr[] = {1,2,3,4,5,6,7,8,9,10}
    //��ǰ�� �ҵ���Ϊż��  �� �Ӻ��ң� �ҵ�һ���������е���λ��
    int left = 0;

    //arr[0]
    int right = sz - 1;
    for (left = 0; left < sz; left++) {
        //��������һ��ż���� Ѱ�Һ��
        if (arr[left] % 2 == 0) {
            for (right = sz - 1; right >= 0; right--) {
                //����ұ���һ������������λ��
                if (arr[right] % 2 != 0) {
                    //����
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


        //�����ż��
        while ((left < right) && (arr[left] % 2 == 1)) {
            //���� ����ѭ������ǰ�����ż�� ����
            left++;
        }
        //�ұ�������
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

//ʵ��һ�����������������ַ�����k���ַ�
//eg: ABCD ����һ�� BCDA
void left_move(char *arr, int k) {


    assert(arr);
    int sz = strlen(arr);

    int i = 0;
    for (i = 0; i < k; i++) {
        //1���ó���һ���ַ�
        char temp = *arr;
        //2���������Ԫ��ǰŲ
        int j = 0;
        for (j = 0; j < sz - 1; j++) {
            //����Ԫ��
            *(arr + j) = *(arr + j + 1);
        }
        //3: �����һ��Ԫ�� ���¸�ֵ
        *(arr + sz - 1) = temp;
    }


}

//2:������ת��
//ab cdef  ����
//ba fedc ����
//cdefab
void reverse(char *left, char *right) {
    //����Ԫ��
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
    reverse(arr, arr + k - 1); //�������
    reverse(arr + k, arr + len - 1); // �����ұ�
    reverse(arr, arr + len - 1); //��������


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
//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ�ѭ��֮�������
//eg: s1=ABCDE s2 = BCDEA ����1
int is_left_move(char *s1, char *s2) {
    //��תn�Σ��ж�ǰ���ַ����Ƿ���ͬ
    //ֻҪ������תlen��
    int len = strlen(s1);
    int i = 0;
    for (i = 0; i < len; i++) {

        arr_move(s1, 1); // ��ת֮�� s1�����˸ı� ��תһ��
        //�ж��Ƿ���ͬ
        /* if(is_same(s1,s2))
         {
             return 1;
         }*/

        int ret = strcmp(s1, s2);
        if (ret == 0) {
            return 1;
        }
    }
    //�����
    return 0;

}

int is_left_move_change(char *s1, char *s2) {
    int len = strlen(s1);
    int len2 = strlen(s1);
    if (len != len2) {
        return 0;
    }

    //1����str�ַ�����׷��һ��str1�ַ���
    strncat(s1, s1, len); //abcdef abcdef
    //2���ж�str2 ָ����ַ����Ƿ���str1 ָ����ַ������ִ�
    //strstr-���ִ�
    char *ret = strstr(s1, s2); //��s1�����ִ�s2 �Ҳ�������NULL
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
    strcat(arr1, arr2);  //��s2׷�ӵ�s1��

    printf("%s", arr1);
}

//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ����ϵ����ǵ����ģ����д�����ѯĳ��������
//Ҫ��ʱ�临�Ӷ�С��o(N)
//1 2 3
//4 5 6
//7 8 9
/*int findNum(int arr[3][3], int k, int row, int col) {
    //������һ������
    int x = 0;
    int y = col - 1; //���Ϊһ�������һ��Ԫ��
    //x��������һ�У�y�϶�����0 ��Ϊ�����һ��Ԫ����ǰ����
    while (x <= row - 1 && y >= 0) {

        //���� ˵�� k����һ��
        if (arr[x][y] > k) {
            y--;
        } else if (arr[x][y] < k) //˵�����ұ�
        {
            x++;
        } else {
            return 1; // �ҵ���
        }

    }
    return 0;


}*/
int findNum(int arr[3][3], int k, int* px, int* py) {
    //������һ������
    int x = 0;
    int y = *py - 1; //���Ϊһ�������һ��Ԫ��
    //x��������һ�У�y�϶�����0 ��Ϊ�����һ��Ԫ����ǰ����
    while (x <= *px - 1 && y >= 0) {

        //���� ˵�� k����һ��
        if (arr[x][y] > k) {
            y--;
        } else if (arr[x][y] < k) //˵�����ұ�
        {
            x++;
        } else {
            //�����Ͳ���
            *px = x;
            *py = y;
            return 1; // �ҵ���
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
        printf("�ҵ���%d %d \n",x,y);
    } else {
        printf("δ�ҵ�\n");
    }
    return 0;

}



