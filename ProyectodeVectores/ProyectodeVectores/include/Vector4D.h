#pragma once
#include "prerequisites.h"

class Vector4D
{
private:

    float x, y, z, w;

public:

    // Constructor default
    Vector4D() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

    // Constructor principal
    Vector4D(float x, float y, float z, float w)
        : x(x), y(y), z(z), w(w) {
    }

    // Constructor copia
    Vector4D(const Vector4D& other)
        : x(other.x), y(other.y), z(other.z), w(other.w) {
    }

    // Getters
    float Getx() const { return x; }
    float Gety() const { return y; }
    float Getz() const { return z; }
    float Getw() const { return w; }

    // Setters
    void Setx(float value) { x = value; }
    void Sety(float value) { y = value; }
    void Setz(float value) { z = value; }
    void Setw(float value) { w = value; }

    // Establece valores nuevos
    void Set(float NewX, float NewY, float NewZ, float NewW)
    {
        x = NewX;
        y = NewY;
        z = NewZ;
        w = NewW;
    }

    // Magnitud
    float Magnitude() const {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    // Magnitud sin raíz
    float SqrMagnitude() const {
        return (x * x + y * y + z * z + w * w);
    }

    // Normalizar
    void Normalize() {
        float m = Magnitude();
        if (m > 0.0f) {
            x /= m;
            y /= m;
            z /= m;
            w /= m;
        }
    }

    // Normalizado sin modificar el original
    Vector4D Normalized() const {
        float m = Magnitude();
        if (m == 0.0f) return Vector4D(0, 0, 0, 0);
        return Vector4D(x / m, y / m, z / m, w / m);
    }

    // Producto punto
    float Dot(const Vector4D& other) const {
        return (x * other.x +
            y * other.y +
            z * other.z +
            w * other.w);
    }

    // Distancia entre dos vectores
    float Distance(const Vector4D& other) const {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        float dw = w - other.w;
        return std::sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
    }

    // Limita la magnitud
    void ClampMagnitude(float maxLength) {
        float m = Magnitude();
        if (m > maxLength) {
            Normalize();
            *this *= maxLength;
        }
    }

    // Operadores aritméticos

    Vector4D operator+(const Vector4D& rhs) const {
        return Vector4D(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
    }

    Vector4D operator-(const Vector4D& rhs) const {
        return Vector4D(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
    }

    Vector4D& operator+=(const Vector4D& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    Vector4D& operator-=(const Vector4D& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    Vector4D operator*(float scalar) const {
        return Vector4D(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vector4D operator/(float scalar) const {
        return Vector4D(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    Vector4D& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4D& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    // Unario negativo
    Vector4D operator-() const {
        return Vector4D(-x, -y, -z, -w);
    }

    // Comparaciones exactas
    bool operator==(const Vector4D& rhs) const {
        return (x == rhs.x &&
            y == rhs.y &&
            z == rhs.z &&
            w == rhs.w);
    }

    bool operator!=(const Vector4D& rhs) const {
        return !(*this == rhs);
    }

    // Interpolación lineal entre 3 vectores 4D
    static Vector4D LerpSequence(
        const Vector4D& a,
        const Vector4D& b,
        const Vector4D& c,
        float t)
    {
        if (t < 0.5f) {
            float u = t / 0.5f;
            return a + (b - a) * u;
        }
        else {
            float u = (t - 0.5f) / 0.5f;
            return b + (c - b) * u;
        }
    }

    // ToString
    std::string ToString() const {
        std::ostringstream os;
        os << "(" << x << ", " << y << ", " << z << ", " << w << ")";
        return os.str();
    }
};