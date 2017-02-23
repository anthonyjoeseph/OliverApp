//
//  NativeInterface.hpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/17/17.
//
//

#ifndef NativeInterface_h
#define NativeInterface_h

#include "cocos2d.h"

#include <string>

using namespace cocos2d;
using namespace std;

class NativeInterface {
public:
    
    string nativeCallback();
    
    NativeInterface();
    virtual ~NativeInterface();
};

#endif /* NativeInterface_h */
