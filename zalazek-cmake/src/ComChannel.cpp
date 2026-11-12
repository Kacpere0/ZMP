#include <mutex>
#include <string>

class ComChannel {
    std::mutex Guard;
public:
    void Print(const std::string &Msg); // chyba?
};

void ComChannel::Print(const std::string &Msg) {
    lock_guard<mutex> Lock(Guard);

    std::cout << Msg;
}