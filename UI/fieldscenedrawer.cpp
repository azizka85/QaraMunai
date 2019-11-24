#include "fieldscenedrawer.h"

FieldSceneDrawer::FieldSceneDrawer(QQuickItem *parent) : QQuickFramebufferObject(parent)
{
    initVariables();
}

QQuickFramebufferObject::Renderer *FieldSceneDrawer::createRenderer() const
{
    return new FieldSceneDrawer::Renderer();
}

ProjectData *FieldSceneDrawer::Data()
{
    return data;
}

bool FieldSceneDrawer::ShowMesh()
{
    return showMesh;
}

bool FieldSceneDrawer::ShowContour()
{
    return showContour;
}

bool FieldSceneDrawer::Transparent()
{
    return transparent;
}

bool FieldSceneDrawer::Lighting()
{
    return lighting;
}

FieldSceneDrawer::RotationAxis FieldSceneDrawer::AxisOfRotation()
{
    return axisOfRotation;
}

int FieldSceneDrawer::SelectedBlockI()
{
    return selectedBlockI;
}

int FieldSceneDrawer::SelectedBlockJ()
{
    return selectedBlockJ;
}

int FieldSceneDrawer::SelectedBlockK()
{
    return selectedBlockK;
}

QVector2D FieldSceneDrawer::MousePosition()
{
    return mousePosition;
}

QVector2D FieldSceneDrawer::MouseDisplacement()
{
    return mouseDisplacement;
}

float FieldSceneDrawer::ZLocation()
{
    return zLocation;
}

float FieldSceneDrawer::MultX()
{
    return multX;
}

float FieldSceneDrawer::MultY()
{
    return multY;
}

float FieldSceneDrawer::MultZ()
{
    return multZ;
}

void FieldSceneDrawer::SetData(ProjectData *data)
{
    this->data = data;

    dataUpdated = true;

    update();

    DataChanged();
}

void FieldSceneDrawer::SetShowMesh(const bool &showMesh)
{
    this->showMesh = showMesh;

    update();

    ShowMeshChanged();
}

void FieldSceneDrawer::SetShowContour(const bool &showContour)
{
    this->showContour = showContour;

    update();

    ShowContourChanged();
}

void FieldSceneDrawer::SetTransparent(const bool &transparent)
{
    this->transparent = transparent;

    update();

    TransparentChanged();
}

void FieldSceneDrawer::SetLighting(const bool &lighting)
{
    this->lighting = lighting;

    update();

    LightingChanged();
}

void FieldSceneDrawer::SetAxisOfRotation(const RotationAxis &axisOfRotation)
{
    this->axisOfRotation = axisOfRotation;

    AxisOfRotationChanged();
}

void FieldSceneDrawer::SetSelectedBlockI(const int &selectedBlockI)
{
    if(this->selectedBlockI != selectedBlockI)
    {
        this->selectedBlockI = selectedBlockI;

        SelectedBlockIndexChanged();
    }
}

void FieldSceneDrawer::SetSelectedBlockJ(const int &selectedBlockJ)
{
    if(this->selectedBlockJ != selectedBlockJ)
    {
        this->selectedBlockJ = selectedBlockJ;

        SelectedBlockIndexChanged();
    }
}

void FieldSceneDrawer::SetSelectedBlockK(const int &selectedBlockK)
{
    if(this->selectedBlockK != selectedBlockK)
    {
        this->selectedBlockK = selectedBlockK;

        SelectedBlockIndexChanged();
    }
}

void FieldSceneDrawer::SetMousePosition(const QVector2D &mouseSelection)
{
    this->mousePosition = mouseSelection;

    update();

    MousePositionChanged();
}

void FieldSceneDrawer::SetMouseDisplacement(const QVector2D &mouseDisplacement)
{
    this->mouseDisplacement = mouseDisplacement;

    float angle = mouseDisplacement.length() / 2.0f;

    QVector3D axis;

    switch (axisOfRotation) {
    case RotationAxis::XY:
        axis = QVector3D(mouseDisplacement.y(), mouseDisplacement.x(), 0.0);
        break;
    case RotationAxis::X:
        axis = QVector3D(mouseDisplacement.y(), 0.0, 0.0);
        break;
    case RotationAxis::Y:
        axis = QVector3D(0.0, mouseDisplacement.x(), 0.0);
        break;
    case RotationAxis::Z:
        axis = QVector3D(0.0, 0.0, mouseDisplacement.x());
        break;
    }

    rot = QQuaternion::fromAxisAndAngle(axis, angle) * rot;

    update();

    MouseDisplacementChanged();
}

