#include <string>
#include <map>
#include <fstream>
#include <iostream>


#include <boost/thread.hpp>
#include<boost/tokenizer.hpp>

#include "Provider.hpp"
#include "Literal.hpp"
#include "Tools.hpp"


struct sphysical_location {
	int latitude, longitude, altitude;
	sphysical_location() {
		latitude = longitude = altitude = -1;
	}
	sphysical_location(int x, int y, int z) {
		latitude = x;
		longitude = y;
		altitude = z;
	}
};

static boost::thread*                     _thread;
static std::map<std::string, CLiteral>*   _contextsInfo;
static std::map<std::string, sphysical_location> _users_locations;
static int                                _current_time;


extern "C" {


static sphysical_location _get_symbolic_location();
static void _run();


static bool ubip_read_conf_file(std::string filename)
{
	std::ifstream in(filename.c_str());

	if (in.is_open() == false) {
		std::cout << "Error reading " << filename << std::endl;
		return false;
	}

	std::string line;

	while(getline(in, line)) {
		std::string::size_type i = line.find_first_not_of ( " \t\n\v" );

		if (i != std::string::npos && line[i] == '#')
			continue;

		// Process non-comment line
		boost::tokenizer<> token_list(line);
/*		for(boost::tokenizer<>::iterator beg=token_list.begin(); beg!=token_list.end();++beg) {
 			std::cout << *beg << "\n";
		}*/
		boost::tokenizer<>::iterator token=token_list.begin();
		std::string step      = *token++;
		std::string identity  = *token++;
		std::string latitude  = *token++;
		std::string longitude = *token++;
		std::string altitude  = *token++;

		_users_locations[step + ":" + identity] = sphysical_location(atoi(latitude.c_str()),atoi(longitude.c_str()),atoi(altitude.c_str()));
	}

	return true;
}

int ubip_init(std::map<std::string, CLiteral>* contextsInfo)
{
	_contextsInfo = contextsInfo;

	ubip_read_conf_file("plocation.data");

// 	_users_locations["1:alex" ] = sphysical_location(1,2,0);
// 	_users_locations["2:alex" ] = sphysical_location(4,5,0);
// 	_users_locations["3:alex" ] = sphysical_location(10,18,0);
// 	_users_locations["4:alex" ] = sphysical_location(14,8,0);

	_current_time = 0;

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
	// A simulacao so comeca apos termos a identificacao do usuario
	while(true) {
		sleep(5);
		if ((*_contextsInfo)["identity.name"].getText() != "") {
// 			std::cout << "identity.name=" << (*_contextsInfo)["identity.name"].getText() << std::endl;
			break;
		}
	}

	while(true) {
		sphysical_location location = _get_symbolic_location();
		if (location.latitude != -1) {
			(*_contextsInfo)["location.latitude" ] = CLiteral(location.latitude);
			(*_contextsInfo)["location.longitude"] = CLiteral(location.longitude);
			(*_contextsInfo)["location.altitude" ] = CLiteral(location.altitude);
// 			(*_contextsInfo)["location.latitude" ] = CLiteral(itoa(location.latitude));
// 			(*_contextsInfo)["location.longitude"] = CLiteral(itoa(location.longitude));
// 			(*_contextsInfo)["location.altitude" ] = CLiteral(itoa(location.altitude));
		}
		sleep(15);
	}
}


static sphysical_location _get_symbolic_location()
{
	_current_time++;
	std::string key_map = std::string(itoa(_current_time)) + std::string(":") + (*_contextsInfo)["identity.name"].getText();
	if (_users_locations.find(key_map) != _users_locations.end()) {
		return _users_locations[key_map];
	} else {
		return sphysical_location(-1,-1,-1);
	}
}

}
