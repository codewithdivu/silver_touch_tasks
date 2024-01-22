#include <iostream>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <ctime>
using namespace std;


class Network {
public:
    static std::string sendMessage(const std::string& message) {
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return "Received: " + message;
    }
};


class CacheNode {
public:
    CacheNode(const std::string& nodeId) : nodeId(nodeId) {}

    std::string get(const std::string& key) {
        std::unique_lock<std::mutex> lock(mutex);
        return cache[key];
    }

    void set(const std::string& key, const std::string& value) {
        std::unique_lock<std::mutex> lock(mutex);
        cache[key] = value;
    }

    
    void startSyncThread() {
        syncThread = std::thread([this]() {
            while (true) {
                std::unique_lock<std::mutex> lock(mutex);
                if (!pendingUpdates.empty()) {
                    auto update = pendingUpdates.front();
                    pendingUpdates.pop();
                    lock.unlock();

                    std::string response = Network::sendMessage("UPDATE:" + update.first + ":" + update.second);
                    std::cout << "Node " << nodeId << " received response: " << response << std::endl;
                }
                else {
                    
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                }
            }
        });
    }

    
    void updateOtherNode(const std::string& nodeId, const std::string& key, const std::string& value) {
        std::unique_lock<std::mutex> lock(mutex);
        pendingUpdates.push({key, value});
    }

    ~CacheNode() {
        if (syncThread.joinable()) {
            syncThread.join();
        }
    }

private:
    std::string nodeId;
    std::unordered_map<std::string, std::string> cache;
    std::queue<std::pair<std::string, std::string>> pendingUpdates;
    std::mutex mutex;
    std::thread syncThread;
};

int main() {
    CacheNode node1("Node1");
    CacheNode node2("Node2");

    
    node1.startSyncThread();
    node2.startSyncThread();

    
    node1.set("key1", "value1");
    node2.set("key2", "value2");

    std::cout << "Node1: key1=" << node1.get("key1") << std::endl;
    std::cout << "Node2: key2=" << node2.get("key2") << std::endl;

    
    node1.updateOtherNode("Node2", "key3", "value3");
    node2.updateOtherNode("Node1", "key4", "value4");

    std::cout << "Node2: key3=" << node2.get("key3") << std::endl;
    std::cout << "Node1: key4=" << node1.get("key4") << std::endl;

    return 0;
}
