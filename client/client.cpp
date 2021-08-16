#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "cpp-httplib/httplib.h"
#include <iostream>
#include <string>

const std::string HOST = "0.0.0.0";
const int PORT = 8080;

httplib::Client cli(HOST, PORT);

void post(){
    httplib::Headers headers = {
        { "accept", "application/json" },
        { "Content-Type", "application/json" }
    };
    if (auto response = cli.Post("/patients/", headers, "{\n\t\"fio\": \"TEST FIO\",\n\t\"disease\": \"TEST DISEASE\"\n}", "application/json")) {
        if (response->status == 200) {
        std::cout << "Status code: " << response->status << std::endl;
        std::cout << "Body: " << response->body << std::endl;
        }
    } else {
        auto err = response.error();
        std::cout << "Status code: " << response->status << std::endl;
    }
}


void get(){
    if (auto response = cli.Get("/patients/")) {
        if (response->status == 200) {
        std::cout << "Status code: " << response->status << std::endl;
        std::cout << "Body: " << response->body << std::endl;
        }
    } else {
        auto err = response.error();
        std::cout << "Status code: " << response->status << std::endl;
    }
}


int main(){
    std::string long_line = "----------------------------------------------------";
    std::string method;

    while (true){
        std::cout << long_line << std::endl;
        std::cout << "\t\tHTTP Client\n";
        std::cout << long_line << std::endl;

        std::cout << "Write HTTP method (or exit): ";
        std::cin >> method;
        std::cout << std::endl;

        if (method == "POST" or method == "post"){
            post();
        }
        else if (method == "GET" or method == "get"){
            get();
        }
        else if (method == "EXIT" or method == "exit" or method == "e"){
            break;
        }
        else {
            std::cout << "Wrong HTTP method!!!" << std::endl;
            std::cout << std::endl;
        }
        
    }
    return 0;
}
