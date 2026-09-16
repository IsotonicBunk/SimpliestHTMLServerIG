
#include "shsig.hpp"
#include "include/httplib.h"
using namespace std; 

void shsig::srvStart() {
	httplib::Server srv;

	srv.set_mount_point("/", staticDir);
	log(info, "Server started!");
	srv.listen(srvHost, srvPort);
}

//int main() {
//	cout << "Hello CMake." << endl;
//	shsig::loadDataFromConfig();
//	
//	return 0;
//}

