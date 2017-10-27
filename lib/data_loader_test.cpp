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
  Sample svm_sample();
  DataStore data_store;
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/a9";
  lib::Parser<Sample, DataStore> svm_parser();
  lib::DataLoader<Sample,DataStore> data_loader;
  // data_loader.load(url, n_features, svm_parser, &data_store);
}

}  // namespace csci5570
