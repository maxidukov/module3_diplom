#include "race_air.h"

Race_Air::Race_Air(double dist) : Race(2, dist){}
std::string Race_Air::get_title(){ //override
  return race_titles[air];
}
bool Race_Air::check_MT_type(int val){ //override
  return MT_Profile_list[val-1].get_mt_type() == air;
}