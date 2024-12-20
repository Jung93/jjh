#pragma once

#define PI 3.141592f

#define WIN_WIDTH 1200
#define WIN_HEIGHT 720

#define LinearInterpolation(s, e, t) s + (e - s) * t 

#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define BLUE RGB(0, 0, 255)
#define SKY RGB(209, 234, 240)
#define WHITE RGB(255, 255, 255)

using int16 = short;
using int32 = int;
using int64 = __int64;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned __int64;