//
//  PushRegistryManager.h
//  PhoneSipManager
//
//  Created by Phone.com on 09/12/19.
//  Copyright © 2019 Phone.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PushKit/PushKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PushRegistryManagerDelegate <NSObject>

@optional
- (void)didReceivedIncomingCallPayload:(PKPushPayload *)payload forType:(PKPushType)type withCompletionHandler:(void(^)(void))callDidCompleted;
- (void)didUpdatePushCredentials:(NSString *)token;

@end

@interface PushRegistryManager : NSObject


#pragma mark *** Sip call handlers ***

@property (nonatomic, weak) id<PushRegistryManagerDelegate> delegate;


#pragma mark *** Intialise singleton object ***

+ (PushRegistryManager *_Nonnull)sharedManager;

- (void)registerForPushKit;
- (PKPushRegistry *)pushRegistry;

@end

NS_ASSUME_NONNULL_END
