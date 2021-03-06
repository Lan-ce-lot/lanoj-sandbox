#include "guard.h"

int FORBIDDEN_LIST[] = {
        // 进程控制
        SCMP_SYS(fork),
        SCMP_SYS(clone),
        SCMP_SYS(vfork)
};
int syscalls_whitelist[] = {SCMP_SYS(read), SCMP_SYS(fstat),
                            SCMP_SYS(mmap), SCMP_SYS(mprotect),
                            SCMP_SYS(munmap), SCMP_SYS(uname),
                            SCMP_SYS(arch_prctl), SCMP_SYS(brk),
                            SCMP_SYS(access), SCMP_SYS(exit_group),
                            SCMP_SYS(close), SCMP_SYS(readlink),
                            SCMP_SYS(sysinfo), SCMP_SYS(write),
                            SCMP_SYS(writev), SCMP_SYS(lseek),
                            SCMP_SYS(clock_gettime), SCMP_SYS(pread64)}; // add extra rule for pread64

/**
 * @author lancel
 * @param ctx scmp_filter_ctx
 * @return int
 * 添加限制规则
 */
int addSeccompRules(scmp_filter_ctx ctx) {
    int len = sizeof(syscalls_whitelist) / sizeof(int);
    for (int i = 0; i < len; i++) {
        if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, syscalls_whitelist[i], 0) != 0) {
//        if (seccomp_rule_add(ctx, SCMP_ACT_KILL, FORBIDDEN_LIST[i], 0) != 0) {
            return 0;
        }
    }

    // add extra rule for execve
//    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 1, SCMP_A0(SCMP_CMP_EQ, (scmp_datum_t)({"PATH=/bin", 0}))) != 0;
    return 1;
}

/**
 * @author lancel
 * @return int
 * 执行规则限制
 */
void setSeccompGuard(struct execConfig *execConfig) {
    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_KILL);

//    ctx = seccomp_init(SCMP_ACT_ALLOW);
    if (!ctx) {
        exit(3);
    }
//    addSeccompRules(ctx);
    int len = sizeof(syscalls_whitelist) / sizeof(int);
    for (int i = 0; i < len; i++) {
        if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, syscalls_whitelist[i], 0) != 0) {
//        if (seccomp_rule_add(ctx, SCMP_ACT_KILL, FORBIDDEN_LIST[i], 0) != 0) {
            return;
        }
    }
    if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 1,
                         SCMP_A0(SCMP_CMP_EQ, (scmp_datum_t) (execConfig->execPath))) != 0) {
        exit(5);
    }
    //    if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0) != 0) {
//        return ;
//    }
//    if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup), 0) != 0) {
//        return ;
//    }
//    if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup2), 0) != 0) {
//        return ;
//    }
//    if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup3), 0) != 0) {
//        return ;
//    }
    seccomp_load(ctx);
//    seccomp_release(ctx);
}