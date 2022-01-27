#include "lm7x.h"
#include <QDebug>

Lm7x::Lm7x(QObject *parent) : QObject(parent)
{
}

void Lm7x::Init_TargetSensor()
{
}

void Lm7x::ReadFetureVal(TYPE_LM7X_FETURE feture, QByteArray *lm7x_feture)
{
    switch (feture) {
    case TYPE_LM7X_TEMP:
        HwDevInit(TYPE_F_TEMP, LM7X_SYSFS_PATH, LM7X_SYSFS_TEMP);
        ReadFeture(TYPE_F_TEMP, lm7x_feture);
        return;
    case TYPE_LM7X_HIGH:
        HwDevInit(TYPE_F_TEMP_HIGH, LM7X_SYSFS_PATH, LM7X_SYSFS_HIGH);
        ReadFeture(TYPE_F_TEMP_HIGH, lm7x_feture);
        return;
    case TYPE_LM7X_HYST:
        HwDevInit(TYPE_F_TEMP_HYST, LM7X_SYSFS_PATH, LM7X_SYSFS_HYST);
        ReadFeture(TYPE_F_TEMP_HYST, lm7x_feture);
        return;
    }

    qDebug("%s\n", __func__);
}
