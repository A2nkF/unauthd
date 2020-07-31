//
//  mach_logger.h
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 2/24/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#ifndef mach_logger_h
#define mach_logger_h

#include <stdio.h>

typedef struct {
    mach_msg_header_t header;
    char content[1024];
    mach_msg_trailer_t trailer;
} in_msg;


kern_return_t loggerAwait(mach_port_t *server_port);
kern_return_t loggerInit(mach_port_t *server_port);

#endif /* mach_logger_h */
