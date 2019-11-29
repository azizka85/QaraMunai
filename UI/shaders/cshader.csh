#version 430
uniform vec2 uViewPort;
uniform vec4 uRay;
uniform mat4 uMVMatrix;

layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout (std430, binding = 0) buffer VertexBuffer { float vertex[]; };
layout (std430, binding = 1) buffer IndexBuffer { uint index[]; };
layout (std430, binding = 2) buffer OutputBuffer { float outBuffer[]; };

void main(void)
{
    uint i = gl_GlobalInvocationID.z * gl_NumWorkGroups.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.x;

    uint ind1 = index[3*i + 0];
    uint ind2 = index[3*i + 1];
    uint ind3 = index[3*i + 2];

    vec4 v1 = vec4(vertex[11*ind1 + 0], vertex[11*ind1 + 1], vertex[11*ind1 + 2], 1.0f);
    vec4 v2 = vec4(vertex[11*ind2 + 0], vertex[11*ind2 + 1], vertex[11*ind2 + 2], 1.0f);
    vec4 v3 = vec4(vertex[11*ind3 + 0], vertex[11*ind3 + 1], vertex[11*ind3 + 2], 1.0f);

    vec4 n = vec4(vertex[11*ind3 + 3], vertex[11*ind3 + 4], vertex[11*ind3 + 5], 0.0f);

    v1 = uMVMatrix * v1;
    v2 = uMVMatrix * v2;
    v3 = uMVMatrix * v3;

    n = uMVMatrix * n;

    vec4 vc = (v1+v3)/4 + v2/2;

    // line-plane intersection
    float d = dot(vc, n) / dot(uRay, n);

    vec4 v = vec4(d*uRay.xyz, 1.0f);

    v2 = v2 - v1;
    v3 = v3 - v1;

    float vv3z = v.x*v3.y - v.y*v3.x;
    float v1v3z = v1.x*v3.y - v1.y*v3.x;

    float vv2z = v.x*v2.y - v.y*v2.x;
    float v1v2z = v1.x*v2.y - v1.y*v2.x;

    float v2v3z = v2.x*v3.y - v2.y*v3.x;

    float vv3x = v.y*v3.z - v.z*v3.y;
    float v1v3x = v1.y*v3.z - v1.z*v3.y;

    float vv2x = v.y*v2.z - v.z*v2.y;
    float v1v2x = v1.y*v2.z - v1.z*v2.y;

    float v2v3x = v2.y*v3.z - v2.z*v3.y;

    float vv3 = abs(v2v3z) > abs(v2v3x) ? vv3z : vv3x;
    float v1v3 = abs(v2v3z) > abs(v2v3x) ? v1v3z : v1v3x;

    float vv2 = abs(v2v3z) > abs(v2v3x) ? vv2z : vv2x;
    float v1v2 = abs(v2v3z) > abs(v2v3x) ? v1v2z : v1v2x;

    float v2v3 = abs(v2v3z) > abs(v2v3x) ? v2v3z : v2v3x;

    float a = (vv3 - v1v3)/v2v3;
    float b = -(vv2 - v1v2)/v2v3;

    float iCheck = d > 0 && a > 0.0f && b > 0.0f && (a+b) < 1.0f ? 1.0f : 0.0f;

    outBuffer[5*i + 0] = d;
    outBuffer[5*i + 1] = iCheck;
    outBuffer[5*i + 2] = vertex[11*ind1 + 7];
    outBuffer[5*i + 3] = vertex[11*ind1 + 8];
    outBuffer[5*i + 4] = vertex[11*ind1 + 9];
}
