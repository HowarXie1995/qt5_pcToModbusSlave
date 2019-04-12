#include "datawindow.h"
#include "ui_datawindow.h"

DataWindow::DataWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    //设置ModBus专注模式默认关闭
    modBusFouc = 0;
    ui->actioncloseModbus->setDisabled(true);
    //设置名字、图标
    this->setWindowTitle("自定modbus调试工具");
    QIcon icon("iMage/title.jpg");
    this->setWindowIcon(icon);
    //初始化串口
    initSerail();
    //绑定接收函数
    QObject::connect(&serial, &QSerialPort::readyRead, this, &DataWindow::analyData);
}

void DataWindow::initSerail()
{
    tic_time = 0;
    //创建串口
    serial.setPortName("COM2");			//串口名
    serial.setBaudRate(QSerialPort::Baud9600);		//波特率
    serial.setDataBits(QSerialPort::Data8);		//数据位
    serial.setParity(QSerialPort::NoParity);		//奇偶校验
    serial.setStopBits(QSerialPort::OneStop);		//停止位
    serial.setFlowControl(QSerialPort::NoFlowControl);	//流控制
    bool ok = serial.open(QIODevice::ReadWrite);
    if(ok)
    {
        ui->label_remind->setText("串口打开成功");
    }else
    {
        ui->label_remind->setText("串口打开失败");
    }
    return ;
}


//槽函数
void DataWindow::analyData()
{
    if(1 == modBusFouc)
    {
        //modbus专属数据分析

    }else{
       ui->label_remind->setText("已接收到数据");
       QByteArray data = serial.readAll();
       ui->text_recevData->append(data);

    }
}



DataWindow::~DataWindow()
{
    serial.close();
    delete ui;
}


void DataWindow::on_bt_sendData_clicked()
{
    if(1 == modBusFouc)
    {
        std::string data = (ui->text_sendData->toPlainText()).toStdString();
        ERROR error = modHand.transDataToMod(data);
        if(TRANS_FAIL == error)
        {
           ui->label_remind->setText("数据转换失败");
           return ;
        }
        serial.write(data.data());
        ui->label_remind->setText("ModBus数据发送成功");

    }else{
                //按下后，接收text内容
        QString textSendData = ui->text_sendData->toPlainText();
        //发送到串口
        serial.write(textSendData.toStdString().data());
        ui->label_remind->setText("数据发送成功");

    }
}

void DataWindow::on_actionReconnect_triggered()
{
   serial.close();
   //设置重新连接
   initSerail();

}

void DataWindow::on_actionserialClose_triggered()
{
   serial.close();
   //
   ui->label_remind->setText("串口已关闭");
}

void DataWindow::on_bt_recevData_clicked()
{
   ui->text_recevData->clear();
}

void DataWindow::on_actionquit_triggered()
{
    this->close();
    qApp->quit();
}

void DataWindow::on_actionopenModbus_triggered()
{
    //打开modbus专注模式
    modBusFouc = 1;
    ui->label_remind->setText("已开启modbus专注模式");
    ui->text_recevData->clear();
    //使按钮不可按
    ui->actionopenModbus->setDisabled(true);
    ui->actioncloseModbus->setDisabled(false);
}

void DataWindow::on_actioncloseModbus_triggered()
{
   //关闭modbus专注模式
    modBusFouc = 0;
    ui->label_remind->setText("已关闭modbus专注模式");
    ui->text_recevData->clear();
    //使按钮不可按
    ui->actionopenModbus->setDisabled(false);
    ui->actioncloseModbus->setDisabled(true);
}
