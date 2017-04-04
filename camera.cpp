#include "camera.h"

CCamera::CCamera()
{
    rXY = 0.0f;
    rZ = 0.0f;
    p[0] = 0.0f;
    p[1] = 0.0f;
    p[2] = 3.0f;
    CCamera::ComputeVectors();
    acc = 30.0f;
    vel = 10.0f;
    forward = backward = false;
}

void CCamera::ComputeVectors()
{
    d[0] = angCosf(rZ) * angCosf(rXY);
    d[1] = angSinf(rZ) * angCosf(rXY);
    d[2] = angSinf(rXY);

    u[0] = -angCosf(rZ) * angSinf(rXY);
    u[1] = -angSinf(rZ) * angSinf(rXY);
    u[2] = angCosf(rXY);

    cross(d, u, s);
}

void CCamera::SetView()
{
    gluLookAt(p[0], p[1], p[2],
            p[0] + d[0], p[1] + d[1], p[2] + d[2],
            u[0], u[1], u[2]);
}

void CCamera::RotZ(float angle)
{
    rZ -= angle * 2.0f;
    if(rZ > 360.0f)
        rZ -= 360.0f;
    if(rZ < 0.0f)
        rZ += 360.0f;
    ComputeVectors();
}

void CCamera::RotXY(float angle)
{
    rXY -= angle * 2.0f;
    if(rXY > 89.0f)
        rXY = 89.0f;
    if(rXY < -89.0f)
        rXY = -89.0f;
    ComputeVectors();
}

void CCamera::Move(float dx)
{
    p[0] += dx * d[0];
    p[1] += dx * d[1];
    p[2] += dx * d[2];
}

void CCamera::ConvertToWorld(vec3 in_ray, vec3 point)
{
    mat3 R;
    for(int i = 0; i < 3; i++)
    {
        R[i][0] = s[i];
        R[i][1] = u[i];
        R[i][2] = d[i];
    }
    vec3 r;
    MultiVector(R, in_ray, r);

    point[0] = r[0] + p[0];
    point[1] = r[1] + p[1];
    point[2] = r[2] + p[2];
}

void CCamera::Update(float dt)
{
    if((forward && !backward) || (!forward && backward))
    {
        vel += dt * acc;
        if(vel > 300.0f)
            vel = 300.0f;
        if(forward)
            Move(dt * vel);
        else if(backward)
            Move(-dt * vel);
    }
}
