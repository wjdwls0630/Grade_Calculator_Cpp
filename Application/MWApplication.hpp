#ifndef MWApplication_hpp
#define MWApplication_hpp
#include "./BaseApplication.hpp"

class MWApplication : public BaseApplication{
private:
  int Mid1Count;
  int Mid2Count;
  int FinalCount;
  int QuizCount;
public:
  MWApplication ();
  virtual ~MWApplication(){}
  void LoadFile(Myifstream &ifs) override;
  void MakeScore(const std::string &FileName, Score *& tempScore, const int &prob1, const int &prob2, const int &prob3);
};
MWApplication::MWApplication() :
BaseApplication("mw_midterm1_score.txt","mw_midterm2_score.txt","mw_final_score.txt","mw_quiz_score.txt"),
Mid1Count(3),Mid2Count(3),FinalCount(3),QuizCount(3){}
void MWApplication::LoadFile(Myifstream &ifs){
  std::string inID, FileName=ifs.getFileName();
  int prob1=0,prob2=0,prob3=0,prob4=0,count,index;
  Student tempStudent;
  Score *tempScore;
  if (FileName=="mw_midterm1_score.txt") {
    count=this->Mid1Count;
  }else if(FileName=="mw_midterm2_score.txt"){
    count=this->Mid2Count;
  }else if(FileName=="mw_final_score.txt"){
    count=this->FinalCount;
  }else if(FileName=="mw_quiz_score.txt"){
    count=this->QuizCount;
  }
  while (ifs.ReadLine(count,inID,prob1,prob2,prob3,prob4)) {
    tempStudent.SetID(inID);
    index=this->SearchIndex(tempStudent);
    if (index==-1) {
      this->MakeScore(FileName,tempScore,prob1,prob2,prob3);
      tempStudent.SetScore(tempScore);
      this->GetStuList().push_back(tempStudent);
    } else{
      this->MakeScore(FileName,tempScore,prob1,prob2,prob3);
      this->GetStuList()[index].SetScore(tempScore);
    }
  }
}
void MWApplication::MakeScore(const std::string &FileName, Score *& tempScore, const int &prob1, const int &prob2, const int &prob3){
  if (FileName=="mw_midterm1_score.txt") {
    tempScore= new Midterm1(prob1,prob2,prob3);
  }else if(FileName=="mw_midterm2_score.txt"){
    tempScore= new Midterm2(prob1,prob2,prob3);
  }else if(FileName=="mw_final_score.txt"){
    tempScore= new Final(prob1,prob2,prob3);
  }else if(FileName=="mw_quiz_score.txt"){
    tempScore= new Quiz(prob1,prob2,prob3);
  }
}



#endif /* MWApplication_hpp */
