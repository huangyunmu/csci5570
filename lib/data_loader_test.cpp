#include "lib/data_loader.hpp"
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
  using Sample=lib::LabeledSample<int, int>;
  using Parse=lib::Parser<Sample, DataStore>;
  DataStore data_store;
  Sample svm_sample();
  Parse svm_parser();
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/a9";
  lib::DataLoader<Sample,DataStore> data_loader;
  data_loader.load<Parse>(url, n_features, svm_parser, &data_store);
}

}  // namespace csci5570
