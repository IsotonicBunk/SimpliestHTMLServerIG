#include "shsig.hpp"

using namespace std;

class shsig {
	enum logLevel {
		debug,
		info,
		warn,
		error,
	};
	void log(logLevel logLevel, std::string msg) {
		std::string prefix = "";
		switch (logLevel) {
			case logLevel::debug: prefix = "[DEBUG] "; break;
			case logLevel::info: prefix = "[INFO] "; break;
			case logLevel::warn: prefix = "[WARN] "; break;
			case logLevel::error: prefix = "[ERROR] "; break;
			default: prefix = "[INFO] ";
		};
		cout << prefix << msg << endl;
		return;
	}
};