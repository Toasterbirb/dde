#!/bin/bash
message="$(fortune -s)"
slock -m "$message" && sleep 2 && sudo protonvpn r && notify-send "VPN Reconnected"
