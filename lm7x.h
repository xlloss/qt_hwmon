#ifndef LM7X_H
#define LM7X_H

#include <QObject>
#include <QWidget>
#include "sysfs/sysfs_file.h"
#include "hwmondev.h"

#define LM7X_SYSFS_PATH "/sys/class/hwmon/hwmon0/"
#define LM7X_SYSFS_TEMP "temp1_input"
#define LM7X_SYSFS_HIGH "temp1_max"
#define LM7X_SYSFS_HYST "temp1_max_hyst"

enum TYPE_LM7X_FETURE {
    TYPE_LM7X_TEMP = 0,
    TYPE_LM7X_HIGH,
    TYPE_LM7X_HYST,
};

class Lm7x : public QObject, public HwmonDev
{
    Q_OBJECT
public:
    explicit Lm7x(QObject *parent = nullptr);
    Sysfs_File m_sysfs;
    void Init_TargetSensor();
    void ReadFetureVal(TYPE_LM7X_FETURE feture, QByteArray *lm7x_feture);
signals:

public slots:

private:
    QString m_targetdir;
    QString m_target_feture;
};

#endif // LM7X_H
