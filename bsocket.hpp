#ifndef BSOCKET
#define BSOCKET

#include <stdio.h>
#include <sys/socket.h> //Socket object
#include <netinet/in.h> //sockaddr_in
#include <string>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

namespace basicServer{
    class bsocket{
        public:
            bsocket(); //Default is a basic tcp/ip webserver
            bsocket(int domain, int type, int protocol,int host_address, int port);
            //virtual int connect_to_network(int sock, sockaddr_in address) = 0;
            void connection_test(int,std::string);
        private:
            std::stringstream message;
            int connection;
            sockaddr_in address;
            int sock;
            int addr_len;
            const int defaultPort = 8091;
    };
}

#endif