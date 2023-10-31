#include "ground_mt.h"

Ground_MT::Ground_MT(MT_Profile prf) : MT(prf){}
int Ground_MT::get_pause_num(double dist){
  return std::ceil(dist/get_speed()/get_time_before_rest()-1);
}
void Ground_MT::set_time(double dist, double time){ //override, time unused
  MT::set_time(dist, dist/get_speed() + get_pause_num(dist)*2);
}