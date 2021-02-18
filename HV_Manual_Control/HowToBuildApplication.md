Author: Stephen Wilson, University of Sheffield
Email: swilson8@sheffield.ac.uk

################
Software Requirements
################

LabVIEW Professional (18.0 or newer)
sethv HV control terminal application

################
Creating Application
################

Open the HV_Manual_Control.lvproj project file in LabVIEW.

Expand the Build Specifications tab at the bottom:

If the Build Specifications tab has HV_Manual_Control present, right click the HV_Manual_Control app and press "Build". This should build the application immediately. Press done when the application is built.

If Build Specifications is empty, follow the steps below:

- Right click on the Build Specifications tab at the bottom of the list and select New >> Application

- Go to the information tab and set the build specification name to HV_Manual_Control and the target filename to HVManualControl.
- Set the destination directory to the same one the project file is located in (HV_Manual_Control). The default option is often wrong and will place the application in the directory above.

- Click on the Source Files tab. Expand the Vis folder and click on HV_Manual_Control.vi, before pressing the right arrow next to Startup Vis. It should list HV_Manual_Control in the Startup Vis sections.
- Click on the Sub Vis folder and press the right arrow next to Always included, this should move the while folder to the Always included section.

- Press the build button at the bottom and the application should build within the same folder as the project is opened in.

When using centOS 7 or Scientific Linux 7, a purple icon should appear in the HV_Manual_Control folder. This is the application.

################
Using Application
################

Navigate to where the application is stored and double click it to open. Or open the location in the terminal and run ./HVManualControl. Both of these should open the application.

When open, the application is the same as the front panel of the normal HV_Manual_Control vi, but it is permanently running and the code can't be seen or anything moved. The operations are carried out in exactly the same way as the vi (see ReadMe file or Read Me tab in vi).

###############
Applying changes made to vi
###############

If any chnages are made to the vi, to apply them to the application, open the project file in labview. Then expand the build specifications section and right click on the HV_Manual_Control application and press build. This should rebuild the application and apply changes.

If there are any issues in building the application, please contact me via the email given at the top.

