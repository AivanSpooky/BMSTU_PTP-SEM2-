#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define OK 0

/*
Игорь Владимирович!
Если Вы это читаете, значит хотите увидеть исправленную ошибку с онлайн-семинара (кстати именно мой файл Вы показывали)
А именно - устранить переобъявление структуры из системного заголовочного файла
Хочу сказать, что без переопределния компилятор gcc начинает ругаться, якобы я
timespec взял из ниоткуда. Не знаю, как починить.

P.S. Уже нашел...
*/

// struct timespec
// {
//    time_t tv_sec;
//    long tv_nsec;
// };

int nanosleep(const struct timespec *req, struct timespec *rem);

// Замерительный метод - gettimeofday
int main (void)
{
   struct timespec tw = {0,100*1e+6};
   struct timespec tr;

   struct timeval current_time;
   unsigned long long beg, end;

   gettimeofday(&current_time, NULL);

   beg = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;
   nanosleep(&tw, &tr);
   gettimeofday(&current_time, NULL);
   end = current_time.tv_sec * 1000ULL + current_time.tv_usec / 1000ULL;

   printf("%llu\n", end-beg);

   return OK;
}
