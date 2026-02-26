#include "tv.h"
using namespace std;

Tv::Tv() : isOn_(false), channel_(1) {}

void Tv::on() {
    isOn_ = true;
}

void Tv::off() {
    isOn_ = false;
}

void Tv::setChannel(int ch) {
    if (!isOn_) {
        return;
    }

    if (ch < 1 || ch > 128) {
        return;
    }

    channel_ = ch;
}

void Tv::print() const {
    cout << "Tv: power=" << (isOn_ ? "ON" : "OFF")
              << ", channel=" << channel_ << "\n";
}
