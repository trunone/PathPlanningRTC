// -*-C++-*-
/*!
 * @file  PathServiceSVC_impl.cpp
 * @brief Service implementation code of PathService.idl
 *
 */

#include "PathServiceSVC_impl.h"

/*
 * Example implementational code for IDL interface RTC::PathService
 */
PathServiceSVC_impl::PathServiceSVC_impl()
{
  // Please add extra constructor code here.
}


PathServiceSVC_impl::~PathServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void PathServiceSVC_impl::get_path(RTC::Path2D_out path, const RTC::Pose2D& position, const RTC::Pose2D& target)
{
    CSerializablePtr serializable_ptr;
    // Convert the simple map from string format to serializable object
    StringToObject(rtc_ptr_->get_map(), serializable_ptr);

    // The path
    std::deque<TPoint2D> deque_path;

    COccupancyGridMap2D grid_map;
    // Convert serializable simple map object to grid map
    grid_map.loadFromSimpleMap(*CSimpleMapPtr(serializable_ptr));

    CPathPlanningCircularRobot path_planning;
    path_planning.robotRadius = 0.15f;

    bool not_found;
    // Find the path
    path_planning.computePath(grid_map,
            CPose2D(position.position.x, position.position.y, position.heading),
            CPose2D(target.position.x, target.position.y, target.heading),
            deque_path, not_found, 1000.0f);

    path = new RTC::Path2D();
    if(!not_found) { // if found any path
        // Copy path from deque_path to path
        path->waypoints.length(deque_path.size());
        int i = 0;
        std::deque<TPoint2D>::const_iterator it = deque_path.begin();
        for(;it != deque_path.end(); ++it, i++) {
            path->waypoints[i].target.position.x = it->x;
            path->waypoints[i].target.position.y = it->y;
            path->waypoints[i].target.heading = 0.0f;
        }
    } else { // if didn't find the path
        path->waypoints.length(0);
        cout<<"Not Found"<<endl;
    }
}


// End of example implementational code



