//
//  uninstaller.h
//  unauthd
//
//  Created by Ilias Morad (A2nkF) on 2/7/20.
//  Copyright © 2020 Ilias Morad (A2nkF). All rights reserved.
//

#ifndef uninstaller_h
#define uninstaller_h


@interface Uninstaller : NSObject

+ (void)_uninstallApp: (NSString*)location;

@end


@interface UNDaemonConnection : NSObject
{
    NSMachPort *serverPort;
    NSMachPort *servicePort;
    NSMachPort *statusPort;
    NSMutableDictionary *requestLookup;
    NSObject<OS_dispatch_source> *inSource;
    NSObject<OS_dispatch_source> *outSource;
    BOOL inShutdown;
}

+ (id)copyOfConnection;
+ (id)copyOfConnectionWithAuth:(struct AuthorizationOpaqueRef *)arg1;
- (BOOL)abortUninstallOfID:(unsigned int)arg1;
- (unsigned int)requestUninstallOfBundlesAtPaths:(id)arg1 withRequest:(id)arg2;
- (BOOL)connectToDaemon:(struct AuthorizationOpaqueRef *)arg1;
- (void)dealloc;
- (void)finalize;
- (id)initWithAuthorization:(struct AuthorizationOpaqueRef *)arg1;
- (id)init;
- (void)removeRequestByID:(unsigned int)arg1;
- (void)disconnected;
- (id)requestForRequestID:(unsigned int)arg1;

@end

@interface UNError : NSError
{
}

- (id)localizedDescription;
- (id)propertyListRepresentation;
- (id)initWithData:(id)arg1;
- (id)initWithError:(int)arg1 userInfo:(id)arg2;

@end


@interface UNUninstallRequest : NSObject
{
    UNDaemonConnection *_connection;
    NSMachPort *_requestingClient;
    NSMachPort *_remoteBootstrap;
    unsigned int _requestNumber;
    NSArray *_bundlePaths;
    BOOL _forceApplicationQuit;
    BOOL _isClient;
}

+ (BOOL)_isAdminUser;
+ (int)uninstallablityOfFileAtURL:(id)arg1;
+ (BOOL)setAuthorizationForRequests:(struct AuthorizationOpaqueRef *)arg1;
+ (id)requestUninstallOfBundlesAtURLsInSet:(id)arg1;
+ (id)requestUninstallOfBundleAtURL:(id)arg1;
- (void)shouldForceRunningApplicationsToQuit:(BOOL)arg1;
- (BOOL)abortUninstall;
- (BOOL)queueRequest;
- (void)dealloc;
- (id)initWithBundlesAtURLsInSet:(id)arg1;
- (id)initWithBundleAtURL:(id)arg1;
- (BOOL)_requestUninstallOfBundlesAtPaths:(id)arg1;
- (void)_setConnection:(id)arg1;
- (id)remoteBootstrap;
- (void)setRemoteBootstrap:(id)arg1;
- (id)requestingClient;
- (void)setRequestingClient:(id)arg1;
- (BOOL)forceApplicationQuit;
- (id)bundlePaths;
- (unsigned int)requestNumber;
- (id)initWithBundlePathsInArray:(id)arg1 asClient:(BOOL)arg2;
- (id)initWithBundlesAtURLsInArray:(id)arg1 asClient:(BOOL)arg2;
- (id)initWithBundleAtURL:(id)arg1 asClient:(BOOL)arg2;

@end




#endif /* uninstaller_h */
