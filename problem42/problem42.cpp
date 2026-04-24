#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <vector>
int triangle_number(int n) { return n * (n + 1) / 2; }
int main() {
  std::ifstream file("0042_words.txt");
  int triangle_numbers{};
  while (!file.eof()) {
    std::string word;
    std::getline(file, word, ',');
    word = std::string(word.begin() + 1, word.begin() + word.length() - 1);
    int sum{};
    for (const auto &c : word) {
      sum += ((int)c - (int)'A') + 1;
    }
    for (int i = 1; i <= 10'000; ++i) {
      if (sum == triangle_number(i)) {
        ++triangle_numbers;
      }
    }
  }
  std::println("{}", triangle_numbers);
  return 0;
}
