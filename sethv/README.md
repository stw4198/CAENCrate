# CAENHV
Control of three V6534P's via command line tools and (optional) simple txt file

##### requirements:
CAENUSBdrvB -- most important, for connecting with the V1718 board
CAENVMElib -- second-most important, libraries for interacting with the boards
CAENComm -- useful to have for communicating with CAEN equipment


Important info:
-- To get a full list of functions, simply open the program (./sethv) without issuing any commands.
-- The format of an input goes as: ./sethv [command] [optional arguments]
-- Currently, error codes are displayed when sethv is run. An error code of "Err: 0" means the command has executed successfully.

Command List:

--VSet        Sets Voltage of a single channel.
              Usage: --VSet ch Voltage\n");
--ISet        Sets Current of a single channel.
              Usage: --ISet ch Current\n");
--Onstate     Turns individual Channels on or off.
              Usages: --Onstate ch \"On\"/\"Off\" (no quotes)
  Note:       channels 6-11 are interpreted as channels 0-5 on the
              Second HV card at Base Address 32120000
--SetSWVMax   Sets the software limit of the voltage based on input.
--setconfig   Requires parameter pointing to the location of the
              configuration file.
--powerdown   Ramp down voltages and turn channels off.
--powerup     Turn channels on and ramp up voltages.
--getconfig   Read the pre-set parameters from VME.
--voltmon     Read the instantaneous currents/Voltages from VME
--statemon    Reads the status of all channels. Used in LabVIEW
--fullmon     Reads all instantaneous Parameters (status + voltages) from VME
--killall        Kill all channels immediately
--rampup      Set ramp up speed (in V/s)
--rampdown    Set ramp down speed (in V/s)

################
Potential Bug:
################

There is an issue that has arisen on occasion where the monitor function shows random values that don't line up with the right heading e.g. the voltage of the card being under VSet rather than VMon. This is a communication error between the sethv code and card. To fix this, turn the VME crate off and back on. If this doesn't work, try restarting both the computer and crate. One of these usually helps as they reset the connection.
If both of these fail, please contact us and we will try and help.
 
