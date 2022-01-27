#include "hwmondev.h"

HwmonDev::HwmonDev()
{

}

void HwmonDev::HwDevInit(TYPE_SENSOR_FETURE feture, QString sensor, QString feture_type)
{
    m_sensor[feture] = sensor;
    m_feture[feture] = feture_type;
}

void HwmonDev::ReadFeture(TYPE_SENSOR_FETURE feture, QByteArray *feture_val)
{
    switch (feture) {
    case TYPE_F_TEMP:
        m_sysfs.Set_Target(m_sensor[TYPE_F_TEMP], m_feture[TYPE_F_TEMP]);
        break;

    case TYPE_F_TEMP_HIGH:
        m_sysfs.Set_Target(m_sensor[TYPE_F_TEMP_HIGH], m_feture[TYPE_F_TEMP_HIGH]);
        break;

    case TYPE_F_TEMP_HYST:
        m_sysfs.Set_Target(m_sensor[TYPE_F_TEMP_HYST], m_feture[TYPE_F_TEMP_HYST]);
        break;

    case TYPE_F_VOL:
        m_sysfs.Set_Target(m_sensor[TYPE_F_VOL], m_feture[TYPE_F_VOL]);
        break;

    case TYPE_F_VOL_MAX:
        m_sysfs.Set_Target(m_sensor[TYPE_F_VOL_MAX], m_feture[TYPE_F_VOL_MAX]);
        break;

    case TYPE_F_VOL_MIN:
        m_sysfs.Set_Target(m_sensor[TYPE_F_VOL_MIN], m_feture[TYPE_F_VOL_MIN]);
        break;

    case TYPE_F_SOC_THERMAL:
        m_sysfs.Set_Target(m_sensor[TYPE_F_SOC_THERMAL], m_feture[TYPE_F_SOC_THERMAL]);
        break;

    case TYPE_F_SOC_THERMAL_MAX:
        m_sysfs.Set_Target(m_sensor[TYPE_F_SOC_THERMAL_MAX], m_feture[TYPE_F_SOC_THERMAL_MAX]);
        break;

    case TYPE_F_SOC_THERMAL_MIN:
        m_sysfs.Set_Target(m_sensor[TYPE_F_SOC_THERMAL_MIN], m_feture[TYPE_F_SOC_THERMAL_MIN]);
        break;

    case TYPE_F_FAN:
        m_sysfs.Set_Target(m_sensor[TYPE_F_FAN], m_feture[TYPE_F_FAN]);
        break;
    case TYPE_F_FAN_MAX:
        m_sysfs.Set_Target(m_sensor[TYPE_F_FAN_MAX], m_feture[TYPE_F_FAN_MAX]);
        break;

    case TYPE_F_FAN_MIN:
        m_sysfs.Set_Target(m_sensor[TYPE_F_FAN_MIN], m_feture[TYPE_F_FAN_MIN]);
        break;

    default:
        break;
    }

    m_sysfs.Read_Target(feture_val);
}
