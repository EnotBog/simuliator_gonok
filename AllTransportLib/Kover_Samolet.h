#pragma once
#include "Air_Transport.h"
class  Kover_Samolet :   protected Air_Transport
{

public:
    ALLTRANSPORTLIB_API Kover_Samolet();

    ALLTRANSPORTLIB_API double metod_finish(const int distance) override;

protected:
    ALLTRANSPORTLIB_API  Kover_Samolet(std::string name, int speed);

    ALLTRANSPORTLIB_API double metod_sokrashenia(const int distance);
};

