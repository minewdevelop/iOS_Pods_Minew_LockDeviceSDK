//
//  MTLockDeviceManager.h
//  MTLockDeviceKit
//
//  Created by Minewtech on 2018/11/7.
//  Copyright © 2018 MinewTech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MTLockDeviceKit/MTLockDevice.h>

typedef NS_ENUM(NSUInteger, BluetoothStatus) {
    Unknown = 0,
    Poweroff,
    Poweron,
};
typedef NS_ENUM(NSUInteger, ConnectType) {
    tempory = 0,
    search,
};

typedef void(^ScanCompletion)(NSArray<MTLockDevice *> *devices);
typedef void(^BluetoothChangeCompletion)(BluetoothStatus statues);

@interface MTLockDeviceManager : NSObject

/**
 the status of iphone bluetooth.
 */
@property (nonatomic, readonly, assign) BluetoothStatus status;

/**
 the scanned devices
 */
@property (nonatomic, readonly, strong) NSArray<MTLockDevice *> *scannedDevices;

/**
 the connected devices.
 */
@property (nonatomic, readonly, strong) NSArray<MTLockDevice *> *connectedDevices;


/**
 get a sharedinstance of the MTLockDeviceManager
 
 @return a sharedinstance.
 */
+ (instancetype)sharedInstance;

/**
 start a scanning task, get devices from the compltionhandler or "scannedDevices" property.
 
 @param completionHandler a block for scanned devices.
 */
- (void)startScan:(ScanCompletion)completionHandler;

/**
 stop the scanning task.
 */
- (void)stopScan;

/**
 connect to a device
 
 @param device a device for connecting.
 @param style connect style,reconnecting is tempory,connecting is search.
 
 */
- (void)connect:(MTLockDevice *)device connectStyle:(ConnectType)style;

/**
 disconnect from a device.
 
 @param device a device for disconnecting.
 */
- (void)disconnect:(MTLockDevice *)device;

/**
 a callback for iphone bluetooth changes.
 
 @param completionHandler the bluetooth status changes block.
 */
- (void)didChangesBluetoothStatus:(BluetoothChangeCompletion)completionHandler;

@end
