#include "modbushand.h"
#include <QThread>

ModbusHand::ModbusHand()
{

}

std::string ModbusHand::transDataToMod(std::string &recvData)
{
    std::string::iterator p;
    for(p = recvData.begin(); p != recvData.end() ; ++p){
        if(*p >= 'A' && *p <= 'F') { //如果在'A' 和 'Z' 范围内
           *p -= 55;
        }else if(*p >= 'a' && *p <= 'f'){ //如果在'a' 和 'z' 范围内
            *p -= 87;
        }else if(*p >= '0' && *p <= '9'){ //如果在'0' 和 '9' 范围内
            *p -= '0';
        }else{
            std::string::iterator pre = p;
            recvData.erase(pre);
        }
    }

       return recvData;
}
