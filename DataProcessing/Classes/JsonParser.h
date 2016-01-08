

#ifndef __JSON_Parser_SCENE_H__
#define __JSON_Parser_SCENE_H__

#include "cocos2d.h"

//rapidjson 需要
#include "document.h"
#include "writer.h"
#include "reader.h"
#include "stringbuffer.h"

class JsonParser : public cocos2d::Ref
{
	//声明返回数据属性
	CC_SYNTHESIZE(cocos2d::ValueVector, list, List);

private: 
	cocos2d::ValueMap row;

	//JSON文件内容
	std::string content;
public:

	static JsonParser * createWithFile(const char *fileName); 
    
    bool initWithFile(const char* JSONName); 
	
	void decode(); 
};

//#endif // __JSON_Parser_SCENE_H__
