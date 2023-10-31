#pragma once
#include "race.h"

class Race_Air : public Race{
  public:
  Race_Air(double dist);
  std::string get_title() override;
  bool check_MT_type(int val) override;
};