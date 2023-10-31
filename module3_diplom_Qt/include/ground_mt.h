#pragma once
#include "mt.h"

class Ground_MT : public MT{
//double time_before_rest, rest_dur;
public:
Ground_MT(MT_Profile prf);
int get_pause_num(double dist);
void set_time(double dist, double time) override;
};