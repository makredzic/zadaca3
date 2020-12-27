#include <iostream>
#include <string>

template<typename Iter> bool jednako(Iter it1begin, Iter it1end, Iter it2begin) {
    while(it1begin != it1end) {
     if (*it1begin != *it2begin) return false; 
      it1begin++;
      it2begin++;
    }
    return true;
}

int main() {

  std::string rijec;
  std::cout << "Unesite rijec: ";

  while(std::cin >> rijec) {
    std::string reverse = std::string(rijec.rbegin(), rijec.rend());
    if (jednako(rijec.begin(), rijec.end(), reverse.begin())) std::cout << "Rijec je palindrom.\n"; else std::cout<< "Rijec nije palindrom.\n";
  }


return 0;
}
