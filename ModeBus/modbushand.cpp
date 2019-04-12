#include "modbushand.h"
#include <QThread>

ModbusHand::ModbusHand()
{

}

ERROR ModbusHand::transDataToMod(std::string &recvData)
{
    std::string::iterator p;
    int flag = 0;
    /****************消除16位标识符意外的元素***************/
    for(p = recvData.begin(); p != recvData.end() ;){
        if(*p >= 'A' && *p <= 'F') { //如果在'A' 和 'Z' 范围内
           *p -= 55;
        }else if(*p >= 'a' && *p <= 'f'){ //如果在'a' 和 'z' 范围内
            *p -= 87;
        }else if(*p >= '0' && *p <= '9'){ //如果在'0' 和 '9' 范围内
            *p -= '0';
        }else{
            for(int i = flag; flag != 2&&i >= 0; --i){		//删除无用数据 比如 x0x 或 x000x
                recvData.erase(p - i);
            }
            flag = 0;
            continue;
        }
        ++flag;
        ++p;
    }
    //如果string只剩一个或者没有，直接返回失败
    if(recvData.empty() || 1 == recvData.length() || 0 == recvData.length()) return TRANS_FAIL;
    /****************消除最后00x9 最后一个单的无用数据***************/
    if(0 != recvData.length() %2){
       recvData.erase(recvData.end());
    }
    for(p = recvData.begin(); p != recvData.end(); ++p){
        qDebug() << *p + 55;
    }
    qDebug() << "=========================";

       return TRANS_SUCCE;
}
