#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "tuya_ble_common.h"
#include "tuya_ble_log.h"

#define ALARM	1
#define NORMAL  0
#define HIGH	0
#define LOW		1

void pressurer_sensor_init(void);
void pressurer_sensor_fun(void);
int pressure_value_get(void);

#endif
