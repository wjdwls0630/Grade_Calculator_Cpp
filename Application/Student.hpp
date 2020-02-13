#ifndef Student_hpp
#define Student_hpp
#include <vector>
#include <algorithm>
#include "Midterm1.hpp"

class Student {
private:
  std::string ID;
  std::vector<Score*> Score_List;
  int Rank;
  float PropTotal;
public:
  Student();
  Student (const std::string &id);
  virtual ~Student(){this->Score_List.clear();}
  void SetID(const std::string &inID);
  std::string GetID() const;
  void SetScore(Score* score);
  Score * GetScore(const std::string &testname);
  std::string ShowScore(const int & num);
  void ShowAll();
  void CalculatePropTotal();
  float GetPropTotal() const;
  void SetRank(const int&rank);
  int GetRank() const;
  Student & operator =(const Student &student);
  bool operator ==(const std::string &inID) const;
  bool operator ==(const Student &inStu) const;
  bool operator <(const Student &inStu) const;
  bool operator >(const Student &inStu) const;
};
Student::Student(){this->Score_List.resize(4);}
Student::Student (const std::string &id) : ID(id){this->Score_List.resize(4);}
void Student::SetID(const std::string &inID){ this->ID=inID; }
std::string Student::GetID() const { return this->ID; }
void Student::SetScore(Score* score){
  std::string testname=score->WhatIs();
  if (testname=="Mid1") {
    this->Score_List[0]=score;
  } else if(testname=="Mid2"){
    this->Score_List[1]=score;
  } else if(testname=="Final"){
    this->Score_List[2]=score;
  } else if(testname=="Quiz"){
    this->Score_List[3]=score;
  }
}
Score * Student::GetScore(const std::string &testname){
  Score * result;
  if (testname=="Mid1") {
    result= this->Score_List[0];
  } else if(testname=="Mid2"){
    result= this->Score_List[1];
  } else if(testname=="Final"){
    result= this->Score_List[2];
  } else if(testname=="Quiz"){
    result= this->Score_List[3];
  } else if(testname=="Total"){
    result= this->Score_List[4];
  }
  return result;
}
std::string Student::ShowScore(const int & num) {
  this->Score_List[num-1]->printInfo();
  return this->Score_List[num-1]->WhatIs();
}

void Student::ShowAll(){
  std::for_each(std::begin(this->Score_List),std::end(this->Score_List),[](Score * x)->void{x->printInfo();});
  this->CalculatePropTotal();
  std::cout << "\t{ Mid1 : 25%  Mid2 : 25%  Final : 25%  Quiz : 30% }" << '\n';
  std::cout << "\tPropTotal Score : " <<this->PropTotal <<'\n';
}
void Student::CalculatePropTotal(){
  if(this->Score_List.size()!=0){
    for (int i = 0; i < this->Score_List.size(); i++) {
      if (this->Score_List[i]->WhatIs()=="Quiz") {
        this->PropTotal+=this->Score_List[i]->GetTotal()*0.3;
      } else{
        this->PropTotal+=this->Score_List[i]->GetTotal()*0.25;
      }
    }
  } else{
    std::cout << "\tNo data in Score_List" << '\n';
  }
}
float Student::GetPropTotal() const{ return this->PropTotal; }
void Student::SetRank(const int&rank){ this->Rank=rank;}
int Student::GetRank() const{ return this->Rank;}

Student & Student::operator =(const Student &student){
  this->ID=student.ID;
  this->Score_List.resize(student.Score_List.size());
  for (int i = 0; i < this->Score_List.size(); i++) {
    this->Score_List[i]=student.Score_List[i];
  }
  return *this;
}

bool Student::operator ==(const std::string &inID) const{ return this->ID==inID; }
bool Student::operator ==(const Student &inStu) const{ return this->ID==inStu.ID; }
bool Student::operator <(const Student &inStu) const{ return this->ID<inStu.ID; }
bool Student::operator >(const Student &inStu) const{ return this->ID>inStu.ID; }

#endif /* Student_hpp */
