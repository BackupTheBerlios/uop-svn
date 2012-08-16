#include <string>
#include <map>
#include <fstream>
#include <iostream>

#include <boost/thread.hpp>
#include<boost/tokenizer.hpp>

#include "Provider.hpp"
#include "Literal.hpp"
#include "Tools.hpp"


static boost::thread*                     _thread;
static std::map<std::string, CLiteral>*   _contextsInfo;
static std::map<std::string, std::string> _users_locations;
static int                                _current_time;


extern "C" {


static std::string _get_symbolic_location();
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
		boost::tokenizer<>::iterator token=token_list.begin();
		std::string step      = *token++;
		std::string identity  = *token++;
		std::string slocation = *token++;
		while(token != token_list.end()) {
			slocation += " " + *token++;
		}

		_users_locations[step + ":" + identity] = slocation;
	}

	return true;
}


int ubip_init(std::map<std::string, CLiteral>* contextsInfo)
{
	_contextsInfo = contextsInfo;

	ubip_read_conf_file("slocation.data");

// 	_users_locations["1:alex" ] = "mini biblioteca";
// 	_users_locations["1:gracy"] = "laboratorio geral";
// 	_users_locations["1:biel" ] = "centro convivencia";
// 	_users_locations["2:alex" ] = "mobilab";
// 	_users_locations["2:gracy"] = "mobilab";
// 	_users_locations["3:alex" ] = "centro convivencia";
// 	_users_locations["3:gracy"] = "centro convivencia";

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
	// A simulacao so comeca apos termos a identificacao do usuario e location.symbolic ter o valor "start"
	while(true) {
		sleep(5);
		if ((*_contextsInfo)["location.symbolic"].getText() == "start" && (*_contextsInfo)["identity.name"].getText() != "") {
			break;
		}
	}
	
	while(true) {
		std::string location = _get_symbolic_location();
		if (location.length() != 0) {
			(*_contextsInfo)["location.symbolic"] = CLiteral(location);
		}
		sleep(15);
	}
}


static std::string _get_symbolic_location()
{
// 	if ((*_contextsInfo)["identity.name"].getText() == "") {
// 		// A simulacao so comeca apos termos a identificacao do usuario e location.symbolic ter o valor "start"
// 		// TODO: Nao acho a melhor abordagem, mas enfim... 3 dias para entregar a dissertacao, entao nao da para perder tempo com implementacao...
// 		// TODO: Talvez o mais interessante seria aguardar alguma informacao no contexto indicando que o sensor pode prosseguir...
// 		return "";
// 	}
	
	_current_time++;
	std::string key_map = std::string(itoa(_current_time)) + std::string(":") + (*_contextsInfo)["identity.name"].getText();
	if (_users_locations.find(key_map) != _users_locations.end()) {
		return _users_locations[key_map];
	} else {
		return "";
	}
}

// static std::string _get_symbolic_location()
// {
// 	static int counter = 0;
// 	return std::string("at home ") + itoa(++counter);
// }

}
