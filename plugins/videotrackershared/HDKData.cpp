/** @file
    @brief Implementation

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include "HDKData.h"

// Library/third-party includes
// - none

// Standard includes
// - none

namespace osvr {
namespace vbtracker {
#ifdef _MSC_VER
#pragma warning(push)
/// Suppress truncation warning so we don't have to put f after every number
/// below.
#pragma warning(disable : 4305)
#endif

    // clang-format off
    // Default 3D locations for the beacons on an OSVR HDK face plate, in
    // millimeters
    // Appears to correspond to manufacturing specs starting at LED7
    const Point3Vector OsvrHdkLedLocations_SENSOR0 = {
        cv::Point3f( -84.93, 2.65, 23.59 ), // LED7 - updated 20151211
        cv::Point3f( -83.27, -14.33, 13.89 ), // LED8 - updated 20151211
        cv::Point3f( -47, 51, 24.09 ),
        cv::Point3f( 47, 51, 24.09 ),
        cv::Point3f( 84.93, 2.65, 23.59 ),// LED11 - updated 20151211
        cv::Point3f( 83.27, -14.33, 13.89 ), // LED12 - updated 20151211
        cv::Point3f( 84.1, 19.76, 13.89 ), // LED13 - updated 20151211
        cv::Point3f( 21, 51, 24.09 ),  // Original spec was 13.09, new position works better
        cv::Point3f( -21, 51, 24.09 ), // Original spec was 13.09, new position works better
        cv::Point3f( -84.1, 19.76, 13.89 ), // LED16
        cv::Point3f( -60.41, 47.55, 44.6 ),
        cv::Point3f( -80.42, 20.48, 42.9 ),
        cv::Point3f( -82.01, 2.74, 42.4 ),
        cv::Point3f( -80.42, -14.99, 42.9 ),
        cv::Point3f( -60.41, -10.25, 48.1 ),
        cv::Point3f( -60.41, 15.75, 48.1 ),
        cv::Point3f( -30.41, 32.75, 50.5 ),
        cv::Point3f( -31.41, 47.34, 47 ),
        cv::Point3f( -0.41, -15.25, 51.3 ),
        cv::Point3f( -30.41, -27.25, 50.5 ),
        cv::Point3f( -60.44, -41.65, 45.1 ),
        cv::Point3f( -22.41, -41.65, 47.8 ),
        cv::Point3f( 21.59, -41.65, 47.8 ),
        cv::Point3f( 59.59, -41.65, 45.1 ),
        cv::Point3f( 79.63, -14.98, 42.9 ),
        cv::Point3f( 29.59, -27.25, 50.5 ),
        cv::Point3f( 81.19, 2.74, 42.4 ),
        cv::Point3f( 79.61, 20.48, 42.9 ),
        cv::Point3f( 59.59, 47.55, 44.6 ),
        cv::Point3f( 30.59, 47.55, 47 ),
        cv::Point3f( 29.59, 32.75, 50.5 ),
        cv::Point3f( -0.41, 20.75, 51.3 ),
        cv::Point3f( 59.59, 15.75, 48.1 ),
        cv::Point3f( 59.59, -10.25, 48.1 )
    };

    // Default 3D locations for the beacons on an OSVR HDK back plate, in
    // millimeters
    const Point3Vector OsvrHdkLedLocations_SENSOR1 = {
        cv::Point3f( 1, 23.8, 0 ), // never actually turns on in production
        cv::Point3f( 11, 5.8, 0 ),
        cv::Point3f( 9, -23.8, 0 ),
        cv::Point3f( 0, -8.8, 0 ), // never actually turns on in production
        cv::Point3f( -9, -23.8, 0 ),
        cv::Point3f( -12, 5.8, 0 )
    };
// clang-format on

#ifdef _MSC_VER
#pragma warning(pop)
#endif

    const Vec3Vector OsvrHdkLedDirections_SENSOR0 = {
        cv::Vec3d{-1, 0, 0},
        cv::Vec3d{-1, 0, 0},
        cv::Vec3d{0, 1, 0},
        cv::Vec3d{0, 1, 0},
        cv::Vec3d{1, 0, 0},
        cv::Vec3d{1, 0, 0},
        cv::Vec3d{1, 0, 0},
        cv::Vec3d{0, 1, 0},
        cv::Vec3d{0, 1, 0},
        cv::Vec3d{-1, 0, 0},
        cv::Vec3d{0, 0.7071067812, 0.7071067812},
        cv::Vec3d{-0.7071067812, 0, 0.7071067812},
        cv::Vec3d{-0.7071067812, 0, 0.7071067812},
        cv::Vec3d{-0.7071067812, 0, 0.7071067812},
        cv::Vec3d{-0.7071067812, 0, 0.7071067812},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0.7071067812, 0.7071067812},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, -0.7071067812, 0.7071067812},
        cv::Vec3d{0, -0.7071067812, 0.7071067812},
        cv::Vec3d{0, -0.7071067812, 0.7071067812},
        cv::Vec3d{0, -0.7071067812, 0.7071067812},
        cv::Vec3d{0.7071067812, 0, 0.7071067812},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0.7071067812, 0, 0.7071067812},
        cv::Vec3d{0.7071067812, 0, 0.7071067812},
        cv::Vec3d{0, 0.7071067812, 0.7071067812},
        cv::Vec3d{0, 0.7071067812, 0.7071067812},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1}};

    const Vec3Vector OsvrHdkLedDirections_SENSOR1 = {
        cv::Vec3d{0, 0, 1}, cv::Vec3d{0, 0, 1}, cv::Vec3d{0, 0, 1},
        cv::Vec3d{0, 0, 1}, cv::Vec3d{0, 0, 1}, cv::Vec3d{0, 0, 1}};

    /// generated by python script in this directory.
    const std::vector<double> OsvrHdkLedVariances_SENSOR0 = {
        5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 3.0, 8.0,
        8.0, 8.0, 8.0, 3.0, 3.0, 8.0, 3.0, 3.0, 8.0, 8.0, 8.0, 8.0,
        8.0, 3.0, 8.0, 8.0, 8.0, 8.0, 3.0, 3.0, 3.0, 3.0};

} // namespace vbtracker
} // namespace osvr
