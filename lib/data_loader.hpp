#pragma once
#include "lib/abstract_data_loader.hpp"
#include <thread>
#include "boost/utility/string_ref.hpp"
#include "base/serialization.hpp"
#include "io/coordinator.hpp"
#include "io/hdfs_assigner.hpp"
#include "io/hdfs_file_splitter.hpp"
#include "io/line_input_format.hpp"
#include "lib/abstract_data_loader.hpp"
#include "lib/labeled_sample.hpp"
namespace csci5570 {
namespace lib {

template <typename Sample, typename DataStore>
class DataLoader : public AbstractDataLoader<Sample, DataStore> {
 public:
  template <typename Parse>  // e.g. std::function<Sample(boost::string_ref, int)>
  static void load(std::string url, int n_features, Parse parse, DataStore* datastore);
  void test();
};  // Class DataLoader
}  // namespace lib
}  // namespace csci5570
