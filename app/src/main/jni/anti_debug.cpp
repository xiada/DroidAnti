//
// Created by pengk on 2016/5/6.
//

#include "anti_debug.h"


static char *getPPCmdline() {
    return getCmdline(getppid());
}

static char *getPPName() {
    return getPPCmdline();
}

static bool lookupBlacklist(const char *name) {
    return false;
}

pid_t anti_debug_getTracePid() {
    char buf[512];
    FILE *fin;
    fin = fopen("/proc/self/status", "r");
    pid_t tpid = 0;
    const char *needle = "TracerPid:";
    size_t nl = strlen(needle);
    while (fgets(buf, 512, fin)) {
        if (!strncmp(buf, needle, nl)) {
            sscanf(buf, "TracerPid: %d", &tpid);
            LOGD("TracePid = %d", tpid);
            if (tpid != 0) {
                break;
            }
        }
    }
    fclose(fin);
    return tpid;
}


/*
 * 返回true表示被调试
 */
bool anti_debug_antiParent() {
    char *ppName = getPPName();
    bool ret = lookupBlacklist(ppName);
    delete ppName;
    return ret;
}

/*
 * 返回true表示被调试
 */
bool anti_debug_antiTracePid() {
    if (anti_debug_getTracePid() != 0) return true;
    return false;
}

bool anti_debug_antiPtrace(void) {
    pid_t child;
    child = fork();
    if (child)
        wait(NULL);
    else {
        pid_t parent = getppid();
        if (ptrace(PTRACE_ATTACH, parent, 0, 0) < 0)
            while (1);
        sleep(1);
        ptrace(PTRACE_DETACH, parent, 0, 0);
        exit(0);
    }
}




