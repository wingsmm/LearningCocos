

#ifndef  _MY_NOTEDAO_H_
#define  _MY_NOTEDAO_H_

#include "cocos2d.h"
#include "sqlite3.h"
#include "MyUtility.h"

using namespace std;
USING_NS_CC;

class NoteDAO 
{
	sqlite3 *db;
public:

	//获得数据库文件路径
	static string dbDirectoryFile();

	//初始化数据库
	static int initDB();

	//插入Note方法
	static int create(string pDate, string pContent);

	//删除Note方法
	static int remove(string pDate);

	//修改Note方法
	static int modify(string pDate, string pContent);

	//查询所有数据方法
	static ValueVector findAll();

	//按照主键查询数据方法
	static ValueMap findById(string pDate);

};

#endif // _MY_NOTEDAO_H_
