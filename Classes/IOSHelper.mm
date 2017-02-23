//
//  IOSHelper.cpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/17/17.
//
//

#include "IOSHelper.h"
#include "RootViewController.h"

string IOSHelper::nativeCallback(string str,void(*callback)(int index)){
    
    RootViewController *rootViewController = (RootViewController *) [UIApplication sharedApplication].keyWindow.rootViewController;
    [rootViewController beginRotationToLandscape];
    
    NSNumber *value = [NSNumber numberWithInt:UIInterfaceOrientationLandscapeLeft];
    UIDevice *current = [UIDevice currentDevice];
    [current setValue:value forKey:@"orientation"];
    [UIViewController attemptRotationToDeviceOrientation];
    
    [rootViewController endRotationToLandscape];
    
    return "Works";
}

IOSHelper::IOSHelper(){}
IOSHelper::~IOSHelper(){}
