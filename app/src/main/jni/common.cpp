//
// Created by pengk on 2016/5/10.
//

#include "common.h"

char *getCmdline(pid_t pid) {
    char buf[32];
    char *cmdline = new char[128];
    snprintf(buf, 31, "/proc/%d/cmdline", pid);
    FILE *f = fopen(buf, "r");
    fgets(cmdline, 128, f);
    return cmdline;
}


pid_t getPidByName(const char *name) {
    DIR *pdir = NULL;
    struct dirent *pde = NULL;
    FILE *pf = NULL;
    char buff[128];
    pid_t pid;
    char szName[128];
    // 遍历/proc目录下所有pid目录
    pdir = opendir("/proc");
    if (!pdir) {
        perror("open /proc fail.\n");
        return -1;
    }
    while ((pde = readdir(pdir))) {
        if ((pde->d_name[0] < '0') || (pde->d_name[0] > '9')) {
            continue;
        }
        sprintf(buff, "/proc/%s/status", pde->d_name);
        pf = fopen(buff, "r");
        if (pf) {
            fgets(buff, sizeof(buff), pf);
            fclose(pf);
            sscanf(buff, "%*s %s", szName);
            pid = atoi(pde->d_name);
            if (strcmp(szName, name) == 0) {
                closedir(pdir);
                return pid;
            }
        }
    }
    closedir(pdir);
    return 0;
}