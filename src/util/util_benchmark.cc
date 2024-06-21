/*******************************************************************************
 * Copyright (c) 2024 xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "absl/time/clock.h"
#include "benchmark/benchmark.h"
#include "src/util/util.h"

namespace shadowsocks {
namespace util {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-value"
static void AbslNow(benchmark::State& state) {
  for (auto _ : state) {
    absl::GetCurrentTimeNanos() / 1000000;
  }
}
BENCHMARK(AbslNow);
BENCHMARK(AbslNow)->UseRealTime()->Threads(16)->Threads(32)->ThreadPerCpu();

int64_t CurrentUnixNanos() {
  const auto& now = std::chrono::system_clock::now().time_since_epoch();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();
}

static void StdNow(benchmark::State& state) {
  for (auto _ : state) {
    CurrentUnixNanos() / 1000000;
  }
}

BENCHMARK(StdNow);
BENCHMARK(StdNow)->UseRealTime()->Threads(16)->Threads(32)->ThreadPerCpu();

#pragma GCC diagnostic pop
BENCHMARK_MAIN();

}  // namespace util
}  // namespace shadowsocks
