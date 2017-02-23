//
//  NativeInterface.cpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/17/17.
//
//

#include "NativeInterface.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSHelper.h"
#endif

using namespace std;

string NativeInterface::nativeCallback(){
    
    string str = "unnecessary";
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) // won't compile this part if IOS
    
    JniMethodInfo minfo;
    
    if(JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/cpp/AppActivity",  "alertJNI", "(Ljava/lang/String;)Ljava/lang/String;"))
    {
        
        string tmp(str);
        tmp = tmp + " from Android";
        
        jstring message = minfo.env->NewStringUTF(tmp.c_str());
        jstring return_value = (jstring) minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID, message);
        
        string ret = JniHelper::jstring2string(return_value);
        
        string sret = string("ef");
        
        minfo.env->DeleteLocalRef(message);
        //minfo.env->DeleteLocalRef(return_value);
        minfo.env->DeleteLocalRef(minfo.classID);
        
        return ret;
    }
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) // won't compile this part if ANDROID
    
    IOSHelper *hios = new IOSHelper();
    
    string tmp(str);
    string ret = hios->nativeCallback(tmp, [](int index){
        string indexAsString = std::to_string(index);
    });
    
    return ret;
    
#endif
    
    return "none";
    
}

NativeInterface::NativeInterface(){}
NativeInterface::~NativeInterface(){}
