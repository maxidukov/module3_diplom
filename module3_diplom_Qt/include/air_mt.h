#pragma once
#include "mt.h"

class Air_MT : public MT {
double quot_;
public:
Air_MT(MT_Profile prf);
void set_time(double dist, double time) override;
virtual void set_quot(double dist, double quot = 0.06);
};