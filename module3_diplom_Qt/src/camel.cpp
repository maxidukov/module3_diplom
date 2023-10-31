#include "camel.h"

Camel::Camel() : Ground_MT(MT_Profile_list[2]){}
void Camel::set_time(double dist, double time){ //override, time unused
  int pause_num = get_pause_num(dist);
MT::set_time(dist, dist/get_speed() + bool(pause_num)*5+(pause_num-1)*8);
}