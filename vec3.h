#ifndef VEC3_H
#define VEC3_H

//what it means, where it appears in your code, and what you changed to test it

#include <cmath>
#include <iostream>

//using double since limited memory is not an issue here (bigger than float)

class vec3 {
    public:
        double e[3]; // an array of type double with 3 spots

        vec3(): e{0,0,0} {};//a constructor initalizing the double array called e to 0's //default
        vec3(double e0, double e1, double e2): e{e0, e1, e2} {}//intialization constructor

        //getters
        double x() const { return e[0]; } //getter for first element in array
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        //operator overloading
        vec3 operator-() const { 
            return vec3(-e[0], -e[1], -e[2]); //returns the pos before that? 
        }

        double operator[](int i) const {
            return e[i];
        }

        double& operator[](int i) {
            return e[i];
        }

        vec3& operator+=(const vec3& v) { //pass in a vector obj
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2]; //is this adding each element from new vec3 to the lhs' element
            return *this;
        }

        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const { 
            return std::sqrt(length_squared()); //length_squared is undefined?
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

//point3 is just an alias (another name) for vec3, but useful for geometric clarity in the code
using point3 = vec3; //using keyword

//vector utility functions 
    //what is inline
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) { 
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator* (double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) { //what is this doing in the big world?
    return u.e[0] * v.e[0] //matrix calculuation?
        +  u.e[1] * v.e[1]
        +  u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) { //is this a matrix

    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], 
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v/v.length(); //vector divided by the magnitude of the vector
}

#endif