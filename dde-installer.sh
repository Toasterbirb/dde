#!/bin/bash
set -e

_printHelp()
{
	echo "Commands:"
	echo -e "\tbuild\tBuilds the dde desktop environment"
	echo -e "\tclean\tRemove build files"
	echo -e "\tinstall\tInstalls the dde desktop environment. Builds automatically"
}

_compile()
{
	echo "Building $1..."
	cd $1
	make 1>/dev/null && echo -e "\n> $1 built successfully\n" || echo "Something went wrong when compiling $1..."
	cd ..
}

_makeinstall()
{
	echo "Installing $1..."
	cd $1
	make install 1>/dev/null && echo "$1 installed successfully" || echo "Something went wrong when installing $1..."
	cd ..
}

_makeclean()
{
	cd $1
	echo "Cleaning $1..."
	make clean
	cd ..
}

_install()
{
	_makeinstall dwm
	_makeinstall dmenu
	_makeinstall dwmblocks
	_makeinstall slock
	_makeinstall st
}

_build()
{
	_compile dwm
	_compile dmenu
	_compile dwmblocks
	_compile slock
	_compile st
}

_clean()
{
	_makeclean dwm
	_makeclean dmenu
	_makeclean dwmblocks
	_makeclean slock
	_makeclean st
}

for i in $@
do
	case $1 in
		build) _build ;;
		clean) _clean ;;
		install)
			_build
			_install
			;;
		*) _printHelp ;;
	esac
done
