#include <iostream>
#include <vector>
#include <list>

std::list<int> parni_neparni(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) {
  
  std::list<int> result;

  while (begin != end) {
    if (*begin % 2 == 0) {
      result.push_front(*begin);
    } else result.push_back(*begin);

    begin++;
  }

  return result;
};

int main() {

  std::list<int> numbers{3,2,5,10,-15,-99,6,8,11};
  auto sorted = parni_neparni(numbers.begin(), numbers.end()); //cbegin() metod vrati constantan iterator ali posto postojii implicitna konverzija iz obicnog u konstanti, moze se i begin() obicno koristit

  for (const int &x : sorted) std::cout<<x<<" ";

return 0;
}
