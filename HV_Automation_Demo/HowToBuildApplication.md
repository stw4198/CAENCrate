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

Open the HV Automation Demo.lvproj project file, that is located in HV_Automation_Demo/LabVIEW_Control, in LabVIEW.

To build "HVAutoDemo":

Expand the Build Specifications tab at the bottom:

If the Build Specifications tab has HV_Automation_Demo present, right click the HV_Automation_Demo app and press "Build". This should build the application immediately. Press done when the application is built.

If Build Specifications doesn't contain this, follow the steps below:

- Right click on the Build Specifications tab at the bottom of the list and select New >> Application

- Go to the information tab and set the build specification name to HV_Automation_Demo and the target filename to HVAutoDemo.
- Set the destination directory to the same one the project file is located in (HV_Automation_Demo/LabVIEW_Control). The default option is often wrong and will place the application in the directory above.

- Click on the Source Files tab. Click on Main.vi, before pressing the right arrow next to Startup Vis. It should list Main.vi in the Startup Vis sections.
- Click on the HV QMH.lvlib and press the right arrow next to Always included, this should move the while folder to the Always included section.

- Press the build button at the bottom and the application should build within the same folder as the project is opened in.

When using centOS 7 or Scientific Linux 7, a purple icon called HVAutoDemo should appear in the HV_Automation_Demo/LabVIEW_Control folder. This is the application.




To build "HVEditPMTFile":

Expand the Build Specifications tab at the bottom:

If the Build Specifications tab has HV_Edit_PMT_File present, right click the HV_Edit_PMT_File app and press "Build". This should build the application immediately. Press done when the application is built.

If Build Specifications doesn't contain this, follow the steps below:

- Right click on the Build Specifications tab at the bottom of the list and select New >> Application

- Go to the information tab and set the build specification name to HV_Edit_PMT_File and the target filename to HVEditPMTFile.
- Set the destination directory to the same one the project file is located in (HV_Automation_Demo/LabVIEW_Control). The default option is often wrong and will place the application in the directory above.

- Click on the Source Files tab. Click on HV Edit PMT File.vi, before pressing the right arrow next to Startup Vis. It should list HV Edit PMT File.vi in the Startup Vis sections.
- Click on the HV QMH.lvlib and press the right arrow next to Always included, this should move the while folder to the Always included section.

- Press the build button at the bottom and the application should build within the same folder as the project is opened in.

When using centOS 7 or Scientific Linux 7, a purple icon called HVEditPMTFile should appear in the HV_Automation_Demo/LabVIEW_Control folder. This is the application.

################
Using Applications
################

HV_Automation_Demo:

Navigate to where the application is stored and double click it to open. Or open the location in the terminal and run ./HVAutoDemo. Both of these should open the application.

When open, the application is the same as the front panel of the normal Main.vi, but it is opened running and the code can't be seen or anything moved. The operations are carried out in exactly the same way as the vi (see ReadMe file or Read Me tab in vi).

The application needs to be built to use the "Edit PMT File" button.

HV_Edit_PMT_File:

Press the "Edit PMT File" button when running the HVAutoDemo application. Or, locate the application within the terminal and run ./HVEditPMTFile. Finally, double clicking the application icon in the directory should also load it.

###############
Applying changes made to vi
###############

If any chnages are made to the vi, to apply them to the application, open the project file in labview. Then expand the build specifications section and right click on the relevant application and press build. This should rebuild the application and apply changes.

If there are any issues in building the application, please contact me via the email given at the top.

