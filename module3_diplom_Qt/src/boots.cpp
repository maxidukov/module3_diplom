#include "boots.h"

Boots::Boots() : Ground_MT(MT_Profile_list[0]){}
void Boots::set_time(double dist, double time){ //override, time unused
  int pause_num = get_pause_num(dist);
  MT::set_time(dist, dist/get_speed() + bool(pause_num)*10+(pause_num-1)*5);
}