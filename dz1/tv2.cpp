#include "tv2.h"
using namespace std;

Tv2::Tv2() : isOn_(false), channel_(1), broken_(false) {}

void Tv2::on() {
    if (broken_) {
        return;
    }
    isOn_ = true;
}

void Tv2::off() {
    if (broken_) {
        return;
    } 

    isOn_ = false;
}

void Tv2::setChannel(int ch) {
    if (broken_) {
        return;
    }

    if (!isOn_) {
        return;
    }

    if (ch < 1 || ch > 128) {
        broken_ = true;
        isOn_ = false;
        return;
    }

    channel_ = ch;
}

void Tv2::print() const {
    cout << "Tv2: power=" << (isOn_ ? "ON" : "OFF")
              << ", channel=" << channel_
              << ", broken=" << (broken_ ? "YES" : "NO")
              << "\n";
}
