#version 330 core

uniform bool uShowMesh;
uniform vec4 uLightPosition;
uniform float uLightPower;
uniform vec4 uMaxColor;
uniform vec4 uMidColor;
uniform vec4 uMinColor;
uniform float uMaxValue;
uniform float uMinValue;
uniform float uSelectedValue;

in vec3 vNormal;
in vec4 vPosition;
in float vValue;
in vec3 d;

void main(void)
{
    vec4 lineColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
    vec4 resultColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
    vec4 diffMatColor;

    vec3 lightVector = normalize(vPosition.xyz - uLightPosition.xyz);

    float w = uMaxValue <= uMinValue ? 0.0f : max(0.0f, min(1.0f, (vValue - uMinValue)/(uMaxValue - uMinValue)));

    if(w <= 0.25f) diffMatColor = uMinColor + 4.0f * w * uMidColor;
    else if(w > 0.25f && w <= 0.5f) diffMatColor = 4.0f * (0.5f - w) * uMinColor + uMidColor;
    else if(w > 0.5f && w <= 0.75f) diffMatColor = uMidColor + 4.0f * (w - 0.5f) * uMaxColor;
    else diffMatColor = 4.0f * (1.0f - w) * uMidColor + uMaxColor;

    vec4 diffColor = diffMatColor * uLightPower * dot(vNormal, -lightVector);

    resultColor += diffColor;

    float sFactor = exp2(-abs(vValue - uSelectedValue));

    resultColor = (1 - 0.5*sFactor)*resultColor + 0.5*sFactor*vec4(1.0f, 1.0f, 1.0f, 1.0f);

    float x = min(min(d[0], d[1]), d[2]) - 1.0f;

    float edgeIntensity = uShowMesh ? exp2(-x*x) : 0.0f;

    gl_FragColor = edgeIntensity * vec4(1.0f, 1.0f, 1.0f, 1.0f) + (1.0f - edgeIntensity) * resultColor;
}
