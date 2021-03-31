#include "pressurer_sensor.h"
#include "app_adc.h"

#define 	TIME_MS		1000
#define		BUF_LEN		(sizeof(DP_buf) / sizeof(DP_buf[0]))

unsigned long sys_time = 0;
uint8_t DP_buf[] = {0x66, 0x04, 0x01, 0x00}; //{DP_ID, DP_type, DP_len, DP_data}

void pressurer_sensor_init(void)
{
	;
}

int pressure_value_get(void)
{
	uint16_t pressure_val;

	pressure_val = adc_sample_and_get_result();
	TUYA_APP_LOG_INFO("pressure_val:%d", pressure_val);

	return pressure_val;
}

void pressurer_sensor_fun(void)
{
	if(!clock_time_exceed(sys_time, 1000 * TIME_MS)){
		return;
	}
	sys_time = clock_time();
    lux_adc_init();

		if(pressure_value_get() > 0x400) {
			DP_buf[3] = HIGH;
			TUYA_APP_LOG_INFO("high press");
		} else {
			DP_buf[3] = LOW;
			TUYA_APP_LOG_INFO("low press");
		}
	tuya_ble_dp_data_report(DP_buf, BUF_LEN);
}
