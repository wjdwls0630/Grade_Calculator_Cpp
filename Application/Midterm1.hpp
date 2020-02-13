#ifndef Midterm1_hpp
#define Midterm1_hpp
#include "Score.hpp"
class Midterm1 : public Score {

public:
  Midterm1 (const int &prob1, const int &prob2, const int &prob3);
  std::string WhatIs() override;
  void printInfo() override;
};
Midterm1::Midterm1 (const int &prob1, const int &prob2, const int &prob3):
Score(prob1,prob2,prob3){}
std::string Midterm1::WhatIs(){ return "Mid1" ; }
void Midterm1::printInfo(){
  std::cout << '\n' << '\n';
  std::cout << "\t----  MidTerm1 Test --------------------" << '\n';
  Score::printInfo();
  std::cout << "\t|        Total Score : "<<this->GetTotal()<<"              |" << '\n';
  std::cout << "\t----------------------------------------" << '\n';
}
#endif /* Score_hpp */
