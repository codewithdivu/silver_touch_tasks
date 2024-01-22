#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    const int port = 12345;

    
    TCPServer server(port, [](int clientSocket, const string& message) {
        cout << "Server received message from client " << clientSocket << ": " << message << endl;
    });

    thread serverThread([&]() {
        server.startListening();
    });

    
    this_thread::sleep_for(chrono::seconds(1));

    
    TCPClient client;
    client.connectToServer("127.0.0.1", port, [](const string& message) {
        cout << "Client received message from server: " << message << endl;
    });

    
    client.sendMessage("Hello from the client!");
    this_thread::sleep_for(chrono::seconds(1));

    server.stop(); 

    serverThread.join(); 

    return 0;
}
