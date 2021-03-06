/*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2014, Timm Linder, Social Robotics Lab, University of Freiburg
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  * Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*  * Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _PAIRING_H
#define _PAIRING_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include <Eigen/Core>

#include <srl_nearest_neighbor_tracker/data/observation.h>
#include <srl_nearest_neighbor_tracker/data/track.h>
#include <srl_nearest_neighbor_tracker/base/defs.h>


namespace srl_nnt
{

/// A pairing is an assignment of a Track and an Observation.
struct Pairing
{
    /// The track of this pairing
    Track::Ptr track;

    /// The observation of this pairing
    Observation::Ptr observation;

    /// Flag indicating if pairing has a singular innovation covariance matrix
    bool singular;

    /// Flag indicating if pairing is validated. The Kalman filter of a track is only updated with validated pairings
    bool validated;

    /// Mahalanobis distance of a pairing
    double d;

    /// Innovation v (nu) of a pairing
    ObsVector v;

    /// Innovation covariance matrix S, inversed
    ObsMatrix Sinv;

    /// Typedefs for easier readability
    typedef boost::shared_ptr<Pairing> Ptr;
    typedef boost::shared_ptr<const Pairing> ConstPtr;
};


/// Typedef for easier readability
typedef std::vector<Pairing::Ptr> Pairings;


} // end of namespace srl_nnt


#endif // _PAIRING_H
