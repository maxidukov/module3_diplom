#pragma once
#include "air_mt.h"

class Carpet : public Air_MT{
public:
Carpet();
void set_quot(double dist, double quot) override;
};