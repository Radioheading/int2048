#ifndef SJTU_BIGINTEGER
#define SJTU_BIGINTEGER
// Integer 1:
// 实现一个有符号的大整数类，只需支持简单的加减

// Integer 2:
// 实现一个有符号的大整数类，支持加减乘除，并重载相关运算符

// 请不要使用除了以下头文件之外的其它头文件
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

// 请不要使用 using namespace std;

namespace sjtu {
class int2048 {
 private:
 public:
  std::vector<long long> big_num; // storing the digits
  bool negative_check; // sign of the big int
  // todo
  // 构造函数
  inline int2048();
  inline int2048(long long x);
  inline int2048(const std::string &s);
  inline int2048(const int2048 &);

  // 以下给定函数的形式参数类型仅供参考，可自行选择使用常量引用或者不使用引用
  // 如果需要，可以自行增加其他所需的函数
  // ===================================
  // Integer1
  // ===================================

  // 读入一个大整数
  inline void read(const std::string &in);
  // 输出储存的大整数
  inline void print();
  // 加上一个大整数
  inline int2048 &add(const int2048 &big_add);
  // 输出两个大整数之和
  inline friend int2048 add(const int2048 &, const int2048 &);
  // 减去一个大整数
  inline int2048 &minus(const int2048 &);
  // 输出两个大整数之差
  inline friend int2048 minus(const int2048 &, const int2048 &);
  // 输出一个大整数的绝对值
  inline friend int2048 abs(int2048);
  // 输出两个大整数的中间值
  // ===================================
  // Integer2
  // ===================================

  inline int2048 &operator=(const int2048 &);

  inline int2048 &operator+=(const int2048 &);
  inline friend int2048 operator+(const int2048 &, const int2048 &);

  inline int2048 &operator-=(const int2048 &);
  inline friend int2048 operator-(const int2048 &, const int2048 &);

  inline int2048 &operator*=(const int2048 &);
  inline friend int2048 operator*(const int2048 &, const int2048 &);

  inline int2048 &operator/=(const int2048 &);
  inline friend int2048 operator/(const int2048 &, const int2048 &);

  inline friend std::istream &operator>>(std::istream &, int2048 &);
  inline friend std::ostream &operator<<(std::ostream &, const int2048 &);

  inline friend bool operator==(const int2048 &, const int2048 &);
  inline friend bool operator!=(const int2048 &, const int2048 &);
  inline friend bool operator<(const int2048 &, const int2048 &);
  inline friend bool operator>(const int2048 &, const int2048 &);
  inline friend bool operator<=(const int2048 &, const int2048 &);
  inline friend bool operator>=(const int2048 &, const int2048 &);
};
}
#endif