// -*- C++ -*-
/*!
 * @file  PathPlanning.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "PathPlanning.h"

// Module specification
// <rtc-template block="module_spec">
static const char* pathplanning_spec[] =
  {
    "implementation_id", "PathPlanning",
    "type_name",         "PathPlanning",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "Intelligent Systems Lab.",
    "category",          "PathPlannin",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
PathPlanning::PathPlanning(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_pathPort("path"),
    m_mapPort("map")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
PathPlanning::~PathPlanning()
{
}



RTC::ReturnCode_t PathPlanning::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_pathPort.registerProvider("get_path", "RTC::PathService", m_get_path);
  
  // Set service consumers to Ports
  m_mapPort.registerConsumer("simpleMap", "Map::SimpleMap", m_getMap);
  
  // Set CORBA Service Ports
  addPort(m_pathPort);
  addPort(m_mapPort);
  
  // </rtc-template>

  m_get_path.set_rtc_ptr(this);

  // <rtc-template block="bind_config">
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PathPlanning::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onExecute(RTC::UniqueId ec_id)
{
    
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PathPlanning::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

void PathPlanning::get_map(std::string &str) {
    char *c_str;
    m_getMap->getMap(c_str);
    str.assign(c_str);
}

extern "C"
{
 
  void PathPlanningInit(RTC::Manager* manager)
  {
    coil::Properties profile(pathplanning_spec);
    manager->registerFactory(profile,
                             RTC::Create<PathPlanning>,
                             RTC::Delete<PathPlanning>);
  }
  
};


