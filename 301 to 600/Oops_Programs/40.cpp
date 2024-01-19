#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    const int port = 12345;

    // Start the server in a separate thread
    TCPServer server(port, [](int clientSocket, const string& message) {
        cout << "Server received message from client " << clientSocket << ": " << message << endl;
    });

    thread serverThread([&]() {
        server.startListening();
    });

    // Simulate a delay for the server to start
    this_thread::sleep_for(chrono::seconds(1));

    // Connect the client to the server
    TCPClient client;
    client.connectToServer("127.0.0.1", port, [](const string& message) {
        cout << "Client received message from server: " << message << endl;
    });

    // Simulate communication between client and server
    client.sendMessage("Hello from the client!");
    this_thread::sleep_for(chrono::seconds(1));

    server.stop(); // Stop the server

    serverThread.join(); // Wait for the server thread to finish

    return 0;
}
