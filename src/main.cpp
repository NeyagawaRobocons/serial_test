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

    Serial::Config config;
    config.baudRate = 115200;
    config.byteSize = 8;
    config.parity = Serial::Config::Parity::NO;
    config.stopBits = Serial::Config::StopBits::ONE;

    Serial serial;
    int port;
    cin >> port;
    //オープン
    if (!serial.open(list[port], 115200))
        return -1;
    //SerialInfo構造体にポート名とデバイス名が入っている
    serial.setConfig(config);
    SerialInfo info = serial.getInfo();
    cout << "open success" << endl;
    cout << "device name:" << info.device_name() << endl;
    cout << "name:" << info.port() << "\n" << endl;
    Serial::Config config_ = serial.getConfig();
    cout << "baudRate:" << config_.baudRate << endl;
    cout << "byteSize:" << config_.byteSize << endl;
    cout << "parity:" << (int)config_.parity << endl;
    cout << "stopBits:" << (int)config_.stopBits << endl;
    //以下ループ
    while (true) {
        auto v = serial.read();
        for (auto c : v) {
            cout << c;
        }
    }
    return 0;
}
