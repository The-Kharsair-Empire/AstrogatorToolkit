#pragma once

#ifndef GROUND_TRACK_DASHBOARD_H
#define GROUND_TRACK_DASHBOARD_H

#include <olcPixelGameEngine.h>

namespace kharsair::astk
{
    class GroundTrackDashboard : public olc::PixelGameEngine {
    public:
        GroundTrackDashboard(const std::string& dashboardName);

    private:


    public:
        bool OnUserCreate() override;

        bool OnUserUpdate(float fElapsedTime) override;

        void show(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h );
    };
} 


#endif