void FieldSceneDrawer::SetZLocation(const float &zLocation)
{
    this->zLocation = zLocation;

    update();

    ZLocationChanged();
}

void FieldSceneDrawer::SetMultX(const float &multX)
{
    this->multX = multX;

    update();

    MultXChanged();
}

void FieldSceneDrawer::SetMultY(const float &multY)
{
    this->multY = multY;

    update();

    MultYChanged();
}

void FieldSceneDrawer::SetMultZ(const float &multZ)
{
    this->multZ = multZ;

    update();

    MultZChanged();
}

void FieldSceneDrawer::setXYViewAxis()
{
    rot = QQuaternion::fromAxisAndAngle(0, 0, 0, 0);

    update();
}

void FieldSceneDrawer::setXZViewAxis()
{
    rot = QQuaternion::fromAxisAndAngle(1, 0, 0, 90);

    update();
}

void FieldSceneDrawer::setYZViewAxis()
{
    rot = QQuaternion::fromAxisAndAngle(0, 1, 0, 90);

    update();
}

QVariantList FieldSceneDrawer::getFields()
{
    QVariantList data;

    foreach (FieldInfo fi, fields) {
        data.append(fi.toMap());
    }

    return data;
}

QVariantList FieldSceneDrawer::getCalcFields()
{
    QVariantList calcFields;

    calcFields.append(fields[SWAT].toMap());
    calcFields.append(fields[SOIL].toMap());
    calcFields.append(fields[SGAS].toMap());
    calcFields.append(fields[PRESSURE].toMap());
    calcFields.append(fields[PBUB].toMap());

    return calcFields;
}

void FieldSceneDrawer::updateData(int state)
{
    this->state = static_cast<ProjectData::ProjectState>(state);

    dataUpdated = true;

    update();
}

void FieldSceneDrawer::initVariables()
{
    data = nullptr;

    dataUpdated = false;
    state = ProjectData::ProjectState::CLOSED;

    selectedBlockI = -1;
    selectedBlockJ = -1;
    selectedBlockK = -1;

    zLocation = 0;
    showMesh = true;
    showContour = true;
    axisOfRotation = RotationAxis::XY;

    multX = multY = multZ = 1;

    QMetaObject metaObject = staticMetaObject;

    QMetaEnum fieldNamesEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FieldNames"));

    fields.resize(fieldNamesEnum.keyCount());

    fields[PERMX] = FieldInfo(QString("Прон. по X"), QString("Прон. по X"), QString("mD"));
    fields[PERMY] = FieldInfo(QString("Прон. по Y"), QString("Прон. по Y"), QString("mD"));
    fields[PERMZ] = FieldInfo(QString("Прон. по Z"), QString("Прон. по Z"), QString("mD"));
    fields[PORO] = FieldInfo(QString("Пористость"), QString("Пористость"), QString());
    fields[NTG] = FieldInfo(QString("Песчанистость"), QString("Песчанистость"), QString());
    fields[TRANX] = FieldInfo(QString("TranX"), QString("Проводимость по X"), QString("cP-rm3/day/bar"));
    fields[TRANY] = FieldInfo(QString("TranY"), QString("Проводимость по Y"), QString("cP-rm3/day/bar"));
    fields[TRANZ] = FieldInfo(QString("TranZ"), QString("Проводимость по Z"), QString("cP-rm3/day/bar"));
    fields[SWAT] = FieldInfo(QString("Sw"), QString("Насыщ. водой"), QString());
    fields[SOIL] = FieldInfo(QString("So"), QString("Насыщ. нефтью"), QString());
    fields[SGAS] = FieldInfo(QString("Sg"), QString("Насыщ. газом"), QString());
    fields[RS] = FieldInfo(QString("RS"), QString("RS"), QString());
    fields[PRESSURE] = FieldInfo(QString("Давление"), QString("Давление"), QString("barsa"));
    fields[PW] = FieldInfo(QString("PW"), QString("PW"), QString("barsa"));
    fields[PBUB] = FieldInfo(QString("Давл. насыщения"), QString("Давл. насыщ."), QString("barsa"));
    fields[DEPTH] = FieldInfo(QString("Глубина"), QString("Глубина"), QString("m"));
    fields[PVTNUM] = FieldInfo(QString("PVTNUM"), QString("PVTNUM"), QString());
    fields[SATNUM] = FieldInfo(QString("SATNUM"), QString("SATNUM"), QString());
    fields[EQLNUM] = FieldInfo(QString("EQLNUM"), QString("EQLNUM"), QString());
    fields[PORV] = FieldInfo(QString("PORV"), QString("PORV"), QString());
    fields[OILV] = FieldInfo(QString("OILV"), QString("OILV"), QString());
}

