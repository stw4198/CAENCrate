/*
Orignal Author: Dr Matt Thiesse, University of Sheffield
Significant Changes and Additional Functions added by Max Calle, University of Sheffield
*/
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

int fullmonitor()
{
  /*
  Prints the settings and outputs of all channels and cards, including the statuses
  originally simply called "monitor()" by Matt, changed it to avoid confusion.
  Deigned for use in the terminal
  */
  if (!init()) return 1;
  
  bool ready = true;
  int num_not_ready = 0;
  printf("#Board		Ch				ISet				VSet								VMon				SWVMax				IMon					RUp					RDwn				Status\n");
  for (int ch = 0; ch < 6; ch++)
    {
      std::string stat = status(ch,1);
      ready = (!strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF") || !strcmp(stat.c_str(),"DISABLED "));
      
      if (!ready)
	{
	  num_not_ready++;
	  printf("V6534PA  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pa(ch),get_config_voltage_v6534pa(ch),get_voltage_v6534pa(ch),get_svmax_v6534pa(ch),get_current_v6534pa(ch),get_ramp_up_v6534pa(ch), get_ramp_down_v6534pa(ch),stat.c_str());
	}
      else
	{
	  printf("V6534PA  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pa(ch),get_config_voltage_v6534pa(ch),get_voltage_v6534pa(ch),get_svmax_v6534pa(ch),get_current_v6534pa(ch),get_ramp_up_v6534pa(ch), get_ramp_down_v6534pa(ch),stat.c_str());
	}    
    }  
  for (int ch = 0; ch < 6; ch++)
    {
      //if (ch == 1) continue;
      std::string stat = status(ch,-1);
      ready = (ch == 1 || !strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF"));
      if (!ready)
	{
          num_not_ready++;
          printf("V6534PB  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pb(ch),get_config_voltage_v6534pb(ch),get_voltage_v6534pb(ch),get_svmax_v6534pb(ch),get_current_v6534pb(ch),get_ramp_up_v6534pb(ch), get_ramp_down_v6534pb(ch),stat.c_str());
        }
      else
	{
	  printf("V6534PB  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pb(ch),get_config_voltage_v6534pb(ch),get_voltage_v6534pb(ch),get_svmax_v6534pb(ch),get_current_v6534pb(ch),get_ramp_up_v6534pb(ch), get_ramp_down_v6534pb(ch),stat.c_str());
        }
    }
  /*for (int ch = 0; ch < 6; ch++) //sethv_C
    {
      //if (ch == 1) continue;
      std::string stat = status(ch,-1);
      ready = (ch == 1 || !strcmp(stat.c_str(),"ON ") || !strcmp(stat.c_str(),"OFF")); //set this condition for 3rd card
      if (!ready)
	{
          num_not_ready++;
          printf("V6534PC  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pc(ch),get_config_voltage_v6534pc(ch),get_voltage_v6534pc(ch),get_svmax_v6534pc(ch),get_current_v6534pc(ch),get_ramp_up_v6534pc(ch), get_ramp_down_v6534pc(ch),stat.c_str());
        }
      else
	{
	  printf("V6534PC  %i  %6.1f uA	%6.1f V  %6.1f V  %i V  %6.3f uA  %i Vps  %i Vps %s\n",ch, get_config_current_v6534pc(ch),get_config_voltage_v6534pc(ch),get_voltage_v6534pc(ch),get_svmax_v6534pc(ch),get_current_v6534pc(ch),get_ramp_up_v6534pc(ch), get_ramp_down_v6534pc(ch),stat.c_str());
        }
    }*/
 
  if (num_not_ready>0) return 1;
  return 0;
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
      //std::string stat = status(ch,1);
      std::cout<< ",";
      excellent = statusarray(ch, "A");//Set Pointer to location of status array
      for (int i = 0; i < 14; i++)
        {
          //std::cout << *(excellent + i) << ",";
          excellentarray[i] = *(excellent + i);//Dereference pointer at array index location in memory
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
    }  
  for (int ch = 0; ch < 6; ch++)
    {
      std::cout << ",";
      //if (ch == 1) continue;
      //std::string stat = status(ch,-1);
      excellent = statusarray(ch, "B");
      for (int i = 0; i < 14; i++)
        {
          //std::cout << *(excellent + i) << " ";
          excellentarray[i] = *(excellent + i);
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
      
    }
  /*for (int ch = 0; ch < 6; ch++) //sethv_C
    {
      std::cout << ",";
      //if (ch == 1) continue;
      //std::string stat = status(ch,-1);
      excellent = statusarray(ch, "C");
      for (int i = 0; i < 14; i++)
        {
          //std::cout << *(excellent + i) << " ";
          excellentarray[i] = *(excellent + i);
          std::cout << excellentarray[i] << ",";
        }
      std::cout << std::endl;
      
    }*/
 
  if (num_not_ready>0) return 1;
  return 0;
}  

int voltmonitor()
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
      std::string stat = status(ch,1);
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
      //if (ch == 1) continue;
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
 
  if (num_not_ready>0) return 1;
  return 0;
}

int getconfig() //is this function needed for labview control?
{
  /*
  Used to locate config file
  Not needed in context of HV Manual Control
  */
  if (!init()) return 1;
  
  std::string BOARD,CHNUM,VSET,ISET,
    PW,TRIP_TIME,SVMAX,RAMP_DOWN,
    RAMP_UP,PWDOWN,IMON_RANGE;
  
  std::string line;
  std::ifstream configfile (config_file.c_str(),std::ifstream::in);
  
  if (configfile.is_open())
    {
      while (getline(configfile,line))
        {
	  std::stringstream ss(line);
          ss >> BOARD;
          if (BOARD == "N")
            {
              ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME
                 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;

              if (stoi(PW))
		{
		  enable_channel.push_back((uint32_t)stoi(CHNUM)+10);
		}
            }
          else if (BOARD == "P")
            {
              ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME
                 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;

              if (stoi(PW))
                {
		  enable_channel.push_back((uint32_t)stoi(CHNUM)+20);
		}
	    }
	  else
	    {
	      continue;
	    }
	}
    }
  else
    {
      std::cout << "Config file not opened." << std::endl;
      return 1;
    }

  std::cout << std::right << std::setw(7) << "Board"
	    << std::setw(8) << "Channel"
	    << std::setw(5) << "VSet"
	    << std::setw(5) << "ISet"
	    << std::setw(6) << "Power"
	    << std::setw(5) << "Trip"
	    << std::setw(5) << "VMax"
	    << std::setw(7) << "RampDn"
	    << std::setw(7) << "RampUp"
	    << std::setw(6) << "PwrDn"
	    << std::setw(6) << "ImonR" << std::endl;
  for (int ch = 0; ch < 6; ch++)
    {
      int en = 0;
      if (find(enable_channel.begin(),enable_channel.end(),ch+10) != enable_channel.end())
	{
	  en = 1;
	}

      std::cout << std::right << std::setw(7) << "V6534PB"
		<< std::setw(8) << ch
		<< std::setw(5) << get_config_voltage_v6534pb(ch)
		<< std::setw(5) << get_config_current_v6534pb(ch)
		<< std::setw(6) << en
		<< std::setw(5) << get_trip_time_v6534pb(ch)
		<< std::setw(5) << get_svmax_v6534pb(ch)
		<< std::setw(7) << get_ramp_down_v6534pb(ch)
		<< std::setw(7) << get_ramp_up_v6534pb(ch)
		<< std::setw(6) << get_pwdown_v6534pb(ch)
		<< std::setw(6) << get_imon_range_v6534pb(ch) << std::endl;
    }
  for (int ch = 0; ch < 6; ch++)
    {
      int en = 0;
      if (find(enable_channel.begin(),enable_channel.end(),ch+20) != enable_channel.end())
        {
          en = 1;
	}

      std::cout << std::right << std::setw(7) << "V6534PA"
		<< std::setw(8) << ch
		<< std::setw(5) << get_config_voltage_v6534pa(ch)
		<< std::setw(5) << get_config_current_v6534pa(ch)
		<< std::setw(6) << en
		<< std::setw(5) << get_trip_time_v6534pa(ch)
		<< std::setw(5) << get_svmax_v6534pa(ch)
		<< std::setw(7) << get_ramp_down_v6534pa(ch)
		<< std::setw(7) << get_ramp_up_v6534pa(ch)
		<< std::setw(6) << get_pwdown_v6534pa(ch)
                << std::setw(6) << get_imon_range_v6534pa(ch) << std::endl;
    }
  CAENVME_End(handle);
  return 0;
}

std::string status(int ch, int board)
{
  //Creates a string containing the status of the particular channel.
  //Requires board to be identified by a number
  //This is a legacy from code that used a positive and a negative card
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
  
  return full_status;
}

std::string * statusarray(int ch, std::string board)
  {
    /*
    returns status of an individual channel in the form of an array. Useful for searching within LabVIEW.
    Requires board to be identified by a number
    This is a legacy from code that used a positive and a negative card 
    */
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
    

    return full_status;
  }

//delete[] names;

int setconfig()
{
  if (!init()) return 1;

  std::string BOARD,CHNUM,VSET,ISET,
    PW,TRIP_TIME,SVMAX,RAMP_DOWN,
    RAMP_UP,PWDOWN,IMON_RANGE;

  std::string line;
  std::ifstream configfile (config_file.c_str(),std::ifstream::in);

  bool success = true;

  CVErrorCodes ret;
  
  if (configfile.is_open())
    {
      while (getline(configfile,line))
	{
	  std::stringstream ss(line);
	  ss >> BOARD;
	  if (BOARD == "N")
	    {
	      ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME 
		 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;
	      
	      ret = set_voltage_v6534pb((uint32_t)stoi(CHNUM),(uint32_t)stoi(VSET));
	      if (ret != cvSuccess)
		{
		  printf("\nBad voltage or bad channel\n");
		  success = false;
		}

	      ret = set_current_v6534pb((uint32_t)stoi(CHNUM),stof(ISET));
	      if (ret != cvSuccess)
		{
		  printf("\nBad current or bad channel\n");
		  success = false;
		}

	      if (stoi(PW)) enable_channel.push_back((uint32_t)stoi(CHNUM)+10);

	      ret = set_trip_time_v6534pb((uint32_t)stoi(CHNUM),(uint32_t)stoi(TRIP_TIME));
	      if (ret != cvSuccess)
		{
		  printf("\nBad trip time or bad channel\n");
		  success = false;
		}

	      ret = set_svmax_v6534pb((uint32_t)stoi(CHNUM),(uint32_t)stoi(SVMAX));
	      if (ret != cvSuccess)
		{
		  printf("\nBad svmax or bad channel\n");
		  success = false;
		}

	      ret = set_ramp_down_v6534pb((uint32_t)stoi(CHNUM),(uint32_t)stoi(RAMP_DOWN));
	      if (ret != cvSuccess)
		{
		  printf("\nBad ramp down or bad channel\n");
		  success = false;
		}

	      ret = set_ramp_up_v6534pb((uint32_t)stoi(CHNUM),(uint32_t)stoi(RAMP_UP));
	      if (ret != cvSuccess)
		{
		  printf("\nBad ramp up or bad channel\n");
		  success = false;
		}

	      if (stoi(PWDOWN))
		{
		  ret = ramp_down_channel_v6534pb((uint32_t)stoi(CHNUM));
		}
	      else 
		{
		  ret = kill_channel_v6534pb((uint32_t)stoi(CHNUM));
		}
	      if (ret != cvSuccess)
		{
		  printf("\nBad power down or bad channel\n");
		  success = false;
		}

	      if (stoi(IMON_RANGE))
		{
		  ret = set_imon_low_v6534pb((uint32_t)stoi(CHNUM));
		}
	      else
		{
		  ret = set_imon_high_v6534pb((uint32_t)stoi(CHNUM));
		}
	      if (ret != cvSuccess)
		{
		  printf("\nBad imon range or bad channel\n");
		  success = false;
		}
	    }
	  else if (BOARD == "P")
	    {
	      ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME 
		 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;
	    
	      ret = set_voltage_v6534pa((uint32_t)stoi(CHNUM),(uint32_t)stoi(VSET));
              if (ret != cvSuccess)
                {
                  printf("\nBad voltage or bad channel\n");
                  success = false;
                }

	      ret = set_current_v6534pa((uint32_t)stoi(CHNUM),stof(ISET));
              if (ret != cvSuccess)
                {
                  printf("\nBad current or bad channel\n");
                  success = false;
                }

	      if (stoi(PW)) enable_channel.push_back((uint32_t)stoi(CHNUM)+20);

              ret = set_trip_time_v6534pa((uint32_t)stoi(CHNUM),(uint32_t)stoi(TRIP_TIME));
              if (ret != cvSuccess)
                {
                  printf("\nBad trip time or bad channel\n");
                  success = false;
		}

              ret = set_svmax_v6534pa((uint32_t)stoi(CHNUM),(uint32_t)stoi(SVMAX));
              if (ret != cvSuccess)
                {
                  printf("\nBad svmax or bad channel\n");
                  success = false;
                }

	      ret = set_ramp_down_v6534pa((uint32_t)stoi(CHNUM),(uint32_t)stoi(RAMP_DOWN));
              if (ret != cvSuccess)
                {
                  printf("\nBad ramp down or bad channel\n");
                  success = false;
		}

	      ret = set_ramp_up_v6534pa((uint32_t)stoi(CHNUM),(uint32_t)stoi(RAMP_UP));
              if (ret != cvSuccess)
		{
                  printf("\nBad ramp up or bad channel\n");
		  success = false;
                }

              if (stoi(PWDOWN))
                {
                  ret = ramp_down_channel_v6534pa((uint32_t)stoi(CHNUM));
                }
              else
                {
                  ret = kill_channel_v6534pa((uint32_t)stoi(CHNUM));
                }
              if (ret != cvSuccess)
                {
                  printf("\nBad power down or bad channel\n");
                  success = false;
                }

	      if (stoi(IMON_RANGE))
                {
                  ret = set_imon_low_v6534pa((uint32_t)stoi(CHNUM));
		}
              else
                {
                  ret = set_imon_high_v6534pa((uint32_t)stoi(CHNUM));
		}
	      if (ret != cvSuccess)
		{
                  printf("\nBad imon range or bad channel\n");
                  success = false;
		}

	    }
	  else
	    {
	      continue;
	    }

	}
    }
  else
    {
      std::cout << "Something is wrong with the config file." << std::endl;
      return 1;
    }

  CAENVME_End(handle);
  if (!success) return 1;
  return 0;
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
	  //printf("\nBad ramp up or bad channel\n");
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_up_v6534pa(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //printf("\nBad ramp up or bad channel\n");
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
	  //printf("\nBad ramp up or bad channel\n");
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_ramp_down_v6534pa(chan,(uint32_t)speed);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //printf("\nBad ramp up or bad channel\n");
          success = false;
        }
    }
  
  CAENVME_End(handle);
  if (!success) return 1;
  return 0;
}

int powerdown()
{
  /*
  Power down all channels
  Not used in context of HV Manual Control
  */
  if (!init()) return 1;
  CVErrorCodes ret;
  bool success = true;
  for (int ch = 0; ch < 6; ch++)
    {
      ret = disable_channel_v6534pb(ch);
      if (ret != cvSuccess)
	{
	  printf("Error %d when ramping down V6534PB!!\n",ret);
	  success = false;
	}
    }
  for (int ch = 0; ch < 6; ch++)
    {
      ret = disable_channel_v6534pa(ch);
      if (ret != cvSuccess)
	{
	  printf("Error %d when ramping down V6534PA!!\n",ret);
	  success = false;
	}
    }
  CAENVME_End(handle);
  if (!success) return 1;
  return 0;
}

int powerup()
{
  /*
  Power down all channels
  Not used in context of HV Manual Control
  */
  
  if (!init()) return 1;

  std::string BOARD,CHNUM,VSET,ISET,
    PW,TRIP_TIME,SVMAX,RAMP_DOWN,
    RAMP_UP,PWDOWN,IMON_RANGE;

  std::string line;
  std::ifstream configfile (config_file.c_str(),std::ifstream::in);

  bool success = true;
  CVErrorCodes ret;
  if (configfile.is_open())
    {
      while (getline(configfile,line))
	{
	  std::stringstream ss(line);
          ss >> BOARD;
          if (BOARD == "N") //N and P are leftovers from before adapting the code
          //Whereas this should really be changed, it might not matter since we don't plan on utilising the config file
            {
              ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME
                 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;

	      if (stoi(PW)) 
		{
		  ret = enable_channel_v6534pb((uint32_t)stoi(CHNUM));
		  if (ret != cvSuccess)
		    {
		      printf("Error enabling V6534PB channel %i\n",stoi(CHNUM));
		      success = false;
		    }
		}
	    }
	  else if (BOARD == "P")
	    {
	      ss >> CHNUM >> VSET >> ISET >> PW >> TRIP_TIME
                 >> SVMAX >> RAMP_DOWN >> RAMP_UP >> PWDOWN >> IMON_RANGE;

              if (stoi(PW))
		{
                  ret = enable_channel_v6534pa((uint32_t)stoi(CHNUM));
                  if (ret != cvSuccess)
                    {
                      printf("Error enabling V6534PA channel %i\n",stoi(CHNUM));
                      success = false;
                    }
		}

	    }
	  else
	    {
	      continue;
	    }
	}
    }
  else
    {
      std::cout << "config_file not set" << std::endl;
      return 1;
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
            //std::cout << "Error enabling channel " << chnum << std::endl;
            success = false; 
          }
      }
    else
      {
        ret = enable_channel_v6534pb(chnum-6);
        if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //std::cout << "Error enabling channel " << chnum << std::endl;
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
    else
      {
        ret = disable_channel_v6534pb(chnum-6);
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            //std::cout << "Error disabling channel " << chnum << std::endl;
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
            //std::cout << "Error setting voltage for channel " << chnum << std::endl;
            success = false;
          }
      }
    else
      {
        ret = set_voltage_v6534pb(chnum - 6, VSet); 
        if (ret != cvSuccess)
          {
            std::cout << "Err: " << ret << std::endl;
            //std::cout << "Error setting voltage for channel " << chnum << std::endl;
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
          //std::cout << "Error setting current on channel " << chnum << std::endl;
          success = false;
        }
    }
  else
    {
      ret = set_current_v6534pb(chnum - 6, ISet);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //std::cout << "Error setting current on channel " << chnum << std::endl;
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
	  //std::cout << "Failed to set Sw VMax on board B, ch " << chan << std::endl;
	  std::cout << "Err: " << ret << std::endl;
	  success = false;
	}
    }
  for (uint32_t chan = 0; chan < 6; chan++)
    {
      ret = set_svmax_v6534pb(chan,SwVMax);
      if (ret != cvSuccess)
        {
          //std::cout << "Failed to set Sw VMax on board B, ch " << chan << std::endl;
	  std::cout << "Err: " << ret << std::endl;
          success = false;
        }
    }
  if (!success) return 1;
  return 0;
}

int killall()
{
  /*
  Kills all channels immediately. Should only be used in an emergency.
  */
  bool success = true;
  CVErrorCodes ret;
  std::cout << "Killing all channels" << std::endl;

  for (int i = 0; i < 6; i++)
    {
      ret = kill_channel_v6534pa((uint32_t)i);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //std::cout << "Failed to kill channel " << i << " On Board A" << std::endl;
          success = false;
        }
        
    }
  for (int i = 0; i < 6; i++)
    {
      ret = kill_channel_v6534pb((uint32_t)i);
      if (ret != cvSuccess)
        {
          std::cout << "Err: " << ret << std::endl;
          //std::cout << "Failed to kill channel " << i << "On Board B" << std::endl;
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
  if (argc >= 2 && !strcmp(argv[i], "--setconfig"))
    {
      if (i+1 == argc)
        {
          printf("Feed me a config file!\n");
          status = 1;
        }
      else
        {
          config_file = (std::string)argv[i+1];
          std::ifstream src(config_file,std::ios::binary);
          std::ofstream dst("current.conf",std::ios::binary);
          dst << src.rdbuf();
	}
      status = setconfig();
    }
    
    
  else if (argc >= 2 && !strcmp(argv[i], "--VSet"))
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
  else if (argc >= 2 && !strcmp(argv[i], "--Onstate"))
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
  else if (argc >= 2 && !strcmp(argv[i], "--killall"))
    {
      status = killall();
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


  
  
  else if (argc >= 2 && !strcmp(argv[i], "--powerdown"))
    {
      status = powerdown();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--powerup"))
    {
      if (i+1 == argc)
        {
          config_file = "current.conf";
        }
      else
        {
          config_file = (std::string)argv[i+1];
        }
      status = setconfig();
      if (!status) status = powerup();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--getconfig"))
    {
      if (i+1 == argc)
        {
          config_file = "current.conf";
        }
      else
        {
          config_file = (std::string)argv[i+1];
        }
      status = setconfig();
      if (!status) status = getconfig(); 
    }
  else if (argc >= 2 && !strcmp(argv[i], "--voltmon"))
    {
      //Used in labview program.
      //Returns voltages, currents of channels only. Does not return status.
      status = voltmonitor();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--statmon"))
    {
      //Returns ONLY the status of all channels. Does not return voltage readouts.
      status = statusmonitor();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--fullmon"))
    {
      //Reads all parameters from the VME crate. Combines voltmon and statmon.
      status = fullmonitor();
    }
  else if (argc >= 2 && !strcmp(argv[i], "--kill"))
    {
      status = killall();
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
      printf("    --Onstate     Turns individual Channels on or off.\n");
      printf("                  Usages: --Onstate ch \"On\"/\"Off\" (no quotes)\n");
      printf("      Note:       channels 6-11 are interpreted as channels 0-5 on the\n");
      printf("                  Second HV card at Base Address 32120000\n");
      printf("    --SetSWVMax   Sets the software limit of the voltage based on input.\n");
      printf("    --setconfig   Requires parameter pointing to the location of the\n");
      printf("                  configuration file.\n");
      printf("    --powerdown   Ramp down voltages and turn channels off.\n");
      printf("    --powerup     Turn channels on and ramp up voltages.\n");
      printf("    --getconfig   Read the pre-set parameters from VME.\n");
      printf("    --voltmon     Read the instantaneous currents/Voltages from VME\n");
      printf("    --statemon    Reads the status of all channels. Used in LabVIEW\n");
      printf("    --fullmon     Reads all instantaneous Parameters (status + voltages) from VME\n");
      printf("                  (e.g. voltage, current, etc.).\n");
      printf("    --killall     Kill all channels immediately.\n");
      printf("    --rampup      Set ramp up speed (in V/s).\n");
      printf("    --rampdown    Set ramp down speed (in V/s).\n");
      status = 1;
    }   
  return status;
}

