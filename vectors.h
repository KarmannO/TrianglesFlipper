#ifndef VECTORS_H
#define VECTORS_H

#include "math.h"
#include "stdlib.h"
#include "memory.h"

#define RT_FLOAT float
#define PI 3.141592654f

typedef float vec2[2];
typedef float vec3[3];
typedef float vec4[4];

typedef double vec2d[2];
typedef double vec3d[3];
typedef double vec4d[4];

typedef int vec2i[2];
typedef int vec3i[3];
typedef int vec4i[4];

typedef unsigned int vec2ui[2];
typedef unsigned int vec3ui[3];
typedef unsigned int vec4ui[4];

typedef unsigned short vec2us[2];
typedef unsigned short vec3us[3];
typedef unsigned short vec4us[4];

typedef float mat2[2][2];
typedef float mat3[3][3];
typedef float mat4[4][4];
typedef float mat3_4[3][4];

typedef double mat2d[2][2];
typedef double mat3d[3][3];
typedef double mat4d[4][4];
typedef double mat3_4d[3][4];

typedef unsigned int mat2ui[2][2];
typedef unsigned int mat3ui[3][3];
typedef unsigned int mat4ui[4][4];

#define G_U 1000.0f
inline float rad(float angle)
{
    return angle * PI / 180.0f;
}

inline float angCosf(float angle)
{
    return cosf(rad(angle));
}

inline float angSinf(float angle)
{
    return sinf(rad(angle));
}

