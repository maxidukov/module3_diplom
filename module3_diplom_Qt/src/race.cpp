#include "race.h"
#include "race_air.h"
#include "race_ground.h"

Race::Race(){};
Race::Race(int race_ind, double dist):
 race_ind_(race_ind),dist_(dist){}
Race* Race::MakeRace(int race_ind, double dist){ //FACTORY METHOD, static
  switch(race_ind){
    case 1: return new Race_Ground(dist);break;
    case 2: return new Race_Air(dist);break;
    case 3: return new Race(race_ind, dist);break;
    default: return nullptr; break;
  }
}
void Race::add_mts(MT *pmt){
  pmts_.push_back(pmt);
  set_sz();
}
void Race::set_sz(){
  sz_ = pmts_.size();
}
void Race::set_pmts(std::vector<MT*> pmts){
  pmts_ = pmts;
}
void Race::set_times(){
  //times_.resize(sz_);
  for(int i{};i<sz_;i++){
    pmts_[i]->set_time(dist_);
  }
  //return times_;
}
void Race::sort_pmts(){
  set_sz();
  set_times();
  bool unsorted = true;
  while(unsorted){
     unsorted = false;
     for(int i{};i<sz_-1;i++){
       for(int j{};j<sz_;j++){
          if(pmts_[i]->get_time()>pmts_[i+1]->get_time()){
             MT* temp = pmts_[i];
             pmts_[i] = pmts_[i+1];
             pmts_[i+1] = temp;
             unsorted = true;
          }
       }
     }
  }
}
std::string Race::get_mt_name(int ind){
  return pmts_[ind]->get_name();
}
double Race::get_mt_time(int ind){
  return pmts_[ind]->get_time();
}
std::string Race::get_title(){ //virtual
  return race_titles[race_ind_-1];
}
bool Race::check_MT_type(int val){ //virtual
  return race_ind_ > 2 ? true : MT_Profile_list[val-1].get_mt_type() == race_ind_-1;
}
Race::~Race(){
  if(!pmts_.empty()){
    set_sz();
    for(int i{};i<sz_;i++){
      delete pmts_[i];
    }
  }
}