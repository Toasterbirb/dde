#!/bin/sh
version=1.0.1

# Create temprary directory for the release
mkdir -p ./dde
cp -rv ./dwm ./dwmblocks ./dmenu ./slock ./dde/

# Remove config files
rm -vf ./dde/dwm/config.h
rm -vf ./dde/dwmblocks/blocks.h
rm -vf ./dde/dmenu/config.h
rm -vf ./dde/slock/config.h

# Pack it up
tar -czvf dde-${version}.tar.gz ./dde
rm -rf ./dde
