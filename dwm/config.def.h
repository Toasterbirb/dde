/* See LICENSE file for copyright and license details. */

/* config file */
static const char* configPath 		= "/home/USER/.config/dde/dwm.conf";

/* appearance */
static int borderpx  = 3;        /* border pixel of windows */
static int snap      = 8;       /* snap pixel */
static int gappih    = 10;       /* horiz inner gap between windows */
static int gappiv    = 10;       /* vert inner gap between windows */
static int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int smartgaps = 0;        /* 1 means no outer gap when there is only one window */
static int barheight = 0; 		/* 0 means automatic */
static int barbottom = 4; 		/* size of the small rect below the bar to create a 3D effect */
static int bartextheightoffset = 0; 		/* vertical offset for the dwm bar text */
static int showbar         	= 1;        /* 0 means no bar */
static int topbar          	= 1;        /* 0 means bottom bar */
static int tagWidthExtra 	= 4; 		/* Add extra width to tags. 0 means default width (16). */
static int user_bh       	= 28;       /* dwmbar height */
static int enable3dbar 		= 1;

/* fonts */
static const char *fonts[]          = { "mononoki:size=13" };
static const char dmenufont[]       = 	"mononoki:size=15";

/* colors */
static char normbgcolor[]           = "#3b4252";
static char normbordercolor[]       = "#2A2139";
static char selbordercolor[]        = "#EDC0FF";
static char normfgcolor[]           = "#d8dee9";
static char selfgcolor[]            = "#2e3440";
static char selbgcolor[]            = "#b48ead"; 	/* Top bar background when there's a window open */
static char col_red[] 				= "#BF616A";
static char col_blue[] 				= "#5E81AC";
static char col_cyan[] 				= "#B48EAD";
static char col_dark[]  			= "#3B4252";
static char normfgshadowcolor[] 	= "#363B48";
static char selfgshadowcolor[]  	= "#91738C";

static char *colors[][3] = {
       	/*               	fg           		bg           	border   */
       	[SchemeNorm] 		= { normfgcolor, 	normbgcolor, 	normbordercolor },
       	[SchemeSel]  		= { selfgcolor,  	selbgcolor,  	selbordercolor  },
		[SchemeStatus]  	= { normfgcolor, 	col_dark, 	 	"#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
		[SchemeTagsSel]  	= { selfgcolor,		selbgcolor, 	"#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
		[SchemeTagsNorm]  	= { normfgcolor,	col_dark,  		"#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
		[SchemeInfoSel]  	= { selfgcolor,		selbgcolor,  	"#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
		[SchemeInfoNorm]  	= { normfgcolor,	col_dark,  		"#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
		[SchemeNormShadow] 	= { normfgshadowcolor, "#000000", 	"#000000" },  // Shadow of the selected tag
		[SchemeSelShadow] 	= { selfgshadowcolor, "#000000", 	"#000000" },  // Shadow of the selected tag

};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       										tags mask     isfloating   monitor */
	//{ "Gimp",     	NULL,       NULL,       										0,            0,           -1 },
	{ "Tor Browser",  	NULL,       NULL,       										0,       	  1,           -1 },
	{ NULL,       		NULL,       "Steam Guard - Computer Authorization Required",  	0, 			  1, 		   -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",   		tile },    /* first entry is default */
	{ "[M]",   		monocle },
	{ "[@]", 		spiral },
	//{ "[\\]",		dwindle },
	//{ "H[]", 		deck },
	{ "TTT",   		bstack },
	//{ "===", 		bstackhoriz },
	//{ "HHH",  		grid },
	//{ "###", 		nrowgrid },
	{ "---",   		horizgrid },
	//{ ":::",     	gaplessgrid },
	{ "|M|",      	centeredmaster },
	//{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-hp", "firefox;surf", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY, 			            XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             			XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_v,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	/* Gaps */
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +4 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -4 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },

	/* Layouts */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ControlMask,       	XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY, 			            XK_f,      togglefullscr,  {0} },

	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = -1 } },

	//{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } }, /* Reload Xresources */
	{ MODKEY,                       XK_F5,     readconfig,           {0} }, /* Reload the config file */

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

