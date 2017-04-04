#ifndef CCAMERA_H
#define CCAMERA_H
#include "vectors.h"
#include "GL/glu.h"

class CCamera
{
protected:
    vec3 p, d, u, s;
    float rXY, rZ;

    float acc;
    float vel;

    bool forward, backward;

    virtual void ComputeVectors();
public:
    CCamera();

    virtual void SetView();
    virtual void RotZ(float angle);
    virtual void RotXY(float angle);
    virtual void Move(float dx);

    void ConvertToWorld(vec3 in_ray, vec3 point);
    void Update(float dt);
};

#endif // CCAMERA_H
