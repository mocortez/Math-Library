#pragma once
#include "Prerequisites.h"

class Vector3D
{
private:

	float x, y, z;



public:

	//Costructor default
	Vector3D() : x(0.0f), y(0.0f), z(0.0f) {}
	//Constructor principal
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}
	//Constructor copia
	Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}

	//Getters
	float Getx() const { return x; }
	float Gety() const { return y; }
	float Getz() const { return z; }
	//Setters
	void Setx(float value) { x = value; }
	void Sety(float value) { y = value; }
	void Setz(float value) { z = value; }

	//Establece valores nuevos a cada eje
	void Set(float NewX, float NewY, float NewZ) { x = NewX; y = NewY; z = NewZ; }


	//Magnitud y normalización
	float Magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	//Magnitud sin raíz cuadrada
	float SqrMagnitude() const {
		return (x * x + y * y + z * z);
	}

	//Normalizar
	void Normalize() {
		float m = Magnitude();
		if (m > 0.0) {
			x /= m;
			y /= m;
			z /= m;
		}
	}

	//Normalizar sin modificar el vector original
	Vector3D Normalized() const {
		float m = Magnitude();
		if (m == 0.0) return Vector3D(0, 0, 0);
		return Vector3D(x / m, y / m, z / m);
	}

	//Operaciones vectoriales

	//Multiplicación
	float Dot(const Vector3D& other) const {
		return (x * other.x + y * other.y + z * other.z);
	}

	//Distancia entre dos vectores
	float Distance(const Vector3D& other) const {
		float dx = x - other.x;
		float dy = y - other.y;
		float dz = z - other.z;
		return std::sqrt(dx * dx + dy * dy + dz * dz);
	}

	//Devolver un vector perpendicular
	Vector3D Perpendicular() const {
		if (std::abs(x) > std::abs(y))
			return Vector3D(-z, 0, x);
		else
			return Vector3D(0, -z, y);
	}

	//Limita la magnitud de un vector
	void ClampMagnitude(float maxLength) {
		float m = Magnitude();
		if (m > maxLength) {
			Normalize();
			x *= maxLength;
			y *= maxLength;
			z *= maxLength;
		}
	}

	//Operadores aritméticos

	//Suma
	Vector3D operator+(const Vector3D& rhs) const {
		return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	//Resta
	Vector3D operator-(const Vector3D& rhs) const {
		return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	//Suma y asigna el valor a la misma variable
	Vector3D& operator+=(const Vector3D& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	//Resta y asigna el valor a la misma variable
	Vector3D& operator-=(const Vector3D& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	//Multiplica, escala los vectores
	Vector3D operator*(float scalar) const {
		return Vector3D(x * scalar, y * scalar, z * scalar);
	}

	//Dividir el vector por un número
	Vector3D operator/(float scalar) const {
		return Vector3D(x / scalar, y / scalar, z / scalar);
	}

	//Multiplica el valor actual y asignalo al mismo tiempo 
	Vector3D operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	//Dividir y asignar
	Vector3D operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	//Unario negativo
	Vector3D operator-() const {
		return Vector3D(-x, -y, -z);
	}

	//Comparar si los vectores tienen valores exactos
	bool operator==(const Vector3D& rhs) const {
		return (x == rhs.x && y == rhs.y && z == rhs.z);
	}

	//Comparar si los vectores no tienen valores exactos
	bool operator!=(const Vector3D& rhs) const {
		return !(*this == rhs);
	}

	//Utilidades

	//Interpolación lineal (lerp) entre 3 vectores
	static Vector3D LerpSequence(const Vector3D& a, const Vector3D& b, const Vector3D& c, float t) {
		if (t < 0.5) {
			//A -> B
			float u = t / 0.5;
			return Vector3D(
				a.x + (b.x - a.x) * u,
				a.y + (b.y - a.y) * u,
				a.z + (b.z - a.z) * u
			);
		}
		else
		{
			//B -> C
			float u = (t - 0.5) / 0.5;
			return Vector3D(
				b.x + (c.x - b.x) * u,
				b.y + (c.y - b.y) * u,
				b.z + (c.z - b.z) * u
			);
		}

	}


	//Devuelve un string con el formato "(x, y, z)".
	std::string ToString() const {
		std::ostringstream os;
		os << "(" << x << ", " << y << "," << z << ")";
		return os.str();
	}


};

