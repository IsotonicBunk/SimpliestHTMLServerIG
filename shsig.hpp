#pragma once

#include <iostream>

class shsig {
	
	

	std::string srvHost = "localhost";
	int srvPort = 8082;
	std::string staticDir = "./htdocs";
	std::string configDir = "./shsigConfig.json";




protected:
	enum logLevel {
		debug,
		info,
		warn,
		error,
		raw
	};
	void firstSetup();
	void log(logLevel logLevel, std::string msg);
	void srvStart();
	void srvStop();
public:
	void loadDataFromConfig();
};