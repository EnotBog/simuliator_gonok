#pragma once
#include <string>

#ifdef ALLTRANSPORTLIB_EXPORTS
#define ALLTRANSPORTLIB_API __declspec(dllexport)
#else
#define ALLTRANSPORTLIB_API __declspec(dllimport)
#endif


class  Transport
{
public:
	
	ALLTRANSPORTLIB_API	Transport();
	
protected:
 	std::string  name_transport;
	std::string type_transport;
	int speed_transport;

	ALLTRANSPORTLIB_API	Transport(std::string type, std::string name, int speed);
	

};

