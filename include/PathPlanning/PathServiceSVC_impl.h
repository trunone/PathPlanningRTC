// -*-C++-*-
/*!
 * @file  PathServiceSVC_impl.h
 * @brief Service implementation header of PathService.idl
 *
 */

#include "BasicDataTypeSkel.h"
#include "ExtendedDataTypesSkel.h"
#include "InterfaceDataTypesSkel.h"

#include "PathServiceSkel.h"

#include "PathPlanning.h"

#include <mrpt/base.h>
#include <mrpt/utils.h>
#include <mrpt/obs.h>
#include <mrpt/slam.h>
#include <mrpt/gui.h>

using namespace mrpt::utils;
using namespace mrpt::poses;
using namespace mrpt::slam;
using namespace mrpt::opengl;
using namespace mrpt::gui;
using namespace mrpt::system;
using namespace mrpt::math;


#ifndef PATHSERVICESVC_IMPL_H
#define PATHSERVICESVC_IMPL_H

class PathPlanning;
 
/*!
 * @class PathServiceSVC_impl
 * Example class implementing IDL interface RTC::PathService
 */
class PathServiceSVC_impl
 : public virtual POA_RTC::PathService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~PathServiceSVC_impl();

    PathPlanning *rtc_ptr;

 public:
  /*!
   * @brief standard constructor
   */
   PathServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~PathServiceSVC_impl();

   // attributes and operations
   void get_path(RTC::Path2D_out path, const RTC::Pose2D& position, const RTC::Pose2D& target);

   void set_rtc_ptr(PathPlanning *rtc_ptr) {this->rtc_ptr = rtc_ptr;}
};


#endif // PATHSERVICESVC_IMPL_H


