#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <print>
#include <string>
#include <vector>

std::vector<std::string> perms(std::string curr, std::vector<std::string> set,
                               std::vector<std::string> acc) {
  if (curr.length() == 10)
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
uint64_t get_number(std::string_view s) {
  uint64_t result{};
  auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.length(), result);
  if (ec == std::errc()) {
    return result;
  }
  return -1;
}
int main() {
  std::vector<std::string> strings =
      perms("", {"9", "8", "7", "6", "5", "4", "3", "2", "1", "0"}, {});
  uint64_t answer = 0;
  for (const auto &s : strings) {
    const std::string_view sv1 = std::string_view(s.begin() + 1, s.begin() + 4);
    const std::string_view sv2 = std::string_view(s.begin() + 2, s.begin() + 5);
    const std::string_view sv3 = std::string_view(s.begin() + 3, s.begin() + 6);
    const std::string_view sv4 = std::string_view(s.begin() + 4, s.begin() + 7);
    const std::string_view sv5 = std::string_view(s.begin() + 5, s.begin() + 8);
    const std::string_view sv6 = std::string_view(s.begin() + 6, s.begin() + 9);
    const std::string_view sv7 =
        std::string_view(s.begin() + 7, s.begin() + 10);
    uint64_t first_num = get_number(sv1);
    uint64_t second_num = get_number(sv2);
    uint64_t third_num = get_number(sv3);
    uint64_t fourth_num = get_number(sv4);
    uint64_t fifth_num = get_number(sv5);
    uint64_t sixth_num = get_number(sv6);
    uint64_t seventh_num = get_number(sv7);
    if (first_num % 2 == 0 && second_num % 3 == 0 && third_num % 5 == 0 &&
        fourth_num % 7 == 0 && fifth_num % 11 == 0 && sixth_num % 13 == 0 &&
        seventh_num % 17 == 0) {
      answer += get_number(s);
    }
  }
  std::println("{}", answer);
}
