#include <iostream>
#include "./Application/MWApplication.hpp"
#include "./Application/TTApplication.hpp"
#include "./Error/InvalidOperation.hpp"

//Caution : Don't Move hpp files
/*
If You need to modify
1) If you want to modify your score, you can modify it in xx_xxx_score.txt
2) If you want to modify Test Problem count(Limit 4 Problem),
   you can modify XXXCount(private member initialize) in MWApplication or TTApplication
3) If your Problem 4 Score is 0, it is calculated, but it isn't printed in console
*/

//Just Run main.cpp



int main() {
  bool done=false;
  int choice;
  BaseApplication * App;
  while (!done) {
    try{
      std::cout << "Choose MW(Monday), TT(Tuesday) ( (1)MW  (2)TT (0)Exit ) : ";
      std::cin >> choice;
      switch (choice) {
        case 1:
        App=new MWApplication();
        break;
        case 2:
        App=new TTApplication();
        break;
        case 0:
        return 0;
        default:
        throw InvalidOperation();
      }
      App->Run();
      done=true;
    } catch(std::exception &ex){
      std::cout << ex.what() << '\n';
      continue;
    }
  }

  return 0;
}
