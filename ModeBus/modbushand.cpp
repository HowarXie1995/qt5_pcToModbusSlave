#include "modbushand.h"

ModbusHand::ModbusHand()
{

}

std::string ModbusHand::transDataToMod(QString recvStr)
{
    std::string recvData = recvStr.toStdString();
    for(unsigned int i = 0; i < recvData.length(); ++i){	//遍历recvStr
        if(recvData[i] >= 'A' && recvData[i] <= 'Z'){		//如果在'A' 和 'Z' 范围内
            recvData[i] -= 55;
        }else if(recvData[i] >= 'a' && recvData[i] <= 'z'){//如果在'a' 和 'z' 范围内
            recvData[i] -= 87;
        }else if(recvData[i] >= '0' && recvData[i] <= '9'){//如果在'0' 和 '9' 范围内
            recvData[i] -= '0';
        }else{		//如果都不在，删除
            recvData.erase(recvData[i]);
        }
    }
    return recvData;

}
