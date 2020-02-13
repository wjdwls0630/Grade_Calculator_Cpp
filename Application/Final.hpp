#ifndef Final_hpp
#define Final_hpp
#include "Score.hpp"
class Final : public Score {
public:
  Final (const int &prob1, const int &prob2, const int &prob3,const int &prob4=0);
  std::string WhatIs() override;
  void printInfo() override;
};
Final::Final (const int &prob1, const int &prob2, const int &prob3,const int &prob4):
Score(prob1,prob2,prob3,prob4){}
std::string Final::WhatIs(){ return "Final" ; }
void Final::printInfo(){
  std::cout << "\t----  Final Test -----------------------" << '\n';
  Score::printInfo();
  if (this->GetProb4()!=0) {
    std::cout << "\t|        Problem 4 Score : "<<this->GetProb4()<<"           |" << '\n';
  }
  std::cout << "\t|        Total Score : "<<this->GetTotal()<<"              |" << '\n';
  std::cout << "\t----------------------------------------" << '\n';
}
#endif /* Midterm2_hpp */
