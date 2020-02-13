#ifndef InvalidOperation_hpp
#define InvalidOperation_hpp

class InvalidOperation : public std::exception {
private:
  std::string message;
public:
  InvalidOperation ():message("\tInvalid Operation"){}
  virtual const char * what() const throw(){ return message.c_str(); }
};

#endif /* InvalidOperation_hpp */
