//
//  Singleton.cpp
//  AdvancedUI
//
//  Created by ZhangBo on 15/7/3.
//
//

#include "Singleton.h"


Singleton * Singleton::instance = new Singleton();


Singleton::Singleton()
{
    
}


Singleton::~Singleton()
{
    
}


Singleton * Singleton::getInstance()
{
    return instance;
}