#pragma once
#include "Air_Transport.h"
class  Metla : protected Air_Transport
{
public:
    ALLTRANSPORTLIB_API  Metla();

    ALLTRANSPORTLIB_API  double metod_finish(const int distance) override;



protected:
    ALLTRANSPORTLIB_API  Metla(std::string name, int speed);
      
    ALLTRANSPORTLIB_API  double metod_sokrashenia(const int distance);
};

