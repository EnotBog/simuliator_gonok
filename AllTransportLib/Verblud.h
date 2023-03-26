#pragma once
#include "Earth_Transport.h"
class  Verblud: protected Earth_Transport
{
public:
    ALLTRANSPORTLIB_API  Verblud();
    ALLTRANSPORTLIB_API  double metod_finish(const int distance) override;
   
                        
protected:
    ALLTRANSPORTLIB_API  Verblud(std::string name, int speed, int stamina);

    ALLTRANSPORTLIB_API  double metod_relax(const int distance, const int times); //метод вычисления общего времени остановок
  
};

