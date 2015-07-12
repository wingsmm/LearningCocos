//
//  Employee_2.cpp
//  MemoryManagementDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "Employee_2.h"


Employee_2::~Employee_2()
{
    log("Employee_2::~Employee_2()");
    CC_SAFE_RELEASE_NULL(first);
    CC_SAFE_RELEASE_NULL(last);
    CC_SAFE_RELEASE_NULL(emails);
    CC_SAFE_RELEASE_NULL(phones);
}