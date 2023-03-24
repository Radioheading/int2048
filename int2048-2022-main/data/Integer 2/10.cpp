/*
Time: 2021-10-21
Test: mul & div
std Time: 0.01s
Time Limit: 1.00s
*/

#include "int2048.h"

sjtu::int2048 a;
std::string s;

int main()
{
    freopen("10.in", "r", stdin);
    freopen("3.666", "w", stdout);
    int n;
    std::cin >> n;
    a = 1;
    for (int i = 1; i <= n; i++)
    {
        int ty = 0;
        std::cin >> ty >> s;
        //std::cout<<a<<" "<<s<<'\n';
        if (ty) {
          a /= s;
          //std::cout<<"/ \n";
        }
        else {
          a *= s;
          //std::cout<<"* \n";
        }
        std::cout << a << '\n';
    }
}