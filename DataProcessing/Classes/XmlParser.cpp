
#include "XmlParser.h" 

USING_NS_CC;


XmlParser * XmlParser::createWithFile(const char *fileName) 
{ 
	XmlParser *pRet = new XmlParser(); 
	if(pRet->initWithFile(fileName)) 
	{ 
		pRet->autorelease(); 
		return pRet; 
	} 
	CC_SAFE_DELETE(pRet); 
	return nullptr; 
} 

bool XmlParser::initWithFile(const char* fileName) 
{
	SAXParser parser;   
	if (!parser.init("UTF-8") ) 
	{
		log("Please use utf-8 format."); 
		return false; 
	}
	parser.setDelegator(this); 

	auto sharedFileUtils = FileUtils::getInstance();
	std::string path = sharedFileUtils->fullPathForFilename(fileName);

	return parser.parse(path); 
} 

//回调方法
void XmlParser::startElement(void *ctx, const char *name, const char **atts) 
{
	CC_UNUSED_PARAM(ctx); 

	startElementName = (char *)name; 

	if(startElementName == "Note"){ 

		row = ValueMap();

		for(int i = 0; atts[i]; i += 2) 
		{
			std::string key = (char*)atts[i];
			std::string value = (char*)atts[i+1];

			std::pair<std::string,Value> pair(key,Value(value));
			row.insert(pair);
		}
	}
} 


//键值对的结束字段 
void XmlParser::textHandler(void *ctx, const char *ch, int len) 
{
	CC_UNUSED_PARAM(ctx); 

	std::string currElementValue = std::string((char*)ch,0,len); 
	std::pair<std::string,Value> pair(startElementName,Value(currElementValue));	
	row.insert(pair);
} 

void XmlParser::endElement(void *ctx, const char *name) 
{
	CC_UNUSED_PARAM(ctx); 

	std::string endElementName = (char *)name; 
	if(endElementName == "Note"){ 
		list.push_back(Value(row));
	}
} 
