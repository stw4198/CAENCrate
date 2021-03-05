<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="18008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Vis" Type="Folder">
			<Item Name="HVSubVis" Type="Folder">
				<Item Name="HV_Error_Statuses.vi" Type="VI" URL="../Vis/HVSubVis/HV_Error_Statuses.vi"/>
				<Item Name="HV_Full_Monitor_Single.vi" Type="VI" URL="../Vis/HVSubVis/HV_Full_Monitor_Single.vi"/>
				<Item Name="HV_ISet_Multi.vi" Type="VI" URL="../Vis/HVSubVis/HV_ISet_Multi.vi"/>
				<Item Name="HV_ISet_Single.vi" Type="VI" URL="../Vis/HVSubVis/HV_ISet_Single.vi"/>
				<Item Name="HV_Import_Status_from_sethv.vi" Type="VI" URL="../Vis/HVSubVis/HV_Import_Status_from_sethv.vi"/>
				<Item Name="HV_Manual_Control_sethv_Path.vi" Type="VI" URL="../Vis/HVSubVis/HV_Manual_Control_sethv_Path.vi"/>
				<Item Name="HV_Onstate_Multi.vi" Type="VI" URL="../Vis/HVSubVis/HV_Onstate_Multi.vi"/>
				<Item Name="HV_Onstate_Single.vi" Type="VI" URL="../Vis/HVSubVis/HV_Onstate_Single.vi"/>
				<Item Name="HV_Rampset.vi" Type="VI" URL="../Vis/HVSubVis/HV_Rampset.vi"/>
				<Item Name="HV_SWVMaxSet.vi" Type="VI" URL="../Vis/HVSubVis/HV_SWVMaxSet.vi"/>
				<Item Name="HV_Status_Main.vi" Type="VI" URL="../Vis/HVSubVis/HV_Status_Main.vi"/>
				<Item Name="HV_Status_to_Bool.vi" Type="VI" URL="../Vis/HVSubVis/HV_Status_to_Bool.vi"/>
				<Item Name="HV_VSet_Multi.vi" Type="VI" URL="../Vis/HVSubVis/HV_VSet_Multi.vi"/>
				<Item Name="HV_VSet_Single.vi" Type="VI" URL="../Vis/HVSubVis/HV_VSet_Single.vi"/>
				<Item Name="HV_Volt_Monitor.vi" Type="VI" URL="../Vis/HVSubVis/HV_Volt_Monitor.vi"/>
			</Item>
			<Item Name="WavedumpSubVis" Type="Folder">
				<Item Name="Clear_Old_Files.vi" Type="VI" URL="../Vis/WavedumpSubVis/Clear_Old_Files.vi"/>
				<Item Name="Create_PMT_Dir.vi" Type="VI" URL="../Vis/WavedumpSubVis/Create_PMT_Dir.vi"/>
				<Item Name="Create_Run_Dir.vi" Type="VI" URL="../Vis/WavedumpSubVis/Create_Run_Dir.vi"/>
				<Item Name="Find_Binary_Wavedump.vi" Type="VI" URL="../Vis/WavedumpSubVis/Find_Binary_Wavedump.vi"/>
				<Item Name="Move_Files.vi" Type="VI" URL="../Vis/WavedumpSubVis/Move_Files.vi"/>
				<Item Name="Plot.vi" Type="VI" URL="../Vis/WavedumpSubVis/Plot.vi"/>
				<Item Name="Read_Binary_Wavedump_File.vi" Type="VI" URL="../Vis/WavedumpSubVis/Read_Binary_Wavedump_File.vi"/>
				<Item Name="Run.vi" Type="VI" URL="../Vis/WavedumpSubVis/Run.vi"/>
				<Item Name="Send_Bash_Command.vi" Type="VI" URL="../Vis/WavedumpSubVis/Send_Bash_Command.vi"/>
				<Item Name="Start_Stop.vi" Type="VI" URL="../Vis/WavedumpSubVis/Start_Stop.vi"/>
				<Item Name="Temp_Mon.vi" Type="VI" URL="../Vis/WavedumpSubVis/Temp_Mon.vi"/>
				<Item Name="Trigger_Cont.vi" Type="VI" URL="../Vis/WavedumpSubVis/Trigger_Cont.vi"/>
				<Item Name="Variables.vi" Type="VI" URL="../Vis/WavedumpSubVis/Variables.vi"/>
				<Item Name="Write.vi" Type="VI" URL="../Vis/WavedumpSubVis/Write.vi"/>
				<Item Name="Write_Bash.vi" Type="VI" URL="../Vis/WavedumpSubVis/Write_Bash.vi"/>
			</Item>
			<Item Name="HV_Manual_Control.vi" Type="VI" URL="../Vis/HV_Manual_Control.vi"/>
			<Item Name="Read_Wavedump_Files.vi" Type="VI" URL="../Vis/Read_Wavedump_Files.vi"/>
			<Item Name="Run_Wavedump.vi" Type="VI" URL="../Vis/Run_Wavedump.vi"/>
			<Item Name="wavedump.vi" Type="VI" URL="../Vis/wavedump.vi"/>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Application Directory.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Application Directory.vi"/>
				<Item Name="Check if File or Folder Exists.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/libraryn.llb/Check if File or Folder Exists.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Error Cluster From Error Code.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Cluster From Error Code.vi"/>
				<Item Name="NI_FileType.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/lvfile.llb/NI_FileType.lvlib"/>
				<Item Name="NI_PackedLibraryUtility.lvlib" Type="Library" URL="/&lt;vilib&gt;/Utility/LVLibp/NI_PackedLibraryUtility.lvlib"/>
				<Item Name="System Exec.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/system.llb/System Exec.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="HV_control" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{5096A4E6-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{5096A445-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{5096AA3D-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">HV_control</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">..</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{5096AA5B-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_version.build" Type="Int">5</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Destination[0].destName" Type="Str">HV</Property>
				<Property Name="Destination[0].path" Type="Path">../HV</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="SourceCount" Type="Int">3</Property>
				<Property Name="Source[0].itemID" Type="Str">{E6D4D92D-7DDA-11EB-A973-98E743BCDD6C}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[1].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Vis/HVSubVis</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[1].type" Type="Str">Container</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/Vis/HV_Manual_Control.vi</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[2].type" Type="Str">VI</Property>
				<Property Name="TgtF_fileDescription" Type="Str">HV_control</Property>
				<Property Name="TgtF_internalName" Type="Str">HV_control</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright 2021 </Property>
				<Property Name="TgtF_productName" Type="Str">HV_control</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{5096A95D-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">HV</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
			<Item Name="wavedump_read" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{65947BD2-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{65947B29-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{65948187-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">wavedump_read</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">..</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{659481A6-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_version.build" Type="Int">5</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Destination[0].destName" Type="Str">read_file</Property>
				<Property Name="Destination[0].path" Type="Path">../read_file</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="SourceCount" Type="Int">3</Property>
				<Property Name="Source[0].itemID" Type="Str">{E6D4D92D-7DDA-11EB-A973-98E743BCDD6C}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Vis/Read_Wavedump_Files.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[2].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/Vis/WavedumpSubVis</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">Container</Property>
				<Property Name="TgtF_fileDescription" Type="Str">wavedump_read</Property>
				<Property Name="TgtF_internalName" Type="Str">wavedump_read</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright 2021 </Property>
				<Property Name="TgtF_productName" Type="Str">wavedump_read</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{6594809A-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">read_file</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
			<Item Name="wavedump_run" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{251E1D11-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{251E1C67-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{251E22D6-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">wavedump_run</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">..</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{251E22F7-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="Bld_version.build" Type="Int">15</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Destination[0].destName" Type="Str">wavedump</Property>
				<Property Name="Destination[0].path" Type="Path">../wavedump</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="SourceCount" Type="Int">3</Property>
				<Property Name="Source[0].itemID" Type="Str">{E6D4D92D-7DDA-11EB-A973-98E743BCDD6C}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Vis/Run_Wavedump.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[2].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/Vis/WavedumpSubVis</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">Container</Property>
				<Property Name="TgtF_fileDescription" Type="Str">wavedump_run</Property>
				<Property Name="TgtF_internalName" Type="Str">wavedump_run</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright 2021 </Property>
				<Property Name="TgtF_productName" Type="Str">wavedump_run</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{251E21E8-7DDB-11EB-91FF-98E743BCDD6C}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">wavedump</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
