#pragma once
#include "Earth_Transport.h"
class   Verblud_fast: protected Earth_Transport
{
public:

    ALLTRANSPORTLIB_API Verblud_fast();

    ALLTRANSPORTLIB_API double metod_finish(const int distance) override;

protected:
    ALLTRANSPORTLIB_API Verblud_fast(const std::string &name,const int speed,const int stamina);

    ALLTRANSPORTLIB_API double metod_relax(const int distance, const int times); //метод вычисления общего времени остановок

};

