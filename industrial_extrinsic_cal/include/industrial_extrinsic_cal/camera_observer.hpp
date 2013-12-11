#include <industrial_extrinsic_cal/Swri_IRD_license.h>

#ifndef CAMERA_OBSERVER_HPP_
#define CAMERA_OBSERVER_HPP_

#include <industrial_extrinsic_cal/basic_types.h> /** needed for target,Roi, & Observation */

namespace industrial_extrinsic_cal {

typedef struct { /** Structure returned by Camera Observer */
  std::vector<Observation> obs;
}Camera_Observations;

class CameraObserver{ 
public:
  CameraObserver(std::string source_name); /** @brief constructor */
                                           /** @param source_name name of image topic */
  virtual void add_target(Target *T, Roi R);/** @brief add a target to look for */
                                            /** @param T a target to look for */
                                            /** @param R Region of interest for target */
  virtual void clear_targets();	/** @brief remove all targets */
  virtual void clear_observations(); /** @brief clear all previous observations */
  virtual int get_observations(Observation &CO); /** @brief perform the observation */
                                                 /** @param output all observations */
};

} // end of namespace
#endif