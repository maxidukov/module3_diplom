#include "carpet.h"

Carpet::Carpet() : Air_MT(MT_Profile_list[6]){}
void Carpet::set_quot(double dist, double quot){ //override, quot unused
  double new_quot = 0.05; 
  if(dist<1000){
    new_quot = 0.0;
  }else if(dist<5000){
    new_quot = 0.03;
  }else if(dist<10000){
    new_quot = 0.1;
  }
  Air_MT::set_quot(dist,new_quot);
}