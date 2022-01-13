#!/bin/bash

(sleep 3s && echo "s" && sleep 3s && echo "W" && sleep 10s && echo "s" && sleep 3s && echo "q") | wavedump WaveDumpConfig_Gain.txt
