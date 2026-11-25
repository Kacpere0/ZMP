#include "ComChannel.hh"

void ComChannel::Print(const string &Msg) {
    lock_guard<mutex> Lock(Guard);

    cout << Msg;
}