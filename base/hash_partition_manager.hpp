#pragma once

#include <cinttypes>
#include <vector>
#include <openssl/md5.h>
#include "base/abstract_partition_manager.hpp"
#include "base/magic.hpp"
#include "base/third_party/sarray.h"

#include "glog/logging.h"

namespace csci5570 {

class HashPartitionManager : public AbstractPartitionManager {
 public:
  HashPartitionManager(const std::vector<uint32_t>& server_thread_ids);

  void Slice(const Keys& keys, std::vector<std::pair<int, Keys>>* sliced) const override;

  void Slice(const KVPairs& kvs, std::vector<std::pair<int, KVPairs>>* sliced) const override;

 private:
  std::vector<third_party::Range> ranges_;
};

}  // namespace csci5570