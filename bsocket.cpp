#include "bsocket.hpp"

basicServer::bsocket::bsocket(){
    std::cout << "Creating object" << std::endl;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(defaultPort);
    addr_len = sizeof(address);
    sock = socket(AF_INET,SOCK_STREAM,0);
        std::cout << "Creating object" << std::endl;
    connection_test(sock,"socket");
    int bindStatus = bind(sock,(sockaddr*) &address,sizeof(address));
    connection_test(bindStatus,"binding");
    connection_test(listen(sock,3),"listening on port");
    int connectedSocket;
    connection_test(connectedSocket = accept(sock,(sockaddr*) &address,(socklen_t*) &addr_len),"acceptance");
    char buffer[30000] = {0};
    int valRead = read(connectedSocket,buffer,30000);
    std::cout << buffer << std::endl;

    //Reading index.html file
    std::ifstream t("index.html");
    std::stringstream buff;
    buff << t.rdbuf();
    std::cout << buff.str() <<std::endl;
    message << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length:" << strlen(buff.str().c_str()) << "\n\n" << buff.str();
    write(connectedSocket,message.str().c_str(),strlen(message.str().c_str()));
    std::cout << message.str() << std::endl;
    close(connectedSocket);
}   

/* basicServer::bsocket::bsocket(int domain, int type, int protocol,int host_address, int port){
    address.sin_family = domain;
    address.sin_port = port;
    address.sin_addr.s_addr = host_address;
    connection_test(sock=socket(domain,type,protocol),"socket") ;
    connection = connect_to_network(sock,address);
}    */

void basicServer::bsocket::connection_test(int test, std::string test_type){
    if(test < 0){
        perror(std::string("Attempt failed..." + test_type).c_str());
        exit(EXIT_FAILURE);
    }
}