/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_IAUDIOPOLICYSERVICECLIENT_H
#define ANDROID_IAUDIOPOLICYSERVICECLIENT_H


#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <system/audio.h>

namespace android {

// ----------------------------------------------------------------------------

class IAudioPolicyServiceClient : public IInterface
{
public:
    DECLARE_META_INTERFACE(AudioPolicyServiceClient);

    // Notifies a change of audio port configuration.
    virtual void onAudioPortListUpdate() = 0;
    // Notifies a change of audio patch configuration.
    virtual void onAudioPatchListUpdate() = 0;
    // Notifies a change in the mixing state of a specific mix in a dynamic audio policy
    virtual void onDynamicPolicyMixStateUpdate(String8 regId, int32_t state) = 0;
    // Notifies when a default effect set is attached to a session/stream
    virtual void onOutputSessionEffectsUpdate(audio_stream_type_t stream,
                                              audio_session_t sessionId,
                                              audio_output_flags_t flags,
                                              audio_channel_mask_t channelMask,
                                              uid_t uid, bool added) = 0;
};


// ----------------------------------------------------------------------------

class BnAudioPolicyServiceClient : public BnInterface<IAudioPolicyServiceClient>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

// ----------------------------------------------------------------------------

}; // namespace android

#endif // ANDROID_IAUDIOPOLICYSERVICECLIENT_H
