#ifndef MODBUSHAND_H
#define MODBUSHAND_H

#include <iostream>
#include <cstring>
#include <QString>
#include <QByteArray>
#include <QDebug>


class ModbusHand
{
public://构造、析构函数
    ModbusHand();
    //ok

public://成员函数
//================================================================================================================================
/*
 *函数名称: transDataToMod
 *函数功能: 把接收的字符串信号转换为modbus信号
 *函数参数: recvStr:从text上接收的数据
 *函数返回值: 处理成modbus格式后的数据
*/
    std::string transDataToMod(QString recvStr);
private://成员函数

};

#endif // MODBUSHAND_H
