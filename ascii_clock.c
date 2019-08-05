#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

const char clr_red[]   = "\x1b[1;31m";
const char clr_green[] = "\x1b[1;32m";
const char clr_white[] = "\x1b[1;37m";


const char patterns[8][88] =  {
   " _____    __     _____   _____   _   _   _____   _____   _____   _____   _____          ",
   "/  _  *  /  |   /  _  | |___  * | | | | |  ___| /  ___| |___  | /  _  * /  _  *    _    ",
   "| / * | |_  |   |_//  /   __| | | |_| | | |___  | |___     /  | | |_| | | |_| |   |_|   ",
   "| | | |   | |     /  /   |__  | |___  | |___  * |  _  *   /  /  |  _  | *___  |    _    ",
   "| *_/ |  _| |_   /  /_   ___| |     | |  ___| | | |_| |  /  /   | |_| |     | |   |_|   ",
   "*_____/ |_____| |_____| |_____/     |_| |_____/ *_____/ |__/    *_____/     |_|         "};

const char frame[9][68] = {
    "+-----------------------------------------------------------------+",
    "|                                                                 |",
    "|                                                                 |",
    "|                                                                 |",
    "|                                                                 |",
    "|                                                                 |",
    "|                                                                 |",
    "|                                                                 |",
    "+-----------------------------------------------------------------+"};

void set_colour_RGB(int r, int g, int b) {
  r %= 6;
  g %= 6;
  b %= 6;
  printf("\x1b[38;5;%im",16+r*36+g*6+b);
}

void set_position(int y, int x) {
  printf("\x1b[%i;%iH",y,x);
}

void clear(void) {
  printf("\x1b[2J");
}

int main(int argc, char *argv[]) {
  int line,c,i;
  int  digits[8] = {0,1,10,3,4,10,6,7};
  time_t now;
  struct tm *now_tm;
  int hrs, mins, secs;

  clear();
  printf("%s",clr_red);
  for(line = 0; line < 9; line++) {
    set_position(2+line, 2);
    printf("%s\n",frame[line]);
  }
 
  while(1) {
    now = time(NULL);
    now_tm = localtime(&now);
    hrs  = now_tm->tm_hour;
    mins = now_tm->tm_min;
    secs = now_tm->tm_sec;

    digits[0] = hrs/10;
    digits[1] = hrs%10;

    digits[3] = mins/10;
    digits[4] = mins%10;

    digits[6] = secs/10;
    digits[7] = secs%10;

    printf("%s",clr_green);
    for(line = 0; line < 6; line++) {
      set_position(3+line,4);
      for(c = 0; c < 8; c++) {
         for(i = 0; i < 8; i++) {
	    char a = patterns[line][digits[c]*8+i];
	    if(a == '*') a = '\\';
	    putchar(a);
         }
      }
    }
    fflush(stdout);
    set_position(5+line,3);
    printf("%s\n",clr_white);
    sleep(1);
  }

}
