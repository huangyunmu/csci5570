#include "glog/logging.h"
#include "gtest/gtest.h"

#include "driver/engine.hpp"
#include "worker/kv_client_table.hpp"

//. Define arguments
DEFINE_int32(my_id, -1, "the process id of this program");
DEFINE_string(config_file, "", "The config file path");
// Data loading config
DEFINE_string(hdfs_namenode, "proj10", "The hdfs namenode hostname");
DEFINE_int32(hdfs_namenode_port, 9000, "The hdfs port");
DEFINE_int32(hdfs_master_port, -1, "A port number for the hdfs assigner host");
DEFINE_int32(n_loaders_per_node, 1, "The number of loaders per node");
DEFINE_string(input, "", "The hdfs input url");
DEFINE_int32(n_feature, -1, "The number of feature in the dataset");
// Traing config
DEFINE_int32(n_workers_per_node, 1, "The number of workers per node");
DEFINE_int32(n_iters, 10, "The number of interattions");
DEFINE_int32(batch_size, 100, "Batch size");
DEFINE_double(alpha, 0.001, "learning rate");

int main(int argc, char** argv){
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    Google::InitGoogleLogging(argc[0]);

    int may_id=FLAG_my_id;
    int n_nodes=5;
    std:vector<Node> nodes(n_nodes);
    //Should read from config file 
    for(int i = 0; i < n_nodes; ++i){
        nodes[i].id = i;
        nodes[i].hostname = "proj" + std::to_string(i+5);
        nodes[i].port = 45612;
        //"0:proj5:45612"
    //"1:proj6:45612"
    }

    const Node& node = nodes[my_id];

    //Load Data
    auto loader=HDFSDataLoader<Sample, DataStore<Sample>>::Get(node, FLAG_hdfs_namenode, FLAGS_hdfs_namenode_port, nodes[0].hostname, FLAGS_hdfs_master_port, n_nodes );
    DataStore<Sample> datastore(FLAGS_n_loaders_per_node);
    loader->Load(FLAGS_input, FLAGS_n_features, Parser::parse_libsvm, &datastore, n_nodes);

    //Start Engine 
    Engine engine(node, nodes);
    engine.StartEverything();

    //Create table on the server side
    const auto kTable = engine.CreateTable<double>(ModelType::BSP,StoreageType::Map,FLAGS_n_features+1,RangePartition);
    //Specify task
    MLTask task;
    task.SetTables({kTable});
    std::vector<WorkerAlloc> worker_alloc;
    for(int i = 0; i < n_nodes; ++i){
        woker_alloc.push_back({nodes[i].id, static_cast<uint32_t>(FLAG_n_workers_per_node)});
    }
    task.SetWorkerAlloc(worker_alloc);
    //get client table
    task.SetLambda([kTable,&datastore](const Info& info){
        auto table=info.CreateKVClientTable<double>(kTable);
	}
	     
    BatchIterator<Sample> batch(datastore);

    //interations
    for (int iter = 0; iter < FLAGS_n_iters; ++iter){
        //get data batch
        auto keys_data=batch.NextBatch(FLAGS_batch_size);
    
        // prepare parameters
        third_party::SArray<double> vals;
        table.Get(keys_data.first,&vals);
        //compute gradients
    
        //update parameters 
        
        //clock
    });
    engine.StopEverything();
    return 1;
}