inline void SetMatrix(mat3d &m, double m00, double m01, double  m02, double  m10, double  m11, double  m12, double  m20, double  m21, double  m22)
{
    m[0][0]=m00;    m[0][1]=m01;    m[0][2]=m02;
    m[1][0]=m10;    m[1][1]=m11;    m[1][2]=m12;
    m[2][0]=m20;    m[2][1]=m21;    m[2][2]=m22;
}
inline void SetMatrix(mat3 &m, float m00, float m01, float  m02, float  m10, float  m11, float  m12, float  m20, float  m21, float  m22)
{
    m[0][0]=m00;    m[0][1]=m01;    m[0][2]=m02;
    m[1][0]=m10;    m[1][1]=m11;    m[1][2]=m12;
    m[2][0]=m20;    m[2][1]=m21;    m[2][2]=m22;
}
inline void SetMatrix(mat2d &m, double m00, double m01, double  m10, double  m11)
{
    m[0][0]=m00;    m[0][1]=m01;
    m[1][0]=m10;    m[1][1]=m11;
}
inline void SetMatrix(mat2 &m, float m00, float m01, float  m10, float  m11)
{
    m[0][0]=m00;    m[0][1]=m01;
    m[1][0]=m10;    m[1][1]=m11;
}
inline void SetMatrixZero(mat3d &m)
{
    m[0][0]=0.0;    m[0][1]=0.0;    m[0][2]=0.0;
    m[1][0]=0.0;    m[1][1]=0.0;    m[1][2]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=0.0;
}
inline void SetMatrixZero(mat3 &m)
{
    m[0][0]=0.0;    m[0][1]=0.0;    m[0][2]=0.0;
    m[1][0]=0.0;    m[1][1]=0.0;    m[1][2]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=0.0;
}
inline void SetMatrixIdentity(mat3d &m)
{
    m[0][0]=1.0;    m[0][1]=0.0;    m[0][2]=0.0;
    m[1][0]=0.0;    m[1][1]=1.0;    m[1][2]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=1.0;
}
inline void SetMatrixRx(mat3d &m, double sa, double ca)
{
    m[0][0]=1.0;    m[0][1]=0.0;    m[0][2]=0.0;
    m[1][0]=0.0;    m[1][1]=ca;     m[1][2]=-sa;
    m[2][0]=0.0;    m[2][1]=sa;     m[2][2]=ca;
}
inline void SetMatrixRy(mat3d &m, double sa, double ca)
{
    m[0][0]=ca;     m[0][1]=0.0;    m[0][2]=sa;
    m[1][0]=0.0;    m[1][1]=1.0;    m[1][2]=0.0;
    m[2][0]=-sa;    m[2][1]=0.0;    m[2][2]=ca;
}
inline void SetMatrixRz(mat3d &m, double sa, double ca)
{
    m[0][0]=ca;     m[0][1]=-sa;    m[0][2]=0.0;
    m[1][0]=sa;     m[1][1]=ca;     m[1][2]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=1.0;
}
inline void SetMatrixRM(mat3d &m, double sa, double ca, double sb, double cb, double sg, double cg)
{
    m[0][0]=ca*cb;    m[0][1]=-sa*cg+ca*sb*sg;    m[0][2]=sa*sg+ca*sb*cg;
    m[1][0]=sa*cb;    m[1][1]=ca*cg+sa*sb*sg;     m[1][2]=-ca*sg+sa*sb*cg;
    m[2][0]=-sb;      m[2][1]=cb*sg;			  m[2][2]=cb*cg;
}
inline void SetMatrixIdentity(mat3_4d &m)
{
    m[0][0]=1.0;    m[0][1]=0.0;    m[0][2]=0.0;	m[0][3]=0.0;
    m[1][0]=0.0;    m[1][1]=1.0;    m[1][2]=0.0;	m[1][3]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=1.0;	m[2][3]=0.0;
}
inline void SetMatrixIdentity(mat3 &m)
{
    m[0][0]=1.0;    m[0][1]=0.0;    m[0][2]=0.0;
    m[1][0]=0.0;    m[1][1]=1.0;    m[1][2]=0.0;
    m[2][0]=0.0;    m[2][1]=0.0;    m[2][2]=1.0;
}
inline void SetMatrixZero(mat2d &m)
{
    m[0][0]=0.0;    m[0][1]=0.0;
    m[1][0]=0.0;    m[1][1]=0.0;
}
inline void SetMatrixZero(mat2 &m)
{
    m[0][0]=0.0;    m[0][1]=0.0;
    m[1][0]=0.0;    m[1][1]=0.0;
}
inline void SetMatrixIdentity(mat2d &m)
{
    m[0][0]=1.0;    m[0][1]=0.0;
    m[1][0]=0.0;    m[1][1]=1.0;
}
inline void SetMatrixIdentity(mat2 &m)
{
    m[0][0]=1.0;    m[0][1]=0.0;
    m[1][0]=0.0;    m[1][1]=1.0;
}
inline void SetVector(vec3 &v, float v0, float v1, float v2=1.0)
{
    v[0]=v0; v[1]=v1; v[2]=v2;
}
inline void SetVector(vec3d &v, double v0, double v1, double v2=1.0)
{
    v[0]=v0; v[1]=v1; v[2]=v2;
}
inline void SetVector(vec2 &v, float v0, float v1)
{
    v[0]=v0; v[1]=v1;
}
inline void SetVector(vec2d &v, double v0, double v1)
{
    v[0]=v0; v[1]=v1;
}

inline void MultiMatrix(mat2d m1, mat2d m2, mat2d &res)
{
    res[0][0]=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]; res[0][1]=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1];
    res[1][0]=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]; res[1][1]=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1];
}
inline void MultiVector(mat2d m, vec2d v, vec2d &r)
{
    r[0]=m[0][0]*v[0]+m[0][1]*v[1];
    r[1]=m[1][0]*v[0]+m[1][1]*v[1];
}
inline void MultiVector(vec2d v, mat2d m, vec2d &r)
{
    r[0]=m[0][0]*v[0]+m[1][0]*v[1];
    r[1]=m[0][1]*v[0]+m[1][1]*v[1];
}
inline void MultiVector(mat3d m, vec3d v, vec3d &r)
{
    r[0]=m[0][0]*v[0]+m[0][1]*v[1]+m[0][2]*v[2];
    r[1]=m[1][0]*v[0]+m[1][1]*v[1]+m[1][2]*v[2];
    r[2]=m[2][0]*v[0]+m[2][1]*v[1]+m[2][2]*v[2];
}

