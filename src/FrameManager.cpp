#include "FrameManager.hpp"

// const std::chrono::milliseconds& FrameManager::getDeltaTime(void) {
//     return FrameManager::deltaTime;
// }

// const std::chrono::milliseconds& FrameManager::getCurrentFrameTimestamp(void) {
//     return FrameManager::deltaTimeSinceStart;
// }

// const std::chrono::milliseconds& FrameManager::getPrevFrameTimestamp(void) {
//     return FrameManager::deltaTimeSinceStartPrev;
// }

void FrameManager::updateFrame(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - FrameManager::prevFrameTimestamp);
    FrameManager::prevFrameTimestamp = FrameManager::currentFrameTimestamp;
    FrameManager::currentFrameTimestamp = now;
    FrameManager::deltaTimeSinceStart = std::chrono::duration_cast<std::chrono::milliseconds>(FrameManager::currentFrameTimestamp - FrameManager::startTimeTimestamp);
    FrameManager::deltaTimeSinceStartPrev = std::chrono::duration_cast<std::chrono::milliseconds>(FrameManager::prevFrameTimestamp - FrameManager::startTimeTimestamp);
}

void FrameManager::init(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::milliseconds(0);
    FrameManager::deltaTimeSinceStart = std::chrono::milliseconds(0);
    FrameManager::deltaTimeSinceStartPrev = std::chrono::milliseconds(0);
    FrameManager::startTimeTimestamp = now;
    FrameManager::prevFrameTimestamp = now;
    FrameManager::currentFrameTimestamp = now;
    
}