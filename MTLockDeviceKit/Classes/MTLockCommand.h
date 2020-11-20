//
//  MTLockCommand.h
//  MTLockDeviceKit
//
//  Created by Minewtech on 2019/3/14.
//  Copyright © 2019 MinewTech. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTLockCommand : NSObject
/**
 verfication device when connecting.
 
 */
+ (NSData *)verification;

/**
 binding the device.
 
 @param user @"H"---host @"S"---guest.
 @param password password of the device.(6-8 digits)
 
 */

+ (NSData *)bindingDeviceWithTheUser:(NSString *)user password:(NSString *)password;
/**
 unbind the device.
 
 @param user @"H"---host @"S"---guest.
 @param password password of the device.(6-8 digits)
 
 */
+ (NSData *)unbindDeviceWithTheUser:(NSString *)user password:(NSString *)password;
/**
 verfication the device.
 
 @param user @"H"---host @"S"---guest.
 @param password password of the device.(6-8 digits)
 
 */
+ (NSData *)verficationDeviceWithTheUser:(NSString *)user password:(NSString *)password;

/**
 lock or unlock operation.
 
 @param user @"H"---host @"S"---guest.
 @param password password of the device.(6-8 digits)

 */
+ (NSData *)UnlockWithTheUser:(NSString *)user password:(NSString *)password;
/**
 read lockRecord from device.
 
 @param time @"20190201131415",now the lockRecord data between the specified time.When time is @"" or nil and operation is RRcd,you will get all lockRecord data.
 
 */
+ (NSData *)readLockRecord:(NSString *)time;
/**
 write lockRecord to device.
 
 @param user @"H"---host @"S"---guest.

 */
+ (NSData *)writeLockRecordWithTheUser:(NSString *)user;


@end

NS_ASSUME_NONNULL_END
