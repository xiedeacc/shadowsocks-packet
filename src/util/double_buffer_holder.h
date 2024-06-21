/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#ifndef SHADOWSOCKS_UTIL_DOUBLE_BUFFER_HOLDER_H
#define SHADOWSOCKS_UTIL_DOUBLE_BUFFER_HOLDER_H

#include <atomic>

namespace shadowsocks {
namespace util {

template <typename TypeName>
class DoubleBufferHolder {
 public:
  DoubleBufferHolder() : pos_(0) {}

  bool Store(const std::string &value) {
    bool ret = buffer_[1 - pos_.load()].Make(value);
    if (ret) {
      pos_.store(1 - pos_.load());
    }
    return ret;
  }

  TypeName &Get() { return buffer_[pos_.load()]; }

 private:
  TypeName buffer_[2];
  std::atomic<int> pos_;
};

}  // namespace util
}  // namespace shadowsocks

#endif /* SHADOWSOCKS_UTIL_DOUBLE_BUFFER_HOLDER_H */
