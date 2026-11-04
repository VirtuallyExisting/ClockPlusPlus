/*
	Clock++
	By Virtualle/VirtuallyExisting

	A simple clock app for AuroraOS that displays a 12-hour clock instead of a 24-hour clock.
	It additionally shows the date using a very easy to read format.
*/



#include <aurora_app.h>
#include <stdio.h>

int year;
int month;
int day;
int hour;
int minute;
int weekday;

char* toDay(int wd) {
	switch (wd) {
		case 6:
			return "Friday";
		case 0:
			return "Saturday";
		case 1:
			return "Sunday";
		case 2:
			return "Monday";
		case 3:
			return "Tuesday";
		case 4:
			return "Wednesday";
		case 5:
			return "Thursday";
	}
	return "What did you do?";
}

char* toMonth(int mn) {
	switch (mn) {
		case 1: return "January";
		case 2: return "February";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
	}
	return "You did it wrong.";
}

char* fixMinutes(int m) {
	static char fix[50];

	if (m < 10) {
		snprintf(fix, 50, "0%d", m);
	} else {
		snprintf(fix, 50, "%d", m);
	}

	return fix;
}

int main(void) {
	SysTime time;
	sys_time(&time);

	while (app_loop()) {
		sys_time(&time);
		year = time.year;
		month = time.month;
		day = time.day;
		hour = time.hour;
		minute = time.minute;
		weekday = time.weekday;

		gfx_clear(SCREEN_TOP, COLOR_BLACK);
		gfx_print(SCREEN_TOP, 10, 10, FONT_TITLE, COLOR_WHITE, "%s, %s %d, %d", toDay(day), toMonth(month), day, year);
		if (hour < 12) {
			gfx_print(SCREEN_TOP, 160, 110, FONT_TITLE, COLOR_WHITE, "%d:%s AM", hour, fixMinutes(minute));
		} else if (hour == 12) {
			gfx_print(SCREEN_TOP, 160, 110, FONT_TITLE, COLOR_WHITE, "12:%s PM", fixMinutes(minute));
		} else {
			gfx_print(SCREEN_TOP, 160, 110, FONT_TITLE, COLOR_WHITE, "%d:%s PM", hour - 12, fixMinutes(minute));
		}

		gfx_clear(SCREEN_BOTTOM, COLOR_BLACK);
		gfx_print(SCREEN_BOTTOM, 10, 10, FONT_TITLE, COLOR_WHITE, "Clock++");
		gfx_print(SCREEN_BOTTOM, 10, 30, FONT_SMALL, COLOR_WHITE, "by Virtualle");

	}
	return 0;
}
