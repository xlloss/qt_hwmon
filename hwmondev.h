#ifndef HWMONDEV_H
#define HWMONDEV_H

#include <QObject>
#include "sysfs/sysfs_file.h"

enum TYPE_SENSOR_TYPE {
    TYPE_LM75 = 0,
    TYPE_F75387,
    TYPE_SOC_THERMAL,
};

enum TYPE_SENSOR_FETURE {
    TYPE_F_TEMP = 0,
    TYPE_F_TEMP_HIGH,
    TYPE_F_TEMP_HYST,
    TYPE_F_VOL,
    TYPE_F_VOL_MAX,
    TYPE_F_VOL_MIN,
    TYPE_F_SOC_THERMAL,
    TYPE_F_SOC_THERMAL_MAX,
    TYPE_F_SOC_THERMAL_MIN,
    TYPE_F_FAN,
    TYPE_F_FAN_MAX,
    TYPE_F_FAN_MIN,
    TYPE_F_MAX,
};


class HwmonDev
{
public:
    HwmonDev();
    void HwDevInit(TYPE_SENSOR_FETURE feture, QString sensor, QString feture_type);
    void ReadFeture(TYPE_SENSOR_FETURE feture, QByteArray *feture_val);

private:
    QString m_sensor[TYPE_F_MAX];
    QString m_feture[TYPE_F_MAX];
    Sysfs_File m_sysfs;
};

#endif // HWMONDEV_H
