/*
Time: 2021-10-21
Test: mul & div 
std Time: 0.03s
Time Limit: 1.00s
*/

#include "int2048.h"

sjtu::int2048 a, b;

int main() {
  freopen("9.in", "r", stdin);
  freopen("3.666", "w", stdout);
  int T;
  std::cin >> T;
  while (T--) {
        std::cin >> a >> b;
    std::cout << a / b<<std::endl;
    std::cout << a / b<<std::endl;
    std::cout << a / b<<std::endl;
  }
}