################
After reading this, please read the "HowToBuildApplication" file as the application doesn't come precompiled. Please also read the Read Me file within the sethv folder.
################


################
Introduction
################

HV_Manual_Control is a program used to monitor and control 2 V6534P High Voltage cards within a VME crate.
This program was created relatively early, and was partially used to test functionality. However, it can be used as a substitute for CAENGECO.
HV_Manual_Control utilises a terminal application (based on a similar application written by Dr Matt Thiesse, University of Sheffield) called sethv. sethv can also be used for HV control, if needed. It is necessary to "make" sethv before using the LabVIEW program.

################
Hardware Requirements (CAEN unless stated):
################

2 x CAEN V6534P 
1 x CAEN V1718 VME-USB Bridge
1 x CAEN NV8020 VME Crate
1 x USB 2.0 A to B
1 x PC running Linux (Scientific Linux 7 or CentOS 7 preferable)

################
Software Requirements:
################

CAENVMElib*
CAENComm*
CAENUSBdrv (CAEN USB driver)*
LabVIEW 18 for Linux (Professional version needed for application)
"Development Tools" Package (build-essentials on debian-like distributions), including GCC


* Softwares available from the Download section of CAEN's website

################
Hardware Setup:
################

1. Set the Base Address of the V1718 Bridge to 32100000 by adjusting the 4 screws on the right hand side of the card. 
2. Insert the V1718 into the left-most slot of the VME crate
3. Set the Base Address of the first V6534P to 32110000 by adjusting the 4 screws on the right hand side of the card. This card shall be referred to in software as Board A.
4. Set the Base Address of the second V6534P to 32120000 by adjusting the 4 screws on the right hand side of the card. This card shall be referred to in software as Board B.
5. Install Board A and Board B into the VME crate; Board B should sit to the right of Board A. 
6. Connect the V1718 to your computer via the USB cable

Channels 0-5 on board A are referred to as channels 0-5 in the software, including the sethv terminal application. Channels 0-5 on board B are referred to as channels 6-11 in software. It is recommended to label the channels on Board B to reflect this.

################
Software Setup:
################

Installation instructions for required drivers and software are not detailed in this section. For these instructions, please refer to the appropriate documentation.
Instead, this section details the setup of the sethv terminal application, as well as the LabVIEW manual HV control program.

To begin, unpack the HV_Manual_Control file (although, if you're reading this, chances are you've done it already). 

========
Sethv:
========

sethv is the terminal application that does the heavy lifting; it is this program that directly communicates with the high-voltage hardware.
In order to save space, the sethv program does not come precompiled. This also stops permission errors when transferring between computers.
Within the terminal, navigate into the HV_Manual_Control/sethv directory. Then, run "make". There is a more complete readme file for sethv within this directory.
The source files, should you need to edit them, are located in "sethv/src". Header files are located in "sethv/include". 
There is currently no option to install the program system wide: for now, it must be run from within the sethv directory.

Detailed instructions on using sethv are provided in the ReadME.md file in the sethv directory.

=========
HV Control
=========

  The LabVIEW HV control program allows graphical control over the HV, utilising the sethv terminal application as a backbone. It can be used as a substitute for CAENGECO.
  The program should work "out of the box" with no installation or setup necessary, assuming that LabVIEW is installed. However, to use the application form, which is recommeded, please see the "HowToBuildApplication" file.

  To run HV Control, open the "HV_Manual_Control.proj" project file in LabVIEW. From within the project, open the HV_Manual_Control.vi.

  The front panel contains a display consisting of 3 tabs: Controls, Monitor and Read Me. This Read Me is basic to allow some help during use. Use the separate ReadMe Document (this one) before referring to front panel Read Me.

===
Controls
===
  The controls section contains the controls and options to set all values on the HV cards.
  On the left is the Parameter select dropdown menu. The options are VSet (sets the voltage), On/Off (turn channels on or off), ISet (sets the maximum current), Rampset (sets the ramp speed) and VMax (sets the Software Voltage maximum). With the exception of VMax and RampSet, each of these parameters can be controlled individually or board-wide. 

To enter values for channels, voltages, currents and whether the channels are on or off, there is a table within the Controls panel. This allows any channels to have any parameter set without the need for any order or indices. To apply the settings in each column, select the parameter desired (VSet, ISet, On/Off) and press the Apply button when the vi is already running. The row corresponds to the channel entered into that row, they don't have to be consecutive or in order, simply enter a channel and the corresponding values.

Set Ramp Rates: Select the RampSet parameter then select which Ramp (rampup or rampdown) you'd like to change in the box below. Enter the ramp rate wanted in the box below. This is applied to all channels.

Set Maximum Software Voltage: Select VMax and enter a voltage into Max Voltage box, then press Apply.
KEEP THIS BELOW 6000V FOR THE HV CARDS, LOWER FOR PMTS!!!!!!

Turn all channels off: Press the "OFF" button.

Close application/vi: Press "CLOSE" to switch all channels off and close application/vi.

===
Monitor
=== 

This tab displays all of the information about all the cards in a table. When the VI is running, it updates continuously, even if all channels are turned off. It has a table of all values, LEDs to indicate if a channel is on, ramping up or ramping down and any errors coming from the channel listed in a table where the index is the channels (eg over voltage).

It also displays the errors returned by sethv. If the code is "Err: 0", there are no errors being encountered.


################
Usage:
################

To run a command, select a parameter to control.

When the VI is running, click the "Apply" button on the front panel to run your commands/settings.

Press "OFF" to switch all channels off.

Press "CLOSE" to switch all channels off and close application/vi.

To use this as an application, please consult the "HowToBuildApplication" file.


################
Note:
################

As mentioned in the monitor sections, the program displays an error code. If the error code is "Err: 0", there is no error being reported. The error code is returned so that error handling can be performed when the HV control is added into a much larger software for the automated electronic testing of PMTs.

################
Potential Bug:
################

There is an issue that has arisen on occasion where the monitor function shows random values that don't line up with the right heading e.g. the voltage of the card being under VSet rather than VMon. This is a communication error between the sethv code and card. To fix this, turn the VME crate off and back on. If this doesn't work, try restarting both the computer and crate. One of these usually helps as they reset the connection.
If both of these fail, please contact us and we will try and help.

Please feel free to email with any questions. Questions about the LabVIEW code are best directed to swilson@sheffield.ac.uk, questions about sethv are best directed to mcalle1@sheffield.ac.uk.

