#pragma once

#include <boost/tokenizer.hpp>
#include <string>
#include "boost/utility/string_ref.hpp"
#include "lib/svm_sample.hpp"
// For testing
#include "glog/logging.h"
#include <thread>
namespace csci5570 {
namespace lib {

template <typename Sample, typename DataStore>
class Parser {
 public:
  /**
   * Parsing logic for one line in file
   *
   * @param line    a line read from the input file
   */
  static Sample parse_libsvm(boost::string_ref line, int n_features) {
    // check the LibSVM format and complete the parsing
    // hints: you may use boost::tokenizer, std::strtok_r, std::stringstream or any method you like
    // so far we tried all the tree and found std::strtok_r is fastest :)
    Sample temp_sample = SVMSample();
    boost::tokenizer<> tok(line);
    int count = 0;
    for (boost::tokenizer<>::iterator beg = tok.begin(); beg != tok.end(); ++beg) {
      if (count == 0) {
        if (line.substr(0, 1) == "+") {
          LOG(INFO) << "Positive";
          // temp_sample.y_=1;  
        } else {
          LOG(INFO) << "Negative";
          // temp_sample.y_=0;
        }
      }
      if (count % 2 == 1) {
        // int index=stoi(*beg);
        // temp_sample.x_.push_back(index);
        LOG(INFO) << *beg;
        // LOG(INFO)<<index;
      }
      count++;
    }
    return temp_sample;
  }

  static Sample parse_mnist(boost::string_ref line, int n_features) {
    // check the MNIST format and complete the parsing
  }

  // You may implement other parsing logic

};  // class Parser

}  // namespace lib
}  // namespace csci5570
