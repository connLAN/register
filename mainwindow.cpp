#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>

#include <map>

#include "m_register.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->groupBox->setTitle("CONFIG_0");
    ui->label->setText("NUM_TX");
    ui->label_2->setText("TX_FREQ_DIV");

    const std::map<int, QString> NUM_TX{{0, "0 Pulses"}, {1, "1 Pulse"}, {2, "2 Pulses"}, {3, "3 Pulse"}, {4, "4 Pulses"}, {5, "5 Pulses"},
                                        {6, "6 Pulses"}, {7, "7 Pulse"}, {8, "8 Pulses"}, {9, "9 Pulse"}, {10, "10 Pulses"}, {11, "11 Pulses"},
                                        {12, "12 Pulses"}, {13, "13 Pulse"}, {14, "14 Pulses"}, {16, "16 Pulse"}, {17, "17 Pulses"}, {18, "18 Pulses"},
                                        {19, "19 Pulses"}, {20, "20 Pulse"}, {21, "21 Pulses"}, {22, "22 Pulse"}, {23, "23 Pulses"}, {24, "24 Pulses"},
                                        {25, "25 Pulses"}, {26, "26 Pulse"}, {27, "27 Pulses"}, {28, "28 Pulse"}, {29, "29 Pulses"}, {30, "30 Pulses"},
                                        {31, "31 Pulses"}, {32, "32 Pulse"}, {33, "33 Pulses"}, {34, "34 Pulse"}, {35, "35 Pulses"}};

    const std::map<int, QString> TX_FREQ_DIV{{0, "Divide by 2"}, {1, "Divide by 4"}, {2, "Divide by 8"}, {3, "Divide by 16"},
                                             {4, "Divide by 32"}, {5, "Divide by 64"}, {6, "Divide by 128"}, {7, "Divide by 256"}};

    for(auto const& it : NUM_TX){
        ui->comboBox->addItem(it.second);
    }

    for(auto const& it : TX_FREQ_DIV){
        ui->comboBox_2->addItem(it.second);
    }

    // Usando la clase

    m_register m_config_0{"CONFIG_0_c"};
    m_config_0.setField_1(NUM_TX);
    m_config_0.setField_2(TX_FREQ_DIV);

    ui->groupBox_2->setTitle(m_config_0.getName());
    ui->label_3->setText("NUM_TX_c");
    ui->label_4->setText("TX_DIV_DIV_c");

    for(auto const& it : m_config_0.getField_1()){
        ui->comboBox_3->addItem(it.second);
    }

    for(auto const& it : m_config_0.getField_2()){
        ui->comboBox_4->addItem(it.second);
    }

    // http://www.developerfusion.com/article/133063/constructors-in-c11/
    // C++11 initializer-list constructors

//    connect(ui->comboBox,
//            // http://doc.qt.io/qt-5/qcombobox.html#currentIndexChanged
//            static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
//            ui->lcdNumber,
//            // http://doc.qt.io/qt-5/qlcdnumber.html#display-1
//            static_cast<void(QLCDNumber::*)(int)>(&QLCDNumber::display));

}

MainWindow::~MainWindow()
{
    delete ui;
}
