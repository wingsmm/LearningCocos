

#ifndef  _CSVPARSER_H_
#define  _CSVPARSER_H_

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class CSVParser 
{
public:
	static __Array* parse(const char* fileName);
};

#endif //  _CSVPARSER_H_
