#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform vec2 uViewPort;
uniform float uM;

in vec4 gVt[3];
in vec4 gVp[3];
in float gValue[3];
in float gBlockIndex[3];

out vec3 fN;
out vec4 fV;
out float fValue;
out vec3 fD;
out float fBlockIndex;

void main(void)
{
    vec2 p1 = uViewPort * gVp[0].xy / gVp[0].w;
    vec2 p2 = uViewPort * gVp[1].xy / gVp[1].w;
    vec2 p3 = uViewPort * gVp[2].xy / gVp[2].w;

    vec2 t1 = p3 - p2;
    vec2 t2 = p3 - p1;
    vec2 t3 = p2 - p1;

    float area = abs(t2.x * t3.y - t2.y * t3.x);

    vec3 v1 = gVt[1].xyz - gVt[0].xyz;
    vec3 v2 = gVt[2].xyz - gVt[0].xyz;

    vec3 nt = normalize(cross(v1, v2));

    fD = vec3(area / length(t1), 0, 0);
    fV = gVt[0];
    fN = nt;
    fValue = gValue[0];
    fBlockIndex = gBlockIndex[0];
    gl_Position = gVp[0];
    EmitVertex();

    fD = vec3(uM, area / length(t2), 0);
    fV = gVt[1];
    fN = nt;
    fValue = gValue[1];
    fBlockIndex = gBlockIndex[1];
    gl_Position = gVp[1];
    EmitVertex();

    fD = vec3(uM, 0, area / length(t3));
    fV = gVt[2];
    fN = nt;
    fValue = gValue[2];
    fBlockIndex = gBlockIndex[2];
    gl_Position = gVp[2];
    EmitVertex();

    EndPrimitive();
}
