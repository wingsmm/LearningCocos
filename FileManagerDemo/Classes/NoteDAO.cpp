#include "NoteDAO.h"

string NoteDAO::dbDirectoryFile()
{
	auto sharedFileUtils = FileUtils::getInstance();
	string writablePath = sharedFileUtils->getWritablePath();
	string fullPath = writablePath + "NotesList.sqlite3";

	return fullPath;
}

//初始化数据库
int NoteDAO::initDB()
{
	auto sharedFileUtils = FileUtils::getInstance();

	string path = dbDirectoryFile();

	bool isExist = false;
	isExist = sharedFileUtils->isFileExist(path);
	if (!isExist) {
		log("NotesList.sqlite3 doesn't exist.");
		return -1;
	}

	sqlite3* db= NULL;
	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		char *err;
		string createSQL = "CREATE TABLE IF NOT EXISTS Note (cdate TEXT PRIMARY KEY, content TEXT)";
		if (sqlite3_exec(db,createSQL.c_str(),NULL,NULL,&err) != SQLITE_OK) {
			sqlite3_close(db);
			CCASSERT(false, "Create table failure.");
		}
		sqlite3_close(db);
	}

	return 0;
}

//插入Note方法
int NoteDAO::create(string pDate, string pContent)
{
	//初始化数据库
	initDB();

	sqlite3* db= NULL;

	string path = dbDirectoryFile();

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		string sqlStr = "INSERT OR REPLACE INTO note (cdate, content) VALUES (?,?)";
		sqlite3_stmt *statement;
		//预处理过程
		if (sqlite3_prepare_v2(db, sqlStr.c_str(), -1, &statement, NULL) == SQLITE_OK) {
			//绑定参数开始
			sqlite3_bind_text(statement, 1, pDate.c_str(), -1, NULL);
			sqlite3_bind_text(statement, 2, pContent.c_str(), -1, NULL);

			//执行插入
			if (sqlite3_step(statement) != SQLITE_DONE) {
				CCASSERT(false, "Insert Data failure.");
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return 0;
}

//删除Note方法
int NoteDAO::remove(string pDate)
{
	//初始化数据库
	initDB();

	sqlite3* db= NULL;

	string path = dbDirectoryFile();

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		string sqlStr = "DELETE  from note where cdate =?";
		sqlite3_stmt *statement;
		//预处理过程
		if (sqlite3_prepare_v2(db, sqlStr.c_str(), -1, &statement, NULL) == SQLITE_OK) {
			//绑定参数开始
			sqlite3_bind_text(statement, 1, pDate.c_str(), -1, NULL);
			//执行删除
			if (sqlite3_step(statement) != SQLITE_DONE) {
				CCASSERT(false, "Delete Data failure.");
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return 0;
}

//修改Note方法
int NoteDAO::modify(string pDate, string pContent)
{
	//初始化数据库
	initDB();

	sqlite3* db= NULL;

	string path = dbDirectoryFile();

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		string sqlStr = "UPDATE note set content=? where cdate =?";
		sqlite3_stmt *statement;
		//预处理过程
		if (sqlite3_prepare_v2(db, sqlStr.c_str(), -1, &statement, NULL) == SQLITE_OK) {
			//绑定参数开始
			sqlite3_bind_text(statement, 1, pContent.c_str(), -1, NULL);			
			sqlite3_bind_text(statement, 2, pDate.c_str(), -1, NULL);

			//执行修改数据
			if (sqlite3_step(statement) != SQLITE_DONE) {
				CCASSERT(false, "Upate Data failure.");
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return 0;
}

//查询所有数据方法
ValueVector NoteDAO::findAll()
{
	//初始化数据库
	initDB();
	sqlite3* db= NULL;

	string path = dbDirectoryFile();
	ValueVector listData;

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		string qsql = "SELECT cdate,content FROM Note";
		sqlite3_stmt *statement;
		//预处理过程
		if (sqlite3_prepare_v2(db, qsql.c_str(), -1, &statement, NULL) == SQLITE_OK) {
			//执行
			while (sqlite3_step(statement) == SQLITE_ROW) {

				char *cdate = (char *)sqlite3_column_text(statement, 0);
				char *content = (char *)sqlite3_column_text(statement, 1);

				ValueMap dict ;
				dict["date"] = Value(cdate);
				dict["content"] = Value(content);

				listData.push_back(Value(dict));
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return listData;
}


//按照主键查询数据方法
ValueMap NoteDAO::findById(string pDate)
{
	//初始化数据库
	initDB();
	sqlite3* db= NULL;
	ValueMap dict ;

	string path = dbDirectoryFile();

	if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
		sqlite3_close(db);
		CCASSERT(false, "DB open failure.");
	} else {
		string qsql = "SELECT cdate,content FROM Note where cdate =?";
		sqlite3_stmt *statement;
		//预处理过程
		if (sqlite3_prepare_v2(db, qsql.c_str(), -1, &statement, NULL) == SQLITE_OK) {

			//绑定参数开始
			sqlite3_bind_text(statement, 1, pDate.c_str(), -1, NULL);

			//执行
			if (sqlite3_step(statement) == SQLITE_ROW) {

				char *cdate = (char *)sqlite3_column_text(statement, 0);
				char *content = (char *)sqlite3_column_text(statement, 1);

				dict["date"] = Value(cdate);
				dict["content"] = Value(content);
			}
		}
		sqlite3_finalize(statement);
		sqlite3_close(db);
	}
	return dict;
}
