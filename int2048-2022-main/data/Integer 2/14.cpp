/*
Time: 2021-10-22
Test: complexity (div)
std Time: 0.01s
Time Limit: 1.00s
*/

#include "int2048.h"

sjtu::int2048 a, b;
std::string s1, s2;

int main() {

  freopen("14.in", "r", stdin);
  freopen("2.666", "w", stdout);
  for (int i = 1; i <= 100; i++) {
    a = 0, b = 0;
    s1 = "", s2 = "";
    for (int j = 1; j < 100; j++)
      s1 += (1ll * (i + j) * 19260817) % 998244353 % 10 + '0';
    for (int j = 1; j < 100 / 2; j++)
      s2 += (1ll * (i + j) * 998244353) % 19260817 % 10 + '0';
    a = s1;
    b = s2;
    b = b + 1;
    if (a-(a/b)*b>b||a-(a/b)*b<0){
      std::cout<<a<<"\n"<<b<<'\n';
  }
    std::cout << a / b << '\n';
  }
}