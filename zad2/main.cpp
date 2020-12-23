#include <iostream>
#include <functional>
#include <vector>
#include <list>

std::list<int> partition(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> check) {

  std::list<int> result;
  while(begin != end) {
    if (check(*begin)) result.push_front(*begin); else result.push_back(*begin);
    begin++;
  };



  return result;
};

int main() {

  std::list<int> nums{15, 20, 25, -10, -75, 100, -255, 430, 200};
  auto result = partition(nums.cbegin(), nums.cend(), [](int num) {return !(num%2);});

  for (const auto &num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
