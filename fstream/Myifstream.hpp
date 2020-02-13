#ifndef Myifstream_hpp
#define Myifstream_hpp
#include "Myfstream.hpp"
#include "../Error/FileNotFoundException.hpp"

class Myifstream : public Myfstream{
private:
  std::ifstream ifs;
public:
  Myifstream (const std::string &fName);
  virtual ~Myifstream ();
  int ReadLine(const int& num,std::string &id,int &prob1, int &prob2, int&prob3 , int&prob4);
  void close() override ;
};


Myifstream::Myifstream (const std::string &fName):Myfstream(fName){
  this->ifs.open("./Data/"+fName);
  if(ifs.fail()){
    throw FileNotFoundException(this->getFileName());
  }
}
Myifstream::~Myifstream (){this->ifs.close();}
int Myifstream::ReadLine(const int& num,std::string &id,int &prob1, int &prob2, int&prob3, int&prob4 ){
  if (this->ifs) {
    if (num==1) {
      this->ifs>>id>>prob1;
    } else if(num==2){
      this->ifs>>id>>prob1>>prob2;
    } else if (num==3) {
      this->ifs>>id>>prob1>>prob2>>prob3;
    } else if(num==4){
      this->ifs>>id>>prob1>>prob2>>prob3>>prob4;
    }
    return 1;
  }
  return 0;
}

void Myifstream::close() {this->ifs.close();}

#endif /* Myifstream_hpp */
