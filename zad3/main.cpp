#include <iostream>
#include <functional>
#include <vector>
#include <list>

std::list<int> partition(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> check) {

  std::list<int> result;
  std::list<int>::const_iterator it1 = begin;
  
  try {
    while(it1 != end) {
      if (check(*it1)) result.push_front(*it1); else result.push_back(*it1);
      it1++;
    };
  } catch (int e) {
    result.assign(begin, end);
  }

  return result;
};


int main() {

  std::list<int> nums{15, 40, 25, -10, -75, 100, -255, 40, 200};
  std::cout << "Original list:\n";
  for (const auto &x : nums) std::cout << x << " ";
  std::cout << std::endl;

  auto predicate = [](int num) {
    if (num > 400) throw 5; else return num > 0;
  };

  auto result = partition(nums.cbegin(), nums.cend(), predicate);

  std::cout << "Changed list:\n";
  for (const auto &num : result) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
