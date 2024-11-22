#ifndef FRAMEMANAGER_HPP
#define FRAMEMANAGER_HPP

// #include "FrameManager.hpp"
#include<chrono>

class FrameManager {

    private:

    static std::chrono::time_point<std::chrono::steady_clock> prevFrameTimestamp;
    static std::chrono::time_point<std::chrono::steady_clock> currentFrameTimestamp;
    static std::chrono::milliseconds deltaTime;

    public:

    FrameManager() = delete;
    static const std::chrono::milliseconds& getDeltaTime(void);
    static const std::chrono::time_point<std::chrono::steady_clock>& getCurrentFrameTimestamp(void);
    static const std::chrono::time_point<std::chrono::steady_clock>& getPrevFrameTimestamp(void);
    static void updateFrame(void);
    static void init(void);

};


#endif // FRAMEMANAGER_HPP
