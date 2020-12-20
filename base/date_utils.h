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
namespace DateUtils {
static long GetCurrentTimeUs() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec*1000000 + t.tv_usec;
}


}
    
}

#endif // TOFT_BASE_DATE_UTILS_H