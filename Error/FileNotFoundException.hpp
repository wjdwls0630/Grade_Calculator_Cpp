#ifndef FileNotFoundException_hpp
#define FileNotFoundException_hpp
class FileNotFoundException : public std::exception {
private:
  std::string message;
public:
  FileNotFoundException (const std::string &fname):message("File \""+fname+"\" not found!"){}
  virtual const char * what() const throw(){return message.c_str();}
};

#endif /* FileNotFoundException_hpp */
