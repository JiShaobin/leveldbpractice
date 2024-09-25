#include <iostream>
#include "leveldb/db.h"

using namespace std;

int main() {
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
    if (!status.ok()) {
        cerr << "Can't open database: " << status.ToString() << endl;
        return 1;
    }

   // 写入数据
    status = db->Put(leveldb::WriteOptions(), "key", "value");
    if (!status.ok()) {
        cerr << "Write failed: " << status.ToString() << endl;
        return 1;
    }

    // 读取数据
    string value;
    status = db->Get(leveldb::ReadOptions(), "key", &value);
    if (status.ok()) {
        cout << "key: " << "value: " << value << endl;
    } else {
        cerr << "Read failed: " << status.ToString() << endl;
        return 1;
    }

    // 删除数据
    status = db->Delete(leveldb::WriteOptions(), "key");
    if (!status.ok()) {
        cerr << "Delete failed: " << status.ToString() << endl;
        return 1;
    }

    // 关闭数据库
    delete db;
    return 0;
}
