#include <iostream>
#include "tv.h"
#include "tv2.h"

using namespace std;

void doStep(const char* name, auto action, auto& tv) {
    cout << "BEFORE " << name << ": ";
    tv.print();
    action();
    cout << "AFTER  " << name << ": ";
    tv.print();
    cout << "-----------------\n";
}

int main() {
    cout << "=== Tv ===\n";
    Tv tv;

    doStep("on()",           [&]{ tv.on(); }, tv);
    doStep("setChannel(13)", [&]{ tv.setChannel(13); }, tv);
    doStep("setChannel(130)",[&]{ tv.setChannel(130); }, tv);
    doStep("off()",          [&]{ tv.off(); }, tv);
    doStep("setChannel(5)",  [&]{ tv.setChannel(5); }, tv);
    doStep("on()",           [&]{ tv.on(); }, tv);
    doStep("on()",           [&]{ tv.on(); }, tv);
    doStep("setChannel(3)",  [&]{ tv.setChannel(3); }, tv);
    doStep("off()",          [&]{ tv.off(); }, tv);

    cout << "\n=== Tv2 ===\n";
    Tv2 tv2;

    doStep("on()",           [&]{ tv2.on(); }, tv2);
    doStep("setChannel(13)", [&]{ tv2.setChannel(13); }, tv2);
    doStep("setChannel(130)",[&]{ tv2.setChannel(130); }, tv2);
    doStep("off()",          [&]{ tv2.off(); }, tv2);
    doStep("setChannel(5)",  [&]{ tv2.setChannel(5); }, tv2);
    doStep("on()",           [&]{ tv2.on(); }, tv2);
    doStep("on()",           [&]{ tv2.on(); }, tv2);
    doStep("setChannel(3)",  [&]{ tv2.setChannel(3); }, tv2);
    doStep("off()",          [&]{ tv2.off(); }, tv2);

    return 0;
}
