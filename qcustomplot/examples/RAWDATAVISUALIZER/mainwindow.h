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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../qcustomplot.h"
#include <QTimer>
#include <QSerialPort>
#include <QByteArray>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void setupPlot();
  
  QTimer *timer;
  QSerialPort serialcom;
  int recpacksize;
  int samplingcount;
  uchar pulsenum;
  // 272 data 544 bytes
  // 256 valid data 512 bytes, 16bytes dummy.
  // 8 from the begining and 8 from the end.
  // including two head and two tail bytes,
  // 544*2+4 = 1092 bytes
#define ONEMEASUREPULSES 5

  QByteArray Databuff_A,Databuff_B,distancebuff;
  QByteArray Data_A[ONEMEASUREPULSES],Data_B[ONEMEASUREPULSES];
  QByteArray packhead;
  QByteArray packtail;
  QByteArray lastbuf;

private slots:
  void horzScrollBarChanged(int value);
  void vertScrollBarChanged(int value);
  void xAxisChanged(QCPRange range);
  void yAxisChanged(QCPRange range);
  
private:
  Ui::MainWindow *ui;

private slots:
  void ALLEXIT();
  void Update();
  void Readcomport();
  //comport slots
  void Send_reset();
  void Send_sample();
  void Send_pulse();
  void ReplotData();

};

#endif // MAINWINDOW_H
