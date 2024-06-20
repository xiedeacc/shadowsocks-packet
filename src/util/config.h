/*******************************************************************************
 * Copyright (c) 2024  xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#ifndef SHADOWSOCKS_UTIL_CONFIG_H
#define SHADOWSOCKS_UTIL_CONFIG_H

#include <string>

#include "gflags/gflags.h"
#include "src/proto/config.pb.h"
#include "src/util/singleton.h"
#include "src/util/util.h"

DECLARE_string(config_path);

namespace shadowsocks {
namespace util {

class Config : public Singleton<Config> {
  friend class SingletonBase<Config>;

 private:
  Config() {}

  virtual ~Config() {}

 public:
  bool Init() {}

 private:
  std::string config_path_;
};

}  // namespace util
}  // namespace shadowsocks

#endif /* SHADOWSOCKS_UTIL_CONFIG_H */
