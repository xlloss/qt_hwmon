#ifndef F75387_H
#define F75387_H

#include <QObject>
#include "sysfs/sysfs_file.h"
#include "hwmondev.h"

#define F75387_SYSFS_PATH "/sys/class/hwmon/hwmon1/device/"

#define F75387_SYSFS_TEMP1 "temp1_input"
#define F75387_SYSFS_HIGH1 "temp1_max"
#define F75387_SYSFS_HYST1 "temp1_max_hyst"

#define F75387_SYSFS_TEMP2 "temp2_input"
#define F75387_SYSFS_HIGH2 "temp2_max"
#define F75387_SYSFS_HYST2 "temp2_max_hyst"

#define F75387_SYSFS_IN(n) (tmp.asprintf("in%d_input", n))
#define F75387_SYSFS_INMAX(n) (tmp.asprintf("in%d_max", n))
#define F75387_SYSFS_INMIN(n) (tmp.asprintf("in%d_min", n))

#define F75387_SYSFS_FAN(n) (tmp.asprintf("fan%d_input", n))
#define F75387_SYSFS_FANMAX(n) (tmp.asprintf("fan%d_max", n))
#define F75387_SYSFS_FANMIN(n) (tmp.asprintf("fan%d_min", n))

#define F75387_TEMP_N 2
#define F75387_IN_N 4
#define F75387_FAN_N 2

enum TYPE_F75387_FETURE {
    TYPE_F75387_TEMP = 0,
    TYPE_F75387_HIGH,
    TYPE_F75387_HYST,
    TYPE_F75387_IN,
    TYPE_F75387_IN_MAX,
    TYPE_F75387_IN_MIN,
    TYPE_F75387_FAN,
    TYPE_F75387_FAN_MAX,
    TYPE_F75387_FAN_MIN,
};

class F75387 : public QObject, public HwmonDev
{
    Q_OBJECT
public:    
    explicit F75387(QObject *parent = nullptr);
    QStringList m_temp_feture_list;
    QStringList m_temphigh_feture_list;
    QStringList m_temphyst_feture_list;
    QStringList m_in_feture_list;
    QStringList m_inmax_feture_list;
    QStringList m_inmin_feture_list;
    QStringList m_fan_feture_list;
    QStringList m_fanmax_feture_list;
    QStringList m_fanmin_feture_list;

    void ReadFetureVal(TYPE_F75387_FETURE feture, QByteArrayList *f75387_feture_list);
signals:

public slots:
};

#endif // F75387_H
