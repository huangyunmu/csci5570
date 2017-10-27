#include <vector>
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "lib/abstract_data_loader.hpp"
#include "lib/labeled_sample.hpp"
#include "lib/parser.hpp"
namespace csci5570 {

class TestDataLoader : public testing::Test {
 public:
  TestDataLoader() {}
  ~TestDataLoader() {}

 protected:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(TestDataLoader, LoadData) {
  using DataStore = std::vector<int>;
  lib::LabeledSample<int, int> svmSample();
  DataStore dataStore;
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/a9";
  lib::Parser<lib::LabeledSample, DataStore> svmParser();
  DataLoader.load(url, n_features, svmParser, &datastore);
}

}  // namespace csci5570
