#include "lib/abstract_data_loader.hpp"

#include <thread>

#include "boost/utility/string_ref.hpp"
#include "glog/logging.h"
#include "gtest/gtest.h"

#include "base/serialization.hpp"
#include "io/coordinator.hpp"
#include "io/hdfs_assigner.hpp"
#include "io/hdfs_file_splitter.hpp"
#include "io/line_input_format.hpp"

namespace csci5570 {
namespace lib {

template <typename Sample, typename DataStore>
class DataLoader : public AbstractDataLoader<Sample, DataStore> {
 public:
  template <typename Parse>  // e.g. std::function<Sample(boost::string_ref, int)>
  static void load(std::string url, int n_features, Parse parse, DataStore* datastore);
};  // Class DataLoader
}  // namespace lib
}  // namespace csci5570