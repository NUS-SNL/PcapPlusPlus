#define LOG_MODULE PacketLogModuleInnetworkccInfoLayer

#include "InnetworkccInfoLayer.h"
#include "PayloadLayer.h"
#include "IpUtils.h"
#include "Logger.h"
#include <string.h>
#include <sstream>
#include <endian.h>

namespace pcpp{
    uint32_t InnetworkccInfoLayer::getAlgo_rwnd() const{
        uint32_t algo_rwnd;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        algo_rwnd = htonl(hdrdata->algo_rwnd);
        return algo_rwnd;
    }

    void InnetworkccInfoLayer::setAlgo_rwnd(uint32_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->algo_rwnd = htonl(value);
    }
    uint32_t InnetworkccInfoLayer::getRtt_mul() const{
        uint32_t rtt_mul;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        rtt_mul = htonl(hdrdata->rtt_mul);
        return rtt_mul;
    }

    void InnetworkccInfoLayer::setRtt_mul(uint32_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->rtt_mul = htonl(value);
    }
    uint32_t InnetworkccInfoLayer::getQdepth_sum() const{
        uint32_t qdepth_sum;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        qdepth_sum = htonl(hdrdata->qdepth_sum);
        return qdepth_sum;
    }

    void InnetworkccInfoLayer::setQdepth_sum(uint32_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->qdepth_sum = htonl(value);
    }
    uint32_t InnetworkccInfoLayer::getPkt_count() const{
        uint32_t pkt_count;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        pkt_count = htonl(hdrdata->pkt_count);
        return pkt_count;
    }

    void InnetworkccInfoLayer::setPkt_count(uint32_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->pkt_count = htonl(value);
    }
    uint16_t InnetworkccInfoLayer::getFinal_rwnd() const{
        uint16_t final_rwnd;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        final_rwnd = htons(hdrdata->final_rwnd);
        return final_rwnd;
    }

    void InnetworkccInfoLayer::setFinal_rwnd(uint16_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->final_rwnd = htons(value);
    }
    uint16_t InnetworkccInfoLayer::getWs() const{
        uint16_t ws;
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        ws = htons(hdrdata->ws);
        return ws;
    }

    void InnetworkccInfoLayer::setWs(uint16_t value){
        innetworkccInfohdr* hdrdata = (innetworkccInfohdr*)m_Data;
        hdrdata->ws = htons(value);
    }
    void InnetworkccInfoLayer::parseNextLayer(){
        if (m_DataLen <= sizeof(innetworkccInfohdr))
            return;
        // else
        //     m_NextLayer = new PayloadLayer(payload, payloadLen, this, m_Packet);
    }
    
    std::string InnetworkccInfoLayer::toString() const {

        std::string result_str = "InNetworkCCInfo Layer, ";
        result_str += "algo_rwnd: " + std::to_string(getAlgo_rwnd()) + ", ";
        result_str += "rtt_mul: " + std::to_string(getRtt_mul()) + ", ";
        result_str += "qdepth_sum: " + std::to_string(getQdepth_sum()) + ", ";
        result_str += "pkt_count: " + std::to_string(getPkt_count()) + ", ";
        result_str += "final_rwnd: " + std::to_string(getFinal_rwnd()) + ", ";
        result_str += "ws: " + std::to_string(getWs());

        return result_str;

    }

}
