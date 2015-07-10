
#include "CSVParser.h"

__Array* CSVParser::parse(const char* fileName)
{
	auto sharedFileUtils = FileUtils::getInstance();

	string pathKey = sharedFileUtils->fullPathForFilename(fileName);

	string content = sharedFileUtils->getStringFromFile(pathKey);
	__String* contentStr  = __String::create(content);

	__Array* rows = contentStr->componentsSeparatedByString("\n");

	__Array* ret = __Array::createWithCapacity(rows->count());

	Ref *obj = nullptr;
	CCARRAY_FOREACH(rows, obj)
	{
		auto fieldStr = static_cast<__String*>(obj);
		__Array* fields = fieldStr->componentsSeparatedByString(",");
		ret->addObject(fields);
	}
	return ret;
}

