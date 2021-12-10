#pragma once
#include <string>
#include <X11/Xlib.h>


/* Definitions */
struct Layout;
struct Rule;
struct Monitor;
struct Client;

struct Layout
{
	const char *symbol;
	void (*arrange)(Monitor *);
};

struct Rule
{
	const char *classifier;
	const char *instance;
	const char *title;
	unsigned int tags;
	bool isfloating;
	int monitor;
};

struct Client
{
	std::string name;
	float mina, maxa;
	int x, y, w, h;
	int oldx, oldy, oldw, oldh;
	int basew, baseh, incw, maxw, maxh, minw, minh;
	int bw, oldbw;
	unsigned int tags;
	int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;

	/* Boolean for checking if the window is a steam client */
	bool issteam;

	Client *next;
	Client *snext;
	Monitor *mon;
	Window win;
};

struct Monitor
{
	char ltsymbol[16];
	float mfact;
	int nmaster;
	int num;
	int by; 			 	/* bar geometry */
	int mx, my, mw, mh; 	/* screen size */
	int wx, wy, ww, wh; 	/* window area */

	/* gaps */
	int gappih; 	/* horizontal gap between windows */
	int gappiv; 	/* vertical gap between windows */
	int gappoh; 	/* horizontal outer gaps */
	int gappov; 	/* vertical outer gaps */

	unsigned int seltags;
	unsigned int sellt;
	unsigned int tagset[2];
	int showbar;
	int topbar;
	Client *clients;
	Client *sel;
	Client *stack;
	Monitor *next;
	Window barwin;
	const Layout *lt[2];
};
