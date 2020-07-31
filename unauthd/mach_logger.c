//
//  mach_logger.c
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 2/24/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//


#include <stdio.h>
#include <servers/bootstrap.h>
#include <assert.h>
#include "mach_logger.h"


kern_return_t receiveMsg(mach_port_t port, char *data, mach_msg_id_t *id);

kern_return_t loggerInit(mach_port_t *server_port) {
    kern_return_t kr = KERN_FAILURE;
    mach_port_t _server_port, bs_port = MACH_PORT_NULL;
    char server[] = "com.a2nkf.logging";
    
    if((kr = task_get_bootstrap_port(mach_task_self(), &bs_port)) != KERN_SUCCESS) {
        printf("[-] task_get_bootstrap_port failed: %s", mach_error_string(kr));
        fflush(stdout);
        return kr;
    }

    if((kr = bootstrap_check_in(bs_port, server, &_server_port)) != KERN_SUCCESS) {
        printf("[-] bootstrap_check_in failed: %s", mach_error_string(kr));
        fflush(stdout);
    }

    puts("[+] Logger registerd!");
    *server_port = _server_port;
    return kr;
}

kern_return_t loggerAwait(mach_port_t *server_port) {
    char data[1024];
    mach_msg_id_t id = -1;
    
    puts("[+] Logger started! Waiting for stage 2... ");
    
    while(1) {
        bzero(data, sizeof(data));
        receiveMsg(*server_port, data, &id);
        
        if(id == 0x4141) {
            printf("[STAGE2] %s\n", data);
        } else if (id == 0x1337) {
            printf("[FINAL] %s\n", data);
            return KERN_SUCCESS;
        } else {
            puts("[-] Logger got unknown message id!");
            return KERN_FAILURE;
        }
    }
}

kern_return_t receiveMsg(mach_port_t port, char *data, mach_msg_id_t *id) {
    kern_return_t kr = KERN_FAILURE;
    in_msg msg = {0};
    
    
    if((kr = mach_msg(&msg.header, MACH_RCV_MSG, 0, sizeof(msg), port, MACH_MSG_TIMEOUT_NONE, mach_task_self())) != KERN_SUCCESS) {
        printf("[-] mach_msg MACH_RCV_MSG failed: %s", mach_error_string(kr));
        fflush(stdout);
    }

    if (msg.header.msgh_size != (sizeof(msg)-sizeof(mach_msg_trailer_t))) {
        puts("[-] Got invalid message size!");
    }
    
    strncpy(data, msg.content, 1024);
    *id = msg.header.msgh_id;
    
    return kr;
}
