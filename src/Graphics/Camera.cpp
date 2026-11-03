#include "Camera.h"

int CameraX = 0;
int CameraY = 0;

void UpdateCamera(int targetX, int targetY, int screenWidth, int screenHeight) {
    CameraX = targetX - (screenWidth / 2);
    CameraY = targetY - (screenHeight / 2);

    if (CameraX < 0)
        CameraX = 0;

    if (CameraY < 0)
        CameraY = 0;
}