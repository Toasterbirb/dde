#pragma once
#include <iostream>
#include <X11/cursorfont.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xproto.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xinerama.h>
#include <X11/Xft/Xft.h>

#include "windows.hpp"

class program
{
	public:
		std::string getversion();
		void checkotherwm();

		bool opendisplay();
		void closedisplay();

		void setup();
		void scan();
		void run();
		void cleanup();

	private:
		std::string version = "dwm++ 1.0";
		
		//Atom wmatom[WMLast], netatom[NetLast];
		int running = 1;
		//Cur *cursor[CurLast];
		//Clr **scheme;
		Display *dpy;
		//Drw *drw;
		Monitor *mons, *selmon;
		Window root, wmcheckwin;
		int screen;
		int sw, sh; 	/* screen width and screen height */
		int bh, blw; 	/* bar geometry */
		int lrpad; 		/* sum of left and right padding for text */

		/* X Error codes */
		static int xerrorxlib(Display *, XErrorEvent *);
		static int xerror(Display *dpy, XErrorEvent *ee);
		static int xerrordummy(Display *dpy, XErrorEvent *ee);
		static int xerrorstart(Display *dpy, XErrorEvent *ee);
};
