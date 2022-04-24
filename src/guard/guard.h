#ifndef LAN_SANDBOX_GUARD_H
#define LAN_SANDBOX_GUARD_H

// 请参阅Linux系统调用列表
// https://www.ibm.com/developerworks/cn/linux/kernel/syscall/part1/appendix.html
#include <seccomp.h>
#include <cstdlib> // exit

void setSeccompGuard();

#endif //LAN_SANDBOX_GUARD_H
