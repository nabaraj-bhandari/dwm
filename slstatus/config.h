const unsigned int interval = 1000;				/* INTERVAL BETWEEN UPDATES */
static const char unknown_str[] = "n/a";		/* TEXT TO SHOW IF NO VALUE IS RETRIEVED */
#define MAXLEN 2048								/* MAXIMUM OUTPUT STRING LENGTH */

static const struct arg args[] = {
	/* function format          		argument */
	/* { ipv4, "|%s",						"wlp2s0" }, */
	{ wifi_essid, "|🛜:%s",				"wlp2s0" },
	{ wifi_perc, "(%s%%)",				"wlp2s0" },
	{ ram_used, "|🔳:%s",				"NULL" },
	{ cpu_perc, "::%s%%",				"NULL" },
	{ disk_free, "|🗄:%s", 				"/"},
	{ datetime, "|📅:%s",				"%F" },
	/* { vol_perc, "|🔊%s%%",				"/dev/mixer" }, */
	/* { vol_perc, "::%s%%",				"/dev/mixer1" }, */
	{ battery_perc, "|🔋:%s%%",			"BAT1" },
  	{ datetime, "|⏰:%s", 				"%T" },
};
