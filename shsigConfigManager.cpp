#include "shsig.hpp"
#include "include/toml.hpp"
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>
#include <limits>
#include <thread>

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

    // getting hostname
    log(raw, "Please enter the hostname for the server. (default=localhost) You can change this value later... | ");
    string inpHost;
    if (getline(cin, inpHost) && !inpHost.empty()) {
        srvHost = inpHost;
    }
    else {
        srvHost = "localhost";
        log(raw, "Hostname is empty. Setting default...");
    }
    log(raw, "Successfully set hostname to \"" + srvHost + "\"!");

    // getting port
    log(raw, "Please enter the port for the server. (default=8080) Note that ports below 1024 need administrator rights. You can change this value later... | ");
    string inpPort;
    if (getline(cin, inpPort) && !inpPort.empty()) {
        try {
            int tmpIPort = stoi(inpPort);
            if (tmpIPort > 0 && tmpIPort <= 65535) {
                srvPort = tmpIPort;
            }
            else {
                log(raw, "Port out of range. Setting default 8080...");
                srvPort = 8080;
            }
        }
        catch (const exception&) {
            log(raw, "Failed to set the server port. Setting default 8080...");
            srvPort = 8080;
        }
    }
    else {
        log(raw, "Port is empty. Setting default...");
        srvPort = 8080;
    }
    log(raw, "Successfully set port to " + to_string(srvPort) + "!");

    // getting static dir
    log(raw, "Please enter the directory for static files (default=./htdocs) You can change this value later... | ");
    string inpSD;
    if (getline(cin, inpSD) && !inpSD.empty()) {
        staticDir = inpSD;
    }
    else {
        staticDir = "./htdocs";
        log(raw, "Value is empty. Setting default...");
    }
    log(raw, "Successfully set the directory for static files to \"" + staticDir + "\"!\n");

    // creating static stuff
    log(info, "Creating config & static files...");
    try {
        log(info, "Creating folder - " + staticDir);
        filesystem::create_directories(staticDir);   
        log(info, "Successfully created folder!");

        log(info, "Creating index.html...");
        ofstream indexHTMLF(staticDir + "/index.html", ios::trunc);
        if (!indexHTMLF) throw runtime_error("Cant open index.html for writing");
        indexHTMLF << "<h1>It works!</h1>";
        if (!indexHTMLF) throw runtime_error("Failed to write index.html");
        log(info, "Successfully created index.html!");
    }
    catch (const exception& e) {
        log(error, string("An error occured while creating static files! - ") + e.what());
    }

    // creating config
    try {
        log(info, "Creating config file...");

        toml::table config;
        config.insert_or_assign("host", srvHost);
        config.insert_or_assign("port", srvPort);
        config.insert_or_assign("staticDir", staticDir);

        ofstream configF("shsig.config.toml", ios::trunc);
        if (!configF) throw runtime_error("Cant open shsig.config.toml for writing");
        configF << config;
        if (!configF) throw runtime_error("Failed to write config");

        log(info, "Successfully created config file!");
    }
    catch (const exception& e) {
        log(error, string("An error occured while creating config file! - ") + e.what());
    }
}

bool shsig::loadDataFromConfig() {
    if (!filesystem::exists("shsig.config.toml")) {
        log(warn, "Failed to load shsig.config.toml! Starting first setup...");
        firstSetup();
        log(info, "Setup finished! Please restart!");
        this_thread::sleep_for(5s);
        return false;
    }

    try {
        toml::table config = toml::parse_file("shsig.config.toml");

        srvHost = config["host"].value_or("localhost");
        srvPort = config["port"].value_or(8080);
        staticDir = config["staticDir"].value_or("./htdocs");
    }
    catch (const toml::parse_error& e) {
        log(error, string("Failed to parse config! - ") + e.what());
    }
    catch (const exception& e) {
        log(error, string("Failed to load values from config! - ") + e.what());
    }
    log(info, "Config loaded successfully!");
    return true;
}