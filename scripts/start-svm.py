import os
num_of_nodes = 2
cmd = ""
port = 12666
for i in range(0, num_of_nodes):
    cmd = cmd + "ssh 1155086998@proj" + str(10 - i) + " & "
    cmd = cmd + "/data/opt/tmp/1155086998/csci5570/build/./TestSVM " + \
        str(10 - i) + " " + str(num_of_nodes) + " " + str(port)
print cmd
os.system(cmd)
