//
// Created by Administrator on 2016/5/7 0007.
//
#include <stdio.h>
#include <unistd.h>

char *getcmdline(int pid) {
    char buf[32];
    char cmdline[128];
    snprintf(buf, 31, "/proc/%d/cmdline", pid);
    FILE *f = fopen(buf, "r");
    fgets(cmdline, 128, f);
    return cmdline;
}

char *getppcmdline() {
    return getcmdline(getppid());
}



