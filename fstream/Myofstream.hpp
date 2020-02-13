#ifndef Myofstream_hpp
#define Myofstream_hpp
#include "../Error/FileNotFoundException.hpp"
class Myofstream : public Myfstream{
private:
  std::ofstream ofs;
public:
  Myofstream (const std::string &fName);
  virtual ~Myofstream ();
  void close() ;
};

Myofstream::Myofstream (const std::string &fName):Myfstream(fName){
  this->ofs.open(fName);
  if(ofs.fail()){
    throw FileNotFoundException(this->getFileName());
  }
}
Myofstream::~Myofstream (){this->ofs.close();}

void Myofstream::close() {this->ofs.close();}
#endif /* Myofstream_hpp */