QOpenGLFramebufferObject *FieldSceneDrawer::Renderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;

    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

    return new QOpenGLFramebufferObject(size, format);
}

FieldSceneDrawer::Renderer::Renderer() : QQuickFramebufferObject::Renderer(), indBuffer(QOpenGLBuffer::IndexBuffer)
{
    initialize();
}

void FieldSceneDrawer::Renderer::initialize()
{
    initialized = true;

    initializeOpenGLFunctions();

    initShaders();
    initBuffer();
}

void FieldSceneDrawer::Renderer::synchronize(QQuickFramebufferObject *fbo)
{
    drawer = static_cast<FieldSceneDrawer*>(fbo);       

    float w = static_cast<float>(drawer->width());
    float h = static_cast<float>(drawer->height());

    float multX = drawer->multX;
    float multY = drawer->multY;
    float multZ = drawer->multZ;

    QQuaternion rotation = drawer->rot;
    float z = drawer->zLocation;

    float aspect = w/h;

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f, aspect, 0.01f, 100.0f);

    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, z);
    viewMatrix.rotate(rotation);

    modelMatrix.setToIdentity();    

    scaleMatrix.setToIdentity();
    scaleMatrix.scale(multX, multY, multZ);

    if(drawer->dataUpdated || initialized)
    {
        if(drawer->state != ProjectData::ProjectState::CLOSED) initGeometry();
        else clearGeometry();

        drawer->dataUpdated = false;
        initialized = false;
    }

    if(mousePosition != drawer->mousePosition)
    {
        compute();

        mousePosition = drawer->mousePosition;
    }
}

