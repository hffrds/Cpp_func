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

isinf()
isnan()

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

//<string>
提供std::string类
类方法：
size() / length()
c_str()：转换为C风格字符串
append/compare/find/substr(提取)/erase

//<ctime>
时间函数



//C++标准库容器(container)：容器（Container）是指一种存储多个元素的动态管理的对象，底层通过分配器(allocator)管理内存
容器是类模板，序列容器：<vector><deque><list>，关联容器，容器适配器(前两种的变体)：queue，stack//由于容器适配器只暴露部分接口（实际上只有5/6个函数），不支持迭代器，因此它们无法与 C++ 标准库算法一起使用。 有关详细信息，请参阅算法。

//<iterator>
iterator是指针的泛化，用于容器(是访问容器元素的通用方法)。范围为第一个元素到最后一个元素的下一个位置：//string也可以使用迭代器
std::vector<int> vec = {1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
++it移动迭代器
vector支持随机访问，有operator[]成员函数//动态数组
vec.insert(it, 10);          // 在位置it前插入元素10
vec.erase(it);               // 删除位置it指向的元素
std::advance(it, 2);  // 将迭代器移动两步
//算法
依赖于迭代器
auto it = std::find(numbers.begin(), numbers.end(), 8); //未找到返回numbers.end()
int count = std::count(numbers.begin(), numbers.end(), 3); //统计出现次数
std::sort //默认升序排序
std::binary_search //使用二分查找实现find()/判断是否在里面             即使不支持随机访问
std::count_if
std::for_each

//<cstring>
bool met[10]; // 初始化
int arr[10];
memset(met, 0, sizeof(met));
memset(arr, 0, sizeof(arr));

//<utility>
定义了std::swap()函数
<algorithm>头文件也有swap()函数，不过是引用的<utility>的，对于容器如<string><vector>有成员函数<swap>，同时也包含了非成员函数swap()

//<algorithm>
auto it = std::find(v.begin(), v.end(), 3);   找到第一个等于 value 的元素，返回值为迭代器 未找到返回end()
<string>有成员函数（vector无） std::string::find()，查找单个字符或子字符串，返回的是size_t的索引，未找到返回std::string::npos
int count = std::count(v.begin(), v.end(), 2);
std::binary_search() 适用于有序容器，返回类型为bool   使用二分查找进行查找(find()也能查找 线性查找)，时间复杂度O(log n)   查找子字符串还是要用find()
可以先std::sort(v.begin(), v.end());升序排序 定义在<algorithm>

                                #include <iostream>
                                #include <vector>
                                #include <algorithm>
                                
                                struct Person {
                                    int id;
                                    std::string name;
                                };
                                
                                // 自定义比较器
                                bool compareById(const Person& p1, const Person& p2) {
                                    return p1.id < p2.id;
                                }
                                
                                int main() {
                                    std::vector<Person> people = {
                                        {1, "Alice"},
                                        {2, "Bob"},
                                        {3, "Charlie"},
                                    };
                                
                                    // 必须先排序
                                    std::sort(people.begin(), people.end(), compareById);
                                
                                    // 查找 id 为 2 的人
                                    Person target = {2, ""};
                                    if (std::binary_search(people.begin(), people.end(), target, compareById)) {
                                        std::cout << "Found person with ID 2!" << std::endl;
                                    } else {
                                        std::cout << "Person with ID 2 not found." << std::endl;
                                    }
                                
                                    return 0;
                                }
std::reverse(v.begin(), v.end());反转
std::replace(v.begin(), v.end(), 3, 99);替代所有的3为99
std::fill(vec.begin(), vec.end(), 42);填充
std::copy(source.begin(), source.end(), destination.begin());复制                     //返回值：std::copy() 会返回指向目标范围末尾元素的迭代器（即，复制操作后的下一个位置）？
auto it = std::unique(vec.begin(), vec.end());移除相邻的相同元素放到末尾返回不重复元素的末尾的迭代器，需要先排序
如之后直接vec.resize(std::distance(vec.begin(), it));（容器的成员函数，用于重新定义大小）


均适用于普通数组，迭代器传指针即可
std::begin(arr) 和 std::end(arr)适用于数组和容器 定义在<iterator> 

<cstdint>
定义intN_t和uintN_t
