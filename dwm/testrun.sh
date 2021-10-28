#!/bin/sh

# This script is meant for fast and simple testing during development

function _relaunch()
{
	[ -f $oldPID ] && pkill -9 -F ./testpid
	./dwm &
	echo "$!" > ./testpid
}

pgrep Xephyr || Xephyr -br -ac -noreset -screen 1920x1080 :1 &>/dev/null &
export DISPLAY=:1

make clean
rm config.h
make && _relaunch
