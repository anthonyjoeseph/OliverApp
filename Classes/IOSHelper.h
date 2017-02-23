//
//  IOSHelper.hpp
//  Oliver
//
//  Created by Anthony Gabriele on 2/17/17.
//
//

#ifndef IOSHelper_hpp
#define IOSHelper_hpp

#include <stdio.h>

using namespace std;

class IOSHelper {
public:
    
    string nativeCallback(string str,void(*callback)(int index));
    
    IOSHelper();
    virtual ~IOSHelper();
};

#endif /* IOSHelper_hpp */
