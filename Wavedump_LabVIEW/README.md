####################
Wavedump LabVIEW Control
####################

Authors: Stephen Wilson (swilson8@sheffield.ac.uk)

################
Requirements
################

Software
 - CAENComm*
 - CAENVMELib*
 - Wavedump*
 - GNU Plot
 - A2818 Driver (For CAEN A2818 PCI Card)
 - CAENUSBdrv* (CAEN USB driver)
 - LabVIEW 2018 (Professional to build applications)

*Available for download from CAEN website

Hardware
 - VME Crate
 - CAEN V1730 Digitiser
 - Linux PC (CentOS 7/Scientific Linux 7 preferred)
 - USB type A to B cable
 - Fibre Cable

########
Intro
########

Wavedump is used to record waveforms, with a particular emphasis on signals from PMTs for this experiment.

Run_Wavedump.vi within the WavedumpLabVIEW project is used to run wavedump tests without needing to use the terminal. It works by running a bash script that selects the Wavedump config file needed for a certain test and determines the time that wavedump records for.
Run_Wavedump allows PMT numbers, the channels they are connected to and the test being performed to be entered. It will then run the test and store the output files in a directory ([Test_Name]/[PMT_Number] eg After_Pulsing/PMT_0) that can be found in the same directory as the folder containing this LabVIEW project. Old files will be wiped from the working directory before the new ones are recorded.
GNU plot will open up and show the waveforms being recorded during recording, it will then close after the recording is stopped.
Read_Wavedump_Files can be executed from within the WavedumpLabVIEW file. This allows the output files to be read and viewed after they have been recorded.

################
Hardware Setup
################

 1. Using the hexidecimal keys on the right of the V1730, set the base address to 32100000 (3210 on the card).
 2. Place the digitiser into the VME crate.
 3. Install the A2818 PCI card into the motherboard of the computer.
 4. Plug the digitiser into the PCI card using the fibre cable.

################
Software Setup
################

 1. Make sure all CAEN softwares and LabVIEW are installed.
 2. Open the WavedumpLabVIEW.lvproj project file within LabVIEW.
 3. Open Run_Wavedump_Tests.vi. This is used the run the tests
 4. Using this, open Read_Wavedump_Files by pressing the "Read File" button when first vi is running. Both programs must be built as applications to do this.
 5. To construct these as applications, please see the "HowToBuildApplication" file.
	Please note the applications are called "Wavedump_LabVIEW" and "ReadPMTFiles".

################
Running a Test
################

 1. Within the "Run_Wavedump.vi", enter the PMTs being tested (up to 8) into consecutive boxes starting from the first box and the channels they are connected to (0-15).
 2. Select the test being performed.
 3. Press "Start" button when vi is running to start the test.
 4. To view the files being written, press the "View PMT Files" button. This opens the "Read_Wavedump_Files" vi. Please see the following section for further instruction.
 5. Press "CLOSE" when finished to close the program.

################
Viewing Output Files
################

 1. When "Read_All_Files" vi is open and running, there are two options to view the files, automatic and manual. These are located in the tabs labelled "Auto Viewing" and "Manual Viewing".
 2. For auto viewing, enter the list of PMTs and the test and press "Start". This will view the traces at a rate of 1 per second for the same length of time as the file was recorded for, scrolling through the waveforms. This rate can be increased to scroll through the traces faster  using the "Viewing Rate" box. If the test was performed at 1 KHz, this will correspond to 1 in 1000 waveforms.
 3. Use the tick box next to the graph to choose which of the plots are visible.
 4. Press "STOP" to stop viewing the traces in automatic mode.
 5. For manual viewing, enter the PMT number and the trace which you would like to view. Use the arrows to scroll through the traces one at a time. The auto viewing must not be running to use this function.
 6. Press "CLOSE" to close the program down.

################
Edits for Testing
################

As these programs were build without access to the final test setup, some parameters and test names will need to be adjusted.

 1. The time taken for the tests. 
	The files for the tests will be copied directories associated with the test and PMT. This should happen after testing has been completed. To ensure this happens, enter the block diagram of the "Run_Wavedump" vi by pressing ctrl+e once the vi is open. Then, in the third section of the diagram where there is a label saying "Test Times", use the arrows at the top of the box to scroll through the test names. Within the box for each of the tests, change the number labelled as "Time (s)" to the length of time is takes to fully run the bash script for each test (recording length and all sleep times).

	Play around with the time values if the files don't seem to be copied at the end of if the program seems to sit and wait for a long time. There are a series of indicators to show how long the program has waited and when the wait is completed to aid the editing process. Some sections have been labelled in such a way as to show the user what can be deleted if unused in this testing.

 2. The names of test folder and bash scripts.
	The correct names for folders and bash scripts for each test are needed. Currently, there are 5 tests included:

	- Nominal Voltage (Bash Script = Nominal_Voltage.sh, Bash Script Folder = Nominal_Voltage, New Folder for PMT Files = Nominal_Voltage)
	- Gain (Bash Script = Gain_Test.sh, Bash Script Folder = Gain_Test, New Folder for PMT Files = Gain_Test)
	- Dark Rate (Bash Script = DarkRateTest.sh, Bash Script Folder = DarkRateTest, New Folder for PMT Files = Dark_Rate)
	- SPE (Bash Script = SPE_Test.sh, Bash Script Folder = SPE_Test, New Folder for PMT Files = SPE_Test)
	- After Pulsing (Bash Script = AP_Test.sh, Bash Script Folder = AP_Test, New Folder for PMT Files = After_Pulsing)

	To add more tests, create the folder within the Wavedump_LabVIEW directory for the bash script and place the bash script inside. Then, right click on the "Test" box within the Run_Wavedump vi and click edit items. Press insert in the pop up box and insert the name of the test eg "Nominal Voltage", and press "OK".
	Next, press ctrl+e to open the block diagram. Right click in empty space to open the functions palette and hover over the "String" option, before clicking on "String Constant". Drag the pink empty box inside the Event Structure and drop it near the pink boxes with text that have the name of the folder containing bash scripts in them. Double click the empty box and type the name of the new folder containing the bash script inside it.
	On the case structure furthest left, right click the top where the names are and press "Duplicate Case". Change the name to match the item added to the Test box on the front panel. Delete the lower wire and rewire the same terminal on the "CLEAR OLD FILES" box to the new folder name by left clicking the terminal that says "Bash Script Folder Name" when hovered over and then left clicking the new test's folder name.
	Then, duplicate the next case structure along that contain "RUN BASH" and rename it in the same way as the previous case structure. Delet the pink wire connected to "Build Path" and wire the "name or relative path" terminal to the new test folder name. Edit the "Name of Bash Script" box to contain the name of the new bash script and edit the "message" box to contain the name of the new test.
	For the "Test Times" case structure, repeat the duplicating case process. Then, change the "Time (s)" box to contain the time taken for the test (see previous item within Edits fot Testing).
	Finally, duplicate the case for the final case structure and rename the case. Change the "Name of Folder to Copy PMT File to" to the name of the folder for the test to save the output files to. Delete the second wire down and rewire this terminal to the folder containing the new bash script that was created at the very start.
	This should allow a new test to be added and run via this program.

	To edit test names to match up with bash script file/folder names (recommended to change name of file/folder itself), change the name of the folder in the relevant pink box toward the left of the block diagram. For a bash script, select the relevant case in the second case structure and change the name of the bash script within that case.
	
