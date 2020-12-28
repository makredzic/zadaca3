#pragma once
#include <functional>

namespace my {

  template<typename iter, typename lambda> void sort(iter p, iter k, lambda f) {
    if (p == k) return;
    bool swapped;
    iter it = p;
    iter last_swap = --k;
    do {
      swapped = false;  
      while (it != last_swap) {
        if (f(*it, *(std::next(it)))) {

          swapped = true;
        }
        p++;
      }
      last_swap = p;
      std::advance(last_swap, std::distance(p, it)-1);
      it = p;
    } while(swapped);
  }

  template<typename iter> void sort(iter p, iter k) {
    if (p == k) return;
    bool swapped;
    iter last_swap = --k;
    do {
      swapped = false;  
      while (p != last_swap) {
        if (*p > *(++p)) {
          auto x = *p;
          *p = *(++p);
          *(++p) = x;
          swapped = true;
        }
        p++;
      }
    } while(swapped);

  }

}
