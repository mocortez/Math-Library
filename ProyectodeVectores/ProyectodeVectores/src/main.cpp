#include <iostream>
#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "MathUtils.h"


int main()
{
    //Vectores 2D
    std::cout << "Test de vectores 2D \n";

    Vector2D v2a(3.0f, 4.0f);
    Vector2D v2b(1.0f, 2.0f);

    std::cout << "v2a = " << v2a.ToString() << "\n";
    std::cout << "v2b = " << v2b.ToString() << "\n";
    std::cout << "Magnitud v2a = " << v2a.Magnitude() << "\n";
    std::cout << "Dot(v2a, v2b) = " << v2a.Dot(v2b) << "\n";
    std::cout << "Distancia = " << v2a.Distance(v2b) << "\n";
    std::cout << "v2a + v2b = " << (v2a + v2b).ToString() << "\n";

    //Vectores 3D
    std::cout << "\nTest de vectores 3D \n";

    Vector3D v3a(1.0f, 2.0f, 3.0f);
    Vector3D v3b(4.0f, 5.0f, 6.0f);

    std::cout << "v3a = " << v3a.ToString() << "\n";
    std::cout << "v3b = " << v3b.ToString() << "\n";
    std::cout << "Magnitud v3a = " << v3a.Magnitude() << "\n";
    std::cout << "Dot(v3a, v3b) = " << v3a.Dot(v3b) << "\n";
    std::cout << "Distancia = " << v3a.Distance(v3b) << "\n";
    std::cout << "Perpendicular = " << v3a.Perpendicular().ToString() << "\n";

    Vector3D v3lerp = Vector3D::LerpSequence(v3a, v3b, Vector3D(10, 10, 10), 0.75f);
    std::cout << "LerpSequence = " << v3lerp.ToString() << "\n";

	//Vectores 4D
    std::cout << "\nTest de vectores 4D \n";

    Vector4D v4a(1, 2, 3, 1);
    Vector4D v4b(4, 5, 6, 1);

    std::cout << "v4a = " << v4a.ToString() << "\n";
    std::cout << "v4b = " << v4b.ToString() << "\n";
    std::cout << "Magnitud v4a = " << v4a.Magnitude() << "\n";
    std::cout << "Dot(v4a, v4b) = " << v4a.Dot(v4b) << "\n";
    std::cout << "Distancia = " << v4a.Distance(v4b) << "\n";
    std::cout << "v4a + v4b = " << (v4a + v4b).ToString() << "\n";
    std::cout << "v4a Normalized = " << v4a.Normalized().ToString() << "\n";

    //Matrices2x2
    std::cout << "\nTest de matrices 2x2\n";

    Matrix2x2 m2a(1, 2,
        3, 4);

    Matrix2x2 m2b(5, 6,
        7, 8);

    std::cout << "m2a:\n" << m2a.ToString() << "\n";
    std::cout << "m2b:\n" << m2b.ToString() << "\n";
    std::cout << "m2a * m2b:\n" << (m2a * m2b).ToString() << "\n";

    //Matrices3x3
    std::cout << "\nTest de matrices 3x3\n";

    Matrix3x3 m3;
    std::cout << "Identidad 3x3:\n" << m3.ToString() << "\n";

    Vector3D v3m = m3 * v3a;
    std::cout << "m3 * v3a = " << v3m.ToString() << "\n";

    //Matrices4x4
    std::cout << "\nTest de matrices 4x4\n";

    Matrix4x4 m4;
    Vector4D v4m = m4 * v4a;

    std::cout << "Identidad 4x4:\n" << m4.ToString() << "\n";
    std::cout << "m4 * v4a = " << v4m.ToString() << "\n";

	//MathUtils
    std::cout << "\nMódulo de utilidades \n";

    std::cout << "Pow(2, 3) = " << MathUtils::Pow(2.0f, 3) << "\n";
    std::cout << "Sqrt(25) = " << MathUtils::Sqrt(25.0f) << "\n";
    std::cout << "Clamp(15, 0, 10) = " << MathUtils::Clamp(15.0f, 0.0f, 10.0f) << "\n";
    std::cout << "Lerp(0, 10, 0.5) = " << MathUtils::Lerp(0.0f, 10.0f, 0.5f) << "\n";

    std::cout << "\nFin del test \n";
    return 0;
}