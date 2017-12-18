#include "base/range_partition_manager.hpp"

namespace csci5570 {

	HashPartitionManager::HashPartitionManager(const std::vector<uint32_t>& server_thread_ids)
		: AbstractPartitionManager(server_thread_ids) {
		
	}

	void HashPartitionManager::Slice(const Keys& keys, std::vector<std::pair<int, Keys>>* sliced) const {
		const int keys_size = keys.size();//Num of keys
		const int range_size = this->ranges_.size();

		for (int j = 0; j < range_size; j++)
		{
			Keys tempKeys;
			for (int i = 0; i < keys_size; i++) {
				if (keys[i] >= this->ranges_[j].begin() && keys[i] < this->ranges_[j].end()) {
					tempKeys.push_back(keys[i]);
				}
			}
			if (tempKeys.size() > 0) {
				std::pair<int, Keys> tempPair (this->server_thread_ids_[j], tempKeys);
				sliced->push_back(tempPair);
			}

		}

	}

	void HashPartitionManager::Slice(const KVPairs& kvs, std::vector<std::pair<int, KVPairs>>* sliced)const  {
		//LOG(INFO) << "Test by Andy 2";
		Keys keys = kvs.first;
		third_party::SArray<double> vals = kvs.second;
		const int keys_size = keys.size();//Num of keys
		//LOG(INFO) <<"Keys size"<< keys_size;
		const int range_size = this->ranges_.size();
		//LOG(INFO) <<"Range size"<< range_size;
		for (int j = 0; j < range_size; j++)
		{
			Keys temp_keys;
			third_party::SArray<double> temp_vals;
			for (int i = 0; i < keys_size; i++) {
				if (keys[i] >= this->ranges_[j].begin() && keys[i] < this->ranges_[j].end()) {

					temp_keys.push_back(keys[i]);
					temp_vals.push_back(vals[i]);
				}
			}
			if (temp_keys.size() > 0) {
				std::pair<int, KVPairs> temp_pair(this->server_thread_ids_[j], std::make_pair(temp_keys, temp_vals));
				sliced->push_back(temp_pair);
			}

		}
	}


}  // namespace csci5570
