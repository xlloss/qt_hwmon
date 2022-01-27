#include "f75387.h"
#include <QDebug>

F75387::F75387(QObject *parent) : QObject(parent)
{
    QString tmp;

    m_temp_feture_list.append(F75387_SYSFS_TEMP1);
    m_temp_feture_list.append(F75387_SYSFS_TEMP2);
    m_temphigh_feture_list.append(F75387_SYSFS_HIGH1);
    m_temphigh_feture_list.append(F75387_SYSFS_HIGH2);
    m_temphyst_feture_list.append(F75387_SYSFS_HYST1);
    m_temphyst_feture_list.append(F75387_SYSFS_HYST2);

    m_in_feture_list.append(F75387_SYSFS_IN(0));
    m_in_feture_list.append(F75387_SYSFS_IN(1));
    m_in_feture_list.append(F75387_SYSFS_IN(2));
    m_in_feture_list.append(F75387_SYSFS_IN(3));

    m_inmax_feture_list.append(F75387_SYSFS_INMAX(0));
    m_inmax_feture_list.append(F75387_SYSFS_INMAX(1));
    m_inmax_feture_list.append(F75387_SYSFS_INMAX(2));
    m_inmax_feture_list.append(F75387_SYSFS_INMAX(3));

    m_inmin_feture_list.append(F75387_SYSFS_INMIN(0));
    m_inmin_feture_list.append(F75387_SYSFS_INMIN(1));
    m_inmin_feture_list.append(F75387_SYSFS_INMIN(2));
    m_inmin_feture_list.append(F75387_SYSFS_INMIN(3));

    m_fan_feture_list.append(F75387_SYSFS_FAN(1));
    m_fan_feture_list.append(F75387_SYSFS_FAN(2));
    m_fanmax_feture_list.append(F75387_SYSFS_FANMAX(1));
    m_fanmax_feture_list.append(F75387_SYSFS_FANMAX(2));
    m_fanmin_feture_list.append(F75387_SYSFS_FANMIN(1));
    m_fanmin_feture_list.append(F75387_SYSFS_FANMIN(2));

}

void F75387::ReadFetureVal(TYPE_F75387_FETURE feture, QByteArrayList *f75387_feture_list)
{
    QByteArray f75387_feture;

    switch (feture) {
    case TYPE_F75387_TEMP:
        for (int i = 0; i < F75387_TEMP_N; i++) {
            HwDevInit(TYPE_F_TEMP, F75387_SYSFS_PATH, m_temp_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_HIGH:
        for (int i = 0; i < F75387_TEMP_N; i++) {
            HwDevInit(TYPE_F_TEMP_HIGH, F75387_SYSFS_PATH, m_temphigh_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP_HIGH, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_HYST:
        for (int i = 0; i < F75387_TEMP_N; i++) {
            HwDevInit(TYPE_F_TEMP_HYST, F75387_SYSFS_PATH, m_temphyst_feture_list.at(i));
            ReadFeture(TYPE_F_TEMP_HYST, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_IN:
        for (int i = 0; i < F75387_IN_N; i++) {
            HwDevInit(TYPE_F_VOL, F75387_SYSFS_PATH, m_in_feture_list.at(i));
            ReadFeture(TYPE_F_VOL, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_IN_MAX:
        for (int i = 0; i < F75387_IN_N; i++) {
            HwDevInit(TYPE_F_VOL_MAX, F75387_SYSFS_PATH, m_inmax_feture_list.at(i));
            ReadFeture(TYPE_F_VOL_MAX, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;


    case TYPE_F75387_IN_MIN:
        for (int i = 0; i < F75387_IN_N; i++) {
            HwDevInit(TYPE_F_VOL_MIN, F75387_SYSFS_PATH, m_inmin_feture_list.at(i));
            ReadFeture(TYPE_F_VOL_MIN, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_FAN:
        for (int i = 0; i < F75387_FAN_N; i++) {
            HwDevInit(TYPE_F_FAN, F75387_SYSFS_PATH, m_fan_feture_list.at(i));
            ReadFeture(TYPE_F_FAN, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_FAN_MAX:
        for (int i = 0; i < F75387_FAN_N; i++) {
            HwDevInit(TYPE_F_FAN_MAX, F75387_SYSFS_PATH, m_fanmax_feture_list.at(i));
            ReadFeture(TYPE_F_FAN_MAX, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;

    case TYPE_F75387_FAN_MIN:
        for (int i = 0; i < F75387_FAN_N; i++) {
            HwDevInit(TYPE_F_FAN_MIN, F75387_SYSFS_PATH, m_fanmin_feture_list.at(i));
            ReadFeture(TYPE_F_FAN_MIN, &f75387_feture);
            f75387_feture_list->append(f75387_feture);
            f75387_feture.clear();
        }
        return;
    }
}
