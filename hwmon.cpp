#include "hwmon.h"
#include "ui_hwmon.h"
#include <QDebug>

#define FONT_SIZE 12

Hwmon::Hwmon(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hwmon)
{
    ui->setupUi(this);
    QTimer *qtimer;

    Init_Lm75_Feture();
    Init_F75387_Feture();
    Init_SocThermal_Feture();

    qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(ShowFeture()));
    qtimer->start(1000);
}

void Hwmon::Init_SocThermal_Feture()
{
    QFont font;
    QByteArray soc_thermal_tmp, soc_thermal_trigger, soc_thermal_hyst;
    QByteArrayList soc_thermal_feture_list;
    int val_len;

    #define SOC_THERMAL_TEMP_VAL(n) ui->lab_thermal_temp_val##n
    #define SOC_THERMAL_TRIG_VAL(n) ui->lab_thermal##n##_trig_val1
    #define SOC_THERMAL_HYST_VAL(n) ui->lab_thermal##n##_hyst_val1

    font.setPixelSize(FONT_SIZE);
    font.setBold(true);
    ui->lab_soc_thermal->setFont(font);
    ui->lab_thermal_temp0->setFont(font);
    ui->lab_thermal_temp1->setFont(font);
    ui->lab_thermal_0->setFont(font);
    ui->lab_thermal_1->setFont(font);
    ui->lab_thermal0_type1->setFont(font);
    ui->lab_thermal1_type1->setFont(font);
    ui->lab_thermal0_trig1->setFont(font);
    ui->lab_thermal0_hyst1->setFont(font);
    ui->lab_thermal1_trig1->setFont(font);
    ui->lab_thermal1_hyst1->setFont(font);

    SOC_THERMAL_TEMP_VAL(0)->setFont(font);
    SOC_THERMAL_TEMP_VAL(1)->setFont(font);
    SOC_THERMAL_TRIG_VAL(0)->setFont(font);
    SOC_THERMAL_TRIG_VAL(1)->setFont(font);
    SOC_THERMAL_HYST_VAL(0)->setFont(font);
    SOC_THERMAL_HYST_VAL(1)->setFont(font);

    /* Temp */
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_TEMP, &soc_thermal_feture_list);
    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(0);
    SOC_THERMAL_TEMP_VAL(0)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(1);
    SOC_THERMAL_TEMP_VAL(1)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");

    /* Trigger */
    soc_thermal_feture_list.clear();   /* Temp */
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_TEMP, &soc_thermal_feture_list);
    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(0);
    SOC_THERMAL_TEMP_VAL(0)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(1);
    SOC_THERMAL_TEMP_VAL(1)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_TRIGGER, &soc_thermal_feture_list);

    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_trigger = soc_thermal_feture_list.at(0);
    SOC_THERMAL_TRIG_VAL(0)->setText(soc_thermal_trigger.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_trigger = soc_thermal_feture_list.at(1);
    SOC_THERMAL_TRIG_VAL(1)->setText(soc_thermal_trigger.remove(val_len, 1) + " °C");

    /* Hyst */
    soc_thermal_feture_list.clear();
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_HYST, &soc_thermal_feture_list);

    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_hyst = soc_thermal_feture_list.at(0);
    SOC_THERMAL_HYST_VAL(0)->setText(soc_thermal_hyst.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_hyst = soc_thermal_feture_list.at(1);
    SOC_THERMAL_HYST_VAL(1)->setText(soc_thermal_hyst.remove(val_len, 1) + " °C");
}

void Hwmon::Update_SocThermal_Feture()
{
    QFont font;
    QByteArray soc_thermal_tmp, soc_thermal_trigger, soc_thermal_hyst;
    QByteArrayList soc_thermal_feture_list;
    int val_len;
    #define SOC_THERMAL_TEMP_VAL(n) ui->lab_thermal_temp_val##n

    /* Temp */
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_TEMP, &soc_thermal_feture_list);
    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(0);
    SOC_THERMAL_TEMP_VAL(0)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_tmp = soc_thermal_feture_list.at(1);
    SOC_THERMAL_TEMP_VAL(1)->setText(soc_thermal_tmp.remove(val_len, 1) + " °C");

    /* Trigger */
    soc_thermal_feture_list.clear();
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_TRIGGER, &soc_thermal_feture_list);

    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_trigger = soc_thermal_feture_list.at(0);
    SOC_THERMAL_TRIG_VAL(0)->setText(soc_thermal_trigger.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_trigger = soc_thermal_feture_list.at(1);
    SOC_THERMAL_TRIG_VAL(1)->setText(soc_thermal_trigger.remove(val_len, 1) + " °C");

    /* Hyst */
    soc_thermal_feture_list.clear();
    sensor_soc_thermal.ReadFetureVal(TYPE_THRTMAL_HYST, &soc_thermal_feture_list);

    val_len = soc_thermal_feture_list.at(0).length() - 1;
    soc_thermal_hyst = soc_thermal_feture_list.at(0);
    SOC_THERMAL_HYST_VAL(0)->setText(soc_thermal_hyst.remove(val_len, 1) + " °C");

    val_len = soc_thermal_feture_list.at(1).length() - 1;
    soc_thermal_hyst = soc_thermal_feture_list.at(1);
    SOC_THERMAL_HYST_VAL(1)->setText(soc_thermal_hyst.remove(val_len, 1) + " °C");
}

