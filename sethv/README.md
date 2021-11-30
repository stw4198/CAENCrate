# CAENHV
Control of V6534P via command line tools

##### requirements:

CAENUSBdrvB

CAENVMElib

CAENComm


Important info:

-- To get a full list of functions, open the program (./sethv) without issuing any commands.

-- The format of an input goes as: ./sethv [command] [optional arguments]

-- Currently, error codes are displayed when sethv is run. An error code of "Err: 0" means the command has executed successfully.

Command List:

--VSet: Sets Voltage of a single channel

Usage: --VSet ch Voltage
              
--ISet: Sets Current of a single channel

Usage: --ISet ch Current
              
--power: Turns individual Channels on or off

Usage: --power ch On/Off
              
Note: Channels 6-11 are interpreted as channels 0-5 on the second HV card at Base Address 32120000. Channels 12-17 are interpreted as channels 0-5 on the third HV card at Base Address 32130000
              
--SetSWVMax   Sets the software limit of the voltage based on input

--monitor     Read the instantaneous currents/Voltages from VME

--statemon    Reads the status of all channels

--rampup      Set ramp up speed (in V/s)

--rampdown    Set ramp down speed (in V/s)

################

Potential Bug:

################


There is an issue that has arisen on occasion where the monitor function shows random values that don't line up with the right heading e.g. the voltage of the card being under VSet rather than VMon. This is a communication error between the sethv code and card. To fix this, turn the VME crate off and back on. If this doesn't work, try restarting both the computer and crate.
 
