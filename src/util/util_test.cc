/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/util/util.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

using namespace std;

namespace shadowsocks {
namespace util {

TEST(Util, StrTimeToTimestamp) {
  auto timestamp = Util::ToUnixMillis("2023-10-08T16:34:31.000+0000");
  LOG(INFO) << "timestamp: " << timestamp;
  EXPECT_EQ(timestamp, 1696782871000);
}

// TEST(Util, LoadContent) {
// auto content = Util::LoadContent(string("test_data/config/config.json"));
// LOG(INFO) << content;
// }

TEST(Util, ToInteger) {
  auto str = "500";
  uint32_t value;
  ASSERT_EQ(true, Util::ToInteger(str, &value));
  ASSERT_EQ(500, value);
}

TEST(Util, HexToUInt64) {
  uint64_t qid = 0;
  Util::HexToUInt64("2eb568d3e24a5e69", &qid);
  LOG(INFO) << "qid: " << qid;
  EXPECT_EQ(qid, 3365711555773226601);
}

TEST(Util, ToHexStr) {
  string sid;
  Util::ToHexStr(6171972363329882614, &sid);
  EXPECT_EQ(sid, "55a74029f7ce49f6");

  Util::ToHexStr(363455392779079689, &sid);
  EXPECT_EQ(sid, "050b40c10a4c1009");
}

TEST(Util, Base64EncodeDecode) {
  std::string input = "Send reinforcements";
  std::string encode_output;
  Util::Base64Encode(input, &encode_output);
  EXPECT_EQ(encode_output, "U2VuZCByZWluZm9yY2VtZW50cw==");
  EXPECT_EQ(encode_output.size(),
            std::string("U2VuZCByZWluZm9yY2VtZW50cw==").size());

  std::string decode_output;
  Util::Base64Decode(encode_output, &decode_output);
  EXPECT_EQ(decode_output, input);
}

TEST(Util, FileMd5) {
  std::string md5_value;
  Util::FileMd5("test_data/config/config.json", &md5_value);
  std::string real_md5 = "579627b6ce697863f94dcb9679392be2";
  EXPECT_EQ(md5_value, real_md5);

  md5_value.clear();
  Util::FileMd5("test_data/file/empty_file", &md5_value);
  EXPECT_EQ(md5_value, "");
}

TEST(Util, PrintProto) {
  std::string real_md5 = "579627b6ce697863f94dcb9679392be2";
  EXPECT_EQ(md5_value, real_md5);

  md5_value.clear();
  Util::FileMd5("test_data/file/empty_file", &md5_value);
  EXPECT_EQ(md5_value, "");
}

}  // namespace util
}  // namespace shadowsocks
