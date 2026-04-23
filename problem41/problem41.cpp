#include <algorithm>
#include <charconv>
#include <cmath>
#include <iostream>
#include <print>
#include <string>
#include <vector>

std::vector<std::string> perms(std::string curr, std::vector<std::string> set,
                               std::vector<std::string> acc) {
  acc.push_back(curr);
  for (int idx = 0; idx < set.size(); ++idx) {
    const std::string &digit = set[idx];
    auto set_cpy = set;
    set_cpy.erase(set_cpy.begin() + idx);
    auto first = perms(curr + digit, set_cpy, {});
    acc.insert(acc.end(), first.begin(), first.end());
  }
  return acc;
}
bool check_prime(int n) {
  int root = (int)std::sqrt(n);
  for (int factor = 2; factor <= root + 1; ++factor) {
    if (n % factor == 0) {
      if (n == 987654321)
        std::println("{} {}", n, factor);
      return false;
    }
  }
  return true;
}
int main() {
  std::vector<std::string> numbers =
      perms("", {"9", "8", "7", "6", "5", "4", "3", "2", "1"}, {});
  std::vector<std::string> filtered;
  for (const auto &s : numbers) {
    int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto &c : s) {
      switch (c) {
      case '1':
        digits[0] = 0;
        break;
      case '2':
        digits[1] = 0;
        break;
      case '3':
        digits[2] = 0;
        break;
      case '4':
        digits[3] = 0;
        break;
      case '5':
        digits[4] = 0;
        break;
      case '6':
        digits[5] = 0;
        break;
      case '7':
        digits[6] = 0;
        break;
      case '8':
        digits[7] = 0;
        break;
      case '9':
        digits[8] = 0;
        break;
      default:
        break;
      }
    }
    bool all_zero = true;
    for (int i = 0; i < s.length(); ++i) {
      all_zero = all_zero && (digits[i] == 0);
    }
    if (all_zero) {
      filtered.push_back(s);
    }
  }
  int max_pandigital = 0;
  int non_primes = 0;
  for (const auto &s : filtered) {
    int result{};
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.length(), result);
    if (ec == std::errc()) {
      if (check_prime(result)) {
        max_pandigital = std::max(max_pandigital, result);
      } else {
        ++non_primes;
      }
    }
  }
  std::println("{}", max_pandigital);
}
