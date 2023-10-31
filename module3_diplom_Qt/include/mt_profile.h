#pragma once
#include <string>

enum MT_type{ground,air};
enum MT_kind{boots,broom,camel,cntrs,eagle,camel_fast,carpet};
class MT_Profile{
   protected:
   const MT_type mt_type_;
   const MT_kind mt_kind_;
   const std::string name_;
   const double speed_;
   double time_before_rest_ = 0.0;
   public:
   MT_Profile(MT_type mt_type, MT_kind mt_kind, std::string name, double speed, double time_before_rest=0.0);
   MT_type get_mt_type(){return mt_type_;} //INLINE
   std::string get_name(){return name_;} //INLINE
};

extern MT_Profile MT_Profile_list[];