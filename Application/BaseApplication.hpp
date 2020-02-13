#ifndef BaseApplication_hpp
#define BaseApplication_hpp
#include <iostream>
#include <iomanip>
#include <vector>
#include "../fstream/Myifstream.hpp"
#include "../Error/InvalidOperation.hpp"
#include "./Student.hpp"
#include "./Midterm1.hpp"
#include "./Midterm2.hpp"
#include "./Final.hpp"
#include "./Quiz.hpp"
class BaseApplication {
private:
  std::vector<Student> Student_List;
  Myifstream inFile_Mid1;
  Myifstream inFile_Mid2;
  Myifstream inFile_Final;
  Myifstream inFile_Quiz;
public:
  BaseApplication (const std::string &inFile_Mid1,const std::string & inFile_Mid2,const std::string & inFile_Final,const std::string & inFile_Quiz);
  virtual ~BaseApplication(){ this->Student_List.clear();}
  void Run();
  int GetCommand();
  void LoadData();
  virtual void LoadFile(Myifstream &ifs)=0;
  int GetData(const std::string &inID, Student &student);
  int SearchIndex(const Student & inStu);
  void Sort(const std::string & standard="name");
  void ShowRank(Student &inStu,const std::string &standard);
  std::vector<Student>& GetStuList() ;
};
BaseApplication::BaseApplication(const std::string &inFile_Mid1,const std::string & inFile_Mid2,const std::string & inFile_Final,const std::string & inFile_Quiz) :
inFile_Mid1(inFile_Mid1),inFile_Mid2(inFile_Mid2),inFile_Final(inFile_Final),inFile_Quiz(inFile_Quiz){}
void BaseApplication::Run(){

  this->LoadData();

SetStudent:
  Student student;
  std::string inID;
  do {
    std::cout << "Enter your ID : ";
    std::cin >> inID;
  } while(!this->GetData(inID,student));

  std::string standard;
  int command;
  while ((command=this->GetCommand())) {
    switch (command) {
      case 1:
      standard=student.ShowScore(1);
      this->Sort(standard);
      this->ShowRank(student,standard);
      break;
      case 2:
      standard=student.ShowScore(2);
      this->Sort(standard);
      this->ShowRank(student,standard);
      break;
      case 3:
      standard=student.ShowScore(3);
      this->Sort(standard);
      this->ShowRank(student,standard);
      break;
      case 4:
      standard=student.ShowScore(4);
      this->Sort(standard);
      this->ShowRank(student,standard);
      break;
      case 5:
      student.ShowAll();
      this->Sort("all");
      this->ShowRank(student,"all");
      break;
      case 6:
      goto SetStudent;
      case 0:
      std::cout << "Exit Program..." << '\n';
      return;
    }
  }
}
int BaseApplication::GetCommand(){
  int command;
  while (1) {
    try{
      std::cout << '\n' << '\n';
      std::cout << "\t----  ID-Command ---------------------------------------------" << '\n';
      std::cout << "\t|        1.Display Midterm1                                   |" << '\n';
      std::cout << "\t|        2.Display Midterm2                                   |" << '\n';
      std::cout << "\t|        3.Display Final                                      |" << '\n';
      std::cout << "\t|        4.Display Quiz                                       |" << '\n';
      std::cout << "\t|        5.Display Total                                      |" << '\n';
      std::cout << "\t|        6.Search Other Student                               |" << '\n';
      std::cout << "\t|        0.Quit                                               |" << '\n';
      std::cout << "\t--------------------------------------------------------------" << '\n';
      std::cout << "\t  Choose a Command-- >";
      if (std::cin.fail()||!(std::cin>>command)||command<0||command>6) {
        std::cin.clear(); //clear flag
        std::cin.ignore(INT_MAX, '\n'); //empty input buffer
        throw InvalidOperation();
      } else{
        std::cin.clear(); // clear flag
        std::cin.ignore(INT_MAX, '\n'); // empty input buffer
        return command;
      }
    } catch(std::exception &ex){
     std::cout << ex.what() << '\n';
     continue;
   }
 }
}
void BaseApplication::LoadData(){
  this->LoadFile(this->inFile_Mid1);
  this->LoadFile(this->inFile_Mid2);
  this->LoadFile(this->inFile_Final);
  this->LoadFile(this->inFile_Quiz);
}

int BaseApplication::GetData(const std::string & inID, Student &student){
  for (int i = 0; i < this->Student_List.size(); i++) {
    if (this->Student_List[i]==inID) {
      student=this->Student_List[i];
      return 1;
    }
  }
  std::cout << "\tNo such Information" << '\n';
  return 0;
}
int BaseApplication::SearchIndex(const Student & inStu){
  int index=0;
  if (this->Student_List.size()==0) {
    return -1;
  }else{
    for (int i = 0; i < this->Student_List.size(); i++) {
      if (this->Student_List[i]==inStu) {
        return i;
        break;
      }
    }
    return -1;
  }
}
void BaseApplication::Sort(const std::string & standard) {
  if (standard=="name") {
    std::sort(std::begin(this->Student_List),std::end(this->Student_List));
  }else if (standard=="all") {
    int target_index;
    for (int i = 0; i < this->Student_List.size()-1; i++) {
      target_index=i;
      for (int j = i; j < this->Student_List.size(); j++) {
        if (this->Student_List[target_index].GetPropTotal()<this->Student_List[j].GetPropTotal()) {
          target_index=j;
        }
      }
      std::swap(this->Student_List[i], this->Student_List[target_index]);
    }

  } else{
    int target_index;
    for (int i = 0; i < this->Student_List.size()-1; i++) {
      target_index=i;
      for (int j = i; j < this->Student_List.size(); j++) {
        if (this->Student_List[target_index].GetScore(standard)->GetTotal()<this->Student_List[j].GetScore(standard)->GetTotal()) {
          target_index=j;
        }
      }
      std::swap(this->Student_List[i], this->Student_List[target_index]);
    }
  }
}
void BaseApplication::ShowRank(Student &inStu,const std::string &standard){
  int Rank=1;
  int count=1;
  this->Student_List[0].SetRank(Rank);
  if (standard=="all") {
    int target=this->Student_List[0].GetPropTotal();
    for (int i = 1; i < this->Student_List.size(); i++) {
      if (target!=this->Student_List[i].GetPropTotal()) {
        Rank+=count;
        count=1;
        this->Student_List[i].SetRank(Rank);
        target=this->Student_List[i].GetPropTotal();
      } else{
        count++;
        this->Student_List[i].SetRank(Rank);
      }
    }
  } else{
    int target=this->Student_List[0].GetScore(standard)->GetTotal();
    for (int i = 1; i < this->Student_List.size(); i++) {
      if (target!=this->Student_List[i].GetScore(standard)->GetTotal()) {
        Rank+=count;
        count=1;
        this->Student_List[i].SetRank(Rank);
        target=this->Student_List[i].GetScore(standard)->GetTotal();
      } else{
        count++;
        this->Student_List[i].SetRank(Rank);
      }
    }
  }
  std::for_each(std::begin(this->Student_List),std::end(this->Student_List),[&inStu,&standard](Student &x)->void{if(x==inStu){std::cout <<'\t'<<standard <<" 등수는 " <<x.GetRank() <<"등"<<'\n';}});
}

std::vector<Student>& BaseApplication::GetStuList() { return this->Student_List; }

#endif /* BaseApplication_hpp */
