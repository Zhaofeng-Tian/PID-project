#include "PID.h"
#include <cmath>
#include <iostream>

using namespace std;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    /**
     * TODO: Initialize PID coefficients (and errors, if needed)
     */
    PID::Kp = Kp_;
    PID::Ki = Ki_;
    PID::Kd = Kd_;

}

void PID::UpdateError(double cte) {
    /**
     * TODO: Update PID errors based on cte.
     */
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;

}

void PID::UpdateSpeedError(double speed_error) {
    /**
     * TODO: Update PID errors based on speed error.
     */
    d_speed_error = speed_error - p_speed_error;
    p_speed_error = speed_error;
    i_speed_error += speed_error;


}

double PID::TotalError() {
    /**
     * TODO: Calculate and return the total error
     */
    return -Kp * p_error - Kd * d_error - Ki * i_error;  // TODO: Add your total error calc here!
}

double PID::TotalSpeedError() {
    /**
     * TODO: Calculate and return the total speed error
     */
    return -Kp * p_speed_error - Kd * d_speed_error - Ki * i_speed_error;  // TODO: Add your total error calc here!
}