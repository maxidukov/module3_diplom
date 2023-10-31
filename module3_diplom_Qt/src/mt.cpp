#include "mt.h"

#include "eagle.h"
#include "broom.h"
#include "carpet.h"
#include "camel.h"
#include "camel_fast.h"
#include "boots.h"
#include "centaurus.h"

//MT::MT(){}
MT::MT(const MT_Profile prf): MT_Profile{prf}{}
MT* MT::MakeMT(int ind){ //FACTORY METHOD, static
switch(ind){
  case 0: return new Boots();break;
  case 1: return new Broom();break;
  case 2: return new Camel();break;
  case 3: return new Centaurus();break;
  case 4: return new Eagle();break;
  case 5: return new Camel_fast();break;
  case 6: return new Carpet();break;
  default: return nullptr; break;
}
}
void MT::set_time(double dist, double time){ // virtual, default time 0, else dist unused
  time_ = time ? time : dist/get_speed();
}