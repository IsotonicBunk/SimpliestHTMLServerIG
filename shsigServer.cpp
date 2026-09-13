
#include "shsig.hpp"
#include "include/httplib.h"
using namespace std; 
class shsig {
	public:
		static void startSrv() {
		httplib::Server srv;
		srv.Get("/shsig/test", [](const httplib::Request& req, httplib::Response& res) {
			res.set_content("hello cmake ig idk Приыет", "text/plain");
			res.status = 200;
			});

		srv.set_mount_point("/", "./htdocs");

		srv.listen("localhost", 8082);
	}
};


int main() {
	cout << "Hello CMake." << endl;
	shsig::startSrv();
	
	return 0;
}

