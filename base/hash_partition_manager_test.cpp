#include "glog/logging.h"
#include "gtest/gtest.h"

#include "base/hash_partition_manager.hpp"
#include "base/magic.hpp"

namespace csci5570 {

class TestHashPartitionManager : public testing::Test {
 protected:
  void SetUp() {}
  void TearDown() {}
};  // class TestHashPartitionManager

TEST_F(TestHashPartitionManager, Init) { HashPartitionManager pm({0, 1, 2}); }

TEST_F(TestHashPartitionManager, SliceKeys) {
  HashPartitionManager pm({0, 1, 2});
  third_party::SArray<Key> keys({2, 8, 9});
  std::vector<std::pair<int, AbstractPartitionManager::Keys>> sliced;
  pm.Slice(keys, &sliced);
}

TEST_F(TestHashPartitionManager, SliceKVs) {
  HashPartitionManager pm({0, 1, 2});
  third_party::SArray<Key> keys({2, 5, 9});
  third_party::SArray<double> vals({.2, .5, .9});
  std::vector<std::pair<int, AbstractPartitionManager::KVPairs>> sliced;
  pm.Slice(std::make_pair(keys, vals), &sliced);
}

}  // namespace csci5570
