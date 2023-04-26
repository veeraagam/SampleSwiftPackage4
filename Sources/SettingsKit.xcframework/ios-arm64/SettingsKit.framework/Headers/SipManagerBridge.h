//
//  VOIPStore.h
//  MobileOffice

//  Copyright (c) 2014 Phone.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "SipCallInfo.h"
#import "SipRegisterInfo.h"
#import "PushRegistryManager.h"

@class IncomingPushCallObject;

@interface SipManagerBridge : NSObject  {
  SIP_CALL_STATE _callState;
}

#pragma mark *** Sip call handlers ***

// call back to handle when application registered to SIP server
@property (copy, nonatomic) OnSipAccountRegistered _Nullable registerationHandler;

// call back to handle incoming audio call
@property (copy, nonatomic) OnIncomingCallRecieved _Nullable incomingCallRecievedHandler;

// call back to handle incoming video call
@property (copy, nonatomic) OnIncomingVideoCaptured _Nullable incomingVideoCapturedHandler;

// call back to handle when application registered to SIP server and ready to make a call
@property (copy, nonatomic) OnIntialisedToMakeCall _Nullable sipIntialisedToMakeCallHandler;

// call back to manage updated media info 
@property (copy, nonatomic) OnMediaInfoUpadted _Nullable mediaInfoUpdatedHandler;


#pragma mark *** Intialise singleton object ***

+ (SipManagerBridge *_Nonnull)sharedManager;

+ (BOOL)isApplicationInForeGround;

#pragma mark *** Intialise and destroy sip system ***

// Will check application registered to SIP server or not.
// If application is not registered then this method will register it automatically.
// This method will call "registerationHandler" and "sipIntialisedToMakeCallHandler"
- (void)checkVOIPSystemStatus;

/*
 Destroy pjsua. Application is recommended to perform graceful shutdown before calling this method (such as unregister the account from the SIP server,
 terminate presense subscription, and hangup active calls), however, this method will do all of these if it finds there are active sessions that need to be terminated.
 This method will block for few seconds to wait for replies from remote.
*/
- (void)destroyStack;


// This method will register application to SIP protocol and will register application to PushKit
// Must call this method to start SIP system
- (void)initSipSystem:(SipRegisterInfo *_Nonnull)registerInfo;


// This method will Initiate CallKit
- (void)setUpCallKit;

// Perform unregistration.
// Application normally only needs to call this method if it wants to manually to unregister from the server.
- (void)unRegister;
- (void)unRegisterFromPush;


#pragma mark *** Get caller info ***

- (NSString *_Nullable)getCallerCNAM:(NSString *_Nonnull)callUUID; // if the name via caller ID exists, return it here
- (NSString *_Nullable)getCallerDID:(NSString *_Nonnull)callUUID;
- (NSString *_Nullable)getSipDomain;
- (NSString *_Nullable)getSipProtocol;


#pragma mark *** Get account state ***

- (SIP_STORE_ACCOUNT_STATE)getStoreAccountState;
- (SIP_STORE_SYSTEM_STATE)getStoreSystemState;


#pragma mark *** Find SipCallInfo object ***

// this method will find and return the object of SipCallInfo from active calls array
- (SipCallInfo *_Nonnull)findSipCallForUUID:(NSString*_Nonnull)callUUID;


#pragma mark *** Hold, unHold, Mute and UnMute Sip call ***

// call this method to hold the call
// pass callUUID of SipCallInfo object on which you want to perfom the action
- (void)holdCall:(NSString *_Nonnull)callUUID onCompletion:(OnCallOnHoldCompletion _Nullable )handler;

// call this method to mute the call
// pass callUUID of SipCallInfo object on which you want to perfom the action
- (void)muteOngoingCall:(NSString *_Nonnull)callUUID;

// call this method to unhold the call
// pass callUUID of SipCallInfo object on which you want to perfom the action
- (void)unHoldCall:(NSString *_Nonnull)callUUID onCompletion:(OnCallUnHoldCompletion _Nullable )handler;

// call this method to unmute the call
// pass callUUID of SipCallInfo object on which you want to perfom the action
- (void)unMuteOngoingCall:(NSString *_Nonnull)callUUID;


#pragma mark *** Make outgoing, incoming & Disconect and transfer Sip call ***

- (BOOL)makeCall:(SipCallInfo* _Nonnull )voipCallInfo parkingSlot:(NSString* _Nullable )parkingSlot routingServer:(NSString* _Nullable )routingServer;
- (void)answerIncomingCall:(NSString *_Nonnull)callUUID;
- (void)hangupAllCalls;
- (void)hangupCallWithUUID:(NSString *_Nonnull)callUUID;
- (void)makeCallUsingCallInfo:(nonnull SipCallInfo *)callInfo;

// Call this method to merge two active calls in the system
- (void)mergeCalls:(NSString *_Nonnull)callUuIdA localIdxB:(NSString *_Nonnull)callUuIdB onCompletion:(callsMergedCompletion _Nullable )handler;

// Initiate call transfer to the specified address.
- (void)transferCallWithId:(NSString *_Nonnull)callUUID toDestination:(nonnull NSString *)toDestination protocol:(NSString *_Nonnull)protocol;

// process incoming call from PushKit
- (void)processIncomingCallForpayLoad:(PKPushPayload *_Nullable)payload
                              forType:(PKPushType _Nullable )type withCompletionHandler:(void(^_Nullable)(void))callDidCompleted;

#pragma mark *** Supporting ***

- (NSInteger)callDurationForCall:(NSString *_Nonnull)callUUID;
- (int)getSipCallsCount;
- (void)activateSoundDev;
- (void)deActivateSoundDev;
- (void)sendDTMFCode:(nonnull NSString *)code callUUID:(NSString *_Nonnull)callUUID;
- (void)updateNetworkTransport;
- (void)updateSipProtocol:(NSString *_Nonnull)protocol;
- (void)reinviteCall:(NSString *_Nonnull)callUUID;

@end


