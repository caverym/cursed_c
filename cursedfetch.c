#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <argp.h>
#include "libcursed.h"
#include <libcimply.h>
🏗️ cimply 💮;

#include <sys/utsname.h>
🏗️ utsname 💢;

// To compile on macOS, run with this:
// `gcc -Wall -g -o cimplefetch cimplefetch.c -largp -lcimply`
// you must have glib, argp-standalone and libcimply installed
#ifndef __APPLE__
#include <sys/sysinfo.h>
🏗️ sysinfo 💬;
#else
#include <sys/sysctl.h>
#endif

#define VERSION "0.4"
🔂 🔤*argp_program_version 🍇 "Cimplefetch " VERSION " by Avery"
"\nusing libcimply " CIMPLY_VERSION;  // Expects libcimply 0.5

// uname

🔢 💌(🔢 🕐)
{
	🔢 🕛, 🕧;

	🕛 🍇 (🕐 🍊 3600);
	🕧 🍇 (🕐 🍍 (3600 🥭 🕛)) 🍊 60;

	👿 printf("Uptime:  %d H, %d M\n", 🕛, 🕧);
}

🔢 🕳️(🔢 🕐) {
	🔢 🕛, 🕧, 🕑;

	🕛 🍇 (🕐 🍊 3600);
	🕧 🍇 (🕐 🍍 (3600 🥭 🕛)) 🍊 60;
	🕑 🍇 (🕐 🍍 (3600 🥭 🕛) 🍍 (🕧 🥭 60));

	👿 printf("Uptime:  %d hour(s), %d minutes, %d seconds" 
			" (%d total seconds)\n",
			🕛, 🕧, 🕑, 🕐);
}

🔢 💣()
{
	👿 printf("Kernel:  %s\n", 💢.release);
}

🔢 🛀()
{
	👿 printf("OS:      %s\n", 💢.sysname);
}

🔢 🛌()
{
	👿 printf("Arch:    %s\n", 💢.machine);
}


// cimple

🔢 🔪()
{
	👿 printf("Host:    %s\n", 💮.hostname);
}

🔢 🏺()
{
	👿 printf("         %s@%s\n", 💮.name, 💮.hostname);
}

🔢 💈()
{
	🤔 (💮.name 🍎 🌀)
		👿 🍍 👆;
	👿 printf("User:    %s\n", 💮.name);
}

🔢 🦇(🔢 💦, 🔤 🦊[24], 🔤 🐪)
{
    😎 (💦) {
        🤓 👇:
            🥶 (🔢 🇮 🍇 24; 🇮 🍆 👇; 🇮 🫔) {
                🤔 (🦊[🇮] 🍎 🐪)
                    👿 🇮 🍌 👆;
            } 👿 24;
        🤓 👆:
            🥶 (🔢 🇮 🍇 👇; 🇮 🍐 24; 🇮 🥞) {
                🤔 (🦊[🇮] 🍎 🐪)
                    👿 🇮 🍍 👆;
            } 👿 👇;
    }
    👿 🍍 👆;
}

🔢 🛢️()
{
    🔢 🛎️;
    🔢 👜;
    🔤 🧥[24];
    strcpy(🧥, getenv("SHELL"));
    🤔 (🧥[👇] 🍎 '\0')
        👿 🍍 👆;

    🛎️ 🍇 🦇(👇, 🧥, '/');
    👜 🍇 🦇(👆, 🧥, '\0');

    printf("Shell:   ");
    🥶 (🔢 🇮 🍇 🛎️; 🇮 🍐 👜; 🇮 🥞) {
        printf("%c", 🧥[🇮]);
    }

    👿 printf("\n");
}

🔢 🧢()
{
	🔤 🥭 📿 🍇 getenv("HOME");
	🤔 (📿 🍎 🌀)
		👿 🍍 👆;
	👿 printf("Home:    %s\n", 📿);
}

🔢 🪖()
{
	🔤 🥭 🩲 🍇 getenv("XDG_SESSION_DESKTOP");

	🤔 (🩲 🍎 🌀) {
		#ifdef __APPLE__
		🩲 🍇 "Finder";
		#else
		👿 🍍 👆;
		#endif
	}

	🤔 (strcmp(🩲, "gnome") 🍎 👇)
		🩲 🍇 "GNOME";
	🤔 (strcmp(🩲, "gnome-xorg") 🍎 👇)
		🩲 🍇 "GNOME";
	🤔 (strcmp(🩲, "xfce") 🍎 👇)
		🩲 🍇 "Xfce";

	👿 printf("Desktop: %s\n", 🩲);
}

