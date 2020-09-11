/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"SpaceMonoNerdFont:size=13" };
static const char dmenufont[]       = "Mensch:size=13";
static const char black_1[]         = "#000000";
static const char col_gray2[]       = "#8FA494";
static const char green_1[]         = "#00ff55";
static const char white_2[]         = "#eeeeee";
static const char col_gray5[]       = "#616462";
static const char col_cyan[]        = "#698D75";
static const char green_2[] 	    = "#419B5F";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white_2, black_1,   col_gray5 },
	[SchemeSel]  = { green_1,   black_1, green_2  },
};

/* tagging */
static const char *tags[] = { "MAIN", "DEVEL", "MISC", "PENTEST", "WEB", "ALL" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class              instance   title   tags-mask   isfloating   monitor */
   { "Gimp",             NULL,     NULL,     1<<3,      1,            -1 },
   { "Spacefm",          NULL,     NULL,     1<<2,      1,            -1 },
   { "st",               NULL,     NULL,     0,         1,            -1 },
   { NULL,               "urxvt",  NULL,     0,         1,            -1 },
  /* { NULL,               "xterm",  NULL,     1<<1,      1,	      -1 },*/
   { "Nitrogen",         NULL,     NULL,     1<<2,      1,	      -1 },
   { "Lxappearance",     NULL,     NULL,     1<<5,      1,	      -1 },
{ "qibittorrent",        NULL,     NULL,     1<<5,	1,	      -1 },
   { "Chromium",  	 NULL,     NULL,     1<<4,      0,            -1 },
   { "VirtualBox",	 NULL,	   NULL,     1<<3,	0,	      -1 },
   {"Parole",		 NULL,	   NULL,     1<<4,      1,	      -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",        tile },    /* first entry is default */
	{ "",        NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", black_1, "-nf", white_2, "-sb", black_1, "-sf", green_1, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *brightdown[]       = { "xbacklight", "-dec", "3", NULL };
static const char *brightup[]     = { "xbacklight", "-inc", "6", NULL };
static const char *Urxvt[]        = {"urxvt", NULL };
static const char *urxvt[]        = {"urxvt", "--geometry", "93x15+420+30", NULL};
static const char *xterm[]        = {"xterm", NULL };

static const char *B[] = { "/home/marko/1999/./brightness.sh", NULL};
/*static const char *mutecmd[] = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *volumedown[] = { "pactl", "set-sink-volume", "0", "-5%", NULL };
static const char *volumeup[] = { "pactl", "set-sink-volume", "0", "+5%", NULL };
*/

static const char *volumeup[] = { "amixer", "-q", "sset", "Master", "6%+", NULL };
static const char *volumedown[] = { "amixer", "-q", "sset", "Master", "3%-", NULL };
static const char *mutecmd[] = { "amixer", "-q", "-D", "default", "sset", "Master", "toggle", NULL };


static const char *Vol[]  =  {"/home/marko/1999/./volume.sh", NULL};

/*define XF86XK_AudioLowerVolume	0x1008FF11    Volume control down        */
/*define XF86XK_AudioMute	0x1008FF12    Mute sound from the system */
/*define XF86XK_AudioRaiseVolume	0x1008FF13    Volume control up          */
/*define XF86XK_MonBrightnessUp   0x1008FF02   Monitor/panel brightness */
/*define XF86XK_MonBrightnessDown 0x1008FF03   Monitor/panel brightness */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,  			XK_x,      spawn,          {.v = Urxvt } },
	{ MODKEY|ShiftMask, 	        XK_Return, spawn, 	   {.v = xterm } },
	{ MODKEY,  	 	        XK_c 	 , spawn, 	   {.v = urxvt } },
        { 0,                          0x1008ff03,  spawn,          {.v = brightdown } },
        { 0,                          0x1008ff03,  spawn,          {.v = B } },
        { 0,                          0x1008ff02,  spawn,          {.v = brightup } },
        { 0,                          0x1008ff02,  spawn,          {.v = B } },
	{ 0,                          0x1008FF12,  spawn,          {.v = mutecmd } },
	{ 0,                          0x1008FF12,  spawn,          {.v = Vol } },
        { 0,                          0x1008FF11,  spawn,          {.v = volumedown } },
        { 0,                          0x1008FF11,  spawn,          {.v = Vol } },
        { 0,                          0x1008FF13,  spawn,          {.v = volumeup } },
        { 0,                          0x1008FF13,  spawn,          {.v = Vol } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_z,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_s,      togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
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

