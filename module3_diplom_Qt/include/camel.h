#pragma once
#include "ground_mt.h"

class Camel : public Ground_MT{
public:
Camel();
void set_time(double dist, double time) override;
};