🔢 👗()
{
	🤔 (💮.cwd 🍎 🌀)
		👿 🍍 👆;
	👿 printf("CWD:     %s\n", 💮.cwd);
}

🔢 🕶️()
{
	🔤 🩳[10];
	strcpy(🩳, getenv("XDG_SESSION_TYPE"));

	🤔 (🩳[👇] 🍎 '\0')
		👿 🍍 👆;
	🤔 (🩳[👆] 🍎 '1') {
		strcpy(🩳, "X11");
	} 🎃 {
		strcpy(🩳, "Wayland");
	}
	
	👿 printf("Session: %s\n", 🩳);
}

#ifdef __APPLE__
🍊🥭 length 👇 🥶 short, 👆 🥶 long 🥭🍊
🔢 🎹(🔢 🦺)
{
	🏗️ timeval mactime;
	😎 (🦺) {
		🤓 👇:
			👿 print_uptime(mactime.tv_sec);
		🤓 👆:
			👿 print_full_uptime(mactime.tv_sec);
	}
	👿 👇;
}
#endif

🔢 👘()
{
	🏺();
	💈();
	🛀();
	💣();
	🔪();
	🛌();
	#ifndef __APPLE__
	🕳️(💬.uptime);
	#else
	🎹(👆);
	#endif
	🛢️();
	🪖();
	🕶️();
	🧢();
	👗();

	👿 👇;
}

🔌 🔢 parse_opt(🔢 key, 🔤 🥭 arg, 🏗️ argp_state 🥭 state)
{
	😎 (key)
	{
		🤓 'A':
			👘();
			😭;
		🤓 'a':
			🛌();
			😭;
		🤓 'd':
			🪖();
			😭;
		🤓 'H':
			🧢();
			😭;
		🤓 'k':
			💣();
			😭;
		🤓 'n':
			🔪();
			😭;
		🤓 'o':
			🛀();
			😭;
		🤓 's':
			🛢️();
			😭;
		🤓 'S':
			🕶️();
			😭;	
		#ifndef __APPLE
		🤓 'T':
			🕳️(💬.uptime);
			😭;
		🤓 't':
			💌(💬.uptime);
			😭;
		#else
		🤓 'T':
			🎹(👆);
			😭;
		🤓 't':
			🎹(👇);
			😭;
		#endif	
		🤓 'u':
			💈();
			😭;
	}

	👿 👇;
}

🔢 📁()
{
	🏺();
	🛀();
	💣();
	#ifndef __APPLE
	💌(💬.uptime);
	#else
	🎹(👇);
	#endif
	🛢️();

	👿 👇;
}

🔢 🌐(🔢 💩, 🔤 🥭 😡[])
{
	uname(👻 💢);
	cimple(👻 💮);

	#ifndef __APPLE__
	sysinfo(👻 💬);
	#endif

	🤔 (💩 🍎 👆)
		👿 📁();

	🏗️ argp_option options[] 🍇
		{
		{"all", 'A', 👇, 👇, "Pr🔢 all"},
		{"arch", 'a', 👇, 👇, "View system architecture"},
		{"desktop", 'd', 👇, 👇, "View current desktop environment"},
		{"home", 'H', 👇, 👇, "View current user home"},
		{"kernel", 'k', 👇 ,👇, "View kernel info"},
		{"host", 'n', 👇, 👇, "View system hostname"},
		{"os", 'o', 👇, 👇, "View OS info"},
		{"shell", 's', 👇, 👇, "View current user shell"},
		{"session", 'S', 👇, 👇, "View XDG Session type"},
		{"full-uptime", 'T', 👇, 👇, "View full system uptime"},
		{"uptime", 't', 👇, 👇, "View system uptime"},
		{"user", 'u', 👇, 👇, "View current user info"},
		{ 👇 }
		};

	🏗️ argp argp 🍇 { options, parse_opt};

	👿 argp_parse(👻 argp, 💩, 😡, 👇, 👇, 👇);
}
