/* 
 * SimpleKalmanFilter - a Kalman Filter implementation for single variable models.
 * Created by Denys Sene, January, 1, 2017.
 * Released under MIT License - see LICENSE file for details.
 */

#include "SimpleKalmanFilter.h"
#include <math.h>

 float _err_measure;
 float _err_estimate;
 float _q;
 float _current_estimate;
 float _last_estimate;
 float _kalman_gain;
 
 float _err_measure_2;
 float _err_estimate_2;
 float _q_2;
 float _current_estimate_2;
 float _last_estimate_2;
 float _kalman_gain_2;
 
  float _err_measure_3;
 float _err_estimate_3;
 float _q_3;
 float _current_estimate_3;
 float _last_estimate_3;
 float _kalman_gain_3;
 
  float _err_measure_4;
 float _err_estimate_4;
 float _q_4;
 float _current_estimate_4;
 float _last_estimate_4;
 float _kalman_gain_4;
 
  float _err_measure_5;
 float _err_estimate_5;
 float _q_5;
 float _current_estimate_5;
 float _last_estimate_5;
 float _kalman_gain_5;
 
  float _err_measure_6;
 float _err_estimate_6;
 float _q_6;
 float _current_estimate_6;
 float _last_estimate_6;
 float _kalman_gain_6;

/* filte 1 */
void SimpleKalmanFilter(float mea_e, float est_e, float q)
{
  _err_measure=mea_e;
  _err_estimate=est_e;
  _q = q;
}

float updateEstimate(float mea)
{
  _kalman_gain = _err_estimate/(_err_estimate + _err_measure);
  _current_estimate = _last_estimate + _kalman_gain * (mea - _last_estimate);
  _err_estimate =  (1.0 - _kalman_gain)*_err_estimate + fabs(_last_estimate-_current_estimate)*_q;
  _last_estimate=_current_estimate;

  return _current_estimate;
}

void setMeasurementError(float mea_e)
{
  _err_measure=mea_e;
}

void setEstimateError(float est_e)
{
  _err_estimate=est_e;
}

void setProcessNoise(float q)
{
  _q=q;
}

float getKalmanGain() {
  return _kalman_gain;
}

/* Filter 2 */
void SimpleKalmanFilter_2(float mea_e, float est_e, float q)
{
  _err_measure_2=mea_e;
  _err_estimate_2=est_e;
  _q_2 = q;
}

float updateEstimate_2(float mea)
{
  _kalman_gain_2 = _err_estimate_2/(_err_estimate_2 + _err_measure_2);
  _current_estimate_2 = _last_estimate_2 + _kalman_gain_2 * (mea - _last_estimate_2);
  _err_estimate_2 =  (1.0 - _kalman_gain_2)*_err_estimate_2 + fabs(_last_estimate_2-_current_estimate_2)*_q_2;
  _last_estimate_2=_current_estimate_2;

  return _current_estimate_2;
}

float getKalmanGain_2() {
  return _kalman_gain_2;
}


/* Filter 3 */
void SimpleKalmanFilter_3(float mea_e, float est_e, float q)
{
  _err_measure_3=mea_e;
  _err_estimate_3=est_e;
  _q_3 = q;
}

float updateEstimate_3(float mea)
{
  _kalman_gain_3 = _err_estimate_3/(_err_estimate_3 + _err_measure_3);
  _current_estimate_3 = _last_estimate_3 + _kalman_gain_3 * (mea - _last_estimate_3);
  _err_estimate_3 =  (1.0 - _kalman_gain_3)*_err_estimate_3 + fabs(_last_estimate_3-_current_estimate_3)*_q_3;
  _last_estimate_3=_current_estimate_3;

  return _current_estimate_3;
}

float getKalmanGain_3() {
  return _kalman_gain_3;
}

/* Filter 4 */
void SimpleKalmanFilter_4(float mea_e, float est_e, float q)
{
  _err_measure_4=mea_e;
  _err_estimate_4=est_e;
  _q_4 = q;
}

float updateEstimate_4(float mea)
{
  _kalman_gain_4 = _err_estimate_4/(_err_estimate_4 + _err_measure_4);
  _current_estimate_4 = _last_estimate_4 + _kalman_gain_4 * (mea - _last_estimate_4);
  _err_estimate_4 =  (1.0 - _kalman_gain_4)*_err_estimate_4 + fabs(_last_estimate_4-_current_estimate_4)*_q_4;
  _last_estimate_4=_current_estimate_4;

  return _current_estimate_4;
}

float getKalmanGain_4() {
  return _kalman_gain_4;
}

/* Filter 5 */
void SimpleKalmanFilter_5(float mea_e, float est_e, float q)
{
  _err_measure_5=mea_e;
  _err_estimate_5=est_e;
  _q_5 = q;
}

float updateEstimate_5(float mea)
{
  _kalman_gain_5 = _err_estimate_5/(_err_estimate_5 + _err_measure_5);
  _current_estimate_5 = _last_estimate_5 + _kalman_gain_5 * (mea - _last_estimate_5);
  _err_estimate_5 =  (1.0 - _kalman_gain_5)*_err_estimate_5 + fabs(_last_estimate_5-_current_estimate_5)*_q_5;
  _last_estimate_5=_current_estimate_5;

  return _current_estimate_5;
}

float getKalmanGain_5() {
  return _kalman_gain_5;
}

/* Filter 6 */
void SimpleKalmanFilter_6(float mea_e, float est_e, float q)
{
  _err_measure_6=mea_e;
  _err_estimate_6=est_e;
  _q_6 = q;
}

float updateEstimate_6(float mea)
{
  _kalman_gain_6 = _err_estimate_6/(_err_estimate_6 + _err_measure_6);
  _current_estimate_6 = _last_estimate_6 + _kalman_gain_6 * (mea - _last_estimate_6);
  _err_estimate_6 =  (1.0 - _kalman_gain_6)*_err_estimate_6 + fabs(_last_estimate_6-_current_estimate_6)*_q_6;
  _last_estimate_6=_current_estimate_6;

  return _current_estimate_6;
}

float getKalmanGain_6() {
  return _kalman_gain_6;
}