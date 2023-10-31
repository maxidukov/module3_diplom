#include "race_ground.h"

Race_Ground::Race_Ground(double dist) : Race(1, dist){}
std::string Race_Ground::get_title(){ //override
  return race_titles[ground];
}
bool Race_Ground::check_MT_type(int val){ //override
  return MT_Profile_list[val-1].get_mt_type() == ground;
}