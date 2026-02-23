#include <iostream>

class Tv {
public:
    Tv();

    void on();
    void off();
    void setChannel(int ch);

    void print() const;

private:
    bool isOn_;
    int channel_;
};
