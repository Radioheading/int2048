//
// Created by 18221 on 2022/11/17.
//
#include "int2048.h"
#include <iostream>
#include <vector>
namespace sjtu {
inline sjtu::int2048::int2048() {
  //std::cin.tie(nullptr);
  big_num.clear();
  negative_check = false;
}
inline sjtu::int2048::int2048(long long in) {
  //std::cin.tie(nullptr);
  big_num.clear();
  negative_check = false;
  if (in < 0) {
    negative_check = true;
    in = -in;
  }
  while (in > 0) {
    big_num.push_back(in % 100000000);
    in /= 100000000;
  }

}
inline sjtu::int2048::int2048(const std::string &string_in) {
  //std::cin.tie(nullptr);
  big_num.clear();
  negative_check = false;
  if (string_in == "-0") { // special judgement
    big_num.push_back(0);
    return;
  }
  if (string_in[0] == '-') { // negative number
    negative_check = true; // storing its sign
    for (int i = string_in.length() - 1; i > 0; i -= 8) {
      // store, eight in a row
      int temp = 0;
      for (int j = std::max(1, i - 7); j <= i; ++j) {
        // we needn't consider string_in[0], as it is '-'
        temp *= 10;
        temp += string_in[j] - '0';
      }
      big_num.push_back(temp);
    }
  } else { // positive, consider every digit
    for (int i = string_in.length() - 1; i >= 0; i -= 8) {
      int temp = 0;
      for (int j = std::max(0, i - 7); j <= i; ++j) {
        temp *= 10;
        temp += string_in[j] - '0';
      }
      big_num.push_back(temp);
    }
  }
}
inline sjtu::int2048::int2048(const sjtu::int2048 &mirror) {
  // duplicating
  big_num.clear();
  negative_check = mirror.negative_check;
  for (int i = 0; i < mirror.big_num.size(); ++i) {
    big_num.push_back(mirror.big_num[i]);
  }
  while ((big_num.size() > 1) && big_num.back() == 0) {
    big_num.pop_back();
  }
}
inline void sjtu::int2048::print() {
  if (big_num.empty()) {
    std::cout << 0;
    return;
  }
  if (negative_check) std::cout << '-';
  std::cout << big_num.back(); // we needn't zero in the very front
  for (int i = big_num.size() - 2; i >= 0; --i) {
    if (big_num[i] < 10) { // we need to fill the blank spaces
      std::cout << "0000000";
    } else if (big_num[i] < 100) {
      std::cout << "000000";
    } else if (big_num[i] < 1000) {
      std::cout << "00000";
    } else if (big_num[i] < 10000) {
      std::cout << "0000";
    } else if (big_num[i] < 100000) {
      std::cout << "000";
    } else if (big_num[i] < 1000000) {
      std::cout << "00";
    } else if (big_num[i] < 10000000) {
      std::cout << "0";
    }
    std::cout << big_num[i];
  }
}
inline void sjtu::int2048::read(const std::string &string_in) {
  //std::cin.tie(nullptr);
  // similar to initialization of string
  {
    big_num.clear();
    negative_check = false;
    if (string_in[0] == '-') {
      negative_check = true;
      for (int i = string_in.length() - 1; i > 0; i -= 8) {
        int temp = 0;
        for (int j = std::max(1, i - 7); j <= i; ++j) {
          temp *= 10;
          temp += string_in[j] - '0';
        }
        big_num.push_back(temp);
      }
    } else {
      for (int i = string_in.length() - 1; i >= 0; i -= 8) {
        int temp = 0;
        for (int j = std::max(0, i - 7); j <= i; ++j) {
          temp *= 10;
          temp += string_in[j] - '0';
        }
        big_num.push_back(temp);
      }
    }
  }
}
inline sjtu::int2048 &sjtu::int2048::operator=(const sjtu::int2048 &initializer) {
  if (this != &initializer) {
    big_num.clear();
    negative_check = initializer.negative_check;
    for (int i = 0; i < initializer.big_num.size(); ++i) {
      big_num.push_back(initializer.big_num[i]);
    }
  }
  return *this;
}
inline sjtu::int2048 &sjtu::int2048::add(const sjtu::int2048 &big_add) {
  return *this = *this + big_add;
}
inline sjtu::int2048 sjtu::add(const sjtu::int2048 &add_1, const sjtu::int2048 &add_2) {
  return add_1 + add_2;
}
inline bool sjtu::operator<(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1.negative_check && !cmp_2.negative_check) return true;
  // negative numbers are always smaller than big numbers
  if (!cmp_1.negative_check && cmp_2.negative_check) return false;
  if (cmp_1.negative_check) { // both are negative
    if (cmp_1.big_num.size() < cmp_2.big_num.size()) return false;
    if (cmp_1.big_num.size() > cmp_2.big_num.size()) return true;
    for (int i = cmp_1.big_num.size() - 1; i >= 0; --i) {
      if (cmp_1.big_num[i] > cmp_2.big_num[i]) return true;
      if (cmp_1.big_num[i] < cmp_2.big_num[i]) return false;
    }
    return false;
  } else { // both are positive
    if (cmp_1.big_num.size() < cmp_2.big_num.size()) return true;
    if (cmp_1.big_num.size() > cmp_2.big_num.size()) return false;
    for (int i = cmp_1.big_num.size() - 1; i >= 0; --i) {
      if (cmp_1.big_num[i] > cmp_2.big_num[i]) return false;
      if (cmp_1.big_num[i] < cmp_2.big_num[i]) return true;
    }
    return false;
  }
}
inline sjtu::int2048 sjtu::abs(sjtu::int2048 initializer) {
  initializer.negative_check = false;
  return initializer;
}
inline sjtu::int2048 &sjtu::int2048::minus(const int2048 &minus_2) {
  return *this = *this - minus_2;
}
inline sjtu::int2048 sjtu::minus(const int2048 &minus_1, const int2048 &minus_2) {
  return minus_1 - minus_2;
}
inline sjtu::int2048 sjtu::operator+(const int2048 &add_1, const int2048 &add_2) {
  int2048 add_ans;
  if (!(add_1.negative_check ^ add_2.negative_check)) { // the basic adding
    add_ans.negative_check = add_1.negative_check;
    int carrier = 0;
    for (int i = 0; i < std::max(add_1.big_num.size(), add_2.big_num.size()); ++i) {
      int temp = carrier;
      if (i < add_1.big_num.size()) temp += add_1.big_num[i];
      if (i < add_2.big_num.size()) temp += add_2.big_num[i];
      carrier = temp / 100000000;
      temp %= 100000000;
      add_ans.big_num.push_back(temp);
    }
    if (carrier) add_ans.big_num.push_back(1);
    return add_ans;
  } else {
    // consider using minus
    if (!add_1.negative_check) {
      return minus(add_1, abs(add_2));
    }
    if (add_1.negative_check) {
      add_ans = minus(abs(add_1), add_2);
      add_ans.negative_check = !add_ans.negative_check;
      return add_ans;
    }
  }
}
inline bool sjtu::operator>(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1.negative_check && !cmp_2.negative_check) return false;
  if (!cmp_1.negative_check && cmp_2.negative_check) return true;
  if (cmp_1.negative_check) { // both are negative
    if (cmp_1.big_num.size() < cmp_2.big_num.size()) return true;
    if (cmp_1.big_num.size() > cmp_2.big_num.size()) return false;
    for (int i = cmp_1.big_num.size() - 1; i >= 0; --i) {
      if (cmp_1.big_num[i] > cmp_2.big_num[i]) return false;
      if (cmp_1.big_num[i] < cmp_2.big_num[i]) return true;
    }
    return false;
  } else { // both are positive
    if (cmp_1.big_num.size() < cmp_2.big_num.size()) return false;
    if (cmp_1.big_num.size() > cmp_2.big_num.size()) return true;
    for (int i = cmp_1.big_num.size() - 1; i >= 0; --i) {
      if (cmp_1.big_num[i] > cmp_2.big_num[i]) return true;
      if (cmp_1.big_num[i] < cmp_2.big_num[i]) return false;
    }
    return false;
  }
}
inline bool sjtu::operator==(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1.negative_check != cmp_2.negative_check) {
    // saving time
    return false;
  }
  if (cmp_1.big_num.size() != cmp_2.big_num.size()) {
    return false;
  }
  for (int i = 0; i < cmp_1.big_num.size(); ++i) {
    if (cmp_1.big_num[i] != cmp_2.big_num[i]) {
      return false;
    }
  }
  return true;
}
inline bool sjtu::operator!=(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1.negative_check != cmp_2.negative_check) {
    // saving time
    return true;
  }
  if (cmp_1.big_num.size() != cmp_2.big_num.size()) {
    return true;
  }
  for (int i = 0; i < cmp_1.big_num.size(); ++i) {
    if (cmp_1.big_num[i] != cmp_2.big_num[i]) {
      return true;
    }
  }
  return false;
}
inline sjtu::int2048 sjtu::operator-(const sjtu::int2048 &minus_1, const sjtu::int2048 &minus_2) {
  int2048 minus_ans;
  if ((!minus_1.negative_check) && (minus_2.negative_check)) { // similar to adding
    return minus_1 + abs(minus_2);
  } else if (minus_1.negative_check && (!minus_2.negative_check)) {
    minus_ans = abs(minus_1) + minus_2;
    minus_ans.negative_check = true;
    return minus_ans;
  } else if (!minus_1.negative_check) {
    int carrier = 0;
    int temp;
    if (minus_1 >= minus_2) { // always putting the bigger one in the front
      temp = 0;
      for (int i = 0; i < std::max(minus_1.big_num.size(), minus_2.big_num.size()); ++i) {
        temp = 0;
        temp -= carrier;
        temp += minus_1.big_num[i];
        if (i < minus_2.big_num.size()) {
          temp -= minus_2.big_num[i];
        }
        if (temp < 0) {
          temp += 100000000;
          carrier = 1;
        } else {
          carrier = 0;
        }
        minus_ans.big_num.push_back(temp);
      }
      while ((minus_ans.big_num.size() > 1) && minus_ans.big_num.back() == 0) {
        minus_ans.big_num.pop_back();
      }
      return minus_ans;
    } else {
      minus_ans = minus(minus_2, minus_1);
      minus_ans.negative_check = true;
      return minus_ans;
    }
  } else {
    if (minus_1 < minus_2) { // swap the order, and changing the sign
      minus_ans = minus(abs(minus_1), abs(minus_2));
      minus_ans.negative_check = true;
      return minus_ans;
    } else {
      minus_ans = minus(abs(minus_2), abs(minus_1));
      minus_ans.negative_check = false;
      return minus_ans;
    }
  }
}
inline bool sjtu::operator<=(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1 > cmp_2) return false;
  return true;
}
inline bool sjtu::operator>=(const sjtu::int2048 &cmp_1, const sjtu::int2048 &cmp_2) {
  if (cmp_1 < cmp_2) return false;
  return true;
}
inline sjtu::int2048 &sjtu::int2048::operator+=(const sjtu::int2048 &big_add) {
  return *this = *this + big_add;
}
inline sjtu::int2048 &sjtu::int2048::operator-=(const sjtu::int2048 &big_minus) {
  return *this = *this - big_minus;
}
inline std::istream &sjtu::operator>>(std::istream &in, sjtu::int2048 &big_in) {
  // return in!!!
  // similar to read(string)
  std::string string_in;
  std::cin >> string_in;
  big_in.big_num.clear();
  big_in.negative_check = false;
  if (string_in[0] == '-') {
    big_in.negative_check = true;
    for (int i = string_in.length() - 1; i > 0; i -= 8) {
      int temp = 0;
      for (int j = std::max(1, i - 7); j <= i; ++j) {
        temp *= 10;
        temp += string_in[j] - '0';
      }
      big_in.big_num.push_back(temp);
    }
  } else {
    for (int i = string_in.length() - 1; i >= 0; i -= 8) {
      int temp = 0;
      for (int j = std::max(0, i - 7); j <= i; ++j) {
        temp *= 10;
        temp += string_in[j] - '0';
      }
      big_in.big_num.push_back(temp);
    }
  }
  return in;
}
inline std::ostream &sjtu::operator<<(std::ostream &out, const sjtu::int2048 &big_out) {
  //std::cout.tie(nullptr);
  // return out
  // similar to print
  if (big_out.big_num.empty()) {
    out << 0;
  } else {
    if (big_out.negative_check) out << '-';
    out << big_out.big_num.back();
    for (int i = big_out.big_num.size() - 2; i >= 0; --i) {
      if (big_out.big_num[i] < 10) {
        out << "0000000";
      } else if (big_out.big_num[i] < 100) {
        out << "000000";
      } else if (big_out.big_num[i] < 1000) {
        out << "00000";
      } else if (big_out.big_num[i] < 10000) {
        out << "0000";
      } else if (big_out.big_num[i] < 100000) {
        out << "000";
      } else if (big_out.big_num[i] < 1000000) {
        out << "00";
      } else if (big_out.big_num[i] < 10000000) {
        out << "0";
      }
      out << big_out.big_num[i];
    }
  }
  return out;
}
inline sjtu::int2048 sjtu::operator*(const sjtu::int2048 &multi_1, const sjtu::int2048 &multi_2) {
  int2048 multi_ans;
  int carrier;
  multi_ans.negative_check = multi_1.negative_check ^ multi_2.negative_check;
  for (int i = 0; i < multi_1.big_num.size(); ++i) {
    // multiplying from right to left
    carrier = 0;
    for (int j = 0; j < multi_2.big_num.size(); ++j) {
      if (multi_ans.big_num.empty() || multi_ans.big_num.size() - 1 < i + j) {
        multi_ans.big_num.push_back(multi_1.big_num[i] * multi_2.big_num[j] + carrier);
      } else {
        multi_ans.big_num[i + j] += multi_1.big_num[i] * multi_2.big_num[j] + carrier;
      }
      carrier = multi_ans.big_num[i + j] / 100000000;
      multi_ans.big_num[i + j] %= 100000000;
    }
    if (carrier > 0) {
      multi_ans.big_num.push_back(carrier); // carrying
    }
  }
  while ((multi_ans.big_num.size() > 1) && multi_ans.big_num.back() == 0) {
    multi_ans.big_num.pop_back();
  }
  return multi_ans;
}
inline sjtu::int2048 &sjtu::int2048::operator*=(const sjtu::int2048 &big_multi) {
  return *this = *this * big_multi;
}
inline sjtu::int2048 sjtu::operator/(const sjtu::int2048 &divide_1, const sjtu::int2048 &divide_2) {
  int2048 divide_ans;
  // special judgement
  if (abs(divide_1) < abs(divide_2)) {
    divide_ans = 0;
  } else if (abs(divide_2) == 1) {
    if (divide_2 == 1) {
      return divide_1;
    }
    divide_ans = divide_1;
    divide_ans.negative_check = !divide_ans.negative_check;
    return divide_ans;
  } else {
    int2048 temp;
    int2048 abs_1 = abs(divide_1);
    int2048 abs_2 = abs(divide_2); // consider unsigned integer division
    int2048 carrier;
    int start = abs_1.big_num.size() - 1;
    int end = abs_2.big_num.size() - 1;
    for (int i = start; i >= end; i--) {
      int2048 small_temp; // simulating normal division
      if (i == start) {
        for (int j = i - end; j <= i; ++j) {
          small_temp.big_num.push_back(abs_1.big_num[j]);
        }
      } else {
        small_temp.big_num.push_back(abs_1.big_num[i - end]);
        for (int j = 0; j < carrier.big_num.size(); ++j) {
          small_temp.big_num.push_back(carrier.big_num[j]);
        }
      }
      while ((small_temp.big_num.size() > 1) && small_temp.big_num.back() == 0) {
        small_temp.big_num.pop_back();
      }
      std::cout << small_temp << '\n';
      long long left, right;
      if (small_temp.big_num.back() - 1 < abs_2.big_num.back() && small_temp.big_num.size() == abs_2.big_num.size()) {
        left = 0;
        right = 1;
      } else if (small_temp.big_num.size() == abs_2.big_num.size()) {
        left = (small_temp.big_num.back()) / (abs_2.big_num.back() + 1);
        right = (small_temp.big_num.back() + 1) / (abs_2.big_num.back());
      } else {
        left = (100000000 * small_temp.big_num.back()) / (abs_2.big_num.back() + 1);
        right = (100000000 * (small_temp.big_num.back() + 1)) / (abs_2.big_num.back());
      }
      int mid = (left + right) >> 1;
      int2048 remain = small_temp - mid * abs_2;
      while (left < right) {
        if (remain >= 0 && remain < abs_2) {
          break;
        }
        if (remain < 0) {
          right = mid;
          mid = (left + right) >> 1;
          remain = small_temp - mid * abs_2;
        } else {
          left = mid + 1;
          mid = (left + right) >> 1;
          remain = small_temp - mid * abs_2;
        }
      } // binary division
      if (mid != 0 || i != start)
        temp.big_num.push_back(mid); // updating the quotient
      carrier = remain; // updating the remainder
      std::cout << remain << '\n';
    }
    for (int i = temp.big_num.size() - 1; i >= 0; --i) {
      divide_ans.big_num.push_back(temp.big_num[i]);
    }
    divide_ans.negative_check = divide_1.negative_check ^ divide_2.negative_check;
  }
  return divide_ans;
}
inline sjtu::int2048 &sjtu::int2048::operator/=(const sjtu::int2048 &divider) {
  return *this = *this / divider;
}
}