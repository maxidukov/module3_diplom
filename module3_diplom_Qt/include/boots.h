#pragma once
#include "ground_mt.h"

class Boots : public Ground_MT{
public:
Boots();
void set_time(double dist, double time) override;
};