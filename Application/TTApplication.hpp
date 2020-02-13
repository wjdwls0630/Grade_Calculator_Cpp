#ifndef TTApplication_hpp
#define TTApplication_hpp
#include "./BaseApplication.hpp"

class TTApplication : public BaseApplication{
private:
  int Mid1Count;
  int Mid2Count;
  int FinalCount;
  int QuizCount;
public:
  TTApplication ();
  virtual ~TTApplication(){}
  void LoadFile(Myifstream &ifs) override;
  void MakeScore(const std::string &FileName, Score *& tempScore, const int &prob1, const int &prob2, const int &prob3,const int prob4=0);
};
TTApplication::TTApplication() :
BaseApplication("tt_midterm1_score.txt","tt_midterm2_score.txt","tt_final_score.txt","tt_quiz_score.txt"),
Mid1Count(3),Mid2Count(4),FinalCount(4),QuizCount(3){}
void TTApplication::LoadFile(Myifstream &ifs){
  std::string inID, FileName=ifs.getFileName();
  int prob1=0,prob2=0,prob3=0,prob4=0,count,index;
  Student tempStudent;
  Score *tempScore;
  if (FileName=="tt_midterm1_score.txt") {
    count=this->Mid1Count;
  }else if(FileName=="tt_midterm2_score.txt"){
    count=this->Mid2Count;
  }else if(FileName=="tt_final_score.txt"){
    count=this->FinalCount;
  }else if(FileName=="tt_quiz_score.txt"){
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
void TTApplication::MakeScore(const std::string &FileName, Score *& tempScore, const int &prob1, const int &prob2, const int &prob3,const int prob4){
  if (FileName=="tt_midterm1_score.txt") {
    tempScore= new Midterm1(prob1,prob2,prob3);
  }else if(FileName=="tt_midterm2_score.txt"){
    tempScore= new Midterm2(prob1,prob2,prob3,prob4);
  }else if(FileName=="tt_final_score.txt"){
    tempScore= new Final(prob1,prob2,prob3,prob4);
  }else if(FileName=="tt_quiz_score.txt"){
    tempScore= new Quiz(prob1,prob2,prob3);
  }
}



#endif /* TTApplication_hpp */
