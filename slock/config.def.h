/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#1f2948",   /* during input */
	[FAILED] = "#902727",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* enable message */
static const int messageEnabled = 0; /* 0 = disabled, 1 = enabled */

/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "-*-comfortaa-*-*-*-*-*-300-*-*-*-*-*-*";
