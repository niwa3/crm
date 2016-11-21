#include <iostream>
#include <pqxx/pqxx>

class Value{
  private:
    std::string username;
    std::string password;
  public:
    Value();
    void setUsername(std::string name);
    void setPassword(std::string pass);
    std::string getUsername();
    std::string getPassword();
    ~Value(){};
};
class DataBase{
  public:
    DataBase();
    int insertValue(Value v);
    int deleteValue(Value v);
    int selectValue(Value v, Value &v_res);
    int checkValue(Value v);
    ~DataBase();
};
