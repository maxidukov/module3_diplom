#include "air_mt.h"

Air_MT::Air_MT(MT_Profile prf) : MT(prf){}
void Air_MT::set_time(double dist, double time){ //override, time unused
  this->set_quot(dist);
  MT::set_time((1-quot_)*dist);
}
void Air_MT::set_quot(double dist, double quot){ //virtual, default quot = 0.06, dist unused
  quot_ = quot;
}