
#include "JsonParser.h" 

USING_NS_CC;

JsonParser * JsonParser::createWithFile(const char *fileName) 
{ 
	JsonParser *pRet = new JsonParser(); 
	if(pRet->initWithFile(fileName)) 
	{ 
		pRet->autorelease(); 
		return pRet; 
	} 
	CC_SAFE_DELETE(pRet); 
	return NULL; 
} 

bool JsonParser::initWithFile(const char* fileName) 
{
	auto sharedFileUtils = FileUtils::getInstance();
	std::string path = sharedFileUtils->fullPathForFilename(fileName);

	Data data = sharedFileUtils->getDataFromFile(path);
	//Data构建string
	content = std::string((const char*)data.getBytes(),0,data.getSize());
	
	return true; 
} 

void JsonParser::decode()
{
	rapidjson::Document document;
	document.Parse<0>(content.c_str());

	//解析错误
	CCASSERT(!document.HasParseError(), "Parsing to document failure.");

	log("Parsing to document succeeded.");

	CC_ASSERT(document.IsObject() && document.HasMember("Record"));

	const rapidjson::Value &records= document["Record"]; //读取中文的数组 
	//判断是不是数组 
	CC_ASSERT(records.IsArray());

	for(unsigned int i = 0; i < records.Size();i++) //如果不是数组，这一行会报错 
	{ 
		row = ValueMap();

		//获得一条记录对象
		const rapidjson::Value &record = records[i]; 

		//判断这个record有没有ID键 
		CC_ASSERT(record.HasMember("ID"));
		const rapidjson::Value &val_id = record["ID"]; 
		//判断ID类型 
		CC_ASSERT(val_id.IsString());
		row["id"] = Value(val_id.GetString()); 

		//判断这个record有没有CDate键 
		CC_ASSERT(record.HasMember("CDate"));
		const rapidjson::Value &val_CDate = record["CDate"]; 
		//判断CDate类型 
		CC_ASSERT(val_CDate.IsString());
		row["CDate"] = Value(val_CDate.GetString()); 

		//判断这个record有没有Content键 
		CC_ASSERT(record.HasMember("Content"));
		const rapidjson::Value &val_Content = record["Content"]; 
		//判断Content类型 
		CC_ASSERT(val_Content.IsString());		
		row["Content"] = Value(val_Content.GetString()); 

		//判断这个record有没有UserID键 
		CC_ASSERT(record.HasMember("UserID"));
		const rapidjson::Value &val_UserID = record["UserID"]; 
		//判断UserID类型 
		CC_ASSERT(val_UserID.IsString());
		row["UserID"] = Value(val_UserID.GetString()); 

		list.push_back(Value(row));
	}
}
