#ifndef FRAMEMANAGER_HPP
#define FRAMEMANAGER_HPP

// #include "FrameManager.hpp"
#include<chrono>

namespace FrameManager {

    // private:

    inline std::chrono::time_point<std::chrono::steady_clock> startTimeTimestamp{};
    inline std::chrono::time_point<std::chrono::steady_clock> prevFrameTimestamp{};
    inline std::chrono::time_point<std::chrono::steady_clock> currentFrameTimestamp{};
    inline std::chrono::milliseconds deltaTimeSinceStart{};
    inline std::chrono::milliseconds deltaTimeSinceStartPrev{};
    inline std::chrono::milliseconds deltaTime{};

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