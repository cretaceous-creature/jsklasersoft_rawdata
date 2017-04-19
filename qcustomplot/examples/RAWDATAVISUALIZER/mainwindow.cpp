/***************************************************************************
**                                                                        **
**  QCustomPlot, an easy to use, modern plotting widget for Qt            **
**  Copyright (C) 2011-2015 Emanuel Eichhammer                            **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.qcustomplot.com/                          **
**             Date: 25.04.15                                             **
**          Version: 1.3.1                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#define LASER850
#define PI 3.1415926535
#define focuslength 6.0
#define lensangle 2*atan(2.56/focuslength)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPlot();

    // configure scroll bars:
    // Since scroll bars only support integer values, we'll set a high default range of -500..500 and
    // divide scroll bar position values by 100 to provide a scroll range -5..5 in floating point
    // axis coordinates. if you want to dynamically grow the range accessible with the scroll bar,
    // just increase the the minimum/maximum values of the scroll bars as needed.
    ui->horizontalScrollBar->setRange(-500, 500);
    ui->verticalScrollBar->setRange(-500, 500);

    // create connection between axes and scroll bars:
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));

    // initialize axis range (and scroll bar positions via signals we just connected):
    ui->plot->xAxis->setRange(272, 272, Qt::AlignCenter);
    ui->plot->yAxis->setRange(100, 500, Qt::AlignCenter);

    // configuration
    connect(ui->actionEXIT,SIGNAL(triggered()),this,SLOT(ALLEXIT()));
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Update()));
    //comport and button
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Send_reset()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Send_sample()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Send_pulse()));
#ifdef LASER850
    ui->horizontalScrollBar_2->setRange(0,1000);ui->horizontalScrollBar_2->setValue(500);
    ui->horizontalScrollBa=r_3->setRange(0,1000);ui->horizontalScrollBar_3->setValue(0);
    ui->horizontalScrollBar_4->setRange(0,1000);ui->horizontalScrollBar_4->setValue(500);
    ui->horizontalScrollBar_5->setRange(0,1000);ui->horizontalScrollBar_5->setValue(500);
    ui->horizontalScrollBar_6->setRange(0,200); ui->horizontalScrollBar_6->setValue(10);
    ui->horizontalScrollBar_7->setRange(0,1000);
#else
    ui->horizontalScrollBar_2->setRange(0,1000);ui->horizontalScrollBar_2->setValue(502);
    ui->horizontalScrollBar_3->setRange(0,1000);ui->horizontalScrollBar_3->setValue(0);
    ui->horizontalScrollBar_4->setRange(0,1000);ui->horizontalScrollBar_4->setValue(413);
    ui->horizontalScrollBar_5->setRange(0,1000);ui->horizontalScrollBar_5->setValue(413);
    ui->horizontalScrollBar_6->setRange(0,200); ui->horizontalScrollBar_6->setValue(10);
    ui->horizontalScrollBar_7->setRange(0,1000);
#endif
    //lcd
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_3->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_4->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_5->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_6->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber_7->setSegmentStyle(QLCDNumber::Flat);

    // comport initial
    serialcom.setPortName("COM4");
    serialcom.setBaudRate(2000000);
    serialcom.setDataBits(QSerialPort::Data8);
    serialcom.setParity(QSerialPort::NoParity);
    serialcom.setStopBits(QSerialPort::OneStop);
    serialcom.setFlowControl(QSerialPort::NoFlowControl);
    serialcom.close();

    connect(&serialcom,SIGNAL(readyRead()),this,SLOT(Readcomport()));

    bool flag = serialcom.open(QIODevice::ReadWrite);

    //start timer
    timer->start(100); //100ms

    packhead.append(0xa2);
    packhead.append(0xa1);
    packtail.append(0x2a);
    packtail.append(0x2b);
    recpacksize = 1096;

}

MainWindow::~MainWindow()
{
    serialcom.close();
    delete ui;
}

void MainWindow::setupPlot()
{
    // The following plot setup is mostly taken from the plot demos:
    //output2 second capacitor
    ui->plot->addGraph();
    //all the data...
    QPen pen;
    pen.setColor(QColor(0, 0, 255));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(40, 40, 200));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(0, 255, 150));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(0, 200, 150));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(0, 150, 150));
    ui->plot->graph()->setPen(pen);


    //output1 first capacitor
    ui->plot->addGraph();
    pen.setColor(QColor(255, 0, 0));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(200, 40, 40));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(150, 255, 0));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(150, 200, 0));
    ui->plot->graph()->setPen(pen);
    ui->plot->addGraph();
    pen.setColor(QColor(150, 150, 0));
    ui->plot->graph()->setPen(pen);

    //third one, distance information
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::green));
    ui->plot->graph()->setBrush(QBrush(QColor(0, 255, 0, 20)));

    QVector<double> x(500), y0(500), y1(500);
    for (int i=0; i<500; ++i)
    {
        x[i] = (i/499.0)*100;
        y0[i] = qExp(-x[i]*x[i]*0.25)*qSin(x[i]*5)*50;
        y1[i] = qExp(-x[i]*x[i]*0.25)*50;
    }
    ui->plot->graph(0)->setData(x, y0);
    ui->plot->graph(1)->setData(x, y1);
    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::horzScrollBarChanged(int value)
{
    if (qAbs(ui->plot->xAxis->range().center()-value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->plot->xAxis->setRange(value/100.0, ui->plot->xAxis->range().size(), Qt::AlignCenter);
        ui->plot->replot();
    }
}

void MainWindow::vertScrollBarChanged(int value)
{
    if (qAbs(ui->plot->yAxis->range().center()+value/100.0) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        ui->plot->yAxis->setRange(-value/100.0, ui->plot->yAxis->range().size(), Qt::AlignCenter);
        ui->plot->replot();
    }
}

void MainWindow::xAxisChanged(QCPRange range)
{
    ui->horizontalScrollBar->setValue(qRound(range.center()*100.0)); // adjust position of scroll bar slider
    ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}

void MainWindow::yAxisChanged(QCPRange range)
{
    ui->verticalScrollBar->setValue(qRound(-range.center()*100.0)); // adjust position of scroll bar slider
    ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0)); // adjust size of scroll bar slider
}


void MainWindow::ALLEXIT()
{
    serialcom.close();
    exit(0);
}

void MainWindow::Send_reset()
{
    //send reset order to board
    QByteArray resetorder = QByteArray("R");
    resetorder.append(pulsenum);
    serialcom.write(resetorder.data(),resetorder.size());
    Databuff_B.clear();
    Databuff_A.clear();
    samplingcount = 0;
}

void MainWindow::Send_sample()
{
    //send sampling order to board
    //send reset order to board
    QByteArray sampletorder = QByteArray("SSS");
    sampletorder.append(pulsenum);
    serialcom.write(sampletorder.data(),sampletorder.size());
}

void MainWindow::Send_pulse()
{
    //send sampling order to board
    //send reset order to board
    QByteArray sampletorder = QByteArray("P");
    sampletorder.append(pulsenum);
    serialcom.write(sampletorder.data(),sampletorder.size());
    samplingcount++;
}


void MainWindow::Readcomport()
{
    if(serialcom.bytesAvailable()>=recpacksize)
    {
        //serialcom.read

        QByteArray re_data;
        if(lastbuf.size())
        {
            re_data = lastbuf + serialcom.readAll();
            lastbuf.clear();
            recpacksize = 1096;
        }
        else
            re_data = serialcom.readAll();

        int startindex = re_data.indexOf(packhead);
        // this means the data is OK...
        if(startindex==0)
        {
            int endindex = re_data.indexOf(packtail,startindex+1000);
            // find the end index behind 544 + 2 bytes,
            if(endindex - 1094 == startindex)
            {
               QByteArray tmpdata = re_data.mid(startindex+packhead.size(),1092);
               unsigned short data_num = (*(unsigned short *)tmpdata.mid(0,2).data());
               unsigned short pulse_num = (*(unsigned short *)tmpdata.mid(2,2).data());
               if(data_num>100)
               {
                   data_num -=100;
                   Data_A[data_num].clear(); Data_B[data_num].clear();
                   Data_A[data_num].append(tmpdata.mid(4,544));
                   Data_B[data_num].append(tmpdata.mid(4+544,544));
                   ReplotData();
                   //now all the data has been stored..
               }
               else
               {
                   Data_A[data_num].clear(); Data_B[data_num].clear();
                   Data_A[data_num].append(tmpdata.mid(4,544));
                   Data_B[data_num].append(tmpdata.mid(4+544,544));
               }
               lastbuf.append(tmpdata.mid(endindex));
            }
            else
                //error
                return;
        }
        //the first is not the head
        else if(startindex>0)
        {
            lastbuf.append(re_data.mid(startindex)); //append all the data
            recpacksize = startindex;
        }

    }
}
static int counter100ms;
void MainWindow::Update()
{
    float SR,Vofs,Dofs,a;
    SR = 0.002*ui->horizontalScrollBar_2->value();
    Vofs = 0.002*ui->horizontalScrollBar_5->value();
    Dofs = 0.002*ui->horizontalScrollBar_3->value();
    a = 0.002*ui->horizontalScrollBar_4->value();
    pulsenum = ui->horizontalScrollBar_6->value();

    ui->lcdNumber->display(samplingcount);
    ui->lcdNumber_2->display(SR);
    ui->lcdNumber_3->display(Vofs);
    ui->lcdNumber_4->display(Dofs);
    ui->lcdNumber_5->display(a);
    ui->lcdNumber_6->display(pulsenum);

    /*
    if(Databuff_A.size()>=544)
    {
        QVector<double> x(272);
        QVector<double> outputDistance(272);
        for (int i=0; i<272; ++i)
        {
            QByteArray tmp;
            x[i] = i;
            tmp = Databuff_A.mid(2*i,2);
            outputDistance[i] = (*(unsigned short *)tmp.data())/100;

        }



        ui->plot->graph(2)->setData(x, outputDistance);
        // less than 3 meter, Red should discharge more than blue one, whereas larger than 3 meter, Red should discharge less than blue

        ui->plot->axisRect()->setupFullAxesBox(true);
        ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->plot->replot();

    }
    */
    if(counter100ms++>10)
    {
        counter100ms = 0;
        //ui->horizontalScrollBar_6->setValue(10);
       // this->Send_reset();
    }

}



void MainWindow::ReplotData()
{
    for(int j=0; j<ONEMEASUREPULSES;j++)
    {
        QVector<double> x(272);
        QVector<double> A(272), B(272);
        if(!(Data_A[j].size()&&Data_B[j].size()))
            break;
        for (int i=0; i<272; ++i)
        {
            QByteArray tmpA, tmpB;
            x[i] = i;
            tmpA = Data_A[j].mid(2*i,2);
            tmpB = Data_B[j].mid(2*i,2);
            A[i] = (*(unsigned short *)tmpA.data())/10;
            B[i] = (*(unsigned short *)tmpB.data())/10;
        }
        ui->plot->graph(j)->setData(x, A);
        ui->plot->graph(j+ONEMEASUREPULSES)->setData(x, B);
    }
    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->plot->replot();
}