void Hwmon::Init_F75387_Feture()
{
    QFont font;
    QByteArray f81439_tmp, f81439_tmphigh, f81439_tmphyst;
    QByteArray f81439_in, f81439_inmax, f81439_inmin;
    QByteArray f81439_fan, f81439_fanmax, f81439_fanmin;
    QByteArrayList f81439_feture_list;
    int val_len;

    #define F75387_TEMP_VAL(n) ui->lab_75387_val_temp##n
    #define F75387_IN_VAL(n) ui->lab_75387_val_in##n
    #define F75387_FAN_VAL(n) ui->lab_75387_val_fan##n

    font.setPixelSize(FONT_SIZE);
    font.setBold(true);

    ui->lab_f75387->setFont(font);
    ui->lab_tmp1->setFont(font);
    ui->lab_tmp2->setFont(font);

    ui->lab_in0->setFont(font);
    ui->lab_in1->setFont(font);
    ui->lab_in2->setFont(font);
    ui->lab_in3->setFont(font);

    ui->lab_fan1->setFont(font);
    ui->lab_fan2->setFont(font);

    F75387_TEMP_VAL(0)->setFont(font);
    F75387_TEMP_VAL(1)->setFont(font);

    F75387_IN_VAL(0)->setFont(font);
    F75387_IN_VAL(1)->setFont(font);
    F75387_IN_VAL(2)->setFont(font);
    F75387_IN_VAL(3)->setFont(font);

    F75387_FAN_VAL(0)->setFont(font);
    F75387_FAN_VAL(1)->setFont(font);

    /* Temp */
    sensor_f75387.ReadFetureVal(TYPE_F75387_TEMP, &f81439_feture_list);
    val_len = f81439_feture_list.at(0).length() - 1;
    f81439_tmp = f81439_feture_list.at(0);
    F75387_TEMP_VAL(0)->setText(f81439_tmp.remove(val_len, 1) + " °C");

    val_len = f81439_feture_list.at(1).length() - 1;
    f81439_in = f81439_feture_list.at(1);
    F75387_TEMP_VAL(1)->setText(f81439_tmp.remove(val_len, 1) + " °C");
    f81439_feture_list.clear();

    /* Volt */
    sensor_f75387.ReadFetureVal(TYPE_F75387_IN, &f81439_feture_list);
    val_len = f81439_feture_list.at(0).length() - 1;
    f81439_in = f81439_feture_list.at(0);
    F75387_IN_VAL(0)->setText(f81439_in.remove(val_len, 1) + " V");

    val_len = f81439_feture_list.at(1).length() - 1;
    f81439_in = f81439_feture_list.at(1);
    F75387_IN_VAL(1)->setText(f81439_in.remove(val_len, 1) + " V");

    val_len = f81439_feture_list.at(2).length() - 1;
    f81439_in = f81439_feture_list.at(2);
    F75387_IN_VAL(2)->setText(f81439_in.remove(val_len, 1) + " V");

    val_len = f81439_feture_list.at(3).length() - 1;
    f81439_in = f81439_feture_list.at(3);
    F75387_IN_VAL(3)->setText(f81439_in.remove(val_len, 1) + " V");
    /* clean buffer */
    f81439_feture_list.clear();

    /* Fan */
    sensor_f75387.ReadFetureVal(TYPE_F75387_FAN, &f81439_feture_list);
    val_len = f81439_feture_list.at(0).length() - 1;
    f81439_fan = f81439_feture_list.at(0);
    F75387_FAN_VAL(0)->setText(f81439_fan.remove(val_len, 1) + " RPM");

    val_len = f81439_feture_list.at(1).length() - 1;
    f81439_in = f81439_feture_list.at(1);
    F75387_FAN_VAL(1)->setText(f81439_fan.remove(val_len, 1) + " RPM");
    f81439_feture_list.clear();
}

