//
//  SipCallInfo.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 5/10/16.
//  Copyright © 2016 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CToObjCBridge.h"
#import "SIPConstant.h"

@interface SipCallInfo : NSObject


#pragma mark *** Intialise and destroy sip system ***

- (instancetype _Nonnull)initWithIncomingCall:(SipCallInfo *_Nonnull)call;
- (instancetype _Nonnull)initWithNumber:(NSString *_Nonnull)number;
- (instancetype _Nonnull)initWithNumber:(NSString *_Nonnull)number callUUID:(NSString *_Nonnull)uuid;


#pragma mark *** Sip call state change handlers ***

@property (copy, nonatomic) OnCallAccepted _Nullable callAcceptedHandler;
@property (copy, nonatomic) OnCallDisConnected _Nullable callDiconnectedHandler;
@property (copy, nonatomic) OnCallOnHoldCompletion _Nullable callOnHoldCompletionHandler;
@property (copy, nonatomic) OnCallRejected _Nullable callRejectedHandler;
@property (copy, nonatomic) OnCallRejectFullfillHandler _Nullable callRejectFullfillHandler;
@property (copy, nonatomic) OnCallUnHoldCompletion _Nullable callUnHoldCompletionHandler;
@property (copy, nonatomic) OnOutgoingCallStateChanged _Nullable callStateChangedHandler;


#pragma mark *** variables ***

@property (readwrite, nonatomic) BOOL active;
@property (readwrite, nonatomic) BOOL answered; // this object knows - incoming call is ansered or not - populated from IncomingPushCallObject
@property (readwrite, nonatomic) BOOL canceled; // this object knows - incoming call is cancelled or not - populated from IncomingPushCallObject
@property (readwrite, nonatomic) BOOL conferenceCall;
@property (readwrite, nonatomic) BOOL hasVideo;
@property (readwrite, nonatomic) BOOL holdCall;
@property (readwrite, nonatomic) BOOL mute;
@property (readwrite, nonatomic) NSInteger * _Nullable callerContactID;
@property (readwrite, nonatomic) NSInteger callIdx;
@property (readwrite, nonatomic) SIP_CALL_STATE state;
@property (strong, nonatomic) NSString * _Nonnull callState; // it contains call state like - @"calling", @"ringing" and all
@property (strong, nonatomic) NSString * _Nonnull callStatus;
@property (strong, nonatomic) NSString * _Nonnull callType; // it contains call type like - @"outgoing", @"incoming"
@property (strong, nonatomic) NSString * _Nonnull callUUID;
@property (strong, nonatomic) NSString * _Nonnull callerDID;
@property (strong, nonatomic) NSString * _Nonnull codecName;
@property (strong, nonatomic) NSString * _Nonnull linkedUUID;
@property (strong, nonatomic) NSString * _Nonnull parkingSlot;
@property (strong, nonatomic) NSString * _Nonnull routingServer;
@property (strong, nonatomic) NSString * _Nullable callerCnam;
@property (strong, nonatomic) NSString * _Nonnull remoteContact;
@property (strong, nonatomic) NSString * _Nonnull pjsuaCallUUID;

@end