void FieldSceneDrawer::Renderer::render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    // glEnable(GL_CULL_FACE);

    // glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    bool showMesh = drawer->showMesh;
    bool showContour = drawer->showContour;
    bool transparent = drawer->transparent;
    bool lighting = drawer->lighting;

    float w = static_cast<float>(drawer->width());
    float h = static_cast<float>(drawer->height());

    QVector2D viewPort(w, h);

    QVector3D maxColor(1, 0, 0);
    QVector3D midColor(0, 1, 0);
    QVector3D minColor(0, 0, 1);

    float maxValue = 150.0f;
    float minValue = 0.0f;

    float i = drawer->selectedBlockI;
    float j = drawer->selectedBlockJ;
    float k = drawer->selectedBlockK;

    shaderProgram.bind();
    shaderProgram.setUniformValue("uProjectionMatrix", projectionMatrix);
    shaderProgram.setUniformValue("uViewMatrix", viewMatrix);
    shaderProgram.setUniformValue("uModelMatrix", modelMatrix);
    shaderProgram.setUniformValue("uScaleMatrix", scaleMatrix);
    shaderProgram.setUniformValue("uViewPort", viewPort);
    shaderProgram.setUniformValue("uShowMesh", showMesh);
    shaderProgram.setUniformValue("uShowContour", showContour);
    shaderProgram.setUniformValue("uTransparent", transparent);
    shaderProgram.setUniformValue("uLighting", lighting);
    shaderProgram.setUniformValue("uMaxColor", maxColor);
    shaderProgram.setUniformValue("uMidColor", midColor);
    shaderProgram.setUniformValue("uMinColor", minColor);
    shaderProgram.setUniformValue("uMaxValue", maxValue);
    shaderProgram.setUniformValue("uMinValue", minValue);
    shaderProgram.setUniformValue("uSelectedBlockI", i);
    shaderProgram.setUniformValue("uSelectedBlockJ", j);
    shaderProgram.setUniformValue("uSelectedBlockK", k);

    arrayBuffer.bind();

    int offset = 0;

    int vertexLocation = shaderProgram.attributeLocation("aPosition");

    shaderProgram.enableAttributeArray(vertexLocation);
    shaderProgram.setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof (VertexData));

    offset += sizeof (QVector3D);

    int normalLocation = shaderProgram.attributeLocation("aNormal");

    shaderProgram.enableAttributeArray(normalLocation);
    shaderProgram.setAttributeBuffer(normalLocation, GL_FLOAT, offset, 3, sizeof (VertexData));

    offset += sizeof (QVector3D);

    int excludeLocation = shaderProgram.attributeLocation("aExclude");

    shaderProgram.enableAttributeArray(excludeLocation);
    shaderProgram.setAttributeBuffer(excludeLocation, GL_FLOAT, offset, 1, sizeof (VertexData));

    offset += sizeof (float);

    int blockILocation = shaderProgram.attributeLocation("aBlockI");

    shaderProgram.enableAttributeArray(blockILocation);
    shaderProgram.setAttributeBuffer(blockILocation, GL_FLOAT, offset, 1, sizeof (VertexData));

    offset += sizeof (float);

    int blockJLocation = shaderProgram.attributeLocation("aBlockJ");

    shaderProgram.enableAttributeArray(blockJLocation);
    shaderProgram.setAttributeBuffer(blockJLocation, GL_FLOAT, offset, 1, sizeof (VertexData));

    offset += sizeof (float);

    int blockKLocation = shaderProgram.attributeLocation("aBlockK");

    shaderProgram.enableAttributeArray(blockKLocation);
    shaderProgram.setAttributeBuffer(blockKLocation, GL_FLOAT, offset, 1, sizeof (VertexData));

    offset += sizeof (float);

    int valueLocation = shaderProgram.attributeLocation("aValue");

    shaderProgram.enableAttributeArray(valueLocation);
    shaderProgram.setAttributeBuffer(valueLocation, GL_FLOAT, offset, 1, sizeof (VertexData));

    indBuffer.bind();

    glDrawElements(GL_TRIANGLES, indBuffer.size(), GL_UNSIGNED_INT, nullptr);

    indBuffer.release();
    arrayBuffer.release();
    shaderProgram.release();
}

void FieldSceneDrawer::Renderer::initShaders()
{
    computeProgram.addShaderFromSourceFile(QOpenGLShader::Compute, ":/shaders/cshader.csh");
    computeProgram.link();

    sortProgram.addShaderFromSourceFile(QOpenGLShader::Compute, ":/shaders/sshader.csh");
    sortProgram.link();

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/vshader.vsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Geometry, ":/shaders/gshader.gsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/fshader.fsh");
    shaderProgram.link();
}

void FieldSceneDrawer::Renderer::initBuffer()
{
    arrayBuffer.create();
    indBuffer.create();
    outputBuffer.create();
}

