#include "Serial.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    //デバイス一覧
    auto list = getSerialList();
    for (const auto& info : list) {
        cout << "device name:" << info.device_name() << endl;
        cout << "name:" << info.port() << "\n" << endl;
    }

    Serial serial;
    int port;
    cin >> port;
    //オープン
    if (!serial.open(list[port], 115200))
        return -1;
    //SerialInfo構造体にポート名とデバイス名が入っている
    SerialInfo info = serial.getInfo();
    cout << "open success" << endl;
    cout << "device name:" << info.device_name() << endl;
    cout << "name:" << info.port() << "\n" << endl;
    //以下ループ
    while (true) {
        auto v = serial.read();
        for (auto c : v) {
            cout << c;
        }
    }
    return 0;
}
