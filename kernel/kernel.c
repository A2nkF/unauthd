//
//  kernel.c
//  kernel
//
//  Created by Ilias Morad (A2nkF) on 2/24/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#include <mach/mach_types.h>
#include <libkern/libkern.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <sys/sysctl.h>

kern_return_t kernel_start(kmod_info_t * ki, void *d);
kern_return_t kernel_stop(kmod_info_t *ki, void *d);

static int sysctl_A2nkF_string SYSCTL_HANDLER_ARGS;

static u_int8_t pwned_string[21] = "--- Kernel pwned ---";

SYSCTL_NODE(_debug,         // our parent
            OID_AUTO ,      // automatically assign us an object ID
            A2nkF ,         // our name
            CTLFLAG_RW,     // we wil be creating children therefore , read/write
            0,              // Handler function ( none selected )
            "A2nkF sysctl hierarchy") ;

SYSCTL_PROC(_debug_A2nkF,                   // our parent
            OID_AUTO,                       // automatically assign us an object ID
            pwned,                          // our name
            (CTLTYPE_STRING |               // type flag
             CTLFLAG_RD | CTLFLAG_ANYBODY), // access flag (read by anybody)
            &pwned_string,                  // location of our data
            0,                              // argument passed to our handler
            sysctl_A2nkF_string,            // our handler function
            "A",                            // our data type (string)
            "kernel pwn demo"               // our description
);

static int sysctl_A2nkF_string SYSCTL_HANDLER_ARGS {

    return sysctl_handle_string( oidp, oidp->oid_arg1 , oidp->oid_arg2 , req );
}
            
kern_return_t kernel_start(kmod_info_t * ki, void *d)
{    
    printf("[Kernel Stage] We have kernel code execution ;P ~A2nkF");
    sysctl_register_oid(&sysctl__debug_A2nkF);
    sysctl_register_oid(&sysctl__debug_A2nkF_pwned);
    
    return KERN_SUCCESS;
}

kern_return_t kernel_stop(kmod_info_t *ki, void *d)
{
    
    printf("[Kernel Stage] Kext unloaded!");
    sysctl_unregister_oid(&sysctl__debug_A2nkF);
    sysctl_unregister_oid(&sysctl__debug_A2nkF_pwned);
    return KERN_SUCCESS;
}
