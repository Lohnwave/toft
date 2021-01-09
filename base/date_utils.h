/*
 * @Author: Lohnwave
 * @Email: waveluozu@163.com
 * @Date: 2020-12-20 13:47:06
 * @Last Modified by: Lohnwave
 * @Last Modified time: 2020-12-20 13:56:12
 * @Description: Description
 */
#ifndef TOFT_BASE_DATE_UTILS_H
#define TOFT_BASE_DATE_UTILS_H
#include <sys/time.h>
namespace toft{
class DateUtils {
    public:
        // 获取毫秒
        static long GetCurrentTimeMillis() {
            return GetCurrentTimeUs() / 1000;
        }
        // 获取微秒
        static long GetCurrentTimeUs() {
            struct timeval t;
            gettimeofday(&t, NULL);
            return t.tv_sec*1000000 + t.tv_usec;
        }
        static long GetCurrentTimeNano() {
            struct timespec tn;
            clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tn);
            return tn.tv_sec * 1000000000 + tn.tv_nsec;
        }
        // 
        static int FastSecondToDate(const time_t& unix_sec, struct tm* tm, int time_zone)
        {
            static const int kHoursInDay = 24;
            static const int kMinutesInHour = 60;
            static const int kDaysFromUnixTime = 2472632;
            static const int kDaysFromYear = 153;
            static const int kMagicUnkonwnFirst = 146097;
            static const int kMagicUnkonwnSec = 1461;
            tm->tm_sec  =  unix_sec % kMinutesInHour;
            int i      = (unix_sec/kMinutesInHour);
            tm->tm_min  = i % kMinutesInHour; //nn
            i /= kMinutesInHour;
            tm->tm_hour = (i + time_zone) % kHoursInDay; // hh
            tm->tm_mday = (i + time_zone) / kHoursInDay;
            int a = tm->tm_mday + kDaysFromUnixTime;
            int b = (a*4  + 3)/kMagicUnkonwnFirst;
            int c = (-b*kMagicUnkonwnFirst)/4 + a;
            int d =((c*4 + 3) / kMagicUnkonwnSec);
            int e = -d * kMagicUnkonwnSec;
            e = e/4 + c;
            int m = (5*e + 2)/kDaysFromYear;
            tm->tm_mday = -(kDaysFromYear * m + 2)/5 + e + 1;
            tm->tm_mon = (-m/10)*12 + m + 2;
            tm->tm_year = b*100 + d  - 6700 + (m/10);
            return 0;
        }

};
    
}

#endif // TOFT_BASE_DATE_UTILS_H