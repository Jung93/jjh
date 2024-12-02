#include <math.h>

struct Vector {

public:
    Vector() :x(0.0f), y(0.0f) {


    }
    Vector(float x, float y) : x(x), y(y) {


    }
    Vector(const Vector& other) : x(other.x), y(other.y) {


    }
    ~Vector() {


    }

    float& operator[](int temp) {

        if (temp == 0) {

            return x;

        }
        else {

            return y;
        }
    }

    Vector operator+(const Vector& other) const {

        Vector result;

        result.x = this->x + other.x;
        result.y = this->y + other.y;

        return result;

    }
    Vector operator-(const Vector& other) const {

        Vector result;

        result.x = this->x - other.x;
        result.y = this->y - other.y;

        return result;
    }
    Vector operator*(const float& value) const
    {
        Vector result;
        result.x = x * value;
        result.y = y * value;

        return result;
        //return Vector(x * value, y * value);
    };

    float Dot(const Vector& other) {

        float result;

        result = (this->x * other.x) + (this->y * other.y);

        return result;
    }
    float Cross(const Vector& other) {

        float result;

        result = (this->x * other.y) - (this->y * other.x);

        return result;

    }
    float Length() const {

        return sqrtf((x * x) + (y * y));
    }
    Vector NormalVector() const
    {
        float length = Length();

        return Vector( x / length, y / length) ;
    }

    void Normalize()
    {
        float length = Length();
        x /= length;
        y /= length;
    }

    Vector& operator=(const Vector& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    Vector& operator+=(const Vector& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }




public:
    float x;
    float y;

};