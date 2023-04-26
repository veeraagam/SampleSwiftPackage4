//
//  SipDataManager.h
//  MobileOffice
//
//  Created by Labs108 on 02/10/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SIPConstant.h"
#import <AVFoundation/AVFoundation.h>

@class VoIPCall;
@class IncomingPushCallObject;

@interface SipDataManager : NSObject

@property SIP_STORE_SYSTEM_STATE voipStoreSystemState;
@property SIP_STORE_ACCOUNT_STATE voipStoreAccountState;

@property(nonatomic, strong, nonnull) NSString *sipDomain;
@property(nonatomic, strong, nonnull) NSString *sipUser;
@property(nonatomic, strong, nonnull) NSString *sipPassword;

@property(nonatomic, strong, nullable) AVAudioPlayer *audioPlayerOutbound;

@property(nonatomic, strong, nonnull) NSMutableArray *arrVoipCalls;

@property(nonatomic, strong, nullable) dispatch_queue_t completionQueue; // Default to mainQueue

+ (SipDataManager *_Nonnull)sharedManager;

- (SipCallInfo *_Nonnull)findVoipCallForUUID:(NSString*_Nonnull)_NullablecallUUID;

- (SipCallInfo *_Nonnull)findVoipCallForCallIdx:(int)callIdx;

- (SipCallInfo *_Nonnull)findVoipCallForUDID:(NSString *_Nullable)callUDID;

- (void)addNewCall:(SipCallInfo *_Nullable)callInfo;

- (NSString*_Nonnull)createSipDomainUri:(NSString*_Nonnull)domain sipProtocol:(NSString *_Nonnull) protocol;

- (NSString*_Nonnull)createSipUri:(NSString*_Nonnull)number sipDomainPort:(NSString *_Nonnull)domain sipProtocol:(NSString *_Nonnull) protocol;

@end
