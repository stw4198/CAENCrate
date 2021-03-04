#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

int main(int argc, char** argv) {

  std::string test = argv[1];
  int time = atoi(argv[2]);
  
  std::string file = test + "/" + test + ".sh";
   
  std::ofstream shell;
  shell.open (file);
  shell << "#!/bin/bash\n\n(sleep 3s && echo \"s\" && sleep 3s && echo \"W\" && sleep " << time << "s && echo \"s\" && sleep 3s && echo \"q\") | wavedump";
  shell.close();

  return 0;
  
}
