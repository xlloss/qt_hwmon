#include "soc_thermal.h"
#include <QDebug>

Soc_Thermal::Soc_Thermal(QObject *parent) : QObject(parent)
{
    m_thermal_temp_feture_list.append(SOC_THERRMAL_TEMP0);
    m_thermal_temp_feture_list.append(SOC_THERRMAL_TEMP1);
    m_thermal_trigger_feture_list.append(SOC_THERRMAL_TRIGGRT0);
    m_thermal_trigger_feture_list.append(SOC_THERRMAL_TRIGGRT1);
    m_thermal_hyst_feture_list.append(SOC_THERRMAL_HYST0);
    m_thermal_hyst_feture_list.append(SOC_THERRMAL_HYST1);
}

void Soc_Thermal::ReadFetureVal(TYPE_SOC_THRTMAL_FETURE feture, QByteArrayList *thermal_feture_list)
{
    QByteArray thermal_feture;

    switch (feture) {
    case TYPE_THRTMAL_TEMP:
        for (int i = 0; i < SOC_THERMAL_TEMP_N; i++) {
            HwDevInit(TYPE_F_TEMP, SOC_THERMAL_SYSFS_PATH, m_thermal_temp_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP, &thermal_feture);
            thermal_feture_list->append(thermal_feture);
            thermal_feture.clear();
        }
        return;

    case TYPE_THRTMAL_TRIGGER:
        for (int i = 0; i < SOC_THERMAL_TEMP_TRIGGER_N; i++) {
            HwDevInit(TYPE_F_TEMP_HIGH, SOC_THERMAL_SYSFS_PATH, m_thermal_trigger_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP_HIGH, &thermal_feture);
            thermal_feture_list->append(thermal_feture);
            thermal_feture.clear();
        }
        return;

    case TYPE_THRTMAL_HYST:
        for (int i = 0; i < SOC_THERMAL_TEMP_HYST_N; i++) {
            HwDevInit(TYPE_F_TEMP_HYST, SOC_THERMAL_SYSFS_PATH, m_thermal_hyst_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP_HYST, &thermal_feture);
            thermal_feture_list->append(thermal_feture);
            thermal_feture.clear();
        }
        return;
    }
}
