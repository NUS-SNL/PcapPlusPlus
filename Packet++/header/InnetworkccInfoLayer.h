//Template for addition of new protocol 'innetworkccInfo'

#ifndef INNETWORKCCINFO_LAYER
#define INNETWORKCCINFO_LAYER

#include <cstring>
#include "Layer.h"
#if defined(WIN32) || defined(WINx64)
#include <winsock2.h>
#elif LINUX
#include <arpa/inet.h>
#endif

namespace pcpp{
    #pragma pack(push,1)
    struct innetworkccInfohdr{
        uint32_t      algo_rwnd;
        uint32_t      rtt_mul;
        uint32_t      qdepth_sum;
        uint32_t      pkt_count;
        uint16_t      final_rwnd;
        uint16_t      ws;
    };

    #pragma pack(pop)
    class InnetworkccInfoLayer: public Layer{
        public:
        InnetworkccInfoLayer(uint8_t* data, size_t dataLen, Layer* prevLayer, Packet* packet): Layer(data, dataLen, prevLayer, packet) {m_Protocol = InnetworkCCInfo;}
        InnetworkccInfoLayer(){
            m_DataLen = sizeof(innetworkccInfohdr);
            m_Data = new uint8_t[m_DataLen];
            memset(m_Data, 0, m_DataLen);
            m_Protocol = InnetworkCCInfo;
        }

         // Getters and Setters for fields
         uint32_t getAlgo_rwnd() const;
         void setAlgo_rwnd(uint32_t value);
         uint32_t getRtt_mul() const;
         void setRtt_mul(uint32_t value);
         uint32_t getQdepth_sum() const;
         void setQdepth_sum(uint32_t value);
         uint32_t getPkt_count() const;
         void setPkt_count(uint32_t value);
         uint16_t getFinal_rwnd() const;
         void setFinal_rwnd(uint16_t value);
         uint16_t getWs() const;
         void setWs(uint16_t value);

         inline innetworkccInfohdr* getInnetworkccInfoHeader() { return (innetworkccInfohdr*)m_Data; }

         void parseNextLayer();

         inline size_t getHeaderLen() const { return sizeof(innetworkccInfohdr); }

         void computeCalculateFields() {}

         std::string toString() const;

         OsiModelLayer getOsiModelLayer() const { return OsiModelApplicationLayer; }

    };
}
#endif
