//
//  SipRegisterInfo.h
//  PhoneSipManager
//
//  Created by vTechnolabs on 03/03/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SipRegisterInfo : NSObject <NSCopying>

@property (nonatomic, copy) NSString* _Nonnull domain;
@property (nonatomic, copy) NSString* _Nonnull user;
@property (nonatomic, copy) NSString* _Nonnull password;
@property (nonatomic, copy) NSString* _Nonnull protocol;
@property (nonatomic, copy) NSString* _Nonnull deviceToken;
@property (nonatomic, copy) NSString* _Nonnull debugMode;
@property (nonatomic, copy) NSString* _Nonnull deviceType;
@property (nonatomic, copy) NSString* _Nonnull appVersion;
@property (nonatomic, copy) NSString* _Nonnull applicationBundleID;
@property (nonatomic, copy) NSString* _Nonnull deviceInfo;
@property (nonatomic, copy) NSString* _Nonnull applicationId;
@property (nonatomic, copy) NSString* _Nonnull voipID;
@property (nonatomic, copy) NSString* _Nonnull voipPhoneID;
@property (nonatomic, copy) NSString* _Nonnull logFileName;
@property (nonatomic) BOOL srtp;

@end

NS_ASSUME_NONNULL_END
