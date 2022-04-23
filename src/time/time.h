#include <ctime>


#ifndef LAN_SANDBOX_TIME_H
#define LAN_SANDBOX_TIME_H

long getTimeMillisecondByTimeval(struct timeval timeval);

int getGapMillsecond(struct timeval startTime, struct timeval endTime);

#endif //LAN_SANDBOX_TIME_H
