#pragma once
#include "race.h"

class Race_Ground : public Race{
  public:
  Race_Ground(double dist);
  std::string get_title() override;
  bool check_MT_type(int val) override;
};