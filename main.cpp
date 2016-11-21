#include "main.h"

int main(){
  DataBase db;
  Value v;
  v.setPassword("seljsj");
  v.setUsername("tanaka");
  if(db.insertValue(v)==0)std::cout<<"ok\n";
  return 0;
}
