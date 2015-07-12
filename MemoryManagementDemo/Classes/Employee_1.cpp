//
//  Employee_1.cpp
//  MemoryManagementDemo
//
//  Created by ZhangBo on 15/7/12.
//
//

#include "Employee_1.h"



unsigned int Employee_1 ::getId()
{
    return id;
}

void Employee_1::setId(unsigned int id)
{
    this->id = id;
}

__String* Employee_1::getFirst() const
{
    return first;
}

void Employee_1::setFirst(__String* first)
{
    first->retain();
    this->first->release();
    this->first = first;
}

__String* Employee_1::getLast() const
{
    return last;
}

void Employee_1::setLast(__String* last)
{
    last->retain();
    this->last->release();
    this->last = last;
}
__Array* Employee_1::getEmails() const
{
    return emails;
}

void Employee_1::setEmails(__Array* emails) {
    emails->retain();
    this->emails->release();
    this->emails = emails;
}

__Array* Employee_1::getPhones() const
{
    return phones;
}

void Employee_1::setPhones(__Array* phones)
{
    phones->retain();
    this->phones->release();
    this->phones = phones;
}

Employee_1::~Employee_1()
{
    this->first->release();
    this->first = nullptr;
    this->last->release();
    this->last = nullptr;
    this->emails->release();
    this->emails = nullptr;
    this->phones->release(); 
    this->phones = nullptr;
}


Employee_1::Employee_1()
{
    this->first->release();
    this->last->release();
    this->emails->release();
    this->phones = nullptr;
}



