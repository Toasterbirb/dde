#include "../include/program.hpp"

std::string program::getversion()
{
	return version;
}

void program::checkotherwm()
{
	//xerrorxlib = XSetErrorHandler(program::xerrorstart);
	std::cout << "Note! WM Check doesn't work!\n";
	XSelectInput(dpy, DefaultRootWindow(dpy), SubstructureRedirectMask);
	XSync(dpy, False);
	XSetErrorHandler(program::xerror);
	XSync(dpy, False);
}

bool program::opendisplay()
{
	return (dpy = XOpenDisplay(NULL));
}

void program::closedisplay()
{
	if (!XCloseDisplay(dpy))
		std::cout << "Display closed successfully!\n";
	else
		std::cout << "Something went wrong while closing the window!\n";
}

void program::setup()
{
	std::cout << "Starting setup\n";

	XSetWindowAttributes windowAttributes;
	Atom utf8string;

	/* clean up zombies */
	//sigchld(0);
	
	/* init screen */
	screen = DefaultScreen(dpy);
	sw = DisplayWidth(dpy, screen);
	sh = DisplayHeight(dpy, screen);
	root = RootWindow(dpy, screen);
	
	std::cout << " > Screen width: " << sw << std::endl;
	std::cout << " > Screen height: " << sh << std::endl;

	//drw = drw_create(dpy, screen, root, sw, sh);	
}

void program::scan()
{
	std::cout << "Starting scan\n";
}

void program::run()
{
	std::cout << "Running dwm++\n";
}

void program::cleanup()
{
	std::cout << "Cleaning up...\n";
}

int program::xerrorxlib(Display*, XErrorEvent*)
{
	return 0;
}

int program::xerror(Display *dpy, XErrorEvent *ee)
{
	if (ee->error_code == BadWindow
	|| (ee->request_code == X_SetInputFocus && ee->error_code == BadMatch)
	|| (ee->request_code == X_PolyText8 && ee->error_code == BadDrawable)
	|| (ee->request_code == X_PolyFillRectangle && ee->error_code == BadDrawable)
	|| (ee->request_code == X_PolySegment && ee->error_code == BadDrawable)
	|| (ee->request_code == X_ConfigureWindow && ee->error_code == BadMatch)
	|| (ee->request_code == X_GrabButton && ee->error_code == BadAccess)
	|| (ee->request_code == X_GrabKey && ee->error_code == BadAccess)
	|| (ee->request_code == X_CopyArea && ee->error_code == BadDrawable))
		return 0;
	fprintf(stderr, "dwm: fatal error: request code=%d, error code=%d\n",
		ee->request_code, ee->error_code);
	return xerrorxlib(dpy, ee); /* may call exit */
}

int program::xerrordummy(Display *dpy, XErrorEvent *ee)
{
	return 0;
}

int program::xerrorstart(Display *dpy, XErrorEvent *ee)
{
	std::cout << "dwm++: another window manager is already running\n";
	return -1;
}
