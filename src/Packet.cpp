#include <string>
#include <vector>

class Packet {
  private:
    int sourcePort;           //16 bits - end point of the connection
    int destinationPort;      //16 bits - end point of the connection
    int sequenceNumber;       //32 bits - specify the number assigned to the first byte of data in the current message
    int acknowledgmentnumber; //32 bits - next sequence number that the sender of the segment is expecting to receive 
                              //if the ACK control bit is set (sequence number ->, ACK <-)
    //dataOffset              //32 bits - header length, how many 32-bit words are contained in the TCP header
    int reserved = 0;         //6 bits - must be zero, this is for future use
    
    //TODO int to bits
    std::vector<int> flags;   //6 bits - URG, ACK, PSH, RST, SYN, FIN
    /**
     * URG - urgent data has been placed
     * ACK - acknowledgement number is valid
     * PSH - data should be passed to the application as soon as possible
     * RST — resets the connection
     * SYN — synchronizes sequence numbers to initiate a connection
     * FIN — the sender of the flag has finished sending data
     */

    //window                  //16 bits - size of the sender’s receive window (buffer space available for incoming data)
    //checksum                //16 bits - packet integrity checking, whether the header was damaged in transit
    //urgentPointer           //16 bits - point the first urgent data byte in the packet
    //options                 //specify TCP options
    //padding
    //data                    //upper-layer information

    unsigned char response;
    
    
    std::string data;

  public:
    Packet() {}
    
    Packet(int _sourcePort, int _destinationPort, std::string _data) {
        sourcePort = _sourcePort;
        destinationPort = _destinationPort;
        data = _data;
    }

    std::string getData() {
        return data;
    }

    void setSYNFlags(int _CWR, int _ECN, int _urgent, int _acknowledgment, int _push, int _reset, int _syn, int _fin) {
        //TODO list
        unsigned char CWR = getBitValue(_CWR, 0);
        unsigned char ECN = getBitValue(_ECN, 0);
        unsigned char urgent = getBitValue(_urgent, 0);
        unsigned char acknowledgment = getBitValue(_acknowledgment, 0);
        unsigned char push = getBitValue(_push, 0);
        unsigned char reset = getBitValue(_reset, 0);
        unsigned char syn = getBitValue(_syn, 1); //Set
        unsigned char fin = getBitValue(_fin, 0);
    }

    void setResponse(unsigned char _response) {
        response = _response;
    }

    unsigned char getResponse() {
        return response;
    }

    unsigned char getBitValue(int _value, int _flag) {
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

};