#pragma once

#include <iostream>

class shsig {
	
	
	void firstSetup();
	void loadDataFromConfig();
	int checkForFirstSetup();

	std::string srvHost = "localhost";
	int srvPort = 8082;
	std::string staticDir = "./htdocs";
	std::string configDir = "./shsigConfig.json";

	enum logLevel;


	void log(logLevel logLevel, std::string msg);

	public:
		static void srvStart();
		static void srvStop();
};