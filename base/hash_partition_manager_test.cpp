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
  third_party::SArray<Key> keys({1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<std::pair<int, AbstractPartitionManager::Keys>> sliced;
  pm.Slice(keys, &sliced);
  LOG(INFO) << sliced.size();
  for (int i = 0; i < sliced.size(); i++) {
    LOG(INFO) << "node id:" << sliced[i].first;
    if (sliced[i].second.size() > 0) {
      LOG(INFO) << "keys:";
      for (int j = 0; j < sliced[i].second.size(); j++) {
        LOG(INFO) << sliced[i].second[j];
      }
    }
  }
  ASSERT_EQ(sliced.size(), 2);            // 2 slices for 2 servers
  EXPECT_EQ(sliced[0].first, 0);          // key to server 0
  EXPECT_EQ(sliced[1].first, 2);          // keys to server 2
  ASSERT_EQ(sliced[0].second.size(), 1);  // key 2
  ASSERT_EQ(sliced[1].second.size(), 2);  // keys 8, 9
  EXPECT_EQ(sliced[0].second[0], 2);
  EXPECT_EQ(sliced[1].second[0], 8);
  EXPECT_EQ(sliced[1].second[1], 9);
}

TEST_F(TestHashPartitionManager, SliceKVs) {
  HashPartitionManager pm({0, 1, 2});
  third_party::SArray<Key> keys({2, 5, 9});
  third_party::SArray<double> vals({.2, .5, .9});
  std::vector<std::pair<int, AbstractPartitionManager::KVPairs>> sliced;
  pm.Slice(std::make_pair(keys, vals), &sliced);
}

}  // namespace csci5570
