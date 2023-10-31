#pragma once
#include "air_mt.h"

class Broom : public Air_MT{
public:
Broom();
void set_quot(double dist, double quot) override;
};
