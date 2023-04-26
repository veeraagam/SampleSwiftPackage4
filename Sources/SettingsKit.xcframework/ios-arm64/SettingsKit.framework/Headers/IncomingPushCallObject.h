//
//  IncomingPushCallObject.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 4/5/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IncomingPushCallObject : NSObject

@property (nonatomic,readwrite)BOOL answered;
@property (nonatomic,readwrite)BOOL callStatusUpdate;
@property (nonatomic,readwrite)BOOL canceled;
@property (nonatomic,strong) NSString *deviceUUidString;
@property (nonatomic,strong) NSString *from;
@property (nonatomic,strong) NSString *linkedUUidString;
@property (nonatomic,strong) NSString *server;
@property (nonatomic,strong) NSString *slot;
@property (nonatomic,strong) NSString *state;
@property (nonatomic,strong) NSString *status;
@property (nonatomic,strong) NSString *type;
@property (nonatomic,strong) NSUUID *deviceUUid;
@property (nonatomic,strong) NSUUID *linkedUUID;
@property (nonatomic,strong) NSString *callerName;


- (instancetype)initWithPushNotifyPayload:(NSDictionary *)pushPayloadDictionary;

@end
