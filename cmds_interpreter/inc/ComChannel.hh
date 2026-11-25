#ifndef COMCHANNEL_HH
#define COMCHANNEL_HH

#include <mutex>
#include <string>
#include <iostream>
    
using namespace std;

class ComChannel {
    mutex Guard;
public:
    void Print(const string &Msg);
};

#endif