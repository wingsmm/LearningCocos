//
//  Singleton.h
//  AdvancedUI
//
//  Created by ZhangBo on 15/7/3.
//
//

#ifndef __AdvancedUI__Singleton__
#define __AdvancedUI__Singleton__

#include <stdio.h>

class Singleton {
    Singleton();
    ~Singleton();
    
    static Singleton * instance;
    
public:
    static Singleton * getInstance();
};



#endif /* defined(__AdvancedUI__Singleton__) */
