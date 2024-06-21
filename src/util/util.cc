/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/util/util.h"

#include <cctype>
#include <cstddef>
#include <exception>
#include <filesystem>
#include <random>
#include <string_view>
#include <thread>
#include <vector>

#include "absl/strings/str_split.h"
#include "absl/time/clock.h"
#include "boost/algorithm/string.hpp"
#include "boost/algorithm/string/trim_all.hpp"
#include "boost/beast/core/detail/base64.hpp"
#include "boost/iostreams/device/mapped_file.hpp"
#include "fmt/core.h"
#include "glog/logging.h"
#include "openssl/md5.h"

using std::string;
using std::string_view;
using std::vector;
using namespace google::protobuf::util;

namespace shadowsocks {
namespace util {

JsonPrintprint_opts Util::print_opt;

int64_t Util::CurrentUnixNanos() { return absl::GetCurrentTimeNanos(); }

int64_t Util::CurrentUnixMillis() {
  return absl::GetCurrentTimeNanos() / 1000000;
}

int64_t Util::ToUnixMillis(string_view time, string_view format) {
  absl::Time t;
  string err;
  if (!absl::ParseTime(format, time, &t, &err)) {
    return -1;
  }
  return absl::ToUnixMillis(t);
}

string Util::UnixMillisToString(const int64_t ms, string_view format) {
  absl::TimeZone time_zone;
  absl::LoadTimeZone("Asia/Shanghai", &time_zone);
  return absl::FormatTime(format, absl::FromUnixMillis(ms), time_zone);
}

int64_t Util::Random(int64_t low, int64_t upper) {
  static thread_local std::mt19937 generator(CurrentUnixNanos());
  std::uniform_int_distribution<int64_t> distribution(low, upper - 1);
  return distribution(generator);
}

void Util::Sleep(int64_t ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

string Util::DirName(string_view path) {
  std::filesystem::path file_path(path);
  return file_path.parent_path().string();
}

string Util::BaseName(string_view path) {
  std::filesystem::path file_path(path);
  return file_path.filename().string();
}

std::string Util::Extention(string_view path) {
  std::filesystem::path file_path(path);
  return file_path.extension().string();
}

std::string Util::LoadContent(string_view path) {
  std::filesystem::path file_path(path);
  try {
    boost::iostreams::mapped_file_source mapped_file(file_path);
    return mapped_file.data();
  } catch (const std::exception &e) {
    LOG(ERROR) << "map " << path << " error, " << e.what();
  }
}

bool Util::StartWith(string_view in, string_view prefix) {
  return boost::starts_with(in, prefix);
}

void Util::ToUpper(string_view in, string *out) {
  out->assign(in);
  std::transform(out->begin(), out->end(), out->begin(),
                 [](unsigned char c) { return std::toupper(c); });
}

void Util::ToUpper(string *in) {
  std::transform(in->begin(), in->end(), in->begin(), ::toupper);
}

void Util::ToLower(string_view in, string *out) {
  out->assign(in);
  std::transform(out->begin(), out->end(), out->begin(),
                 [](unsigned char c) { return std::tolower(c); });
}

void Util::ToLower(string *in) {
  std::transform(in->begin(), in->end(), in->begin(), ::tolower);
}

void Util::Trim(string &in) { boost::algorithm::trim_all(in); }

bool Util::HexToUInt64(string_view in, uint64_t *out) {
  return absl::SimpleHexAtoi(in, out);
}

void Util::ToHexStr(const unsigned char *in, size_t len, string *out,
                    bool upper_case) {
  out->reserve(len * 2);
  if (upper_case) {
    for (size_t i = 0; i < len; ++i) {
      out->append(fmt::format("{:02X}", in[i]));
    }
    return;
  }

  for (size_t i = 0; i < len; ++i) {
    out->append(fmt::format("{:02x}", in[i]));
  }
}

void Util::ToHexStr(const uint64_t in, string *out, bool upper_case) {
  out->reserve(16);
  if (upper_case) {
    *out = fmt::format("{:016X}", in);
    return;
  }
  *out = fmt::format("{:016x}", in);
}

void Util::ReplaceAll(string &in, string_view from, string_view to) {
  boost::algorithm::replace_all(in, from, to);
}

void Util::Split(string_view in, string_view delim, vector<string> &result) {
  for (const auto sv : absl::StrSplit(in, delim)) {
    result.emplace_back(sv);
  }
}

void Util::Base64Encode(string_view in, string *out) {
  out->resize(boost::beast::detail::base64::encoded_size(in.size()));
  boost::beast::detail::base64::encode(out->data(), in.data(), in.size());
}

void Util::Base64Decode(string_view in, string *out) {
  out->resize(boost::beast::detail::base64::decoded_size(in.size()));
  auto ret =
      boost::beast::detail::base64::decode(out->data(), in.data(), in.size());
  out->resize(ret.first);
}

void Util::Md5(string_view in, string *out, bool upper_case) {
  unsigned char result[MD5_DIGEST_LENGTH];
  MD5((unsigned char *)in.data(), in.size(), result);
  out->reserve(MD5_DIGEST_LENGTH * 2);
  ToHexStr(result, MD5_DIGEST_LENGTH, out, upper_case);
}

void Util::FileMd5(const string &path, string *out, bool upper_case) {
  unsigned char result[MD5_DIGEST_LENGTH];
  try {
    boost::iostreams::mapped_file_source mapped_file(path);
    MD5((unsigned char *)mapped_file.data(), mapped_file.size(), result);
    ToHexStr(result, MD5_DIGEST_LENGTH, out, upper_case);
  } catch (const std::exception &e) {
    LOG(ERROR) << "map " << path << " error, " << e.what();
  }
}

bool Util::PrintProto(const google::protobuf::Message &msg, string *out) {
  if (!MessageToJsonString(msg, out, print_opt).ok()) {
    return false;
  }
  return true;
}

}  // namespace util
}  // namespace shadowsocks
