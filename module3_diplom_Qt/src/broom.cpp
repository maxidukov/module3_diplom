#include "broom.h"

Broom::Broom() : Air_MT(MT_Profile_list[1]){}
void Broom::set_quot(double dist, double quot){ //override, quot unused
  Air_MT::set_quot(dist,0.01*std::ceil(dist/1000-1));
}