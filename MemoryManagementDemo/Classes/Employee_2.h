//
//  Employee_2.h
//  MemoryManagementDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __MemoryManagementDemo__Employee_2__
#define __MemoryManagementDemo__Employee_2__

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class Employee_2 : public cocos2d::Ref {
    
private:
    CC_SYNTHESIZE(unsigned int, id, Id);
    CC_SYNTHESIZE_RETAIN(__String*, first,First);
    CC_SYNTHESIZE_RETAIN(__String*, last, Last);
    CC_SYNTHESIZE_RETAIN(__Array*, emails, Emails);
    CC_SYNTHESIZE_RETAIN(__Array*, phones, Phones);
    
public:
    
    ~Employee_2();
};


#endif /* defined(__MemoryManagementDemo__Employee_2__) */
