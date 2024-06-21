/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "gflags/gflags.h"
#include "gtest/gtest.h"
#include "src/util/util.h"

class GTestEnvironment : public testing::Environment {
 public:
  virtual void SetUp() { shadowsocks::util::Util::SetUp(); }
  virtual void TearDown() {}
};

int main(int argc, char **argv) {
  testing::AddGlobalTestEnvironment(new GTestEnvironment);
  testing::InitGoogleTest(&argc, argv);
  google::ParseCommandLineFlags(&argc, &argv, true);
  return RUN_ALL_TESTS();
}
