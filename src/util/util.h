/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#ifndef SHADOWSOCKS_UTIL_UTIL_H
#define SHADOWSOCKS_UTIL_UTIL_H

#include <string_view>

#include "absl/strings/numbers.h"
#include "google/protobuf/message.h"
#include "google/protobuf/util/json_util.h"

namespace shadowsocks {
namespace util {

class Util {
 private:
  Util() {}
  ~Util() {}

 public:
  static void SetUp() {
    option.add_whitespace = false;
    option.always_print_enums_as_ints = false;
    option.always_print_primitive_fields = true;
    option.preserve_proto_field_names = true;
  }

  static int64_t CurrentUnixNanos();

  static int64_t CurrentUnixMillis();

  static int64_t ToUnixMillis(
      std::string_view time,
      std::string_view format = "%Y-%m-%d%ET%H:%M:%E3S%Ez");

  static std::string UnixMillisToString(
      const int64_t ms, std::string_view format = "%Y-%m-%d %H:%M:%S");

  static int64_t Random(int64_t low, int64_t upper);

  static void Sleep(int64_t ms);

  static std::string DirName(std::string_view path);

  static std::string BaseName(std::string_view path);

  static std::string Extention(std::string_view path);

  static bool StartWith(std::string_view in, std::string_view prefix);

  static void ToUpper(std::string_view in, std::string *out);

  static void ToUpper(std::string *in);

  static void ToLower(std::string_view in, std::string *out);

  static void ToLower(std::string *in);

  static void Trim(std::string &in);

  template <class IntegerType>
  static bool ToInteger(std::string_view in, IntegerType *out) {
    // auto result = std::from_chars(in.data(), in.data() + in.size(), *out);
    // if (result.ec != std::errc{}) {
    // return false;
    // }
    // return true;
    return absl::SimpleAtoi(in, out);
  }

  static bool HexToUInt64(std::string_view in, uint64_t *out);

  static void ToHexStr(const unsigned char *in, size_t len, std::string *out,
                       bool upper_case = false);

  static void ToHexStr(const uint64_t in, std::string *out,
                       bool upper_case = false);

  static void ReplaceAll(std::string &in, std::string_view from,
                         std::string_view to);

  static void Split(std::string_view in, std::string_view delim,
                    std::vector<std::string> &result);

  static void Base64Encode(std::string_view in, std::string *out);

  static void Base64Decode(std::string_view in, std::string *out);

  static void Md5(std::string_view in, std::string *out,
                  bool upper_case = false);

  static void FileMd5(const std::string &path, std::string *out,
                      bool upper_case = false);

  static bool PrintProtoMessage(const google::protobuf::Message &msg,
                                std::string *out);

 public:
  static google::protobuf::util::JsonOptions option;
  static std::string ip;
};

}  // namespace util
}  // namespace shadowsocks

#endif /* SHADOWSOCKS_UTIL_UTIL_H */
