####################
HV Automation Demo
####################

Authors: Max Calle (mcalle1@sheffield.ac.uk) and Steve Wilson (swilson8@sheffield.ac.uk)
Some code adapted from code originally written by Dr Matt Thiesse

################
Requirements
################

Software
 - CAENComm
 - CAENVMELib
 - CAENUSBdrv (CAEN USB driver)
 - LabVIEW 2018 (Professional to build applications)

Hardware
 - VME Crate
 - CAEN V1718 VME-USB Bridge
 - 2 x CAEN V6534P HV Cards
 - Linux PC (CentOS 7/Scientific Linux 7 preferred)
 - USB type A to B cable
 
########
Intro
########

This is a demo software for the automated control of 2 CAEN V6534P High Voltage (HV) cards. The purposes are to show the functionality of some of the subVIs written that will eventually be implemented into the WATCHMAN PMT test stand control software, as well as to provide some semblance of automated control.

Communication with the cards is achieved by means of a terminal application: sethv. sethv was originally written by Dr Matt Thiesse for control of positive and negative V6521 cards, and modified for our purposes. These modifications included new commands, as well as additions and changes to existing commands. Automation is achieved by sending external commands to the sethv application via LabVIEW VIs, based on input from the user and/or a configuration file containing lists of PMTs and their test voltages.

This method was chosen as the LabVIEW HV command libraries provided by CAEN were not directly compatible with the Linux Version of LabVIEW. Although importing the CAEN HVWrapper library was attempted, this proved difficult and time consuming. Since sethv already existed, this was the faster and more effective solution.

################
Hardware Setup
################

 1. Using the hexadecimal turnkeys on the board, set the Base Address of the V1718 to 32100000 (First key to 3, second to 2 and so on)
 2. Install the V1718 into the leftmost slot in the VME crate
 3. Again use the hexadecimal turnkeys to set the Base address of 1 V6534P to 32110000. This is referred to as board A
 4. Set the Base Address of the second V6534P to 32120000. This is referred to as board B.*
 5. Install Boards A and B into the VME crate, installing board B to the right of Board A. It is recommended to re-label channels 0-5 on Board B as channels 6-11.**
 6. Connect the V1718 to a PC via USB.
* The base addresses for cards A and B are defined in the header files for their respective C++ scripts. If you choose to use different Base addresses for each card, make sure to change the Base Addresses within the header file as well.
** Within sethv (and LabVIEW), channels 0-5 on board B are referred to as channels 6-11. This was originally to make terminal command input easier.

################
Software Setup
################

There are 2 components to the software: the sethv terminal application and the LabVIEW project. In order for the LabVIEW program to function, sethv must be compiled first. 

sethv:

 1. Install CAENComm, CAENVME and CAENUSBdrv, all available from CAEN's website. Install them in the order listed for best results. 
 2. Within a terminal, navigate to the HV_Automation_Demo/LabVIEW_Control/HV_QMH/sethv directory.
 3. Run "make".
 4. To ensure that the program is functioning correctly, power up the VME crate and enter into terminal "./sethv --voltmon" with the USB connected. If done correctly, the terminal will print "Err: 0", followed by a table of voltages and current settings, and the monitored values. "Err: 0" means that everything worked as expected.

LabVIEW:
To open the front panel with all SubVIs loaded:
 1. Open LabVIEW, and select "Open Existing"
 2. Navigate to /HV_Automation_Demo/LabVIEW_Control and open "HV Automation Demo.lvproj".
 3. From within the LabVIEW project explorer opened in step 2, open "Main.vi".
 
From within LabVIEW, there is an option to edit the configuration file that dictates the voltages for each PMT. This is done by selecting the "HV_Edit_PMT_File.vi" option within the project.

To build the vis as applications, which is highly recommended, please see the "HowToBuildApplication" file.

################
Changing the Automated
Voltage Settings
################

The voltage settings for each PMT are stored in a tab-delimited text file, located in the "LabVIEW_Control/HV_Settings" directory. This file is based on a mockup of the gain test voltage config file.

Each line within the file contains a PMT number, followed by 4 voltages. The automation software accepts PMT serial numbers, channels and test number as inputs: the PMT numbers and test numbers are then checked against this file. If the PMTs and tests are listed in the HV_Settings file, then the PMT's HV channel is set to the voltage associated with that test and PMT, and the channel is powered on to the given voltage (see the Front Panel section for more details on operation). If you wish to add a PMT's settings to the file, simply add a new line with the PMT's number, and 4 voltages. It is very important that each is separated with a tab; not a space.

If the "Edit PMT File" button is pressed when "Main.vi" is used as an application, a new vi will open. This is "HV_Edit_PMT_File.vi". This vi allows the file to be edited by either rewriting the PMT file in the table given or adding a single PMT to the existing file. Please see the relevant section on editing the PMT file for more details.

################
The HV Automation Demo Front Panel
################

Upon opening Main.vi from within the project manager, you will see a front panel containing tabs: "Automated" and "Monitor".

Automated
=========

The automated tab is the simplest of the 2; consisting of two arrays and 4 buttons. To power the PMTs, enter the PMT number in the "PMT" section and then its channel in the "Channel" section at the same index, before entering the test desired (currently 1, 2, 3 or 4). Up to 12 PMT numbers and channels may be entered at a time. It is not necessary to enter the voltages in this program.

Once these details have been entered, press "Apply". The SubVIs will first check the PMT numbers entered against the PMTs listed in the "HV_Settings" file. If a PMT number is valid, the associated voltage is passed into an array. SubVIs then use the voltage and PMT channel information to power on the HV voltage channels to their set voltage. 

To power all of the channels down, press the "OFF" button: This will safely power down the PMTs.

Between powering the PMTs on and powering them down, use the monitor tab to monitor the HV cards.

To edit the "HV_Settings.txt", press the "Edit PMT File" button when both "Main.vi" and "HV_Edit_PMT_File.vi" are compiled as applications.

To close the application down and power down the PMTs, press the "CLOSE" button.

Note: At this stage, this automation is mainly useful as a demo. To perform on-the-fly control and monitoring, please use the Manual Control version of this program. A combined version will be developed, but HV_Manual_Control offers full control of all 12 HV channels.

Monitor
========

The monitor tab consists of a 2D voltage monitoring array, 3 arrays of Booleans and a 1D error status array.

The 2D voltage monitoring array, when run, will show the voltage/current settings and monitored outputs for all 12 channels available. This should be used to ensure that your channels have reached their correct settings. 

The 3 Boolean arrays show the On/Off status, and whether or not a channel is ramping up or ramping down. If a channel is On, the On LED will be lit. If the card is on and ramping up, then the corresponding LED will light. If the card is being shut down, then the On and Rampdown LEDs will be lit.

################
Edit PMT File vi
################

When the "HV_Edit_PMT_File" application is loaded, there are two options as to how to edit the settings file.

First, the entire file can be rewritten using the large table provided at the top of the tab. Make sure the "Append Single PMT?" button is deselected so there is no green light.
This allows PMT numbers and 4 voltages per PMT to be entered. Use the top set of arrows situated at the top left of the table to scroll through the rows.
Press the "Apply" button when changes are made.

Second, a PMT can be appended to the end of the file. This is done by selecting the "Append Single PMT?" button and entering a PMT number and 4 voltages in the single row table at the bottom of the tab.
Press the "Apply" button when changes are made.

To see the current PMT file, use the "Current PMT File" tab. This is continually updated.

Press the "CLOSE" button when editing is completed to close the application down.





