#include "Packet.h"

#include <string>
#include <vector>
#include <initializer_list>

//Packet::Packet() {}

Packet::Packet(int _sourcePort, int _destinationPort, std::string _data) {
    sourcePort = _sourcePort;
    destinationPort = _destinationPort;
    data = _data;
}

std::string Packet::getData() {
    return data;
}

/**
 * TCP three-way handshake
 * 
 * TODO more fields
 */
void Packet::createSYNPacket(std::string _message) {
    setPorts(_message);
    sequenceNumber = 0;
    acknowledgmentnumber = 1;
    std::vector<int> flagValues; //{0,0,0,0,0,0,1,0};
    flagValues.push_back(0);
    flagValues.push_back(0);
    flagValues.push_back(0);
    flagValues.push_back(0);
    flagValues.push_back(0);
    flagValues.push_back(0);
    flagValues.push_back(1);
    flagValues.push_back(0);
    setSYNFlags(flagValues);
    //reserved = 0;
}

void Packet::receiveSYNPacket() {

    //return
}

void Packet::setPorts(std::string message) {
    if (message == "SYN" || message == "ACK") {
        sourcePort = 54841;
        destinationPort = 80;
    } else if (message == "SYN-ACK") {
        sourcePort = 80;
        destinationPort = 54841;
    }
}

/**
 * {_CWR, _ECN, _urgent, _acknowledgment, _push, _reset, _syn, _fin}
 */ 
void Packet::setSYNFlags(std::vector<int> _flagValue) {
    for (int i = 0; i < flags.size(); i++) {
        flags.push_back(getBitValue(i, _flagValue[i]));
    }
}

void Packet::setResponse(unsigned char _response) {
    response = _response;
}

unsigned char Packet::getResponse() {
    return response;
}

unsigned char Packet::getBitValue(int _flag, int _value) {
    unsigned char value = 0x00;

    if (_value != 0) {
        switch (_flag) {
            case 0:
                value = 0x80; //1000 0000
                break;
            case 1:
                value = 0x40; //0100 0000
                break;
            case 2:
                value = 0x20; //0010 0000
                break;
            case 3:
                value = 0x10; //0001 0000
                break;
            case 4:
                value = 0x08; //0000 1000
                break;
            case 5:
                value = 0x04; //0000 0100
                break;
            case 6:
                value = 0x02; //0000 0010
                break;
            case 7:
                value = 0x01; //0000 0001
                break;
            default:
                break;
            }
    }
    return value;
}

