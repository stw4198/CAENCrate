#include "sethv.h"
#include <typeinfo>
int32_t handle;
uint32_t hv_data;
std::vector<int> enable_channel;
std::string config_file;

int init()
{
  CVBoardTypes vme_board = cvV1718;
  CVErrorCodes ret;
  ret = CAENVME_Init(vme_board, V1718_USB_PORT, V1718_USB_PORT, &handle);
  std::cout << "Err: " << ret << std::endl;
  if (ret != cvSuccess)
    {
      printf("######################\n#Error opening V1718!#\n######################\n");
      CAENVME_End(handle);
      return 0;
    }
  return 1;
}

int statusmonitor()
{
  /*
  Gets the status of each channel on each card and prints them in tabular format.
  If a status is not true, (e.g. the card is NOT tripping) then only a comma is printed.
  This is used for manipulating the statuses as an array in LabVIEW.
  */
  if (!init()) return 1;
  
  int num_not_ready = 0;
  std::string excellentarray[14];//Initialise an array to hold possible statuses
  std::string * excellent;//Statusarray returns a pointer to an array
  for (int ch = 0; ch < 6; ch++)
    {
      std::cout<< ",";
      excellent = statusarray(ch, "A");//Set Pointer to location of status array
      for (int i = 0; i < 14; i++)
        {
          excellentarray[i] = *(excellent + i);//Dereference pointer at array index location in memory
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
    }  
  for (int ch = 0; ch < 6; ch++)
    {
      std::cout << ",";
      excellent = statusarray(ch, "B");
      for (int i = 0; i < 14; i++)
        {
          excellentarray[i] = *(excellent + i);
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
      
    }
  for (int ch = 0; ch < 6; ch++)
    {
      std::cout << ",";
      excellent = statusarray(ch, "C");
      for (int i = 0; i < 14; i++)
        {
          excellentarray[i] = *(excellent + i);
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
      
    }
 
  if (num_not_ready>0) return 1;
  return 0;
}  

int monitor()
{
  /*
  Monitors all parameters in comma delimited format
  Used for monitoring within LabVIEW
  */
  if (!init()) return 1;
  
  bool ready = true;
  int num_not_ready = 0;
  printf("Board, Ch, ISet, VSet, VMon, SWVMax, IMon, RUp, RDwn, Status\n");
  for (int ch = 0; ch < 6; ch++)
    {
      std::string stat = status(ch,1); //have third option of 0 for board C?
      ready = (!strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF") || !strcmp(stat.c_str(),"DISABLED "));
      
      if (!ready)
	{
	  num_not_ready++;
	  printf("V6534PA, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pa(ch),get_config_voltage_v6534pa(ch),get_voltage_v6534pa(ch),get_svmax_v6534pa(ch),get_current_v6534pa(ch),get_ramp_up_v6534pa(ch), get_ramp_down_v6534pa(ch),stat.c_str());
	}
      else
	{
	  printf("V6534PA, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pa(ch),get_config_voltage_v6534pa(ch),get_voltage_v6534pa(ch),get_svmax_v6534pa(ch),get_current_v6534pa(ch),get_ramp_up_v6534pa(ch), get_ramp_down_v6534pa(ch),stat.c_str());
	}    
    }  
  for (int ch = 0; ch < 6; ch++)
    {
      std::string stat = status(ch,-1);
      ready = (ch == 1 || !strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF"));
      if (!ready)
	{
          num_not_ready++;
          printf("V6534PB, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pb(ch),get_config_voltage_v6534pb(ch),get_voltage_v6534pb(ch),get_svmax_v6534pb(ch),get_current_v6534pb(ch),get_ramp_up_v6534pb(ch), get_ramp_down_v6534pb(ch),stat.c_str());
        }
      else
	{
	  printf("V6534PB, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pb(ch),get_config_voltage_v6534pb(ch),get_voltage_v6534pb(ch),get_svmax_v6534pb(ch),get_current_v6534pb(ch),get_ramp_up_v6534pb(ch), get_ramp_down_v6534pb(ch),stat.c_str());
        }
    }
  for (int ch = 0; ch < 6; ch++)
    {
      std::string stat = status(ch,0);
      ready = (ch == 1 || !strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF"));
      if (!ready)
	{
          num_not_ready++;
          printf("V6534PC, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pc(ch),get_config_voltage_v6534pc(ch),get_voltage_v6534pc(ch),get_svmax_v6534pc(ch),get_current_v6534pc(ch),get_ramp_up_v6534pc(ch), get_ramp_down_v6534pc(ch),stat.c_str());
        }
      else
	{
	  printf("V6534PC, %i, %.3fuA, %.3fV, %.3fV, %iV, %.3fuA, %iVps, %iVps, %s,\n",ch, get_config_current_v6534pc(ch),get_config_voltage_v6534pc(ch),get_voltage_v6534pc(ch),get_svmax_v6534pc(ch),get_current_v6534pc(ch),get_ramp_up_v6534pc(ch), get_ramp_down_v6534pc(ch),stat.c_str());
        }
    }
 
  if (num_not_ready>0) return 1;
  return 0;
}

std::string status(int ch, int board)
{
  std::string full_status;

  if (board == -1)//Board B
    {
      struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pb(ch);
      if (stat->ON) full_status+="ON ";
      if (stat->RAMPUP) full_status+="RAMPUP ";
      if (stat->RAMPDOWN) full_status+="RAMPDOWN ";
      if (stat->OVERCURRENT) full_status+="OVERCURRENT ";
      if (stat->OVERVOLTAGE) full_status+="OVERVOLTAGE ";
      if (stat->UNDERVOLTAGE) full_status+="UNDERVOLTAGE ";
      if (stat->MAXV) full_status+="MAXV ";
      if (stat->MAXI) full_status+="MAXI ";
      if (stat->TRIP) full_status+="TRIP ";
      if (stat->OVERPOWER) full_status+="OVERPOWER ";
      if (stat->OVERTEMPERATURE) full_status+="OVERTEMPERATURE ";
      if (stat->DISABLED) full_status+="DISABLED ";
      if (stat->INTERLOCK) full_status+="INTERLOCK ";
      if (stat->UNCALIBRATED) full_status+="UNCALIBRATED ";
      if (full_status.length()==0) full_status+="OFF";
    }
  else if (board == 1)//Board A
    {
      struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pa(ch);
      if (stat->ON) full_status+="ON ";
      if (stat->RAMPUP) full_status+="RAMPUP ";
      if (stat->RAMPDOWN) full_status+="RAMPDOWN ";
      if (stat->OVERCURRENT) full_status+="OVERCURRENT ";
      if (stat->OVERVOLTAGE) full_status+="OVERVOLTAGE ";
      if (stat->UNDERVOLTAGE) full_status+="UNDERVOLTAGE ";
      if (stat->MAXV) full_status+="MAXV ";
      if (stat->MAXI) full_status+="MAXI ";
      if (stat->TRIP) full_status+="TRIP ";
      if (stat->OVERPOWER) full_status+="OVERPOWER ";
      if (stat->OVERTEMPERATURE) full_status+="OVERTEMPERATURE ";
      if (stat->DISABLED) full_status+="DISABLED ";
      if (stat->INTERLOCK) full_status+="INTERLOCK ";
      if (stat->UNCALIBRATED) full_status+="UNCALIBRATED ";
      if (full_status.length()==0) full_status+="OFF";
    }
  else if (board == 0)//Board C
    {
      struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pc(ch);
      if (stat->ON) full_status+="ON ";
      if (stat->RAMPUP) full_status+="RAMPUP ";
      if (stat->RAMPDOWN) full_status+="RAMPDOWN ";
      if (stat->OVERCURRENT) full_status+="OVERCURRENT ";
      if (stat->OVERVOLTAGE) full_status+="OVERVOLTAGE ";
      if (stat->UNDERVOLTAGE) full_status+="UNDERVOLTAGE ";
      if (stat->MAXV) full_status+="MAXV ";
      if (stat->MAXI) full_status+="MAXI ";
      if (stat->TRIP) full_status+="TRIP ";
      if (stat->OVERPOWER) full_status+="OVERPOWER ";
      if (stat->OVERTEMPERATURE) full_status+="OVERTEMPERATURE ";
      if (stat->DISABLED) full_status+="DISABLED ";
      if (stat->INTERLOCK) full_status+="INTERLOCK ";
      if (stat->UNCALIBRATED) full_status+="UNCALIBRATED ";
      if (full_status.length()==0) full_status+="OFF";
    }
  
  return full_status;
}

std::string * statusarray(int ch, std::string board)
  {
    std::string* full_status = new std::string[14];
    if (board == "A")
      {
        struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pa(ch);
        if (stat->ON) full_status[0] = "On";
        if (stat->RAMPUP) full_status[1] = "RAMPUP";
        if (stat->RAMPDOWN) full_status[2] = "RAMPDOWN";
        if (stat->OVERCURRENT) full_status[3] = "OVERCURRENT";
        if (stat->OVERVOLTAGE) full_status[4] = "OVERVOLTAGE";
        if (stat->UNDERVOLTAGE) full_status[5] = "UNDERVOLTAGE";
        if (stat->MAXV) full_status[6] = "MAXV";
        if (stat->MAXI) full_status[7] = "MAXI";
        if (stat->TRIP) full_status[8] = "TRIP";
        if (stat->OVERPOWER) full_status[9] = "OVERPOWER";
        if (stat->OVERTEMPERATURE) full_status[10] = "OVERTEMPERATURE";
        if (stat->DISABLED) full_status[11] = "DISABLED";
        if (stat->INTERLOCK) full_status[12] = "INTERLOCK";
        if (stat->UNCALIBRATED) full_status[13] = "UNCALIBRATED";
      }
    else if (board == "B")
      {
        struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pb(ch);
        if (stat->ON) full_status[0] = "On";
        if (stat->RAMPUP) full_status[1] = "RAMPUP";
        if (stat->RAMPDOWN) full_status[2] = "RAMPDOWN";
        if (stat->OVERCURRENT) full_status[3] = "OVERCURRENT";
        if (stat->OVERVOLTAGE) full_status[4] = "OVERVOLTAGE";
        if (stat->UNDERVOLTAGE) full_status[5] = "UNDERVOLTAGE";
        if (stat->MAXV) full_status[6] = "MAXV";
        if (stat->MAXI) full_status[7] = "MAXI";
        if (stat->TRIP) full_status[8] = "TRIP";
        if (stat->OVERPOWER) full_status[9] = "OVERPOWER";
        if (stat->OVERTEMPERATURE) full_status[10] = "OVERTEMPERATURE";
        if (stat->DISABLED) full_status[11] = "DISABLED";
        if (stat->INTERLOCK) full_status[12] = "INTERLOCK";
        if (stat->UNCALIBRATED) full_status[13] = "UNCALIBRATED";
      }
    else if (board == "C")
      {
        struct STATUS_REGISTER *stat = (struct STATUS_REGISTER *) get_channel_status_v6534pc(ch);
        if (stat->ON) full_status[0] = "On";
        if (stat->RAMPUP) full_status[1] = "RAMPUP";
        if (stat->RAMPDOWN) full_status[2] = "RAMPDOWN";
        if (stat->OVERCURRENT) full_status[3] = "OVERCURRENT";
        if (stat->OVERVOLTAGE) full_status[4] = "OVERVOLTAGE";
        if (stat->UNDERVOLTAGE) full_status[5] = "UNDERVOLTAGE";
        if (stat->MAXV) full_status[6] = "MAXV";
        if (stat->MAXI) full_status[7] = "MAXI";
        if (stat->TRIP) full_status[8] = "TRIP";
        if (stat->OVERPOWER) full_status[9] = "OVERPOWER";
        if (stat->OVERTEMPERATURE) full_status[10] = "OVERTEMPERATURE";
        if (stat->DISABLED) full_status[11] = "DISABLED";
        if (stat->INTERLOCK) full_status[12] = "INTERLOCK";
        if (stat->UNCALIBRATED) full_status[13] = "UNCALIBRATED";
      }
    

    return full_status;
  }

int rampup(int speed)
{
  /*
  Sets rampup rate
  */
  if (!init()) return 1;
  CVErrorCodes ret;
  bool success = true;
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_up_v6534pb(chan,(uint32_t)speed);
      if (ret != cvSuccess)
	{
	  std::cout << "Err: " << ret << std::endl;
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_up_v6534pa(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_up_v6534pc(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  
  CAENVME_End(handle);
  if (!success) return 1;
  return 0;
}

int rampdown(int speed)
{
  /*
  Sets rampdown rate
  */
  if (!init()) return 1;
  CVErrorCodes ret;
  bool success = true;
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_down_v6534pb(chan,(uint32_t)speed);
      if (ret != cvSuccess)
	{
	  std::cout << "Err: " << ret << std::endl;
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_down_v6534pa(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_down_v6534pc(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  
  CAENVME_End(handle);
  if (!success) return 1;
  return 0;
}

int OnOff(uint32_t chnum, bool OnOff)
{
  if (!init()) return 1;
  //Just allows selective channel enabling/disabling
  CVErrorCodes ret;
  bool success = true;//used to tell other functions whether or not this operation was successful
  if (OnOff)
  {
    if (chnum < 6) //Channels <6 are in first card
      {
        ret = enable_channel_v6534pa(chnum); //enables channel in first card
        if (ret != cvSuccess) // if it doesn't work, print a message saying so
          {
            std::cout << "Err: " << ret << std::endl;
            success = false; 
          }
      }
    else if (chnum > 5 && chnum < 12)
      {
        ret = enable_channel_v6534pb(chnum-6);
        if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
      }
    else if (chnum > 11 && chnum < 18)
      {
        ret = enable_channel_v6534pc(chnum-12);
        if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
      }
  }
  else
  {
  
    if (chnum < 6)
      {
        ret = disable_channel_v6534pa(chnum);
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            //std::cout << "Error disabling channel " << chnum << std::endl;
            success = false;
          }
      }
    else if (chnum > 5 && chnum < 12)
      {
        ret = disable_channel_v6534pb(chnum-6);
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            success = false;
          }
      }
    else if (chnum > 11 && chnum < 18)
      {
        ret = disable_channel_v6534pc(chnum-12);
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            success = false;
          }
      }
  }
  if (!success) return 1;
  return 0;
}
int SetVoltage(uint32_t chnum, uint32_t VSet)
{
  //Sets the voltage of a single channel
  if (!init()) return 1; //Initiliases the crate. If it fails, function returns 1 i.e. failure
  bool success = true;     //Used to update status of crate
  CVErrorCodes ret;
    if (chnum < 6)
      {
        ret = set_voltage_v6534pa(chnum, VSet);
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            success = false;
          }
      }
    else if (chnum > 5 && chnum < 12)
      {
        ret = set_voltage_v6534pb(chnum - 6, VSet); 
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            success = false;
          }
      }
    else if (chnum > 11 && chnum < 18)
      {
        ret = set_voltage_v6534pc(chnum - 12, VSet); 
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            success = false;
          }
      }
  if (!success) return 1;
  return 0;
}

int SetCurrent(uint32_t chnum, uint32_t ISet)
{
  //Sets the current of a single channel
  if (!init()) return 1; //Initiliases the crate. If it fails, function returns 1 i.e. failure
  bool success = true;     //Used to update status of crate
  CVErrorCodes ret;
  
  if (chnum < 6)
    {
      ret = set_current_v6534pa(chnum, ISet);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  else if (chnum > 5 && chnum < 12)
    {
      ret = set_current_v6534pb(chnum - 6, ISet);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  else if (chnum > 11 && chnum < 18)
    {
      ret = set_current_v6534pc(chnum - 12, ISet);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  if (!success) return 1;
  return 0;
}
  
int SetVMax(uint32_t SwVMax)
{
  if (!init()) return 1;
  // Sets maximum software voltage
  bool success = true;
  CVErrorCodes ret;
  
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_svmax_v6534pa(chan,SwVMax);
      if (ret != cvSuccess)
	{
	  std::cout << "Err: " << ret << std::endl;
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_svmax_v6534pb(chan,SwVMax);
      if (ret != cvSuccess)
        {
	  std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_svmax_v6534pc(chan,SwVMax);
      if (ret != cvSuccess)
        {
	  std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  if (!success) return 1;
  return 0;
}

int main(int argc, char *argv[]) 
{
  int i = 1;
  int status = 1;
  
  if (argc >= 2 && !strcmp(argv[i], "--VSet"))
    {
      //Uses arguments given to set the voltage for one channel
      //Allows control without using the config file (useful for labview integration)
      status = 1;
      //Convert values in argv to int
      int ch = std::atoi(argv[i+1]);
      int VSet = std::atoi(argv[i+2]);
  
      status = SetVoltage((uint32_t)ch, (uint32_t)VSet);
    }
  else if (argc >= 2 && !strcmp(argv[i], "--ISet"))
    {
      //Uses arguments given to set the current for all channels
      //Possibly necessary if avoiding the use of the config file
      //Convert values in argv to int
      int ch = std::atoi(argv[i+1]);
      int ISet = std::atoi(argv[i+2]);
      
      status = SetCurrent((uint32_t)ch, (uint32_t)ISet);
    }
  else if (argc >= 2 && !strcmp(argv[i], "--power"))
    {
      //Uses arguments given to individually control the on state of each channel
      int ch = std::atoi(argv[i+1]);
      std::string Switch = argv[i+2]; //Switch is the on/off state.
   
      if (Switch == "On" || Switch == "on" || Switch == "1")
        {
          status = OnOff((uint32_t)ch, true);
        }
      else if (Switch == "Off" || Switch ==  "off" || Switch == "0")
        {
          status = OnOff((uint32_t)ch, false);
        }
    
    }
  else if (argc >= 2 && !strcmp(argv[i], "--SetSWVMax"))
    {
      //Sets a software voltage limit for all channels. Does not allow any voltages above 6000
      uint32_t Maximum;
      if (argc < 3)
        {
          std::cout << "Please enter a sensible voltage (<6000V)" << std::endl;
          status = 1;
        }
      else
        {
          Maximum = std::atoi(argv[i+1]);
          status = SetVMax(Maximum);
        }
    }
  else if (argc >= 2 && !strcmp(argv[i], "--monitor"))
    {
      //Used in labview program.
      //Returns voltages, currents of channels only. Does not return status.
      status = monitor();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--statemon"))
    {
      //Returns ONLY the status of all channels. Does not return voltage readouts.
      status = statusmonitor();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--rampup"))
    {  
      if (i+1 != argc)
        {
          std::istringstream ss(argv[i+1]);
          int speed;
          if (ss >> speed)
          {
            status = rampup(speed);
          }
        }
    }
  else if (argc >= 2 && !strcmp(argv[i], "--rampdown"))
    {  
      if (i+1 != argc)
        {
          std::istringstream ss(argv[i+1]);
          int speed;
          if (ss >> speed)
            {
              status = rampdown(speed);
            }
        }
    }
  else
    {
      printf("Usage: sethv [command] [optional parameters]\n");
      printf("  Commands:\n");
      printf("    --VSet        Sets Voltage of a single channel.\n");
      printf("                  Usage: --VSet ch Voltage\n");
      printf("    --ISet        Sets Current of a single channel.\n");
      printf("                  Usage: --ISet ch Current\n");
      printf("    --power     Turns individual Channels on or off.\n");
      printf("                  Usages: --power ch \"On\"/\"Off\" (no quotes) or 1/0\n");
      printf("      Note:       channels 6-11 are interpreted as channels 0-5 on the\n");
      printf("                  second HV card at Base Address 32120000, channels 12-17 are on third card at 32130000\n");
      printf("    --SetSWVMax   Sets the software limit of the voltage based on input.\n");
      printf("    --monitor     Read the instantaneous currents/Voltages from VME\n");
      printf("    --statemon    Reads the status of all channels. Used in LabVIEW\n");
      printf("    --rampup      Set ramp up speed (in V/s).\n");
      printf("    --rampdown    Set ramp down speed (in V/s).\n");
      status = 1;
    }   
  return status;
}

