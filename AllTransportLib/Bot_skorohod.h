#pragma once
#include "Earth_Transport.h"
class  Bot_skorohod :    protected Earth_Transport
{
public:

    ALLTRANSPORTLIB_API Bot_skorohod();

    ALLTRANSPORTLIB_API  double metod_finish(const int distance) override;

protected:

    ALLTRANSPORTLIB_API  Bot_skorohod(const std::string &name, const int speed,const int stamina) ;

    ALLTRANSPORTLIB_API  int metod_relax(const int distance,const int times); //метод вычисления общего времени остановок
   
};

