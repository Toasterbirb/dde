#!/bin/bash

# This script is meant for fast and simple testing during development

Help()
{
   # Display Help
   echo "Runs dwm in Xephyr."
   echo
   echo "Syntax: $(basename $0) [-h|d]"
   echo "options:"
   echo "h     Print this help."
   echo "d     Change display for test server."
   echo
   echo "example: $(basename $0) -d :2"
   echo
}

# Default display
XEPHYR_DISPLAY=":1"

while getopts ':hd:' OPTION; do
  case "$OPTION" in
    d)
      XEPHYR_DISPLAY="$OPTARG"
      echo "\$XEPHYR_DISPLAY configured to $OPTARG"
      ;;
    h)
      Help
      exit;;
    ?)
      Help
      exit 1;;
  esac
done
shift "$(($OPTIND -1))"

function _relaunch()
{
	[ -f $oldPID ] && pkill -9 -F ./testpid
	./dwm &
	echo "$!" > ./testpid
}


pgrep Xephyr || Xephyr -br -ac -noreset -screen 1280x720 $XEPHYR_DISPLAY &>/dev/null &

export DISPLAY=$XEPHYR_DISPLAY

make clean
rm config.h
make && _relaunch
