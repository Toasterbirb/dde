//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/	/*Update Interval*/	/*Update Signal*/
	{" Mem: ", 	"free -h --si | awk '/^Mem/ { print $3\"/\"$2 }'",	30,	0},
	{"",	"date '+%b %d (%a) %H:%M%p '",	5,	0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
