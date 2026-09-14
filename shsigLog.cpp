#include "shsig.hpp"

using namespace std;


void shsig::log(shsig::logLevel logLevel, std::string msg) {
	std::string prefix = "";
	switch (logLevel) {
	case logLevel::debug: prefix = "[DEBUG] "; break;
	case logLevel::info: prefix = "[INFO] "; break;
	case logLevel::warn: prefix = "[WARN] "; break;
	case logLevel::error: prefix = "[ERROR] "; break;
	case logLevel::raw: prefix = ""; break;
	default: prefix = "[INFO] ";
	};
	cout << prefix << msg << endl;
	return;
}

int main() {
	cout << "Hello CMake." << endl;
	shsig* Shsig;
	Shsig->loadDataFromConfig();

	return 0;
}