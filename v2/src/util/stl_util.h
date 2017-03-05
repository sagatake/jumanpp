//
// Created by Arseny Tolmachev on 2017/02/28.
//

#ifndef JUMANPP_STL_UTIL_H
#define JUMANPP_STL_UTIL_H

#include <initializer_list>

namespace jumanpp {
namespace util {

template <typename C, typename I>
inline bool contains(const C& c, const I& i) {
  for (auto&& x : c) {
    if (x == i) {
      return true;
    }
  }
  return false;
}

template <typename T>
inline bool contains(std::initializer_list<T> data, const T& obj) {
  return contains<std::initializer_list<T>, T>(data, obj);
}

template <typename C1, typename C2>
inline void copy(const C1& data, C2& result) {
  std::copy(std::begin(data), std::end(data), std::back_inserter(result));
}

template <typename C1, typename Fn = std::less<typename C1::value_type>>
inline void sort(C1& c, Fn fn) {
  std::sort(std::begin(c), std::end(c), fn);
};

}  // util
}  // jumanpp

#endif  // JUMANPP_STL_UTIL_H