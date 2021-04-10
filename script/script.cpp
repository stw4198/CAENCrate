#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

int main(int argc, char** argv) {

  std::string test = argv[1];
  int time = atoi(argv[2]);
  
  std::string file = test + "/" + test + ".sh";
  
  if(test == "DarkRateTest"){
  
  std::string config = "WaveDumpConfig_DarkRate.txt";
  
  std::ofstream shell;
  shell.open (file);
  shell << "#!/bin/bash\n\n(sleep 3s && echo \"s\" && sleep 3s && echo \"W\" && sleep " << time << "s && echo \"s\" && sleep 3s && echo \"q\") | wavedump " << config;
  shell.close();

  printf("\nBash script written\n");

  return 0;
  
  }
  
  else{
  
  std::cout << "\nNo test folder defined for " << test << "\n";
  
  return 1;
  
  }
  
}
