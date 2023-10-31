#include "mt_profile.h"

MT_Profile::MT_Profile(MT_type mt_type, MT_kind mt_kind, std::string name, double speed, double time_before_rest):mt_type_{mt_type},mt_kind_(mt_kind),name_(name),speed_(speed),time_before_rest_(time_before_rest){}

MT_Profile MT_Profile_list[] = {
{ground,boots,"Ботинки-вездеходы",6,60}, {air,broom,"Метла",20}, 
   {ground,camel,"Верблюд",10,30}, {ground,cntrs,"Кентавр",15,8},{air,eagle,"Орёл",8},
   {ground,camel_fast,"Верблюд-быстроход",40,10},{air,carpet,"Ковёр-самолёт",10}
};