#pragma once
#include <string>
#include "base/third_party/sarray.h"
#include "lib/LabeledSample.hpp"
namespace csci5570 {
namespace lib {

// Consider both sparse and dense feature abstraction
// You may use Eigen::Vector and Eigen::SparseVector template

class SVMSample : lib::LabeledSample<third_party::SArray<int>, int> {
public:
  void test() {
    for (int i = 0; i < 5; i++) {
      this.x_.push_back(i);
    }
    this.y_ = 2;
  }
  std::string toString(){
    test();
    std::string result="";
    for (int i = 0; i < 5; i++) {
        result=result+" "+this.x_[i];
      }
    result=result+" "+this.y_;
    return result;
  }

  //  public:
  //   vector<int> x_;
  //   Label y_;
};  // class LabeledSample

}  // namespace lib
}  // namespace csci5570
