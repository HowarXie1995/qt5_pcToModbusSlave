#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QMainWindow>
#include <QSerialPort>				//串口相关文件
#include <QSerialPortInfo>
#include <QByteArray>
#include <QtDebug>

#include "modbushand.h"




namespace Ui {
class DataWindow;
}

class DataWindow : public QMainWindow
{
    Q_OBJECT

public://构造、析构函数
    explicit DataWindow(QWidget *parent = 0);
    ~DataWindow();

public://成员函数
//================================================================================================================================
/*
 *函数名称: initSerail
 *函数功能: 初始化串口
 *函数参数: 无
 *函数返回值: 无
*/
    void initSerail();
//================================================================================================================================
/*
 * 槽函数：有信号就接受
*/
    void analyData();


private slots:
//================================================================================================================================
/*
 *函数名称: on_bt_sendData_clicked
 *函数功能: 按下发送text_sendData里面的内容
 *函数参数: 无
 *函数返回值: 无
*/
    void on_bt_sendData_clicked();
//================================================================================================================================
/*
 *函数名称: on_actionReconnect_triggered
 *函数功能: 重新连接端口
 *函数参数: 无
 *函数返回值: 无
*/

    void on_actionReconnect_triggered();
//================================================================================================================================
/*
 *函数名称: on_actionserialClose_triggered
 *函数功能: 关闭串口
 *函数参数: 无
 *函数返回值: 无
*/

    void on_actionserialClose_triggered();
//================================================================================================================================
/*
 *函数名称: on_bt_recevData_clicked
 *函数功能: 清除显示数据
 *函数参数: 无
 *函数返回值: 无
*/
    void on_bt_recevData_clicked();
//================================================================================================================================
/*
 *函数名称: on_actionquit_triggered
 *函数功能: 退出程序
 *函数参数: 无
 *函数返回值: 无
*/

    void on_actionquit_triggered();
//================================================================================================================================
/*
 *函数名称: on_actionopenModbus_triggered
 *函数功能: 打开modbus模式
 *函数参数: 无
 *函数返回值: 无
*/

    void on_actionopenModbus_triggered();
//================================================================================================================================
/*
 *函数名称: on_actioncloseModbus_triggered
 *函数功能: 关闭modbus模式
 *函数参数: 无
 *函数返回值: 无
*/
    void on_actioncloseModbus_triggered();

private://成员变量
    int tic_time;				//计时器
    Ui::DataWindow *ui;
    QSerialPort serial;
    int modBusFouc;				//modBus专注模式
    ModbusHand modHand;			//Modbus处理函数

};

#endif // DATAWINDOW_H
//================================================================================================================================
/*
 *函数名称:
 *函数功能:
 *函数参数:
 *函数返回值:
*/
