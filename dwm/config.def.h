/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;       /* border pixel of windows */
static const unsigned int snap      = 32;      /* snap pixel */
static const int showbar            = 1;       /* 0 means no bar */
static const int topbar             = 1;       /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=12",
                                        "Noto Color Emoji:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrains Mono:size=12";

/* Dracula color palette */
static const char col_bg[]           = "#282a36";  /* Background with ~80% opacity */
static const char col_fg[]           = "#f8f8f2";    /* Foreground (text) */
static const char col_gray[]         = "#44475a";    /* Inactive window border */
static const char col_purple[]       = "#bd93f9";    /* Selected tag bg */
static const char col_border_focus[] = "#ff79c6";    /* Focused window border (pink) */

static const char *colors[][3] = {
    /*               fg         bg          border   */
    [SchemeNorm] = { col_fg,    col_bg,     col_gray },
    [SchemeSel]  = { col_bg,    col_purple, col_border_focus },
};

/* Volume control commands */
static const char *audioMute[]      = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *audioLowerVolume[]= { "pactl", "set-sink-volume", "0", "-5%", NULL };
static const char *audioRaiseVolume[]= { "pactl", "set-sink-volume", "0", "+5%", NULL };
static const char *audioMicMute[]   = { "pactl", "set-source-mute", "0", "toggle", NULL };

/* Brightness control commands */
static const char *monBrightnessDown[]= { "brightnessctl", "set", "10%-", NULL };
static const char *monBrightnessUp[]= { "brightnessctl", "set", "+10%", NULL };

/* Player control commands */
static const char *audioPlay[]      = { "playerctl", "play-pause", NULL };
static const char *audioStop[]      = { "playerctl", "stop", NULL };
static const char *audioPrev[]      = { "playerctl", "previous", NULL };
static const char *audioNext[]      = { "playerctl", "next", NULL };

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

/* Rules for floating windows, etc. */
static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
    { "Firefox",  NULL,       NULL,       1 << 4,       0,           -1 },  // tag 5
};

/* layout(s) */
static const float mfact     = 0.55;  /* master area size [0.05..0.95] */
static const int nmaster     = 1;     /* number of clients in master area */
static const int resizehints = 1;     /* respect size hints in tiled resizals */
static const int lockfullscreen = 1;  /* force focus on fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* default */
    { "><>",      NULL },    /* floating */
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* includes */
#include <X11/XF86keysym.h>

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd */
static const char *dmenucmd[] = {
    "dmenu_run", "-m", dmenumon,
    "-fn", dmenufont,
    "-nb", col_bg,
    "-nf", col_fg,
    "-sb", col_purple,
    "-sf", col_bg,
    NULL
};
static const char *termcmd[]  = { "alacritty", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", NULL };

/* key bindings */
static const Key keys[] = {
    /* modifier                     key           function        argument */
    // FUNCTION KEYS
    { 0,                            XF86XK_AudioMute,           spawn,  {.v = audioMute} },
    { 0,                            XF86XK_AudioLowerVolume,    spawn,  {.v = audioLowerVolume} },
    { 0,                            XF86XK_AudioRaiseVolume,    spawn,  {.v = audioRaiseVolume} },
    { 0,                            XF86XK_AudioMicMute,        spawn,  {.v = audioMicMute} },
    { 0,                            XF86XK_MonBrightnessDown,   spawn,  {.v = monBrightnessDown} },
    { 0,                            XF86XK_MonBrightnessUp,     spawn,  {.v = monBrightnessUp} },

    // MEDIA KEYS
    { 0,                            XF86XK_AudioPlay,           spawn,  {.v = audioPlay} },
    { 0,                            XF86XK_AudioStop,           spawn,  {.v = audioStop} },
    { 0,                            XF86XK_AudioPrev,           spawn,  {.v = audioPrev} },
    { 0,                            XF86XK_AudioNext,           spawn,  {.v = audioNext} },

    // LAUNCHERS
    { MODKEY,                       XK_a,      spawn,          {.v = roficmd } },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },

    // WINDOW MANAGEMENT
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },

    // LAYOUTS
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },

    // MULTI-MONITOR
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    // TAG KEYS (only 5 tags)
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)

    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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

