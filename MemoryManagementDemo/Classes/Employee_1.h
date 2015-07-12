//
//  Employee_1.h
//  MemoryManagementDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#ifndef __MemoryManagementDemo__Employee_1__
#define __MemoryManagementDemo__Employee_1__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Employee_1 : public cocos2d::Ref {
    
private:
    unsigned int id;
    __String* first;
    __String* last;
    __Array* emails;
    __Array* phones;
    
public:
    
    Employee_1();
    ~Employee_1();

    
    unsigned int getId();
    
    void setId(unsigned int id);
    
    __String* getFirst() const;
    void setFirst(__String* first);
    
    __String* getLast() const;
    void setLast(__String* last);
    
    __Array* getPhones() const;
    void setPhones(__Array* phones);
    
    __Array* getEmails() const;
    void setEmails(__Array* emails);
};

#endif /* defined(__MemoryManagementDemo__Employee_1__) */
