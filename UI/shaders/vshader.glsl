#version 330 core

uniform mat4 uProjectionMatrix;
uniform mat4 uMVMatrix;

in vec4 vV;
in float vValue;
in float vBlockIndex;

out vec4 gVt;
out vec4 gVp;
out float gValue;
out float gBlockIndex;

void main(void)
{
    gVt = uMVMatrix * vV;

    gVp = uProjectionMatrix * gVt;

    gValue = vValue;

    gBlockIndex = vBlockIndex;
}
