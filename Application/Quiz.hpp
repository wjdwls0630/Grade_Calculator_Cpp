#ifndef Quiz_hpp
#define Quiz_hpp
#include "Score.hpp"
class Quiz : public Score {

public:
  Quiz (const int &prob1, const int &prob2, const int &prob3);
  std::string WhatIs() override;
  void printInfo() override;
};
Quiz::Quiz (const int &prob1, const int &prob2, const int &prob3):
Score(prob1,prob2,prob3){}
std::string Quiz::WhatIs(){ return "Quiz" ; }
void Quiz::printInfo(){
  std::cout << "\t----  Quiz -----------------------------" << '\n';
  Score::printInfo();
  std::cout << "\t|        Total Score : "<<this->GetTotal()<<"              |" << '\n';
  std::cout << "\t----------------------------------------" << '\n';
}
#endif /* Quiz_hpp */
