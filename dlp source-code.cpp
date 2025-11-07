#include <stdio.h>
 
int main() {
    char isbn[14]; // 定义一个字符数组来存储输入的ISBN号码，足够容纳13个字符加上一个终止符'\0'
 
    scanf("%s", isbn); // 读取用户输入的ISBN号码字符串，假定输入格式正确（包括分隔符）
 
    int sum = 0, weight = 1; // 初始化加权和变量sum和权重变量weight
    for(int i = 0; isbn[i]; i++) { // 遍历ISBN号码字符串
        if(isbn[i] == '-') continue; // 如果当前字符是分隔符'-'，则跳过当前循环迭代
        if(weight > 9) break; // 如果权重大于9，说明已经处理完9个数字，可以退出循环
        sum += (isbn[i] - '0') * weight++; // 将字符转换成对应的数字并乘以权重，加到sum上，并将权重加1
    }
 
    // 根据加权和sum计算校验位，如果余数是10则用'X'表示，否则用余数对应的数字字符
    // (sum % 11) 计算加权和sum除以11得到的余数，如果余数是10，则校验位为'X'，否则为0到9之间的数字
    char check_digit = (sum % 11 == 10) ? 'X' : (sum % 11) + '0';
 
    // 比较计算得到的校验位与ISBN号码中的最后一位字符
    // 如果它们相等，则输出"Right"，表示输入的ISBN号码是正确的
    if(check_digit == isbn[12]) {
        printf("Right\n");
    } else {
        // 如果它们不相等，则将错误的校验位替换为正确的校验位，并输出修正后的完整ISBN号码
        isbn[12] = check_digit; // 将正确的校验位字符赋值给isbn数组的最后一个元素（校验位位置）
        printf("%s\n", isbn); // 输出修正后的ISBN号码
    }    
    return 0; // 程序正常退出，返回0
}