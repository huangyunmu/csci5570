#include "server/util/pending_buffer.hpp"

namespace csci5570 {

std::vector<Message> PendingBuffer::Pop(const int clock) {
  std::unordered_map<int, std::vector<Message>>::iterator iter;
  iter = map_.find(clock);
  std::vector<Message> temp;
  if (iter != map_.end()) {
    temp = this->map_[clock];
    map_.erase(iter);
  }
  return temp;
}

void PendingBuffer::Push(const int clock, Message& msg) { this->map_[clock].push_back(msg); }

int PendingBuffer::Size(const int progress) { return this->map_[progress].size(); }

}  // namespace csci5570
