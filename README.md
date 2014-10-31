PathPlanningRTC
====

Layout
----

![Path Planning RTC](https://farm4.staticflickr.com/3954/15665417562_c231727b2a_o.png)

Features
----
  * Receive the environment map in the string format
  * Receive start position and target position then it will calculate path and send back

Requirements
----
  * Libraries
   * Mobile Robot Programming Toolkit 0.9.x
  * OS
   * Linux Distributions
   * Windows
  * Softwares
   * OpenRTM-aist C++ 1.1 or later
   * CMake 2.8

Port
----

| Name     | Type          | Data Type   | Purpose |
| -------- | ------------- | ----------- | ------- |
| path     | Service       | PathService | Get the target position and the original position and send back the path |
| map      | Service       | MapService  | Get the environment map |

  * PathService.idl

| Function | Variable | Type | Data Type | Purpose |
| -------- | -------- | ---- | --------- | ------- |
| get_path | path     | out | RTC::Path2D | The found path |
|          | position | in  | RTC::Pose2D | The robot position |
|          | target   | in  | RTC::Pose2D | The target position |

  * MapService.idl

| Function | Variable | Type | Data Type   |
| -------- | -------- | ---- | ----------- |
| getMap   | arg      | out  | string      |

Usage
----

Download and install [Mobile Robot Programming Toolkit](http://www.mrpt.org/)

License
----

Licensed under the [Apache License, Version 2.0][Apache]  
Distributed under the [MIT License][mit].  
Dual licensed under the [MIT license][MIT] and [Apache License, Version 2.0][Apache].  
 
[Apache]: http://www.apache.org/licenses/LICENSE-2.0
[MIT]: http://www.opensource.org/licenses/mit-license.php
