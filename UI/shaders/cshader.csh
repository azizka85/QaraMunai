#version 430
uniform vec2 uViewPort;
uniform vec4 uRay;
uniform mat4 uProjectionMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uScaleMatrix;

layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout (std430, binding = 0) buffer VertexBuffer { float vertex[]; };
layout (std430, binding = 1) buffer IndexBuffer { uint index[]; };
layout (std430, binding = 2) buffer OutputBuffer { float outBuffer[]; };

void main(void)
{
    uint i = gl_GlobalInvocationID.x;

    uint ind1 = index[3*i + 0];
    uint ind2 = index[3*i + 1];
    uint ind3 = index[3*i + 2];

    vec4 v1 = vec4(vertex[11*ind1 + 0], vertex[11*ind1 + 1], vertex[11*ind1 + 2], 1.0f);
    vec4 v2 = vec4(vertex[11*ind2 + 0], vertex[11*ind2 + 1], vertex[11*ind2 + 2], 1.0f);
    vec4 v3 = vec4(vertex[11*ind3 + 0], vertex[11*ind3 + 1], vertex[11*ind3 + 2], 1.0f);

    vec4 n = vec4(vertex[11*ind3 + 3], vertex[11*ind3 + 4], vertex[11*ind3 + 5], 0.0f);

    v1 = uMVMatrix * uScaleMatrix * v1;
    v2 = uMVMatrix * uScaleMatrix * v2;
    v3 = uMVMatrix * uScaleMatrix * v3;

    n = uMVMatrix * n;

    // line-plane intersection
    float d = dot(v1, n) / dot(uRay, n);

    vec4 v = vec4(d*uRay.xyz, 1.0f);

    v1 = uProjectionMatrix * v1;
    v2 = uProjectionMatrix * v2;
    v3 = uProjectionMatrix * v3;

    v = uProjectionMatrix * v;

    vec2 p1 = uViewPort * v1.xy / v1.w;
    vec2 p2 = uViewPort * v2.xy / v2.w;
    vec2 p3 = uViewPort * v3.xy / v3.w;

    vec2 p = uViewPort * v.xy / v.w;

    float iCheck = 0.0f;

    // checking
    float area = 0.5f *(-p2.y*p3.x + p1.y*(-p2.x + p3.x) + p1.x*(p2.y - p3.y) + p2.x*p3.y);

    float s = 1/(2*area)*(p1.y*p3.x - p1.x*p3.y + (p3.y - p1.y)*p.x + (p1.x - p3.x)*p.y);
    float t = 1/(2*area)*(p1.x*p2.y - p1.y*p2.x + (p1.y - p2.y)*p.x + (p2.x - p1.x)*p.y);

    if(d >= 0 && s >= 0 && t >= 0 && 1 - s - t >= 0) iCheck = 1.0f;

    outBuffer[5*i + 0] = d;
    outBuffer[5*i + 1] = iCheck;
    outBuffer[5*i + 2] = vertex[11*ind1 + 7];
    outBuffer[5*i + 3] = vertex[11*ind1 + 8];
    outBuffer[5*i + 4] = vertex[11*ind1 + 9];
}
