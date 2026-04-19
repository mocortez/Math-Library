#pragma once
#include "Prerequisites.h"
#include "Vector4D.h"
#include <sstream>
#include <string>

// Matriz 4x4 para transformaciones 3D completas

class Matrix4x4
{
public:
    float m[4][4];

    // Identidad
    Matrix4x4() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    static Matrix4x4 Identity() {
        return Matrix4x4();
    }

    //Factorias

    static Matrix4x4 Translation(float x, float y, float z) {
        Matrix4x4 r;
        r.m[0][3] = x;
        r.m[1][3] = y;
        r.m[2][3] = z;
        return r;
    }

    static Matrix4x4 Scale(float sx, float sy, float sz) {
        Matrix4x4 r;
        r.m[0][0] = sx;
        r.m[1][1] = sy;
        r.m[2][2] = sz;
        return r;
    }

    static Matrix4x4 RotationZ(float rad) {
        Matrix4x4 r;
        float c = std::cos(rad);
        float s = std::sin(rad);
        r.m[0][0] = c; r.m[0][1] = -s;
        r.m[1][0] = s; r.m[1][1] = c;
        return r;
    }

	//Operadores

    Matrix4x4 operator*(const Matrix4x4& rhs) const {
        Matrix4x4 r;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) {
                r.m[i][j] = 0;
                for (int k = 0; k < 4; ++k)
                    r.m[i][j] += m[i][k] * rhs.m[k][j];
            }
        return r;
    }

    Vector4D operator*(const Vector4D& v) const {
        return Vector4D(
            m[0][0] * v.Getx() + m[0][1] * v.Gety() + m[0][2] * v.Getz() + m[0][3] * v.Getw(),
            m[1][0] * v.Getx() + m[1][1] * v.Gety() + m[1][2] * v.Getz() + m[1][3] * v.Getw(),
            m[2][0] * v.Getx() + m[2][1] * v.Gety() + m[2][2] * v.Getz() + m[2][3] * v.Getw(),
            m[3][0] * v.Getx() + m[3][1] * v.Gety() + m[3][2] * v.Getz() + m[3][3] * v.Getw()
        );
    }

    //Utilidades

    std::string ToString() const {
        std::ostringstream os;
        os << "[";
        for (int i = 0; i < 4; ++i) {
            os << "[";
            for (int j = 0; j < 4; ++j) {
                os << m[i][j];
                if (j < 3) os << ", ";
            }
            os << "]";
            if (i < 3) os << ", ";
        }
        os << "]";
        return os.str();
    }
};
