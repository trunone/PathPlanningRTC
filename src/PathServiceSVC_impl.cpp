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
    string str;
    rtc_ptr->get_map(str);

    std::deque<TPoint2D> t_path;

    CSimpleMap simple_map;
    simple_map.loadFromFile("/tmp/icp_tmp.simplemap");
    COccupancyGridMap2D grid_map;
    grid_map.loadFromSimpleMap(simple_map);

    CPathPlanningCircularRobot path_planning;
    path_planning.robotRadius = 0.30f;

    bool not_found;
    path_planning.computePath(grid_map,
            CPose2D(position.position.x, position.position.y, position.heading),
            CPose2D(target.position.x, target.position.y, target.heading), t_path, not_found, 1000.0f);

    path = new RTC::Path2D();
    if(!not_found) {
        path->waypoints.length(t_path.size());
        int i = 0;
        std::deque<TPoint2D>::const_iterator it = t_path.begin();
        for(;it != t_path.end(); ++it, i++) {
            path->waypoints[i].target.position.x = it->x;
            path->waypoints[i].target.position.y = it->y;
            std::cout<<"Path Point "<<it->x<<" "<<it->y<<std::endl;
        }
    } else {
        path->waypoints.length(0);
        cout<<"Not Found"<<endl;
    }
}


// End of example implementational code