void FieldSceneDrawer::Renderer::initGeometry()
{
    primitiveCount = 0;

    QVector<VertexData> vertexes;
    QVector<GLuint> indexes;

    if(drawer->data != nullptr)
    {
        double xMin = 0;
        double xMax = 0;

        double yMin = 0;
        double yMax = 0;

        double zMin = 0;
        double zMax = 0;

        QVector<Depth> depths;
        QVector<bool> existBlock;
        QVector<bool> drawBlock;
        QVector<Block> blocks;

        DataHelper::CalculateBlockDepthArray(drawer->data, depths);
        DataHelper::CalculateExistBlockArray(drawer->data, existBlock);
        DataHelper::CalculateDrawBlockArray(drawer->data, depths, existBlock, drawBlock);
        DataHelper::GetDrawBlocks(drawer->data, drawBlock, blocks, xMin, xMax, yMin, yMax, zMin, zMax);
        DataHelper::NormalizeBlocks(xMin, xMax, yMin, yMax, zMin, zMax, blocks);

        qDebug() << "xMin: " << xMin << ", yMin: " << yMin << ", zMin: " << zMin << "\n";
        qDebug() << "xMax: " << xMax << ", yMax: " << yMax << ", zMax: " << zMax << "\n";

        for(int i = 0; i < blocks.size(); i++)
        {
            Block& block = blocks[i];

            vertexes.append(VertexData(QVector3D(block.P7().X(), block.P7().Y(), block.P7().Z()), QVector3D(0.0f, 0.0f, 1.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P5().X(), block.P5().Y(), block.P5().Z()), QVector3D(0.0f, 0.0f, 1.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P8().X(), block.P8().Y(), block.P8().Z()), QVector3D(0.0f, 0.0f, 1.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P6().X(), block.P6().Y(), block.P6().Z()), QVector3D(0.0f, 0.0f, 1.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            vertexes.append(VertexData(QVector3D(block.P8().X(), block.P8().Y(), block.P8().Z()), QVector3D(1.0f, 0.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P6().X(), block.P6().Y(), block.P6().Z()), QVector3D(1.0f, 0.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P4().X(), block.P4().Y(), block.P4().Z()), QVector3D(1.0f, 0.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P2().X(), block.P2().Y(), block.P2().Z()), QVector3D(1.0f, 0.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            vertexes.append(VertexData(QVector3D(block.P8().X(), block.P8().Y(), block.P8().Z()), QVector3D(0.0f, 1.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P4().X(), block.P4().Y(), block.P4().Z()), QVector3D(0.0f, 1.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P7().X(), block.P7().Y(), block.P7().Z()), QVector3D(0.0f, 1.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P3().X(), block.P3().Y(), block.P3().Z()), QVector3D(0.0f, 1.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            vertexes.append(VertexData(QVector3D(block.P4().X(), block.P4().Y(), block.P4().Z()), QVector3D(0.0f, 0.0f, -1.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P2().X(), block.P2().Y(), block.P2().Z()), QVector3D(0.0f, 0.0f, -1.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P3().X(), block.P3().Y(), block.P3().Z()), QVector3D(0.0f, 0.0f, -1.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P1().X(), block.P1().Y(), block.P1().Z()), QVector3D(0.0f, 0.0f, -1.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            vertexes.append(VertexData(QVector3D(block.P7().X(), block.P7().Y(), block.P7().Z()), QVector3D(-1.0f, 0.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P3().X(), block.P3().Y(), block.P3().Z()), QVector3D(-1.0f, 0.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P5().X(), block.P5().Y(), block.P5().Z()), QVector3D(-1.0f, 0.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P1().X(), block.P1().Y(), block.P1().Z()), QVector3D(-1.0f, 0.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            vertexes.append(VertexData(QVector3D(block.P5().X(), block.P5().Y(), block.P5().Z()), QVector3D(0.0f, -1.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P1().X(), block.P1().Y(), block.P1().Z()), QVector3D(0.0f, -1.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P6().X(), block.P6().Y(), block.P6().Z()), QVector3D(0.0f, -1.0f, 0.0f), 0.0f, block.I(), block.J(), block.K(), 0.0f));
            vertexes.append(VertexData(QVector3D(block.P2().X(), block.P2().Y(), block.P2().Z()), QVector3D(0.0f, -1.0f, 0.0f), 1.0f, block.I(), block.J(), block.K(), 0.0f));

            for(GLuint j = 0; j < 24; j += 4)
            {
                indexes.append(static_cast<GLuint>(24*i) + j + 0);
                indexes.append(static_cast<GLuint>(24*i) + j + 1);
                indexes.append(static_cast<GLuint>(24*i) + j + 2);

                indexes.append(static_cast<GLuint>(24*i) + j + 2);
                indexes.append(static_cast<GLuint>(24*i) + j + 1);
                indexes.append(static_cast<GLuint>(24*i) + j + 3);

                primitiveCount += 2;
            }
        }

        qDebug() << "Depth array size: " << depths.size();
        qDebug() << "Exist block array size: " << existBlock.size();
        qDebug() << "Draw block array size: " << drawBlock.size();
        qDebug() << blocks.size() << ", " << primitiveCount;
    }

    arrayBuffer.bind();
    arrayBuffer.allocate(vertexes.constData(), vertexes.size() * static_cast<int>(sizeof (VertexData)));
    arrayBuffer.release();

    indBuffer.bind();
    indBuffer.allocate(indexes.constData(), indexes.size() * static_cast<int>(sizeof (GLuint)));
    indBuffer.release();

    outputBuffer.bind();
    outputBuffer.allocate(5 * static_cast<int>(primitiveCount) * static_cast<int>(sizeof(float)));
    outputBuffer.release();
}

void FieldSceneDrawer::Renderer::clearGeometry()
{
    primitiveCount = 0;

    arrayBuffer.bind();
    arrayBuffer.allocate(0);
    arrayBuffer.release();

    indBuffer.bind();
    indBuffer.allocate(0);
    indBuffer.release();

    outputBuffer.bind();
    outputBuffer.allocate(0);
    outputBuffer.release();
}

void FieldSceneDrawer::Renderer::compute()
{
    float width = static_cast<float>(drawer->width());
    float height = static_cast<float>(drawer->height());

    QVector2D viewPort(width, height);

    QVector2D mousePosition = drawer->MousePosition();

    mousePosition.setX(2*mousePosition.x() - width);
    mousePosition.setY(2*mousePosition.y() - height);

    QVector4D rayClip(mousePosition.x()/width, mousePosition.y()/height, -1.0f, 1.0f);

    QVector4D rayEye = projectionMatrix.inverted() * rayClip;

    rayEye.setW(0);

    QVector4D rayWorld = rayEye;

    rayWorld.normalize();

    QMatrix4x4 mvMatrix = viewMatrix * modelMatrix;

    int cNx, cNy;

    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &cNx);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &cNy);

    qDebug() << "Max compute nodes: " << cNx << ", " << cNy;

    int lNx, lNy;

    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &lNx);
    glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &lNy);

    qDebug() << "Max local invocations: " << lNx << ", " << lNy;

    int cx, cy, cz;

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, arrayBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, indBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, outputBuffer.bufferId());

    computeProgram.bind();
    computeProgram.setUniformValue("uScaleMatrix", scaleMatrix);
    computeProgram.setUniformValue("uViewPort", viewPort);
    computeProgram.setUniformValue("uRay", rayWorld);
    computeProgram.setUniformValue("uProjectionMatrix", projectionMatrix);
    computeProgram.setUniformValue("uMVMatrix", mvMatrix);

    DataHelper::NumberOfGPUNodes(primitiveCount, cNx, cNy, cx, cy, cz);

    qDebug() << "Compute: " << cx << ", " << cy << ", " << cz;

    glDispatchCompute(cx, cy, cz);

    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);

    computeProgram.release();

    sortProgram.bind();
    sortProgram.setUniformValue("uPrimitiveCount", primitiveCount);

    uint d = 1;
    uint n = primitiveCount;

    while(d < primitiveCount)
    {
        n = (n%2 == 0) ? n/2 : (n+1)/2;

        sortProgram.setUniformValue("uDiv", d);

        DataHelper::NumberOfGPUNodes(n, cNx, cNy, cx, cy, cz);

        qDebug() << "Sort " << d << ": " << cx << ", " << cy << ", " << cz;

        glDispatchCompute(cx, cy, cz);

        glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);

        d = 2*d;
    }

    sortProgram.release();

    outputBuffer.bind();

    float out[5];

    outputBuffer.read(0, out, 5*sizeof (float));

    outputBuffer.release();

    if(out[1] > 0)
    {
        drawer->SetSelectedBlockI(qRound(out[2]));
        drawer->SetSelectedBlockJ(qRound(out[3]));
        drawer->SetSelectedBlockK(qRound(out[4]));        
    }
    else
    {
        drawer->SetSelectedBlockI(-1);
        drawer->SetSelectedBlockJ(-1);
        drawer->SetSelectedBlockK(-1);
    }
}
