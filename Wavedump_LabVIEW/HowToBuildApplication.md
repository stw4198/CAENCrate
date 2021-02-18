Author: Stephen Wilson, University of Sheffield
Email: swilson8@sheffield.ac.uk

################
Software Requirements
################

LabVIEW Professional (18.0 or newer)
Wavedump
CAENComm
CAENDigitiser
A2818 Driver module

################
Creating Application
################

Open the Wavedump_LabVIEW.lvproj project file in LabVIEW.

Expand the Build Specifications tab at the bottom:

If the Build Specifications tab has Run_Wavedump and Read_Wavedump_Files present, right click them both and press "Build". This should build the applications immediately. Press done when the application is built.

If Build Specifications is empty or either is missing, follow the steps below:

- Right click on the Build Specifications tab at the bottom of the list and select New >> Application

For "Run_Wavedump":

- Go to the information tab and set the build specification name to Run_Wavedump and the target filename to WavedumpLabVIEW.
- Set the destination directory to the same one the project file is located in (Wavedump_LabVIEW). The default option is often wrong and will place the application in the directory above.

- Click on the Source Files tab. Expand the Vis folder and click on Run_Wavedump.vi, before pressing the right arrow next to Startup Vis. It should list Run_Wavedump in the Startup Vis sections.
- Click on the Sub Vis folder and press the right arrow next to Always included, this should move the while folder to the Always included section.

For "Read_Wavedump_Files":

- Go to the information tab and set the build specification name to Run_Wavedump_Files and the target filename to ReadPMTFiles.
- Set the destination directory to the same one the project file is located in (Wavedump_LabVIEW). The default option is often wrong and will place the application in the directory above.

- Click on the Source Files tab. Expand the Vis folder and click on Read_Wavedump_Files.vi, before pressing the right arrow next to Startup Vis. It should list Read_Wavedump_Files in the Startup Vis sections.
- Click on the Sub Vis folder and press the right arrow next to Always included, this should move the while folder to the Always included section.

- Press the build button at the bottom and the application should build within the same folder as the project is opened in.

When using centOS 7 or Scientific Linux 7, two purple icons should appear in the Wavedump_LabVIEW folder. This is the application.

################
Using Application
################

Navigate to where the application is stored and double click it to open. Or open the location in the terminal and run ./WavedumpLabVIEW. Both of these should open the application.

When open, the application is the same as the front panel of the normal Run_Wavedump vi, but it is permanently running and the code can't be seen or anything moved. The operations are carried out in exactly the same way as the vi (see ReadMe file or Read Me tab in vi).

The same should occur if ./ReadPMTFiles is run for Read_Wavedump_Files. Alternatively, press the "View PMT Files" button in Run_Wavedump.

###############
Applying changes made to vi
###############

If any changes are made to the vi, to apply them to the application, open the project file in labview. Then expand the build specifications section and right click on the applications and press build. This should rebuild the application and apply changes.

If there are any issues in building the application, please contact me via the email given at the top.

