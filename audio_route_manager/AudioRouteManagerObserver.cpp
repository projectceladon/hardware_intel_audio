/*
 * Copyright (C) 2013-2017 Intel Corporation
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

#include "AudioRouteManagerObserver.hpp"
#include <AudioUtilitiesAssert.hpp>

namespace audio_hal
{

AudioRouteManagerObserver::AudioRouteManagerObserver()
{
    AUDIOUTILITIES_ASSERT(sem_init(&mSyncSem, 0, 0) == 0, "failed to create semaphore");
}

AudioRouteManagerObserver::~AudioRouteManagerObserver()
{
    AUDIOUTILITIES_ASSERT(sem_destroy(&mSyncSem) == 0, "failed to destroy semaphore");
}

void AudioRouteManagerObserver::waitNotification()
{
    AUDIOUTILITIES_ASSERT(sem_wait(&mSyncSem) == 0, "failed to wait semaphore");
}

void AudioRouteManagerObserver::notify()
{
    AUDIOUTILITIES_ASSERT(sem_post(&mSyncSem) == 0, "failed to post semaphore");
}

} // namespace audio_hal
