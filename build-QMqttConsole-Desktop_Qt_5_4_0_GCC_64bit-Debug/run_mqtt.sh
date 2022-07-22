#!/bin/sh

script_dir=$(cd $(dirname $0); pwd)

cd $script_dir

#if [ ! -x /root/.config/OpenPilot ];then
#   mkdir  /root/.config/OpenPilot
#fi

#export LD_LIBRARY_PATH=/usr/local/scwp_gcs/lib/openpilotgcs:$LD_LIBRARY_PATH
#export gcs_tomcat=/usr/wwwroot

#cp ./SwcpGcs_config.xml /root/.config/OpenPilot/

./QMqttConsole
