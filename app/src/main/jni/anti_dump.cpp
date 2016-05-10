//
// Created by pengk on 2016/5/6.
//

#include "stdio.h"

void anti_dump_inotify(int pid, int flag) {
    char *pagemap = new char[0x100];
    char *mem = new char[0x100];
    sprintf(pagemap, "/proc/%d/pagemap", pid);
    sprintf(mem, "/proc/%d/mem", pid);


}


