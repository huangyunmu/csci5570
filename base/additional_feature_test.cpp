#include "glog/logging.h"
#include "gtest/gtest.h"

#include "base/magic.hpp"
#include "lib/data_loader.hpp"
#include "lib/kdd_sample.hpp"

#include "base/hash_partition_manager.hpp"
#include "lib/batchiterator.hpp"
namespace csci5570 {

class TestAdditionalFeature : public testing::Test {
 protected:
  void SetUp() {}
  void TearDown() {}
};  // class TestHashPartitionManager

TEST_F(TestAdditionalFeature, LoadHash) {
  using DataStore = std::vector<lib::KddSample>;
  using Parser = lib::Parser<lib::KddSample, DataStore>;
  using Parse = std::function<lib::KddSample(boost::string_ref, int)>;
  DataStore data_store;
  lib::KddSample kdd_sample;
  auto kdd_parse = Parser::parse_kdd;
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/kdd12";
  lib::DataLoader<lib::KddSample, DataStore> data_loader;
  data_loader.load<Parse>(url, n_features, kdd_parse, &data_store);
  BatchIterator<lib::KddSample> batch(data_store);
  auto keys_data = batch.NextBatch(20000);
  auto keys = keys_data.first;
  HashPartitionManager pm({0, 1, 2});
  std::vector<std::pair<int, AbstractPartitionManager::Keys>> sliced;
  LOG(INFO) << "Start split";
  pm.Slice(keys, &sliced);
  LOG(INFO) << "End split";
}

}  // namespace csci5570
