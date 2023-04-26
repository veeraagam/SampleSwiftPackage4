//
//  CallKitManager.h
//  MobileOffice
//
//  Created by Labs108 on 02/10/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SipManagerBridge.h"

@class IncomingPushCallObject;

@interface CallKitManager : NSObject

@property (copy, nonatomic) WillInitiatInComingCall _Nullable willInitiatInComingCallHandler;
@property(nonatomic, strong, nullable) dispatch_queue_t completionQueue; // Default to mainQueue
@property (strong, nonatomic) NSString * _Nonnull pjsuaCallUUID;

+ (CallKitManager *_Nonnull)sharedManager;

- (void)invalidateAllCalls;

- (void)setupWithAppName:(NSString *_Nullable)appName
           supportsVideo:(BOOL)supportsVideo
 actionNotificationBlock:(SipCallKitActionNotificationBlock _Nullable)
actionNotificationBlock;

- (void)mute:(BOOL)mute callUUID:(NSUUID * _Nonnull)callUUID completion:(SipCallKitManagerCompletion _Nullable)completion;

- (void)hold:(BOOL)hold callUUID:(NSUUID * _Nonnull)callUUID completion:(SipCallKitManagerCompletion _Nullable)completion;

- (void)endCall:(NSUUID * _Nonnull)callUUID completion:(SipCallKitManagerCompletion _Nullable)completion;

- (void)reportIncomingCallWithCallInfo:(SipCallInfo* _Nonnull)callInfo withCompletionHandler:(void(^_Nullable)(void))callCompleted;
- (void)reportIncomingCallWithcallUUID:(NSString* _Nonnull)UUID callerName:(NSString*)callerName callerNumber:(NSString*)callerNumber withCompletionHandler:(void(^)(void))callCompleted;

- (NSUUID * _Nonnull)reportIncomingCallWithNumber:(NSString * _Nonnull )number completion:(SipCallKitManagerCompletion _Nullable)completion;
- (NSUUID * _Nonnull)reportOutgoingCallUsingCallInfo:(SipCallInfo* _Nonnull)callInfo
                                          completion:(SipCallKitManagerCompletion _Nullable )completion;

- (void)updateCall:(NSUUID *_Nonnull)callUUID state:(CallKitCallState)state withCompletionHandler:(void(^_Nullable)(void))callCompleted;
- (void)reportIncomingCallToAvoidCrashWithUUID:(NSUUID * _Nonnull )callUUID completion:(void(^_Nonnull)(void))callCompleted;

@end