void Hwmon::Update_F75387_Feture()
{
    QByteArrayList f81439_feture_list;
    QByteArray f81439_temp, f81439_in, f81439_fan;
    int val_len;

    f81439_feture_list.clear();
    sensor_f75387.ReadFetureVal(TYPE_F75387_TEMP, &f81439_feture_list);
    for (int i = 0; i < F75387_TEMP_N; i++) {
        val_len = f81439_feture_list.at(i).length() - 1;
        f81439_temp = f81439_feture_list.at(i);

        switch (i) {
        case 0:
            F75387_TEMP_VAL(0)->setText(f81439_temp.remove(val_len, 1) + " °C");
            break;
        case 1:
            F75387_TEMP_VAL(1)->setText(f81439_temp.remove(val_len, 1) + " °C");
            break;
        }
    }

    f81439_feture_list.clear();
    sensor_f75387.ReadFetureVal(TYPE_F75387_IN, &f81439_feture_list);
    for (int i = 0; i < F75387_IN_N; i++) {
        val_len = f81439_feture_list.at(i).length() - 1;
        f81439_in = f81439_feture_list.at(i);
        switch (i) {
        case 0:
            F75387_IN_VAL(0)->setText(f81439_in.remove(val_len, 1) + " V");
            break;
        case 1:
            F75387_IN_VAL(1)->setText(f81439_in.remove(val_len, 1) + " V");
            break;
        case 2:
            F75387_IN_VAL(2)->setText(f81439_in.remove(val_len, 1) + " V");
            break;
        case 3:
            F75387_IN_VAL(3)->setText(f81439_in.remove(val_len, 1) + " V");
            break;
        }
    }

    f81439_feture_list.clear();
    sensor_f75387.ReadFetureVal(TYPE_F75387_FAN, &f81439_feture_list);
    for (int i = 0; i < F75387_FAN_N; i++) {
        val_len = f81439_feture_list.at(i).length() - 1;
        f81439_fan = f81439_feture_list.at(i);
        switch (i) {
        case 0:
            F75387_FAN_VAL(0)->setText(f81439_fan.remove(val_len, 1) + " V");
            break;
        case 1:
            F75387_FAN_VAL(1)->setText(f81439_fan.remove(val_len, 1) + " V");
            break;
        }
    }
}

void Hwmon::Init_Lm75_Feture()
{
    QFont font;
    QByteArray lm75_tmp, lm75_high, lm75_hyst;
    int lm75_val_len;

    font.setPixelSize(FONT_SIZE);
    font.setBold(true);

    sensor_lm7x.Init_TargetSensor();
    sensor_lm7x.ReadFetureVal(TYPE_LM7X_TEMP, &lm75_tmp);

    ui->lab_lm75->setFont(font);
    ui->lab_lm75_tmp->setFont(font);
    ui->lab_lm75_high->setFont(font);
    ui->lab_lm75_hyst->setFont(font);

    lm75_val_len = lm75_tmp.length() - 1;
    ui->val_lm75_tmp->setFont(font);
    ui->val_lm75_tmp->setText("+" + lm75_tmp.remove(lm75_val_len, 1) + " °C");

    sensor_lm7x.ReadFetureVal(TYPE_LM7X_HIGH, &lm75_high);
    lm75_val_len = lm75_high.length() - 1;
    ui->val_lm75_high->setFont(font);
    ui->val_lm75_high->setText("+" + lm75_high.remove(lm75_val_len, 1) + " °C");

    sensor_lm7x.ReadFetureVal(TYPE_LM7X_HYST, &lm75_hyst);
    lm75_val_len = lm75_hyst.length() - 1;
    ui->val_lm75_hyst->setFont(font);
    ui->val_lm75_hyst->setText("+" + lm75_hyst.remove(lm75_val_len, 1) + " °C");
}

void Hwmon::Update_Lm75_Feture()
{
    QByteArray lm75_tmp, lm75_high, lm75_hyst;
    int lm75_val_len;

    sensor_lm7x.Init_TargetSensor();
    sensor_lm7x.ReadFetureVal(TYPE_LM7X_TEMP, &lm75_tmp);
    lm75_val_len = lm75_tmp.length() - 1;
    ui->val_lm75_tmp->setText("+" + lm75_tmp.remove(lm75_val_len, 1) + " °C");
    update();
}

void Hwmon::ShowFeture()
{
    Update_Lm75_Feture();
    Update_F75387_Feture();
    Update_SocThermal_Feture();
}

Hwmon::~Hwmon()
{
    delete ui;
}
