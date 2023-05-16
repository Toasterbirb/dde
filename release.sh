#!/bin/sh
version=1.0.0

# Create temprary directory for the release
mkdir -p ./dde
cp -rv ./dwm ./dwmblocks ./dmenu ./slock ./st ./dde/

# Remove binaries
rm -vf ./dde/dmenu/{dmenu,stest}
rm -vf ./dde/dwm
rm -vf ./dde/dwmblocks/dwmblocks
rm -vf ./dde/slock/slock
rm -vf ./dde/st/st

# Remove config files
rm -vf ./dde/dwm/config.h
rm -vf ./dde/dwmblocks/blocks.h
rm -vf ./dde/dmenu/config.h
rm -vf ./dde/slock/config.h
rm -vf ./dde/st/config.h

# Pack it up
tar -czvf dde-${version}.tar.gz ./dde
rm -rf ./dde
