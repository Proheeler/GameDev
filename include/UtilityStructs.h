#pragma once

struct Dimensions2D
{
    int x;
    int y;
};

struct Dimensions3D:Dimensions2D
{
    int z;
};
using Speed = Dimensions2D;
using Speed3D = Dimensions3D;
using Size2D = Dimensions2D;
using Size3D = Dimensions3D;