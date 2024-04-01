#pragma once
#include <string>
#include <sstream>
#include <vector>

struct TMonom
{
    double coef; // коэффициент монома
    int degX; // степень по X
    int degY; // степень по Y
    int degZ; // степень по Z

    TMonom()
    {
        coef = 0;
        degX = 0;
        degY = 0;
        degZ = 0;
    }

    TMonom(double cval, int dx, int dy, int dz)
    {
        coef = cval;
        degX = dx;
        degY = dy;
        degZ = dz;
    }

    std::string ToString() const
    {
        std::ostringstream oss;
        oss << coef << "x^" << degX << "y^" << degY << "z^" << degZ;
        return oss.str();
    }

    void SetCoef(double cval) { coef = cval; }
    double GetCoef() const { return coef; }

    void SetDegX(int dx) { degX = dx; }
    int GetDegX() const { return degX; }

    void SetDegY(int dy) { degY = dy; }
    int GetDegY() const { return degY; }

    void SetDegZ(int dz) { degZ = dz; }
    int GetDegZ() const { return degZ; }

    TMonom operator*(const TMonom& other) const
    {
        return TMonom(coef * other.coef, degX + other.degX, degY + other.degY, degZ + other.degZ); // умножение мономов
    }

    bool operator==(const TMonom& other) const
    {
        return (degX == other.degX && degY == other.degY && degZ == other.degZ);
    }

    bool operator>(const TMonom& other) const
    {
        return (degX > other.degX || (degX == other.degX && degY > other.degY) || (degX == other.degX && degY == other.degY && degZ > other.degZ));
    }

    bool operator<(const TMonom& other) const
    {
        return (degX < other.degX || (degX == other.degX && degY < other.degY) || (degX == other.degX && degY == other.degY && degZ < other.degZ));
    }

    TMonom TMonom::Derivative() const
    {
        return TMonom(coef * degX, degX > 0 ? degX - 1 : 0, degY, degZ);
    }

    TMonom TMonom::Integral() const
    {
        return TMonom(coef / (degX + 1), degX + 1, degY, degZ);
    }
};