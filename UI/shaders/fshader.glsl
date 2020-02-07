#version 330 core

uniform bool uShowMesh;
uniform bool uShowContour;
uniform bool uTransparent;
uniform bool uLighting;
uniform vec3 uMaxColor;
uniform vec3 uMidColor;
uniform vec3 uMinColor;
uniform float uMaxValue;
uniform float uMinValue;
uniform float uSelectedBlockIndex;

in vec3 fN;
in vec4 fV;
in float fValue;
in vec3 fD;
in float fBlockIndex;

void main(void)
{
    vec4 resultColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);

    if(uShowContour)
    {
        vec3 diffMatColor;

        float w = uMaxValue <= uMinValue ? 0.0f : max(0.0f, min(1.0f, (fValue - uMinValue)/(uMaxValue - uMinValue)));

        if(w <= 0.25f) diffMatColor = uMinColor + 4.0f * w * uMidColor;
        else if(w > 0.25f && w <= 0.5f) diffMatColor = 4.0f * (0.5f - w) * uMinColor + uMidColor;
        else if(w > 0.5f && w <= 0.75f) diffMatColor = uMidColor + 4.0f * (w - 0.5f) * uMaxColor;
        else diffMatColor = 4.0f * (1.0f - w) * uMidColor + uMaxColor;

        vec3 diffColor = diffMatColor;

        if(uLighting)
        {
            vec3 lightPosition = vec3(0.0f, 0.0f, 0.0f);

            vec3 lightVector = normalize(fV.xyz - lightPosition);

            float colorIntensity = dot(fN, -lightVector);

            if(colorIntensity < 0.0f) colorIntensity = -colorIntensity;

            diffColor = diffMatColor * colorIntensity;
        }

        resultColor.xyz += diffColor;

        float sFactor = exp2(-10*abs(fBlockIndex - uSelectedBlockIndex));

        resultColor.xyz = (1 - 0.5*sFactor)*resultColor.xyz + 0.5*sFactor*vec3(1.0f, 1.0f, 1.0f);

        if(uTransparent) resultColor.w = 0.3;
    }
    else resultColor.w = 0.0f;

    if(uShowMesh)
    {
        float x = min(min(fD[0], fD[1]), fD[2]);

        float edgeIntensity = exp2(-x*x);

        resultColor = edgeIntensity * vec4(1.0f, 1.0f, 1.0f, 1.0f) + (1.0f - edgeIntensity) * resultColor;
    }

    gl_FragColor = resultColor;
}
