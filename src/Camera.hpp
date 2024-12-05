#ifndef CAMERA_HPP
#define CAMERA_HPP

// #include "Camera.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glmlib.hpp"

class Camera {

    private:

    // Default camera values
    static constexpr float YAW = -90.0f;
    static constexpr float PITCH = 0.0f;
    static constexpr float SPEED = 2.5f;
    static constexpr float SENSITIVITY = 0.1f;
    static constexpr float ZOOM = 45.0f;



    



    public:

    // Camera attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    // Euler Angles
    float Yaw;
    float Pitch;

    // Camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // prev states
    bool firstMouse;
    float prevPosX;
    float prevPosY;

    enum Camera_Movement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT,
    };

    // Constructor
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    // Returns the view matrix
    // [[no_discard]]
    glm::mat4 GetViewMatrix() ;

    
    // Updates the camera's vectors
    void updateCameraVectors() ;

    // Processes keyboard input
    void ProcessKeyboard(Camera_Movement direction, float deltaTime) ;

    // Processes mouse movement
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) ;

    // Processes mouse scroll input
    void ProcessMouseScroll(float yoffset) ;

};


#endif // CAMERA_HPP
