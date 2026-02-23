#include <iostream>

class Tv2 {
public:
    Tv2();

    void on();
    void off();
    void setChannel(int ch);

    void print() const;

private:
    bool isOn_;
    int channel_;
    bool broken_;
};
