#include "tic.h"
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));
typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;
typedef int8_t int_fast8_t;
typedef uint8_t uint_fast8_t;
typedef int16_t int_fast16_t;
typedef uint16_t uint_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast32_t;
typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;
typedef int64_t intmax_t;
typedef uint64_t uintmax_t;
typedef int32_t int_farptr_t;
typedef uint32_t uint_farptr_t;
extern uint16_t adc_samples[ 8 ];
void adc_init( void );
struct adc_buf {
  uint16_t sum;
  uint16_t values[0x20];
  uint8_t head;
};
void adc_buf_channel(uint8_t adc_channel, struct adc_buf* s);
extern int16_t ir_roll;
extern int16_t ir_pitch;
extern float ir_rad_of_ir;
extern int16_t ir_contrast;
extern int16_t ir_roll_neutral;
extern int16_t ir_pitch_neutral;
void ir_init(void);
void ir_update(void);
void ir_gain_calib(void);
typedef uint8_t bool_t;
typedef int16_t pprz_t;
struct inter_mcu_msg {
  int16_t channels[9];
  uint8_t ppm_cpt;
  uint8_t status;
  uint8_t nb_err;
  uint8_t vsupply;
};
void test_ppm_task(void);
void check_mega128_values_task(void);
void send_data_to_autopilot_task(void);
void check_failsafe_task(void);
extern uint8_t pprz_mode;
extern uint8_t ir_estim_mode;
extern uint8_t fatal_error_nb;
extern uint8_t inflight_calib_mode;
extern uint8_t vertical_mode;
extern bool_t auto_pitch;
extern uint8_t lateral_mode;
extern uint8_t vsupply;
extern bool_t rc_event_1, rc_event_2;
extern float slider_1_val, slider_2_val;
extern bool_t launch;
void periodic_task( void );
void use_gps_pos(void);
void radio_control_task(void);
void receive_gps_data_task(void);
void stabilisation_task(void);
extern float estimator_x;
extern float estimator_y;
extern float estimator_z;
extern float estimator_phi;
extern float estimator_psi;
extern float estimator_theta;
extern float estimator_x_dot;
extern float estimator_y_dot;
extern float estimator_z_dot;
extern float estimator_phi_dot;
extern float estimator_psi_dot;
extern float estimator_teta_dot;
extern uint16_t estimator_flight_time;
extern float estimator_t;
extern float estimator_hspeed_mod;
extern float estimator_hspeed_dir;
void estimator_init( void );
void estimator_update_state_infrared( void );
void estimator_update_state_gps( void );
void estimator_propagate_state( void );
extern float estimator_rad_of_ir, estimator_ir, estimator_rad;
int16_t ir_roll;
int16_t ir_pitch;
int16_t ir_contrast = 200;
int16_t ir_roll_neutral = -915;
int16_t ir_pitch_neutral = 110;
float ir_rad_of_ir = 0.75 / 200;
static struct adc_buf buf_ir1;
static struct adc_buf buf_ir2;
void ir_init(void) {
  TIC(40) /* BBs: 2, 3, 4, 5, 1 */, ir_rad_of_ir = 0.75 / 200;;
  adc_buf_channel(1, &buf_ir1);
  adc_buf_channel(2, &buf_ir2);
}
void ir_update(void) {
  TIC(108) /* BBs: 1 */; int16_t x1_mean = buf_ir1.sum/0x20;
  int16_t x2_mean = buf_ir2.sum/0x20;
  ir_roll = (-1*(x1_mean)+ -1*(x2_mean)) - ir_roll_neutral;
  ir_pitch = (-1*(x1_mean)+ 1*(x2_mean)) - ir_pitch_neutral;
}
void ir_gain_calib(void) {
  TIC(1355) /* BBs: 2, 3, 4, 5, 6, 7, 1, __floatsisf, __divsf3 */, ir_contrast = - ir_pitch;
  ir_rad_of_ir = 0.75 / ir_contrast;;
}
