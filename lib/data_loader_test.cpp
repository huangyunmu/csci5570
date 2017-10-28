#include "lib/data_loader.hpp"
#include <vector>
#include "glog/logging.h"
#include "gtest/gtest.h"

namespace csci5570 {
namespace {
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
  using Sample = lib::LabeledSample<int, int>;
  using Parser = lib::Parser<Sample, DataStore>;
  using Parse = int;
  // using Parse=std::function<Sample(boost::string_ref, int)>;
  DataStore data_store;
  Sample svm_sample();
  Parser svm_parser();
  Parse svm_parse;
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/a9";
  lib::DataLoader<Sample, DataStore> data_loader;
  data_loader.load<Parse>(url, n_features, svm_parse, &data_store);
}
}
}  // namespace csci5570
