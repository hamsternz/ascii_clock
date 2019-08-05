#include <stdio.h>
#include <time.h>
#include <sys/time.h>


char patterns[8][88] =  {
   " _____    __     _____   _____   _   _   _____   _____   _____   _____   _____          ",
   "/  _  *  /  |   /     | |___  * | | | | |  ___| /  ___| |___  | /  _  * /  _  *    _    ",
   "| | | | |_  |   |_//  /   __| | | |_| | | |___  | |___     /  | | |_| | | |_| |   |_|   ",
   "| | | |   | |     /  /   |__  | |___  | |___  * |  _  *   /  /  |  _  | *___  |    _    ",
   "| *_/ |  _| |_   /  /_   ___| |     | |  ___| | | |_| |  /  /   | |_| |     | |   |_|   ",
   "*_____/ |_____| |_____| |_____/     |_| |_____/ *_____/ |__/    *_____/     |_|         "};


int main(int argc, char *argv[]) {
  int line,c,i;
  int  digits[8] = {0,1,10,3,4,10,6,7};
  time_t now;
  struct tm *now_tm;
  int hrs, mins, secs;

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

  for(line = 0; line < 6; line++) {
    putchar(' ');
    for(c = 0; c < 8; c++) {
       for(i = 0; i < 8; i++) {
	  char a = patterns[line][digits[c]*8+i];
	  if(a == '*') a = '\\';
	  putchar(a);
       }
    }
    putchar('\n');
  }
  putchar('\n');
}
