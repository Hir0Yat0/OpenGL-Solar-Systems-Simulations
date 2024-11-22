#include "FrameManager.hpp"

const std::chrono::milliseconds& FrameManager::getDeltaTime(void) {
    return FrameManager::deltaTime;
}

const std::chrono::time_point<std::chrono::steady_clock>& FrameManager::getCurrentFrameTimestamp(void) {
    return FrameManager::currentFrameTimestamp;
}

const std::chrono::time_point<std::chrono::steady_clock>& FrameManager::getPrevFrameTimestamp(void) {
    return FrameManager::prevFrameTimestamp;
}

void FrameManager::updateFrame(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - FrameManager::prevFrameTimestamp);
    FrameManager::prevFrameTimestamp = FrameManager::currentFrameTimestamp;
    FrameManager::currentFrameTimestamp = now;
}

void FrameManager::init(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::milliseconds(0);
    FrameManager::prevFrameTimestamp = now;
    FrameManager::currentFrameTimestamp = now;
}
