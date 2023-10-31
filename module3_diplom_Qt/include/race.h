#pragma once

#include <string>
#include <cmath>
#include <vector>

#include "mt.h"

const std::vector<std::string> race_titles {
  "Гонка для наземного транспорта",
  "Гонка для воздушного транспорта",
  "Гонка для наземного и воздушного транспорта"
};

class Race{
std::vector<MT*> pmts_;
int sz_= 0;
double dist_ = 0;
int race_ind_;
public:
Race();
Race(int race_ind, double dist);
static Race* MakeRace(int race_ind, double dist); //FACTORY METHOD
void add_mts(MT *pmt);
void set_sz();
void set_pmts(std::vector<MT*> pmts);
void set_times();
void sort_pmts();
std::string get_mt_name(int ind);
double get_mt_time(int ind);
virtual std::string get_title();
virtual bool check_MT_type(int val);
int get_size(){ return sz_; }; //IN-LINE
double get_dist(){ return dist_; }; //IN-LINE
~Race();
};