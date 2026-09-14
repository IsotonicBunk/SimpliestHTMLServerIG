#include "shsig.hpp"
#include "include/toml.hpp"
#include <fstream>
using namespace std;

void shsig::firstSetup() {
	log(raw, "\n         _         _        ");
	log(raw, "        | |       (_)       ");
	log(raw, "     ___| |__  ___ _  __ _  ");
	log(raw, "    / __| '_ \\/ __| |/ _` | ");
	log(raw, "    \\__ \\ | | \\__ \\ | (_| | ");
	log(raw, "    |___/_| |_|___/_|\\__, | ");
	log(raw, "                      __/ | ");
	log(raw, "                     |___/  \n");

	log(raw, "Welcome to the setup!");

	// get hostname
	log(raw, "Please enter the hostname for the server. (default=localhost) You can change this value later... | ");
	std::string inpHost = "localhost";
	cin >> inpHost;
	if (!inpHost.empty()) srvHost = inpHost;
	log(raw, "Successfuly set hostname to \"" + srvHost + '"');

	// get port
	log(raw, "Please enter the hostname for the server. (default=8080) Note that port below 1024 needs administrator rights. You can change this value later... | ");
	std::string inpPort = "8080";
	cin >> inpPort;

	// under dev rn


}

void shsig::loadDataFromConfig() {
	// checking if file exists
	fstream configF("shsig.config.toml", ios_base::binary);
	if (configF.bad()) {
		log(warn, "Failed to load shsig.config.toml! Starting first setup...");
		firstSetup();
		log(info, "Setup Finished! Please restart ");
		return;
	}
	auto config = toml::parse_file("shsig.config.toml");
	



}

