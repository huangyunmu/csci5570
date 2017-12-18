#include "base/hash_partition_manager.hpp"

namespace csci5570 {

int32_t HashPartitionManager::JumpConsistentHash(uint64_t key, int32_t num_buckets) {
  int64_t b = -1, j = 0;
  while (j < num_buckets) {
    b = j;
    key = key * 2862933555777941757ULL + 1;
    j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
  }
  return b;
}

HashPartitionManager::HashPartitionManager(const std::vector<uint32_t>& server_thread_ids)
    : AbstractPartitionManager(server_thread_ids) {
  // MD5_CTX ctx;
  // unsigned char out[16];
  // LOG(INFO) << MD5_Init(&ctx);
  // int num = 0;
  // MD5_Update(&ctx, &num, 10);
  // MD5_Final(out, &ctx);
  // for (int i = 0; i < 16; i < i++) {
  //   LOG(INFO) << out[i];
  //   printf("%02X", out[i]);
  // }
  int key = 10;
  int num_buckets = 5;
  int result = this->JumpConsistentHash(key, num_buckets);
  LOG(INFO) << "Result" << result;
}

void HashPartitionManager::Slice(const Keys& keys, std::vector<std::pair<int, Keys>>* sliced) const {
  const int keys_size = keys.size();  // Num of keys
}

void HashPartitionManager::Slice(const KVPairs& kvs, std::vector<std::pair<int, KVPairs>>* sliced) const {
  Keys keys = kvs.first;
  third_party::SArray<double> vals = kvs.second;
  const int keys_size = keys.size();  // Num of keys
  // LOG(INFO) <<"Keys size"<< keys_size;
}

}  // namespace csci5570
