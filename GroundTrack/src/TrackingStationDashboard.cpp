#define OLC_PGE_APPLICATION // if you define it in header, then when library compile, it defines once, and when outside include it, it defines again
#include "TrackingStationDashboard.h"

using namespace kharsair::astk;

GroundTrackDashboard::GroundTrackDashboard(const std::string& dashboardName)
{
    sAppName = dashboardName;
}

void GroundTrackDashboard::show(int32_t screen_w, int32_t screen_h, int32_t pixel_w, int32_t pixel_h ) {
    if (this->Construct(screen_w, screen_h, pixel_w, pixel_h))
        this->Start();
}

bool GroundTrackDashboard::OnUserCreate() {
    return True;
}

bool GroundTrackDashboard::OnUserUpdate(float fElapsedTime) {
    for (int x = 0; x < ScreenWidth(); x++)
        for (int y = 0; y < ScreenHeight(); y++)
            Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
    return true;
}
