#pragma once
#include "Air_Transport.h"
class  Orel : protected Air_Transport
{
public:
    
    ALLTRANSPORTLIB_API  Orel();

    ALLTRANSPORTLIB_API  double metod_finish(const int distance) override;



protected:
    ALLTRANSPORTLIB_API  Orel(const std::string &name, int speed);

    ALLTRANSPORTLIB_API  double metod_sokrashenia(const int distance);
};

