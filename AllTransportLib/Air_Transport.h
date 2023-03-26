#pragma once
#include "Transport.h"
class  Air_Transport :  protected Transport
{
public: 
	ALLTRANSPORTLIB_API Air_Transport();
	
	ALLTRANSPORTLIB_API virtual double metod_finish(int distance);

protected:
	ALLTRANSPORTLIB_API	Air_Transport(std::string name, int speed);
};

