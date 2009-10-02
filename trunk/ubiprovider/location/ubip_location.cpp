#include <string>
#include <map>

#include <boost/thread.hpp>

#include "Provider.hpp"
#include "Literal.hpp"
#include "Tools.hpp"


static boost::thread*                   _thread;
static std::map<std::string, CLiteral>* _contextsInfo;


extern "C" {


static std::string _get_symbolic_location();
static void _run();


int ubip_init(std::map<std::string, CLiteral>* contextsInfo)
{
	_contextsInfo = contextsInfo;

	return UBIP_OK;
}


int ubip_finish()
{
	return UBIP_OK;
}


int ubip_run()
{
	_thread = new boost::thread(boost::bind(&_run));

	return UBIP_OK;
}


static void _run()
{
	while(true) {
		(*_contextsInfo)["location.symbolic"] = CLiteral(_get_symbolic_location());
		sleep(60);
	}
}


static std::string _get_symbolic_location()
{
	static int counter = 0;
	return std::string("at home ") + itoa(++counter);
}

}
