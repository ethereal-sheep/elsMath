# elsMath
`els` is a header-only math library written with **modern C++**. 
It provides a number of objects and helper functions for vector and matrix 
algebra, as well as more general stuff like random and noise.

# Quick Start
Simply include the `elsMath/include` folder in your project and include the
respective header files to start using the library.

## Vector & Matrix
The library provides support for the following vector and matrix types:
| Type | File | Typename | Alias |
|------|------|----------|-------| 
| 2D Vector | `elsVector2.h` |`Vector2<T>` | `vec2` |
| 3D Vector | `elsVector3.h` |`Vector3<T>` | `vec3` |
| 4D Vector | `elsVector4.h` |`Vector4<T>` | `vec4` |
| 2X2 Matrix | `elsMatrix2.h` |`Matrix2<T>` | `mat2`|
| 3X3 Matrix | `elsMatrix3.h` |`Matrix3<T>` | `mat3`|
| 4X4 Matrix | `elsMatrix4.h` |`Matrix4<T>` | `mat4`|

Vector and Matrix types can be used algebraically.
```c++
using namespace els;

// construction
vec3 i{1,0,0};          // Construct   
vec3 j = vec3{0,1,0};   // Assignment
vec3 k = vec3::k;       // static constant

mat4 I;                 // default identity
mat4 zero = mat4::zero; // static constant

// addition/subtraction
vec3 a = i + j;
vec3 b = j - k;
mat4 m = I + zero;

// scaling
a *= 2;
b = b * 3;
mat4 five = m * 5;

// matrix composition
five *= I;
five = five * five;

// vector matrix multiplication
vec3 result = five * j;
```

Common member functions and operations for vector and matrix types

```c++
// vector operations
vec3 v1, v2;

float normal = v1.normalized();     // normal of vector
float length = v1.length();         // length of vetor
float dot = v1.dot(v2);             // dot product of two vectors
float angle = v1.angle(v2);         // angle between two vectors
vec3 lerp = v1.lerp(v2, 0.5f);      // interpolate between two vectors

v1.normalize();                     // normalizes the vector

// matrix operations
mat4 m;

float det = m.det();                // determinant of matrix
mat4 inverse = m.inverse();         // inverse of matrix
mat4 transposed = m.transposed();   // transpose of matrix

m.invert();                         // inverts the vector
m.transpose();                      // transposes the vector


```

### Helpers
The library also include some helpers to improve conversion between different
math libraries and types.

```c++
// strange vector
struct strange_vec {
    strange_vec(float x, float y, float z) 
    : x_{x}, y_{y}, z_{z} {}
    float x_,y_,z_;
};

vec3 els_vec{1,2,3};

strange_vec strange{els_vec};   // implicit cast to any vector type

vec3 one = to_vec3(strange);    // helper to cast any vector type to an els::vec

// using elsValue.h functions
float v[] = {1,2,3};
vec3 two = make_vec3(v);        // helper to cast an array to an els::vec
float* ptr = value_ptr(two);    // helper to cast a vector to an array
vec3 three = make_vec3(ptr);    // helper to cast a pointer to an els::vec
```

## Transforms
The library provides some helper functions for creating transform matrices.
| Type | File | Typename | Alias |
|------|------|----------|-------| 
| 2D Transforms | `elsTransform2.h` |`Transform2<T>` | `t2` |
| 3D Transforms | `elsTransform3.h` |`Transform3<T>` | `t3` |
```c++
using namespace els;

// 2D transforms
mat3 translate2d = t2::translate(1,1);
mat3 rotate2d = t2::rotate(45);
mat3 scale2d = t2::scale(5);

// 3D transforms
mat3 translate3d = t3::translate(1,1);
mat3 rotateX = t3::rotateX(45);
mat3 rotateY = t3::rotateY(45);
mat3 rotateZ = t3::rotateZ(45);
mat3 scale3d = t3::scale(5);

```
## Random
The random library provides functions for common random operations.
```c++
using namespace els;

int random_int = random::uniform_rand(1, 100);          // random int between 1 and 100
float random_float = random::uniform_rand(1.f, 100.f);  // random float between 1 and 100

// random float following a normal distribution given the mean and standard deviation
float normal_float = random::normal_rand(50.f, 1.f); 

// random point on a circle with given radius
vec2 circle_pt = random::circular_rand(1.f);

// random point on a disk with given radius     
vec2 disk_pt = random::disk_rand(1.f);

// random point on the surface of sphere with given radius
vec3 sphere_pt = random::sphere_rand(1.f);

// random point in a ball with given radius
vec3 ball_pt = random::ball_rand(1.f);
```