#ifndef V6534PC_HH
#define V6534PC_HH 1

#ifndef LINUX
#define LINUX
#endif
#define V6534PC_VMAX 0x0050
#define V6534PC_IMAX 0x0054
#define V6534PC_STATUS 0x0058
#define V6534PC_FWREL 0x005C

#define V6534PC_VSET_CH0 0x0080
#define V6534PC_ISET_CH0 0x0084
#define V6534PC_VMON_CH0 0x0088
#define V6534PC_IMONH_CH0 0x008C
#define V6534PC_PW_CH0 0x0090
#define V6534PC_CHSTATUS_CH0 0x0094
#define V6534PC_TRIP_TIME_CH0 0x0098
#define V6534PC_SVMAX_CH0 0x009C
#define V6534PC_RAMP_DOWN_CH0 0x00A0
#define V6534PC_RAMP_UP_CH0 0x00A4
#define V6534PC_PWDOWN_CH0 0x00A8
#define V6534PC_POLARITY_CH0 0x00AC
#define V6534PC_TEMPERATURE_CH0 0x00B0
#define V6534PC_IMON_RANGE_CH0 0x00B4
#define V6534PC_IMONL_CH0 0x00B8

#define V6534PC_VSET_CH1 0x0100
#define V6534PC_ISET_CH1 0x0104
#define V6534PC_VMON_CH1 0x0108
#define V6534PC_IMONH_CH1 0x010C
#define V6534PC_PW_CH1 0x0110
#define V6534PC_CHSTATUS_CH1 0x0114
#define V6534PC_TRIP_TIME_CH1 0x0118
#define V6534PC_SVMAX_CH1 0x011C
#define V6534PC_RAMP_DOWN_CH1 0x0120
#define V6534PC_RAMP_UP_CH1 0x0124
#define V6534PC_PWDOWN_CH1 0x0128
#define V6534PC_POLARITY_CH1 0x012C
#define V6534PC_TEMPERATURE_CH1 0x0130
#define V6534PC_IMON_RANGE_CH1 0x0134
#define V6534PC_IMONL_CH1 0x0138

#define V6534PC_VSET_CH2 0x0180
#define V6534PC_ISET_CH2 0x0184
#define V6534PC_VMON_CH2 0x0188
#define V6534PC_IMONH_CH2 0x018C
#define V6534PC_PW_CH2 0x0190
#define V6534PC_CHSTATUS_CH2 0x0194
#define V6534PC_TRIP_TIME_CH2 0x0198
#define V6534PC_SVMAX_CH2 0x019C
#define V6534PC_RAMP_DOWN_CH2 0x01A0
#define V6534PC_RAMP_UP_CH2 0x01A4
#define V6534PC_PWDOWN_CH2 0x01A8
#define V6534PC_POLARITY_CH2 0x01AC
#define V6534PC_TEMPERATURE_CH2 0x01B0
#define V6534PC_IMON_RANGE_CH2 0x01B4
#define V6534PC_IMONL_CH2 0x01B8

#define V6534PC_VSET_CH3 0x0200
#define V6534PC_ISET_CH3 0x0204
#define V6534PC_VMON_CH3 0x0208
#define V6534PC_IMONH_CH3 0x020C
#define V6534PC_PW_CH3 0x0210
#define V6534PC_CHSTATUS_CH3 0x0214
#define V6534PC_TRIP_TIME_CH3 0x0218
#define V6534PC_SVMAX_CH3 0x021C
#define V6534PC_RAMP_DOWN_CH3 0x0220
#define V6534PC_RAMP_UP_CH3 0x0224
#define V6534PC_PWDOWN_CH3 0x0228
#define V6534PC_POLARITY_CH3 0x022C
#define V6534PC_TEMPERATURE_CH3 0x0230
#define V6534PC_IMON_RANGE_CH3 0x0234
#define V6534PC_IMONL_CH3 0x0238

