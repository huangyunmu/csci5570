#include "server/consistency/bsp_model.hpp"
#include "glog/logging.h"

namespace csci5570 {

BSPModel::BSPModel(uint32_t model_id, std::unique_ptr<AbstractStorage>&& storage_ptr,
                   ThreadsafeQueue<Message>* reply_queue) {
  // TODO
  model_id_=model_id;
  reply_queue = reply_queue;
  storage_=std::move(storage_ptr);
}

void BSPModel::Clock(Message& msg) {
  // TODO
  int tid = msg.meta.sender;
  if(progress_tracker_.CheckThreadValid(tid)){
    int temp = progress_tracker_.AdvanceAndGetChangedMinClock(tid);
    if(temp !=-1){
      for(size_t index = 0; index < add_buffer_.size();index++){
        storage_->Add(add_buffer_[index]);
        add_buffer_.erase(add_buffer_.begin()+index);
      }
    }
  }
}

void BSPModel::Add(Message& msg) {
  // TODO
  add_buffer_.push_back(msg);
}

void BSPModel::Get(Message& msg) {
  // TODO
  Message reply = storage_->Get(msg);
  reply_queue_->Push(reply);
}

int BSPModel::GetProgress(int tid) {
  // TODO
  return progress_tracker_.GetProgress(tid);
}

int BSPModel::GetGetPendingSize() {
  // TODO
  return get_buffer_.size();
}

int BSPModel::GetAddPendingSize() {
  // TODO
  return add_buffer_.size();
}

void BSPModel::ResetWorker(Message& msg) {
  // TODO

  // msg.meta.flag=Flag::kResetWorkerInModel;
  // third_party::SArray<int> tidstemp;
  // tidstemp = msg.data[0];
  // std::vector<uint32_t> tids;
  // for(size_t i=0; i<tidstemp.size();i++){
  //   tids.push_back(tidstemp[i]);
  // }
  // progress_tracker_.Init(tids);
  // reply_queue_->Push(msg);

  CHECK_EQ(msg.data.size(), 1);
  third_party::SArray<uint32_t> tids;
  tids = msg.data[0];
  std::vector<uint32_t> tids_vec(tids.begin(), tids.end());
  this->progress_tracker_.Init(tids_vec);
  Message reply_msg;
  reply_msg.meta.model_id = model_id_;
  reply_msg.meta.recver = msg.meta.sender;
  reply_msg.meta.flag = Flag::kResetWorkerInModel;
  reply_queue_->Push(reply_msg);
}

}  // namespace csci5570
