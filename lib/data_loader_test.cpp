#include "lib/data_loader.hpp"
#include "glog/logging.h"
#include "gtest/gtest.h"
#include <vector>
#include "lib/svm_sample.hpp"
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
  using Parser = lib::Parser<lib::SVMSample, DataStore>;
  // using Parse = int;
  using Parse =Parser.parse_libsvm(boost::string_ref line, int n_features);
  // using Parse=std::function<Sample(boost::string_ref, int)>;
  DataStore data_store;
  lib::SVMSample svm_sample;
  // Parser svm_parser();
  Parse svm_parse;
  int n_features = 10;
  std::string url = "hdfs:///datasets/classification/a9";
  lib::DataLoader<lib::SVMSample, DataStore> data_loader;
  data_loader.load<Parse>(url, n_features, svm_parse, &data_store);
  // data_loader.test();
}

}  // namespace csci5570