#define V6534PC_VSET_CH4 0x0280
#define V6534PC_ISET_CH4 0x0284
#define V6534PC_VMON_CH4 0x0288
#define V6534PC_IMONH_CH4 0x028C
#define V6534PC_PW_CH4 0x0290
#define V6534PC_CHSTATUS_CH4 0x0294
#define V6534PC_TRIP_TIME_CH4 0x0298
#define V6534PC_SVMAX_CH4 0x029C
#define V6534PC_RAMP_DOWN_CH4 0x02A0
#define V6534PC_RAMP_UP_CH4 0x02A4
#define V6534PC_PWDOWN_CH4 0x02A8
#define V6534PC_POLARITY_CH4 0x02AC
#define V6534PC_TEMPERATURE_CH4 0x02B0
#define V6534PC_IMON_RANGE_CH4 0x02B4
#define V6534PC_IMONL_CH4 0x02B8

#define V6534PC_VSET_CH5 0x0300
#define V6534PC_ISET_CH5 0x0304
#define V6534PC_VMON_CH5 0x0308
#define V6534PC_IMONH_CH5 0x030C
#define V6534PC_PW_CH5 0x0310
#define V6534PC_CHSTATUS_CH5 0x0314
#define V6534PC_TRIP_TIME_CH5 0x0318
#define V6534PC_SVMAX_CH5 0x031C
#define V6534PC_RAMP_DOWN_CH5 0x0320
#define V6534PC_RAMP_UP_CH5 0x0324
#define V6534PC_PWDOWN_CH5 0x0328
#define V6534PC_POLARITY_CH5 0x032C
#define V6534PC_TEMPERATURE_CH5 0x0330
#define V6534PC_IMON_RANGE_CH5 0x0334
#define V6534PC_IMONL_CH5 0x0338

#define V6534PC_CHNUM 0x8100
#define V6534PC_SERNUM 0x811E
#define V6534PC_VME_FWREL 0x8120

#define V6534PC_BASE_ADDRESS 0x32130000
//#define V6534PC_CURRENT_RESOLUTION 0.02 /* 20 nA */
#define V6534PC_VOLTAGE_RESOLUTION 0.1 /* 0.1 V */
#define V6534PC_TIME_RESOLUTION 0.1 /* 0.1 s */
#define V6534PC_NUM_CHANNELS 6
#define V6534PC_MAX_VOLTAGE 6000
#define V6534PC_RAMP_SPEED 5

#include <sys/types.h>
#include <stdint.h>
#include "CAENVMElib.h"

float V6534PC_CURRENT_RESOLUTION = 0.02;
CVErrorCodes write_to_v6534pc(uint32_t vme_addr, uint32_t data);
CVErrorCodes read_from_v6534pc(uint32_t vme_addr);
int get_powered_v6534pc(uint32_t ch_num);
CVErrorCodes set_svmax_v6534pc(uint32_t ch_num, uint32_t vmax);
int get_svmax_v6534pc(uint32_t ch_num);
CVErrorCodes set_current_v6534pc(uint32_t ch_num, float current);
CVErrorCodes set_voltage_v6534pc(uint32_t ch_num, uint32_t voltage);
CVErrorCodes set_ramp_up_v6534pc(uint32_t ch_num, uint32_t volts_per_sec);
int get_ramp_up_v6534pc(uint32_t ch_num);
CVErrorCodes set_ramp_down_v6534pc(uint32_t ch_num, uint32_t volts_per_sec);
int get_ramp_down_v6534pc(uint32_t ch_num);
CVErrorCodes set_trip_time_v6534pc(uint32_t ch_num, uint32_t trip_time);
int get_trip_time_v6534pc(uint32_t ch_num);
float get_current_v6534pc(uint32_t ch_num);
float get_config_current_v6534pc(uint32_t ch_num);
float get_voltage_v6534pc(uint32_t ch_num);
float get_config_voltage_v6534pc(uint32_t ch_num);
uint32_t* get_channel_status_v6534pc(uint32_t ch_num);
CVErrorCodes enable_channel_v6534pc(uint32_t ch_num);
CVErrorCodes disable_channel_v6534pc(uint32_t ch_num);
CVErrorCodes kill_channel_v6534pc(uint32_t ch_num);
CVErrorCodes ramp_down_channel_v6534pc(uint32_t ch_num);
CVErrorCodes set_imon_high_v6534pc(uint32_t ch_num);
CVErrorCodes set_imon_low_v6534pc(uint32_t ch_num);
int get_pwdown_v6534pc(uint32_t ch_num);
int get_imon_range_v6534pc(uint32_t ch_num);
#endif /*V6534PC_HH*/



