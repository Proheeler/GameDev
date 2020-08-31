#pragma once
#include <UtilityStructs.h>
struct GameParameters
{
    /* data */
    static constexpr Speed paddleSpeed{20, 20};
    static constexpr Speed ballSpeed{20, 30};
    static constexpr int ballRadius{20};
    static constexpr Dimensions2D paddlePos{100, 0};
    static constexpr Dimensions2D paddleSize{200, 25};
    static constexpr Dimensions2D circlePos{500, 500};
    static constexpr Dimensions2D windowSize{1000, 1000};
    static constexpr Dimensions2D gridSize{10,10};
};
