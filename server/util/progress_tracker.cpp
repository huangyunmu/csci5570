#include "server/util/progress_tracker.hpp"

#include "glog/logging.h"

namespace csci5570 {

void ProgressTracker::Init(const std::vector<uint32_t>& tids) {
  // TODO
  min_clock_ = 0;
  for (int i = 0; i < tids.size(); i++) {
    progresses_.insert(map<int, int>::value_type(tids[i], 0));
  }
}

int ProgressTracker::AdvanceAndGetChangedMinClock(int tid) {
  // TODO
  int newProgress = progresses_[tid] + 1;
  if (IsUniqueMin(tid) == True)
  // The min clock need to be updated
  {
    progresses_[tid] = newProgress;
    min_clock_++;
    return min_clock_;
  } else {
    progresses_[tid] = newProgress;
    return -1;
  }
}

int ProgressTracker::GetNumThreads() const {
  return progresses_.size();
  // TODO
}

int ProgressTracker::GetProgress(int tid) const {
  return progresses_[tid];
  // TODO
}

int ProgressTracker::GetMinClock() const {
  return min_clock_;
  // TODO
}

bool ProgressTracker::IsUniqueMin(int tid) const {
  if (progresses_[tid] != GetMinClock()) {
    // It is not min
    return false;
  }
  map<int, int>::iterator it = progresses_.begin();
  for (; it != progresses_.end(); ++it){    
    if(it->first!=tid && it->second==GetMinClock()){
      return false;
    }
  }
  return true;

  // TODO
}

bool ProgressTracker::CheckThreadValid(int tid) const {
  return (progresses_.find(tid) != progresses_.end());
  // TODO
}

}  // namespace csci5570
