/* 
 * SimpleKalmanFilter - a Kalman Filter implementation for single variable models.
 * Created by Denys Sene, January, 1, 2017.
 * Released under MIT License - see LICENSE file for details.
 */

//#ifndef SimpleKalmanFilter_h
//#define SimpleKalmanFilter_h


void	SimpleKalmanFilter(float mea_e, float est_e, float q);
float updateEstimate(float mea);
/*
void setMeasurementError(float mea_e);
void setEstimateError(float est_e);
void setProcessNoise(float q);
float getKalmanGain();

extern float _err_measure;
extern float _err_estimate;
extern float _q;
extern float _current_estimate;
extern float _last_estimate;
extern float _kalman_gain;
*/
void	SimpleKalmanFilter_2(float mea_e, float est_e, float q);
float updateEstimate_2(float mea);

void	SimpleKalmanFilter_3(float mea_e, float est_e, float q);
float updateEstimate_3(float mea);

void	SimpleKalmanFilter_4(float mea_e, float est_e, float q);
float updateEstimate_4(float mea);

void	SimpleKalmanFilter_5(float mea_e, float est_e, float q);
float updateEstimate_5(float mea);

void	SimpleKalmanFilter_6(float mea_e, float est_e, float q);
float updateEstimate_6(float mea);
//#endif
