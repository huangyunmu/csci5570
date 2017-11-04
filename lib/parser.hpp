#pragma once

#include "boost/utility/string_ref.hpp"
#include "lib/svm_sample.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char* token = std::strtok_r(line, " ");
    while (token != NULL) {
      if (token == "+1") {
        // It is a possitive token
        temp_sample.y_ = 1;
      } else if (token == "-1") {
        // It is a negative token
        temp_sample.y_ = 0;
      } else {
        int position = token.find(":") string sub_str = token.substr(position, token.length() - position);
        int index = std::stoi(sub_str, NULL, 10);
        temp_sample.x_.push_back(index);
      }
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
