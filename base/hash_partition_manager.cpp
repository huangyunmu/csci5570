#include "base/hash_partition_manager.hpp"

namespace csci5570 {

	HashPartitionManager::HashPartitionManager(const std::vector<uint32_t>& server_thread_ids)
		: AbstractPartitionManager(server_thread_ids) {
		MD5_CTX ctx; 
		LOG(INFO)<<MD5_Init(&ctx);
		int num=0;
		MD5_Update(MD5_CTX *c, &num, 10);
        // unsigned char outmd[16]; 
	}

	void HashPartitionManager::Slice(const Keys& keys, std::vector<std::pair<int, Keys>>* sliced) const {
		const int keys_size = keys.size();//Num of keys
	}

	void HashPartitionManager::Slice(const KVPairs& kvs, std::vector<std::pair<int, KVPairs>>* sliced)const  {
		Keys keys = kvs.first;
		third_party::SArray<double> vals = kvs.second;
		const int keys_size = keys.size();//Num of keys
		//LOG(INFO) <<"Keys size"<< keys_size;
		
	}


}  // namespace csci5570
