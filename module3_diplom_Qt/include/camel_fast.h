#pragma once
#include "ground_mt.h"

class Camel_fast : public Ground_MT{
public:
Camel_fast();
void set_time(double dist, double time) override;
};