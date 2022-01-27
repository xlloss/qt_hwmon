#ifndef SOC_THERMAL_H
#define SOC_THERMAL_H

#include <QObject>
#include "sysfs/sysfs_file.h"
#include "hwmondev.h"

#define SOC_THERMAL_SYSFS_PATH "/sys/class/thermal/"

#define SOC_THERRMAL_TEMP0 "thermal_zone0/temp"
#define SOC_THERRMAL_TYPE0 "thermal_zone0/trip_point_1_type"
#define SOC_THERRMAL_TRIGGRT0 "thermal_zone0/trip_point_1_temp"
#define SOC_THERRMAL_HYST0 "thermal_zone0/trip_point_1_hyst"

#define SOC_THERRMAL_TEMP1 "thermal_zone1/temp"
#define SOC_THERRMAL_TYPE1 "thermal_zone1/trip_point_1_type"
#define SOC_THERRMAL_TRIGGRT1 "thermal_zone1/trip_point_1_temp"
#define SOC_THERRMAL_HYST1 "thermal_zone1/trip_point_1_hyst"

#define SOC_THERMAL_TEMP_N 2
#define SOC_THERMAL_TEMP_TRIGGER_N 2
#define SOC_THERMAL_TEMP_HYST_N 2

enum TYPE_SOC_THRTMAL_FETURE {
    TYPE_THRTMAL_TEMP = 0,
    TYPE_THRTMAL_TRIGGER,
    TYPE_THRTMAL_HYST,
};

class Soc_Thermal:public QObject, public HwmonDev
{
    Q_OBJECT
public:
    explicit Soc_Thermal(QObject *parent = nullptr);

public:
    void ReadFetureVal(TYPE_SOC_THRTMAL_FETURE feture, QByteArrayList *thermal_feture_list);
    QStringList m_thermal_temp_feture_list;
    QStringList m_thermal_trigger_feture_list;
    QStringList m_thermal_hyst_feture_list;
};

#endif // SOC_THERMAL_H
