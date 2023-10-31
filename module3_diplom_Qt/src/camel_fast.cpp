#include "camel_fast.h"

Camel_fast::Camel_fast() : Ground_MT(MT_Profile_list[5]){}
void Camel_fast::set_time(double dist, double time){ //override, time unused
  int pause_num = dist/get_speed()/get_time_before_rest();
  double time_new;
  if(pause_num==0){
    time_new = dist/get_speed();
  }else if(pause_num==1){
    time_new = dist/get_speed() + 5;
  }else{
    time_new = dist/get_speed() + 5 + 6.5 + (pause_num-2)*8;
  }
  MT::set_time(dist, time_new);
}