//
//  MTLockDevice.h
//  MTLockDeviceKit
//
//  Created by Minewtech on 2018/11/7.
//  Copyright © 2018 MinewTech. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString *const sServiceString = @"Service";
static NSString *const sReceiveString = @"Receive";
static NSString *const sWriteString = @"Write";
static NSString *const sReadString = @"Read";

typedef NS_ENUM(NSUInteger, Connection) {
    Disconnected = 0,
    Connected,
    Connecting,
    Validating,
};

@class MTLockDevice;

typedef void(^WriteCompletion)(BOOL success, NSError *error);
typedef void(^ReceiveCompletion)(NSData *data);
typedef void(^ConnectionChangeCompletion)(MTLockDevice *device, Connection connection);

@interface MTLockDevice : NSObject


/**
 bluetooth advertising name.
 */
@property (nonatomic, readonly, copy) NSString *name;

/**
 bluetooth advertising mac.
 */
@property (nonatomic, readonly, copy) NSString *mac;

/**
 device battery.
 */
@property (nonatomic, readonly, copy) NSString *battery;

/**
 device bind status.
 */
@property (nonatomic, readonly, copy) NSString *bindStatus;

/**
 device lock status.
 */
@property (nonatomic, readonly, copy) NSString *lockStatus;

/**
 a identifier for this device
 !!! Please note every new scanning task will get a new identifier
 */
@property (nonatomic, readonly, copy) NSString *identifier;

/**
 advertising data
 */
@property (nonatomic, readonly, strong) NSDictionary *advertisingData;

/**
 the timestamp of last update.
 */
@property (nonatomic, readonly, strong) NSDate *lastUpdate;

/**
 current connection status.
 */
@property (nonatomic, readonly, assign) Connection connection;

/**
 current rssi of this device.
 */
@property (nonatomic, readonly, assign) NSInteger rssi;

/**
 service and characteristics uuid.
 */
@property (nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *uuids;

/**
 infomations of this device.
 */
@property (nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *infos;

/**
 Send data to the device
 
 @param data the sending data.
 @param handler writing completion callback, success == YES means send successfully.
 */
- (void)writeData:(NSData *)data completion:(WriteCompletion)handler;

/**
 Received data from device.
 !!! this is a callback method, please listen to the block, it will execute when receiving data from device.
 @param completionHandler the receiving completion block.
 */
- (void)didReceiveData:(ReceiveCompletion)completionHandler;

/**
 listen the changes of connection.
 !!! this is a callback method, please listen to the block, it will execute when the device changes connection.
 @param completionHandler the connection changing block.
 */
- (void)didChangeConnection:(ConnectionChangeCompletion)completionHandler;

@end
