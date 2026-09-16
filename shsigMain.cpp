#include "shsig.hpp"
using namespace std;

int shsig::main() {
	std::string version = "v1.0.0-beta.1";
	log(raw, "SimpliestHTMLServerIG " + version);
	log(info, "Loading config...");
	if (!loadDataFromConfig()) return 0;
	log(info, "Starting server...");
	srvStart();
	return 0;
}

int main() {
	shsig shsigLink;
	return shsigLink.main();
}