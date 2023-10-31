#include <iostream>
#include <string>
//#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

//#include "mt_profile.h"
//#include "mt.h"
//#include "air_mt.h"
#include "include/eagle.h"
#include "include/broom.h"
#include "include/carpet.h"
//#include "include/ground_mt.h"
#include "include/camel.h"
#include "include/camel_fast.h"
#include "include/boots.h"
#include "include/centaurus.h"

//#include "include/race.h"
#include "include/race_air.h"
#include "include/race_ground.h"

inline void clear_stdin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
  std::cout<<"Добро пожаловать в гоночный симулятор\n";
  int quit{0};
  do{
  for(int i{};i<3;i++){
    std::cout<<i+1<<". "<<race_titles[i]<<"\n";
  }
  int race_ind;
  double dump;
  Race* prace;
  do{
    std::cout<<"Выберите тип гонки: ";
    std::cin>>race_ind;
    if(race_ind != 1 && race_ind != 2 && race_ind != 3 || std::cin.fail()){std::cout<<"Ошибка: вы ввели неверный тип гонки!\n";};
    clear_stdin();
  }while(race_ind != 1 && race_ind != 2 && race_ind != 3 || std::cin.fail());
  double dist;
  do{
    std::cout<<"\nУкажите длину дистанции (должна быть положительна): ";
    std::cin>>dist;
    if(dist<=0){std::cout<<"Ошибка: вы ввели неподходящую дистанцию!\n";};
    clear_stdin();
  }while(dist<=0 || std::cin.fail());
  prace = prace->MakeRace(race_ind, dist);
  std::vector<int> inds;
  int val;
  std::cout<<"\nДолжно быть зарегистрировано хотя бы 2 транспортных средства\n";
  int choice;
  do{
       std::cout<<"1. Зарегистрировать транспорт\nВыбрать действие: ";
       std::cin>>choice;
       clear_stdin();
       std::cout<<"\n";
  }while(choice!=1||std::cin.fail());
  do{
    std::cout<<prace->get_title()<<". Расстояние: "<<prace->get_dist()<<" км\n";
    //std::cout<<"Размер: "<<race.get_size()<<"\n";
    if(prace->get_size()){
      int sz_temp = prace->get_size();
      std::cout<<"Зарегистрированные транспортные средства: ";
      for(int i{};i<sz_temp;i++){
        std::cout<<prace->get_mt_name(i);
        if(i<sz_temp-1){
          std::cout<<", ";
        }else{
          std::cout<<"\n";
        }
      }
    }
    for(int i{};i<7;i++){
      std::cout<<i+1<<". "<<MT_Profile_list[i].get_name()<<"\n";
    }
    std::cout<<"0. Закончить регистрацию\n";
    std::cout<<"Выберите транспорт или ноль для окончания процесса регистрации: ";
    if(std::cin>>val){
      std::cout<<"\n";
      if(!val){
        clear_stdin();
        if(inds.size()<2){
          std::cout<<"Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
          int choice;
          do{
               std::cout<<"1. Зарегистрировать транспорт\nВыбрать действие: ";
               std::cin>>choice;
               clear_stdin();
          }while(choice!=1||std::cin.fail());
          continue;
        }else{
          int choice;
          do{
            std::cout<<"1. Зарегистрировать транспорт\n2. Начать гонку\nВыберите действие: ";
             std::cin>>choice;
             clear_stdin();
          }while(choice!=1 && choice != 2||std::cin.fail());
          //std::cout<<choice<<"\n";
          if(choice == 1) continue;
          else break;
        }
      }
      if(std::find(inds.begin(),inds.end(),val)!=inds.end()){
        std::cout<<MT_Profile_list[val-1].get_name()<<" уже зарегистрирован!\n";
        continue;
      }
      //if(race_ind<3){
      if(!prace->check_MT_type(val)){
           std::cout<<"Попытка зарегистрировать неправильный тип транспортного средства!\n";
           continue;
      }
      //}
      if(val<0||val>7){
        std::cout<<"Ошибка: вы ввели неверный номер!\n";
        continue;
      };
      prace->add_mts(MT::MakeMT(val-1));
      std::cout<<MT_Profile_list[val-1].get_name()<<" успешно зарегистрирован!\n";
      inds.push_back(val);
    }else{
      clear_stdin();
    }
  }while(1);

  prace->set_times();
  prace->sort_pmts();
  std::cout<<"\nРезультаты гонки:\n";
  for(int i{};i<prace->get_size();i++){
    std::cout<<i+1<<". "<<prace->get_mt_name(i)<<". Время: "<<prace->get_mt_time(i)<<"\n";
  }
  delete prace;
  std::cout<<"\n1. Провести еще одну гонку\n2. Выйти\n";
  std::cin>>quit;
  clear_stdin();
  }while(!--quit);
}
