#include "glog/logging.h"
#include "gtest/gtest.h"
#include "parser.hpp"
#include "lib/labeled_sample.hpp"
#include "lib/abstract_data_loader.hpp"
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
  using DataStore=std::vector <int,int>;
  LabeledSample<int,int> svmSample;
  DataStore dataStore;
  int n_features = 10;
  std::string url= "hdfs:///datasets/classification/a9";
  Parser<LabeledSample,DataStore> svmParser;
  DataLoader.load(std::string url, n_features, svmParse, &datastore);
}

}  // namespace
}  // namespace csci5570
