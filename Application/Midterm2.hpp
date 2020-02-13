#ifndef Midterm2_hpp
#define Midterm2_hpp
#include "Score.hpp"
class Midterm2 : public Score {
public:
  Midterm2 (const int &prob1, const int &prob2, const int &prob3,const int&prob4=0);
  std::string WhatIs() override;
  void printInfo() override;
};
Midterm2::Midterm2 (const int &prob1, const int &prob2, const int &prob3,const int&prob4):
Score(prob1,prob2,prob3,prob4){}
std::string Midterm2::WhatIs(){ return "Mid2" ; }
void Midterm2::printInfo(){
  std::cout << "\t----  MidTerm2 Test --------------------" << '\n';
  Score::printInfo();
  if (this->GetProb4()!=0) {
    std::cout << "\t|        Problem 4 Score : "<<this->GetProb4()<<"           |" << '\n';
  }
  std::cout << "\t|        Total Score : "<<this->GetTotal()<<"              |" << '\n';
  std::cout << "\t----------------------------------------" << '\n';
}
#endif /* Midterm2_hpp */
