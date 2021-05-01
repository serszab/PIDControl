#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(const double Kp_, const double Ki_, const double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  prev_cte = 0.0;
}

void PID::UpdateError(const double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  prev_cte = cte;
  
  //total_square_error += cte * cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return - Kp * p_error - Ki * i_error - Kd * d_error;  // TODO: Add your total error calc here!
}
