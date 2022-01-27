#ifndef HWMON_H
#define HWMON_H

#include <QMainWindow>
#include <QTimer>
#include "lm7x.h"
#include "f75387.h"
#include "soc_thermal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Hwmon; }
QT_END_NAMESPACE

class Hwmon : public QMainWindow
{
    Q_OBJECT

public:
    Hwmon(QWidget *parent = nullptr);
    ~Hwmon();
    Lm7x sensor_lm7x;
    F75387 sensor_f75387;
    Soc_Thermal sensor_soc_thermal;
    void Init_SocThermal_Feture();
    void Update_SocThermal_Feture();
    void Init_F75387_Feture();
    void Update_F75387_Feture();
    void Init_Lm75_Feture();
    void Update_Lm75_Feture();
private:
    Ui::Hwmon *ui;

public slots:
    void ShowFeture();
};
#endif // HWMON_H
