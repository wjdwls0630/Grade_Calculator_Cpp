#ifndef Myfstream_hpp
#define Myfstream_hpp
#include <fstream>

class Myfstream : public std::fstream {
private:
  std::string filename;
public:
  Myfstream (const std::string &fName);
  virtual ~Myfstream ();
  std::string getFileName() const;
  virtual void close()=0;
};

Myfstream::Myfstream (const std::string &fName):filename(fName){}
Myfstream::~Myfstream(){}

std::string Myfstream::getFileName() const{ return this->filename;}



#endif /* Myfstream_hpp */
