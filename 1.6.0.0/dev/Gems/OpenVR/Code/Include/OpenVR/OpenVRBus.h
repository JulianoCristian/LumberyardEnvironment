/*
 * All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
 * its licensors.
 *
 * For complete copyright and license terms please see the LICENSE at the root of this
 * distribution (the "License"). All use of this software is governed by the License,
 * or, if provided, by the license below or the license accompanying this file. Do not
 * remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 */

#include <AzCore/EBus/EBus.h>
#include <AzCore/Math/Vector3.h>

namespace OpenVR
{
    class OpenVRRequests
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////

        ///
        /// Rectangle storing the playspace defined by the user when
        /// setting up OpenVR.
        ///
        struct Playspace
        {
            bool isValid = false; ///< The playspace data is valid (calibrated).
            AZ::Vector3 corners[4];      ///< Playspace corners defined in device-local space. The center of the playspace is 0.
        };

        virtual void GetPlayspace(Playspace& playspace) const = 0;
    };
    using OpenVRRequestBus = AZ::EBus<OpenVRRequests>;
}
