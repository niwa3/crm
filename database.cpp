#include "database.h"

typedef std::string VALUEERR;

//===============class Value================
Value::Value(){};

std::string Value::getPassword(){
  return Value::password;
}

std::string Value::getUsername(){
  return Value::username;
}

void Value::setPassword(std::string pass){
  Value::password=pass;
}

void Value::setUsername(std::string name){
  Value::username=name;
}
//==========================================

//=============class DataBase===============
DataBase::DataBase(){
};

DataBase::~DataBase(){
};

int DataBase::insertValue(Value v) try{
  if(v.getUsername().size()==0){
    VALUEERR err = "no name.";
    throw err;
  }
  try{
    pqxx::connection conn("dbname=test user=testuser password=testpas");
    pqxx::work T(conn);
    std::cout<<v.getPassword()<<v.getUsername()<<std::endl;

    pqxx::result r=T.exec(
        "SELECT * "
        "FROM usertable "
        "WHERE name =" +T.quote(v.getUsername()));
    
    if(r.size() != 0){
      std::cerr<<v.getUsername()<<" is existing."<<std::endl;
      return 1;
    }
    else{
      T.exec(
          "INSERT INTO usertable "
          "VALUES (" + T.quote(v.getUsername()) + "," + T.quote(v.getPassword()) + ");");
      T.commit();
      return 0;
    }
  }
  catch(const pqxx::sql_error& e){
    std::cerr<<e.what()<<": SQL->"<<"select id from test"<<std::endl;
  }
  catch(const pqxx::usage_error& e){
    std::cerr<<e.what()<<std::endl;
  }
  return -1;
} catch(VALUEERR e){
  std::cerr<< e <<std::endl;
  return -1;
}
//==========================================
