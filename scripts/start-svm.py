import os
num_of_nodes=1
cmd=""
for i in range(0,num_of_nodes):
    cmd=cmd+"ssh 1155086998@proj"+str(10-i)+"; /data/opt/tmp/1155086998/pms/build/./TestSVM "+str(10-i)+" "+str(num_of_nodes)
    if(i==0):
        break
    # if(i<num_of_nodes):
    #     cmd=cmd+" & "
print cmd
os.system(cmd)