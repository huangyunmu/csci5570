#include "server/consistency/asp_model.hpp"
#include "glog/logging.h"

namespace csci5570 {

ASPModel::ASPModel(uint32_t model_id, std::unique_ptr<AbstractStorage>&& storage_ptr,
                   ThreadsafeQueue<Message>* reply_queue)
    : model_id_(model_id), storage_(std::move(storage_ptr)), reply_queue_(reply_queue) {}

void ASPModel::Clock(Message& msg) { progress_tracker_.AdvanceAndGetChangedMinClock(msg.meta.sender); }

void ASPModel::Add(Message& msg) {
  CHECK(progress_tracker_.CheckThreadValid(msg.meta.sender));
  storage_->Add(msg);
}

void ASPModel::Get(Message& msg) {
  CHECK(progress_tracker_.CheckThreadValid(msg.meta.sender));
  reply_queue_->Push(storage_->Get(msg));
}

int ASPModel::GetProgress(int tid) { return progress_tracker_.GetProgress(tid); }

void ASPModel::ResetWorker(Message& msg) {
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
