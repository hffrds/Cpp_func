//<climits>
定义整数类型范围确保可移植性
CHAR_MIN, CHAR_MAX：char 类型的最小值和最大值。
SCHAR_MIN, SCHAR_MAX：signed char 类型的最小值和最大值。
UCHAR_MAX：unsigned char 类型的最大值。
SHRT_MIN, SHRT_MAX：short 类型的最小值和最大值。
USHRT_MAX：unsigned short 类型的最大值。
INT_MIN, INT_MAX：int 类型的最小值和最大值。
UINT_MAX：unsigned int 类型的最大值。
LONG_MIN, LONG_MAX：long 类型的最小值和最大值。
ULONG_MAX：unsigned long 类型的最大值。
LLONG_MIN, LLONG_MAX：long long 类型的最小值和最大值。
ULLONG_MAX：unsigned long long 类型的最大值。
CHAR_BIT：char 类型的位数（通常是 8 位）。
CHAR_WIDTH：char 类型的宽度。
MB_LEN_MAX：在多字节字符集中的最大字节数。

//<cmath>
abs()：返回整数或浮点数的绝对值
fabs()：返回浮点数的绝对值
ceil()：返回大于或等于参数的最小整数
floor():向下取整
round()：返回四舍五入后的最接近整数
trunc()：返回去掉小数部分的整数部分（即截断）

exp()：计算自然指数函数（e^x）
double exp_val = exp(1.0); // 返回 e ≈ 2.71828
log()：计算自然对数（以 e 为底）
double log_val = log(2.71828); // 返回 1.0
log10()：计算以 10 为底的对数
double log10_val = log10(100.0); // 返回 2.0
pow()：计算 x 的 y 次方
double pow_val = pow(2.0, 3.0); // 返回 8.0
sqrt()：计算平方根
double sqrt_val = sqrt(16.0); // 返回 4.0

modf()：将浮点数分解为整数部分和小数部分
double int_part, frac_part;
frac_part = modf(5.75, &int_part); // int_part = 5.0, frac_part = 0.75

//<cstdio>--由<stdio.h>发展
输入与输出

//<cstdlib>--<stdlib.h>
包含通用工具函数
malloc(),free()
exit(),abort()进程控制
rand()
qsort(),bsearch()快速排序，二分查找
atoi(),atof(),strtol(),strtoul(),strtof()字符串转换

//<cstring>
用于C风格字符串
strlen()：计算字符串的长度
strcpy()：复制字符串
strcat()：连接字符串
strcmp()：比较字符串
strchr()：查找字符
strstr()：查找子字符串
