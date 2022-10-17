#ifndef PACKET_H
#define PACKET_H

#include <string>
#include <vector>
#include <initializer_list>

class Packet {
  private:
    int sourcePort;           //16 bits - end point of the connection
    int destinationPort;      //16 bits - end point of the connection
    int sequenceNumber;       //32 bits - specify the number assigned to the first byte of data in the current message
    int acknowledgmentnumber; //32 bits - next sequence number that the sender of the segment is expecting to receive 
                              //if the ACK control bit is set (sequence number ->, ACK <-)
    //dataOffset              //32 bits - header length, how many 32-bit words are contained in the TCP header
    int reserved;         //6 bits - must be zero, this is for future use
    
    std::vector<unsigned char> flags;   //6 bits - URG, ACK, PSH, RST, SYN, FIN
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
    
    Packet(int _sourcePort, int _destinationPort, std::string _data);

    std::string getData();

    /**
     * Create a SYN packet
     * @param _message data message needed by setPorts()
     */
    void createSYNPacket(std::string _message);

    void receiveSYNPacket();

    /**
     * Generate the source and destination ports
     * @param _message data message: SYN, ACK, SYN-ACK
     */
    void setPorts(std::string message);

    /**
     * Set the flags as bits
     * {_CWR, _ECN, _urgent, _acknowledgment, _push, _reset, _syn, _fin}
     * @param _flagValue the list of flag values
     */ 
    void setSYNFlags(std::vector<int> _flagValue);

    //void setResponse(unsigned char _response);

    //unsigned char getResponse();

    /**
     * Generate the bit value of the flag
     * @param _flag name of the flag
     * @param _value value of the flag
     */ 
    unsigned char getBitValue(int _flag, int _value);

};

#endif