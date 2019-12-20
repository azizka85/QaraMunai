#version 430
uniform int uPrimitiveCount;
uniform int uDiv;

layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
layout (std430, binding = 3) buffer OutBlockIndexBuffer { uint outBlockIndex[]; };
layout (std430, binding = 4) buffer OutBlockDistanceBuffer { float outBlockDistance[]; };
layout (std430, binding = 5) buffer OutIsSelectedBlockBuffer { bool outIsSelectedBlock[]; };

bool compare(in uint id1, in uint id2);
void check(in uint id1, in uint id2);

void main(void)
{
    uint id = gl_GlobalInvocationID.z * gl_NumWorkGroups.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.y * gl_NumWorkGroups.x +
                gl_GlobalInvocationID.x;

    uint n = uDiv;

    uint id1 = n*(2*id);
    uint id2 = n*(2*id+1);

    if(id2 < uPrimitiveCount) check(id1, id2);
}

bool compare(in uint id1, in uint id2)
{
    if(outIsSelectedBlock[id1])
    {
        if(outIsSelectedBlock[id2])
        {
            if(outBlockDistance[id1] > outBlockDistance[id2]) return false;
        }

        return true;
    }

    return false;
}

void check(in uint id1, in uint id2)
{
    bool isMin = compare(id1, id2);

    if(!isMin)
    {
        float ftemp = outBlockDistance[id1];
        outBlockDistance[id1] = outBlockDistance[id2];
        outBlockDistance[id2] = ftemp;

        uint itemp = outBlockIndex[id1];
        outBlockIndex[id1] = outBlockIndex[id2];
        outBlockIndex[id2] = itemp;

        bool btemp = outIsSelectedBlock[id1];
        outIsSelectedBlock[id1] = outIsSelectedBlock[id2];
        outIsSelectedBlock[id2] = btemp;
    }
}


