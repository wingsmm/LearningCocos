


#ifndef __XML_Parser_SCENE_H__
#define __XML_Parser_SCENE_H__

#include "cocos2d.h"

class XmlParser : public cocos2d::Ref, public cocos2d::SAXDelegator 
{
	//声明返回数据属性
	CC_SYNTHESIZE(cocos2d::ValueVector, list, List);

private: 

	std::string startElementName;//记录开始元素 
	cocos2d::ValueMap row;

public:
	
	static XmlParser * createWithFile(const char *fileName); 
   
    bool initWithFile(const char* xmlName); 
  
    //SAXDelegator 的3个回调方法
    virtual void startElement(void *ctx, const char *name, const char **atts); 
    virtual void endElement(void *ctx, const char *name); 
    virtual void textHandler(void *ctx, const char *ch, int len); 

};

#endif // __XML_Parser_SCENE_H__
