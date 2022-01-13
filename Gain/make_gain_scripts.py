import numpy as np
import sys as sys

file = "../HVScan-new.txt"
print("Reading %s"%file)
pmt,v1,v2,v3,v4,v5,nv=np.loadtxt(file,unpack=True,delimiter=",",skiprows=1)

#pmts_in  = sys.argv[1]
pmts_in = [1,2,3,4]
print("Input PMTs =",pmts_in)
#daq_in = sys.argv[2]
daq_in = [0,1,2,3]
print("Input digitizer channels =",daq_in)
#hv_in = sys.argv[3]
hv_in = [0,1,2,3]
print("Input HV channels =",hv_in,"\n")

time = 900

pmts_out = []
hv_out = []
daq_out = []
v1_out = []
v2_out = []
v3_out = []
v4_out = []
v5_out = []

for i in range(len(pmts_in)):
    result = np.where(pmt==pmts_in[i])[0]
    if len(result)!=0:
        print("Found PMT %i, HV Channel %i, Digitizer Channel %i"%(pmts_in[i],hv_in[i],daq_in[i]))
        pmts_out.append(pmts_in[i])
        hv_out.append(hv_in[i])
        daq_out.append(daq_in[i])
        v1_out.append(v1[result])
        v2_out.append(v2[result])
        v3_out.append(v3[result])
        v4_out.append(v4[result])
        v5_out.append(v5[result])

daq_shell_string = "(sleep 3s && echo \"s\" && sleep 3s && echo \"W\" && sleep %is && echo \"s\" && sleep 3s && echo \"q\") | wavedump WaveDumpConfig_Gain.txt"%time
print(daq_shell_string)
total_time = time + 3 + 3 + 3

hv_shell_string = ""

hv_shell_string += "sleep 3s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --VSet %i %i"%(hv_out[i],v1_out[i])
hv_shell_string += " && sleep 1s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --power %i 1"%(daq_out[i])
hv_shell_string += " && sleep 20s"
hv_shell_string += " && source Gain_DAQ.sh"
hv_shell_string += " && sleep %is"%total_time

hv_shell_string += " sleep 3s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --VSet %i %i"%(hv_out[i],v2_out[i])
hv_shell_string += " && sleep 20s"
hv_shell_string += " && source Gain_DAQ.sh"
hv_shell_string += " && sleep %is"%total_time

hv_shell_string += " sleep 3s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --VSet %i %i"%(hv_out[i],v3_out[i])
hv_shell_string += " && sleep 20s"
hv_shell_string += " && source Gain_DAQ.sh"
hv_shell_string += " && sleep %is"%total_time

hv_shell_string += " sleep 3s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --VSet %i %i"%(hv_out[i],v4_out[i])
hv_shell_string += " && sleep 20s"
hv_shell_string += " && source Gain_DAQ.sh"
hv_shell_string += " && sleep %is"%total_time

hv_shell_string += " sleep 3s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --VSet %i %i"%(hv_out[i],v5_out[i])
hv_shell_string += " && sleep 20s"
hv_shell_string += " && source Gain_DAQ.sh"
hv_shell_string += " && sleep %is"%total_time

hv_shell_string += " && sleep 10s"
for i in range(len(pmts_out)):
    hv_shell_string += " && ../sethv/sethv --power %i 0"%(daq_out[i])
hv_shell_string += " && echo \"Done\""

print(hv_shell_string)

daq_shell="""
#!/bin/bash

%s
"""%daq_shell_string

hv_shell="""
#!/bin/bash

%s
"""%hv_shell_string

with open("Gain_HV.sh", "w") as f:
    f.write(hv_shell_string)

with open("Gain_DAQ.sh", "w") as f:
    f.write(daq_shell_string)