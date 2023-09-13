# dde

**NOTICE**
This project is defunct! Bundling suckless tools into a singular repository didn't really work out in the end. It just doesn't make sense and only makes things more difficult.


dde (dynamic desktop environment) is a collection of different programs creating a simple desktop environment. How is this different from Gnome or KDE etc. you might ask. Not too much and a lot at the same time. When someone chooses to go with a window manager only setup instead of a readymade desktop environment, they are basically building their own desktop environment by combining different programs.

## Features and programs
The list is still short, but it doesn't necessarily need to be even that long to have a working system. Things are going to be added as needed.

| Feature           | Program   |
|-------------------|-----------|
| Window management | dwm       |
| Statusbar         | dwmblocks |
| Launcher          | dmenu     |
| Lockscreen        | slock     |

## Configuration
Most of the configuration is done via modifying the source code and recompiling. There is on-going effort to add reloadable configuration files though.

Currently dwm is the only program with such config file. It resides in $HOME/.config/dde/dwm.conf. An example configuration file can be found [here](https://github.com/Toasterbirb/dwm/blob/master/dwm.conf)
