#pragma once

#include <cmath>

#include "mt_profile.h"

class MT : public MT_Profile {
double time_;
public:
//MT();
MT(const MT_Profile prf);
static MT* MakeMT(int ind); //FACTORY METHOD
virtual void set_time(double dist, double time = 0);
double get_speed(){ return speed_; }; // INLINE
double get_time_before_rest(){ return time_before_rest_; }; //INLINE
double get_time(){ return time_; }; //INLINE
std::string get_name(){ return name_; }; //INLINE
};