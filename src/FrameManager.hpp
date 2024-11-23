#ifndef FRAMEMANAGER_HPP
#define FRAMEMANAGER_HPP

// #include "FrameManager.hpp"
#include<chrono>

namespace FrameManager {

    // private:

    static std::chrono::time_point<std::chrono::steady_clock> startTimeTimestamp;
    static std::chrono::time_point<std::chrono::steady_clock> prevFrameTimestamp;
    static std::chrono::time_point<std::chrono::steady_clock> currentFrameTimestamp;
    static std::chrono::milliseconds deltaTimeSinceStart;
    static std::chrono::milliseconds deltaTimeSinceStartPrev;
    static std::chrono::milliseconds deltaTime;

    // public:

    // FrameManager() = delete;
    // virtual void nonconstructible(void) = 0;
    // [[nodiscard]]
    // static const std::chrono::milliseconds& getDeltaTime(void);
    // [[nodiscard]]
    // static const std::chrono::milliseconds& getCurrentFrameTimestamp(void);
    // [[nodiscard]]
    // static const std::chrono::milliseconds& getPrevFrameTimestamp(void);
    void updateFrame(void);
    void init(void);

};


#endif // FRAMEMANAGER_HPP