inline void MultiVector(vec3d v, mat3d m, vec3d &r)
{
    r[0]=m[0][0]*v[0]+m[1][0]*v[1]+m[2][0]*v[2];
    r[1]=m[0][1]*v[0]+m[1][1]*v[1]+m[2][1]*v[2];
    r[2]=m[0][2]*v[0]+m[1][2]*v[1]+m[2][2]*v[2];
}
inline void MultiVector(mat3_4d& m, vec3d& v, vec3d &r)
{
    r[0]=m[0][0]*v[0]+m[0][1]*v[1]+m[0][2]*v[2]+m[0][3];
    r[1]=m[1][0]*v[0]+m[1][1]*v[1]+m[1][2]*v[2]+m[1][3];
    r[2]=m[2][0]*v[0]+m[2][1]*v[1]+m[2][2]*v[2]+m[2][3];
}
inline void MultiVectorXYT(mat3_4d& m, vec3d& v, vec3d &r)
{
    r[0]=m[0][0]*v[0]+m[0][1]*v[1]+m[0][2]+m[0][3]*v[2];
    r[1]=m[1][0]*v[0]+m[1][1]*v[1]+m[1][2]+m[1][3]*v[2];
    r[2]=m[2][0]*v[0]+m[2][1]*v[1]+m[2][2]+m[2][3]*v[2];
}
inline void CopyMatrix(mat3_4d &obj, mat3_4d &src)
{
    obj[0][0]=src[0][0];    obj[0][1]=src[0][1];    obj[0][2]=src[0][2];	obj[0][3]=src[0][3];
    obj[1][0]=src[1][0];    obj[1][1]=src[1][1];    obj[1][2]=src[1][2];	obj[1][3]=src[1][3];
    obj[2][0]=src[2][0];    obj[2][1]=src[2][1];    obj[2][2]=src[2][2];	obj[2][3]=src[2][3];
}
inline void CopyMatrix(mat3d &obj, mat3d src)
{
    obj[0][0]=src[0][0];    obj[0][1]=src[0][1];    obj[0][2]=src[0][2];
    obj[1][0]=src[1][0];    obj[1][1]=src[1][1];    obj[1][2]=src[1][2];
    obj[2][0]=src[2][0];    obj[2][1]=src[2][1];    obj[2][2]=src[2][2];
}
inline void CopyMatrix(mat3 &obj, mat3 src)
{
    obj[0][0]=src[0][0];    obj[0][1]=src[0][1];    obj[0][2]=src[0][2];
    obj[1][0]=src[1][0];    obj[1][1]=src[1][1];    obj[1][2]=src[1][2];
    obj[2][0]=src[2][0];    obj[2][1]=src[2][1];    obj[2][2]=src[2][2];
}
inline void CopyMatrix(mat2d &obj, mat2d src)
{
    obj[0][0]=src[0][0];    obj[0][1]=src[0][1];
    obj[1][0]=src[1][0];    obj[1][1]=src[1][1];
}
inline void CopyMatrix(mat2 &obj, mat2 src)
{
    obj[0][0]=src[0][0];    obj[0][1]=src[0][1];
    obj[1][0]=src[1][0];    obj[1][1]=src[1][1];
}
inline void CopyVector(vec3d &obj, vec3d src)
{
    obj[0]=src[0];  obj[1]=src[1];  obj[2]=src[2];
}
inline void CopyVector(vec3i &obj, vec3i src)
{
    obj[0]=src[0];  obj[1]=src[1];  obj[2]=src[2];
}
inline void CopyVector(vec3 &obj, vec3 src)
{
    obj[0]=src[0];  obj[1]=src[1];  obj[2]=src[2];
}
inline void CopyVector(vec2d &obj, vec2d src)
{
    obj[0]=src[0];  obj[1]=src[1];
}
inline void CopyVector(vec2 &obj, vec2 src)
{
    obj[0]=src[0];  obj[1]=src[1];
}
inline void MultiMatrix(mat4 m1, mat4 m2,mat4 &res)
{
    int i,k,j;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
        {
            res[i][j]=0.0;
            for (k=0; k<4; k++)
            {
                res[i][j]+=m1[i][k]*m2[k][j];
            }
        }
}
inline void MultiVector(mat4 m, vec3 v3, vec3 &res)
{
    int i,k;
    vec4 v;
    vec4 res4;
    v[0]=v3[0];
    v[1]=v3[1];
    v[2]=v3[2];
    v[3]=1.0;
    for (i=0; i<4; i++)
    {
        res4[i]=0.0;
        for (k=0; k<4; k++)
            res4[i]+=m[i][k]*v[k];
    }
    res[0]=res4[0];
    res[1]=res4[1];
    res[2]=res4[2];
}
inline void MultiVector(vec3 v, mat4 m, vec3 &r)
{
    r[0]=v[0]*m[0][0]+v[1]*m[1][0]+v[2]*m[2][0]+m[3][0];
    r[1]=v[0]*m[0][1]+v[1]*m[1][1]+v[2]*m[2][1]+m[3][1];
    r[2]=v[0]*m[0][2]+v[1]*m[1][2]+v[2]*m[2][2]+m[3][2];
}
inline void MultiVectorT(vec3 v, mat3 m, vec3 &r)
{
    r[0]=v[0]*m[0][0]+v[1]*m[1][0]+v[2]*m[2][0];
    r[1]=v[0]*m[0][1]+v[1]*m[1][1]+v[2]*m[2][1];
    r[2]=v[0]*m[0][2]+v[1]*m[1][2]+v[2]*m[2][2];
}
inline void MultiVector(vec3 v, mat3 m, vec3 &r)
{
    r[0]=v[0]*m[0][0]+v[1]*m[0][1]+v[2]*m[0][2];
    r[1]=v[0]*m[1][0]+v[1]*m[1][1]+v[2]*m[1][2];
    r[2]=v[0]*m[2][0]+v[1]*m[2][1]+v[2]*m[2][2];
}
inline void MultiMatrix(mat3 m1, mat3 m2,mat3 &res)
{
    res[0][0]=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]+m1[0][2]*m2[2][0];
    res[0][1]=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]+m1[0][2]*m2[2][1];
    res[0][2]=m1[0][0]*m2[0][2]+m1[0][1]*m2[1][2]+m1[0][2]*m2[2][2];

    res[1][0]=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]+m1[1][2]*m2[2][0];
    res[1][1]=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]+m1[1][2]*m2[2][1];
    res[1][2]=m1[1][0]*m2[0][2]+m1[1][1]*m2[1][2]+m1[1][2]*m2[2][2];

    res[2][0]=m1[2][0]*m2[0][0]+m1[2][1]*m2[1][0]+m1[2][2]*m2[2][0];
    res[2][1]=m1[2][0]*m2[0][1]+m1[2][1]*m2[1][1]+m1[2][2]*m2[2][1];
    res[2][2]=m1[2][0]*m2[0][2]+m1[2][1]*m2[1][2]+m1[2][2]*m2[2][2];
}
inline void MultiMatrix(mat3d m1, mat3d m2,mat3d &res)
{
    res[0][0]=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]+m1[0][2]*m2[2][0];
    res[0][1]=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]+m1[0][2]*m2[2][1];
    res[0][2]=m1[0][0]*m2[0][2]+m1[0][1]*m2[1][2]+m1[0][2]*m2[2][2];

    res[1][0]=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]+m1[1][2]*m2[2][0];
    res[1][1]=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]+m1[1][2]*m2[2][1];
    res[1][2]=m1[1][0]*m2[0][2]+m1[1][1]*m2[1][2]+m1[1][2]*m2[2][2];

    res[2][0]=m1[2][0]*m2[0][0]+m1[2][1]*m2[1][0]+m1[2][2]*m2[2][0];
    res[2][1]=m1[2][0]*m2[0][1]+m1[2][1]*m2[1][1]+m1[2][2]*m2[2][1];
    res[2][2]=m1[2][0]*m2[0][2]+m1[2][1]*m2[1][2]+m1[2][2]*m2[2][2];
}
inline void MultiMatrix(mat3_4d &m1, mat3_4d &m2, mat3_4d &res)
{
    res[0][0]=m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0]+m1[0][2]*m2[2][0];
    res[0][1]=m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1]+m1[0][2]*m2[2][1];
    res[0][2]=m1[0][0]*m2[0][2]+m1[0][1]*m2[1][2]+m1[0][2]*m2[2][2];
    res[0][3]=m1[0][0]*m2[0][3]+m1[0][1]*m2[1][3]+m1[0][2]*m2[2][3]+m1[0][3];

    res[1][0]=m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0]+m1[1][2]*m2[2][0];
    res[1][1]=m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1]+m1[1][2]*m2[2][1];
    res[1][2]=m1[1][0]*m2[0][2]+m1[1][1]*m2[1][2]+m1[1][2]*m2[2][2];
    res[1][3]=m1[1][0]*m2[0][3]+m1[1][1]*m2[1][3]+m1[1][2]*m2[2][3]+m1[1][3];

    res[2][0]=m1[2][0]*m2[0][0]+m1[2][1]*m2[1][0]+m1[2][2]*m2[2][0];
    res[2][1]=m1[2][0]*m2[0][1]+m1[2][1]*m2[1][1]+m1[2][2]*m2[2][1];
    res[2][2]=m1[2][0]*m2[0][2]+m1[2][1]*m2[1][2]+m1[2][2]*m2[2][2];
    res[2][3]=m1[2][0]*m2[0][3]+m1[2][1]*m2[1][3]+m1[2][2]*m2[2][3]+m1[2][3];
}
inline void MultiMatrix(mat3 m1, mat3 &m2)
{
    mat3 res;

    int i,k,j;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
            res[i][j]=0.0;
            for (k=0; k<3; k++)
            {
                res[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    m2[0][0]=res[0][0]; m2[0][1]=res[0][1]; m2[0][2]=res[0][2];
    m2[1][0]=res[1][0]; m2[1][1]=res[1][1]; m2[1][2]=res[1][2];
    m2[2][0]=res[2][0]; m2[2][1]=res[2][1]; m2[2][2]=res[2][2];
}

inline void MultiVector(mat3 m, vec3 v3, vec3 &res)
{
    int i,k;
    for (i=0; i<3; i++)
    {
        res[i]=0.0;
        for (k=0; k<3; k++)
            res[i]+=m[i][k]*v3[k];
    }
}


inline float length(vec3 v)
{
    return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}
inline double length(vec3d v)
{
    return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}
inline void sub(vec3 v1, vec3 v2, vec3 &res)
{
    res[0]=v1[0]-v2[0];
    res[1]=v1[1]-v2[1];
    res[2]=v1[2]-v2[2];
}
inline RT_FLOAT distance(vec3 p0, vec3 p1)
{
    vec3 v;
    sub(p0,p1,v);
    return length(v);
}
inline void normalize(vec3 v, vec3 &res)
{
    float len=length(v);
    res[0]=v[0]/len;
    res[1]=v[1]/len;
    res[2]=v[2]/len;
}
inline void normalize(vec3d v, vec3d &res)
{
    double len=length(v);
    res[0]=v[0]/len;
    res[1]=v[1]/len;
    res[2]=v[2]/len;
}
inline void normalize(vec3 &v)
{
    float len=1.0f/length(v);
    v[0]=v[0]*len;
    v[1]=v[1]*len;
    v[2]=v[2]*len;
}
inline void normalize(vec3d &v)
{
    double len=1.0f/length(v);
    v[0]=v[0]*len;
    v[1]=v[1]*len;
    v[2]=v[2]*len;
}
inline void cross(vec3 v1, vec3 v2, vec3& res)
{
    res[0]=v1[1]*v2[2]-v1[2]*v2[1];
    res[1]=v1[2]*v2[0]-v1[0]*v2[2];
    res[2]=v1[0]*v2[1]-v1[1]*v2[0];
}
inline void cross(vec3d v1, vec3d v2, vec3d& res)
{
    res[0]=v1[1]*v2[2]-v1[2]*v2[1];
    res[1]=v1[2]*v2[0]-v1[0]*v2[2];
    res[2]=v1[0]*v2[1]-v1[1]*v2[0];
}

inline void GetPointTangent(vec3 v0, vec3 v1, vec3 v2, vec2 t0, vec2 t1, vec2 t2, vec3 &res0, vec3 &res1)
{
    float EPS=0.0000001f;
    vec3 e0;
    vec3 e1;
    e0[0]=(v1[0]-v0[0]); e0[1]=(t1[0]-t0[0]); e0[2]=(t1[1]-t0[1]);
    e1[0]=(v2[0]-v0[0]); e1[1]=(t2[0]-t0[0]); e1[2]=(t2[1]-t0[1]);
    vec3 cp;
    cross(e0,e1,cp);
    if (fabs(cp[0])>EPS)
    {
        res0[0]=-cp[1]/cp[0];
        res1[0]=-cp[2]/cp[0];
    }
    else
    {
        res0[0]=0.0;
        res1[0]=0.0;
    }

    e0[0]=v1[1]-v0[1];
    e1[0]=v2[1]-v0[1];
    cross(e0,e1,cp);;
    if (fabs(cp[0])>EPS)
    {
        res0[1]=-cp[1]/cp[0];
        res1[1]=-cp[2]/cp[0];
    }
    else
    {
        res0[1]=0;
        res1[1]=0;
    }

    e0[0]=v1[2]-v0[2];
    e1[0]=v2[2]-v0[2];
    cross(e0,e1,cp);
    if (fabs(cp[0])>EPS)
    {
        res0[2]=-cp[1]/cp[0];
        res1[2]=-cp[2]/cp[0];
    }
    else
    {
        res0[2]=0.0;
        res1[2]=0.0;
    }
    vec3 buf;
    normalize(res0,buf);
    res0[0]=buf[0]; res0[1]=buf[1]; res0[2]=buf[2];
    normalize(res1,buf);
    res1[0]=buf[0]; res1[1]=buf[1]; res1[2]=buf[2];
}
inline float det3(mat3 m)
{
    return m[0][0]*m[1][1]*m[2][2]+m[0][1]*m[1][2]*m[2][0]+m[0][2]*m[1][0]*m[2][1]-m[0][2]*m[1][1]*m[2][0]-
            m[0][1]*m[1][0]*m[2][2]-m[0][0]*m[1][2]*m[2][1];
}
inline float det2(mat2 m)
{
    return m[0][0]*m[1][1]-m[0][1]*m[1][0];
}
inline double det3(mat3d m)
{
    return m[0][0]*m[1][1]*m[2][2]+m[0][1]*m[1][2]*m[2][0]+m[0][2]*m[1][0]*m[2][1]-m[0][2]*m[1][1]*m[2][0]-
            m[0][1]*m[1][0]*m[2][2]-m[0][0]*m[1][2]*m[2][1];
}
inline double det2(mat2d m)
{
    return m[0][0]*m[1][1]-m[0][1]*m[1][0];
}
inline float dot(vec3 v1, vec3 v2)
{
    return v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}
inline double dot(vec3d v1, vec3d v2)
{
    return v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}
inline void ProjectVector(vec3d v, vec3d to, vec3d &r)
{
    double multer=dot(v,to)/(to[0]*to[0]+to[1]*to[1]+to[2]*to[2]);
    r[0]=to[0]*multer;
    r[1]=to[1]*multer;
    r[2]=to[2]*multer;
}
inline void ProjectVector(vec3 v, vec3 to, vec3 &r)
{
    float multer=dot(v,to)/(to[0]*to[0]+to[1]*to[1]+to[2]*to[2]);
    r[0]=to[0]*multer;
    r[1]=to[1]*multer;
    r[2]=to[2]*multer;
}

inline void MatInverse(mat3 m, mat3 &r)
{
    float k=1.0f/det3(m);
    r[0][0]=k*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);	r[0][1]=k*(-m[0][1]*m[2][2]+m[0][2]*m[2][1]);	r[0][2]=k*(m[0][1]*m[1][2]-m[0][2]*m[1][1]);
    r[1][0]=k*(-m[1][0]*m[2][2]+m[1][2]*m[2][0]);	r[1][1]=k*(m[0][0]*m[2][2]-m[0][2]*m[2][0]);	r[1][2]=k*(-m[0][0]*m[1][2]+m[0][2]*m[1][0]);
    r[2][0]=k*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);	r[2][1]=k*(-m[0][0]*m[2][1]+m[0][1]*m[2][0]);	r[2][2]=k*(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
}
inline void MatInverse(mat3d m, mat3d &r)
{
    double k=1.0/det3(m);
    r[0][0]=k*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);	r[0][1]=k*(-m[0][1]*m[2][2]+m[0][2]*m[2][1]);	r[0][2]=k*(m[0][1]*m[1][2]-m[0][2]*m[1][1]);
    r[1][0]=k*(-m[1][0]*m[2][2]+m[1][2]*m[2][0]);	r[1][1]=k*(m[0][0]*m[2][2]-m[0][2]*m[2][0]);	r[1][2]=k*(-m[0][0]*m[1][2]+m[0][2]*m[1][0]);
    r[2][0]=k*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);	r[2][1]=k*(-m[0][0]*m[2][1]+m[0][1]*m[2][0]);	r[2][2]=k*(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
}
inline void MatInverse(mat2 m, mat2 &r)
{
        float k=1.0f/(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
        r[0][0]=k*(m[1][1]);	r[0][1]=k*(-m[0][1]);
        r[1][0]=k*(-m[1][0]);	r[1][1]=k*(m[0][0]);
}
inline void MatInverse(mat2d m, mat2d &r)
{
        double k=1.0/(m[0][0]*m[1][1]-m[0][1]*m[1][0]);
        r[0][0]=k*(m[1][1]);	r[0][1]=k*(-m[0][1]);
        r[1][0]=k*(-m[1][0]);	r[1][1]=k*(m[0][0]);
}
inline void MatTranspose(mat2d m, mat2d &r)
{
    r[0][0]=m[0][0]; r[0][1]=m[1][0];
    r[1][0]=m[0][1]; r[1][1]=m[1][1];
}
inline void MatTranspose(mat2d &m)
{
    vec2d b;
    b[0]=m[1][0];
    b[1]=m[0][1];
    m[1][0]=b[1];
    m[0][1]=b[0];
}
inline void MatTranspose(mat3d m, mat3d &r)
{
    r[0][0]=m[0][0];    r[0][1]=m[1][0];    r[0][2]=m[2][0];
    r[1][0]=m[0][1];    r[1][1]=m[1][1];    r[1][2]=m[2][1];
    r[2][0]=m[0][2];    r[2][1]=m[1][2];    r[2][2]=m[2][2];
}
inline void MatTranspose(mat3d &m)
{
    vec3d b;
    b[0]=m[0][1];       b[1]=m[0][2];       b[2]=m[1][2];
    m[0][1]=m[1][0];    m[0][2]=m[2][0];    m[1][2]=m[2][1];
    m[1][0]=b[0];       m[2][0]=b[1];       m[2][1]=b[2];
}

inline void MatTranspose(mat2 m, mat2 &r)
{
    r[0][0]=m[0][0]; r[0][1]=m[1][0];
    r[1][0]=m[0][1]; r[1][1]=m[1][1];
}
inline void MatTranspose(mat2 &m)
{
    vec2 b;
    b[0]=m[1][0];
    b[1]=m[0][1];
    m[1][0]=b[1];
    m[0][1]=b[0];
}
inline void MatTranspose(mat3 m, mat3 &r)
{
    r[0][0]=m[0][0];    r[0][1]=m[1][0];    r[0][2]=m[2][0];
    r[1][0]=m[0][1];    r[1][1]=m[1][1];    r[1][2]=m[2][1];
    r[2][0]=m[0][2];    r[2][1]=m[1][2];    r[2][2]=m[2][2];
}
inline void MatTranspose(mat3 &m)
{
    vec3 b;
    b[0]=m[0][1];       b[1]=m[0][2];       b[2]=m[1][2];
    m[0][1]=m[1][0];    m[0][2]=m[2][0];    m[1][2]=m[2][1];
    m[1][0]=b[0];       m[2][0]=b[1];       m[2][1]=b[2];
}


#define CLOSE_POINT_ITR 3

inline void GetClosePoint(vec3d fp, vec3d sp, mat3d F, vec3d &fo, vec3d &so)
{
    CopyVector(fo,fp);
    CopyVector(so,sp);
    vec3d fline;
    vec3d sline;
    mat2d FM,SM,FMI,SMI;
    vec2d FR,SR;
    vec2d fc,sc;
    //double d;
    for (int i=0; i<CLOSE_POINT_ITR; i++)
    {
        MultiVector(F,so,fline);
        MultiVector(fo,F,sline);

        FM[0][0]=fline[0];  FM[0][1]=fline[1];
        FM[1][0]=fline[1];  FM[1][1]=-fline[0];

        SM[0][0]=sline[0];  SM[0][1]=sline[1];
        SM[1][0]=sline[1];  SM[1][1]=-sline[0];

        FR[0]=-fline[2];    FR[1]=fline[1]*fo[0]-fline[0]*fo[1];
        SR[0]=-sline[2];    SR[1]=sline[1]*so[0]-sline[0]*so[1];

        MatInverse(FM,FMI);
        MatInverse(SM,SMI);

        MultiVector(FMI,FR,fc);
        MultiVector(SMI,SR,sc);

        //d=sqrt((fo[0]-fc[0])*(fo[0]-fc[0])+(fo[1]-fc[1])*(fo[1]-fc[1]))+sqrt((so[0]-sc[0])*(so[0]-sc[0])+(so[1]-sc[1])*(so[1]-sc[1]));

        fo[0]=0.5*(fo[0]+fc[0]);
        fo[1]=0.5*(fo[1]+fc[1]);

        so[0]=0.5*(so[0]+sc[0]);
        so[1]=0.5*(so[1]+sc[1]);
    }
}


inline void EvaluteLeftM(mat3d F, vec3d E, mat3d M)
{
    M[0][0]=(F[0][1]-E[0])/(-E[2]); M[0][1]=(F[0][0]+E[1])/(E[2]); M[0][2]=1.0;
    M[1][0]=(F[1][1]-E[0])/(-E[2]); M[1][1]=(F[1][0]+E[1])/(E[2]); M[1][2]=1.0;
    M[2][0]=(F[2][1]-E[0])/(-E[2]); M[2][1]=(F[2][0]+E[1])/(E[2]); M[2][2]=1.0;
}
inline void EvaluteRightM(mat3d F, vec3d E, mat3d M)
{
    M[0][0]=(F[1][0]+E[0])/(E[2]);  M[0][1]=(F[1][1]+E[0])/(E[2]);   M[0][2]=(F[1][2]+E[0])/(E[2]);
    M[1][0]=(F[0][0]-E[1])/(-E[2]); M[1][1]=(F[0][1]-E[1])/(-E[2]);  M[1][2]=(F[0][2]-E[1])/(-E[2]);
    M[2][0]=1.0;                    M[2][1]=1.0;                     M[2][2]=1.0;
}


inline void SkewSymm(vec3d E, mat3d &Ex)
{
    Ex[0][0]=0.0;   Ex[0][1]=-E[2]; Ex[0][2]=E[1];
    Ex[1][0]=E[2];  Ex[1][1]=0.0;   Ex[1][2]=-E[0];
    Ex[2][0]=-E[1]; Ex[2][1]=E[0];  Ex[2][2]=0.0;
}

//------------------------------------------------------------------


struct queue
{
    int size;
    int start;
    int end;
    int *q;
    queue()
    {
        size=0;
        start=0;
        end=0;
        q=NULL;
    }
    bool Init(int am)
    {
        if (q) delete[] q;
        q=new int[am];
        if (!q) return false;
        size=am;
        start=0;
        end=0;
        return true;
    }
    inline void Insert(int el)
    {
        q[end]=el;
        end++;
        if (end>size-1) end=0;
    }
    inline int Eject()
    {
        int res=q[start];
        start++;
        if (start>size-1) start=0;
        return res;
    }
    inline bool IsEmpty()
    {
        return start==end;
    }
    inline int GetElementsAmount()
    {
        if (start<=end) return end-start;
        else return size-start+end;
    }
    void ZeroQueue()
    {
        start=0;
        end=0;
    }
    ~queue()
    {
        if (q) delete[] q;
    }
};



#endif
