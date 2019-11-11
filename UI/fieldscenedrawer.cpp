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

QVariant FieldSceneDrawer::SelectedValue()
{
    return selectedValue;
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

void FieldSceneDrawer::SetSelectedValue(const QVariant &selectedValue)
{
    this->selectedValue = selectedValue;

    SelectedValueChanged();
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
    dataUpdated = false;
    state = ProjectData::ProjectState::CLOSED;

    zLocation = -5;
    showMesh = true;
    showContour = true;
    axisOfRotation = RotationAxis::XY;

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

    QQuaternion rotation = drawer->rot;
    float z = drawer->zLocation;

    float aspect = w/h;

    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f, aspect, 0.1f, 100.0f);

    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0f, 0.0f, z);
    viewMatrix.rotate(rotation);

    modelMatrix.setToIdentity();    

    if(drawer->dataUpdated || initialized)
    {
        if(drawer->state != ProjectData::ProjectState::CLOSED) initGeometry();
        else clearGeometry();

        drawer->dataUpdated = false;
        initialized = false;
    }

    if(mousePosition != drawer->mousePosition)
    {
        QVariant retVal = compute();

        drawer->SetSelectedValue(retVal);

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

    float selectedValue = drawer->SelectedValue().isNull() ? -1000 : drawer->SelectedValue().toFloat();

    shaderProgram.bind();
    shaderProgram.setUniformValue("uProjectionMatrix", projectionMatrix);
    shaderProgram.setUniformValue("uViewMatrix", viewMatrix);
    shaderProgram.setUniformValue("uModelMatrix", modelMatrix);
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
    shaderProgram.setUniformValue("uSelectedValue", selectedValue);

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
    float width = 1.0f;

    float width_div_2 = width / 2.0f;

    QVector<VertexData> vertexes;

    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector3D(0.0f, 0.0f, 1.0f), 1.0f, 0.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2),QVector3D(0.0f, 0.0f, 1.0f), 0.0f, 0.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector3D(0.0f, 0.0f, 1.0f), 0.0f, 0.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector3D(0.0f, 0.0f, 1.0f), 1.0f, 0.0f));

    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector3D(1.0f, 0.0f, 0.0f), 1.0f, 30.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector3D(1.0f, 0.0f, 0.0f), 0.0f, 30.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector3D(1.0f, 0.0f, 0.0f), 0.0f, 30.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector3D(1.0f, 0.0f, 0.0f), 1.0f, 30.0f));

    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, width_div_2), QVector3D(0.0f, 1.0f, 0.0f), 1.0f, 60.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector3D(0.0f, 1.0f, 0.0f), 0.0f, 60.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector3D(0.0f, 1.0f, 0.0f), 0.0f, 60.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector3D(0.0f, 1.0f, 0.0f), 1.0f, 60.0f));

    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector3D(0.0f, 0.0f, -1.0f), 1.0f, 90.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector3D(0.0f, 0.0f, -1.0f), 0.0f, 90.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector3D(0.0f, 0.0f, -1.0f), 0.0f, 90.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector3D(0.0f, 0.0f, -1.0f), 1.0f, 90.0f));

    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, width_div_2), QVector3D(-1.0f, 0.0f, 0.0f), 1.0f, 120.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, width_div_2, -width_div_2), QVector3D(-1.0f, 0.0f, 0.0f), 0.0f, 120.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2), QVector3D(-1.0f, 0.0f, 0.0f), 0.0f, 120.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector3D(-1.0f, 0.0f, 0.0f), 1.0f, 120.0f));

    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, width_div_2), QVector3D(0.0f, -1.0f, 0.0f), 1.0f, 150.0f));
    vertexes.append(VertexData(QVector3D(-width_div_2, -width_div_2, -width_div_2), QVector3D(0.0f, -1.0f, 0.0f), 0.0f, 150.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, width_div_2), QVector3D(0.0f, -1.0f, 0.0f), 0.0f, 150.0f));
    vertexes.append(VertexData(QVector3D(width_div_2, -width_div_2, -width_div_2), QVector3D(0.0f, -1.0f, 0.0f), 1.0f, 150.0f));

    QVector<GLuint> indexes;

    primitiveCount = 0;

    for(GLuint i = 0; i < 24; i += 4)
    {
        indexes.append(i + 0);
        indexes.append(i + 1);
        indexes.append(i + 2);

        indexes.append(i + 2);
        indexes.append(i + 1);
        indexes.append(i + 3);

        primitiveCount += 2;
    }

    arrayBuffer.bind();
    arrayBuffer.allocate(vertexes.constData(), vertexes.size() * static_cast<int>(sizeof (VertexData)));
    arrayBuffer.release();

    indBuffer.bind();
    indBuffer.allocate(indexes.constData(), indexes.size() * static_cast<int>(sizeof (GLuint)));
    indBuffer.release();

    outputBuffer.bind();
    outputBuffer.allocate(3 * static_cast<int>(primitiveCount) * static_cast<int>(sizeof(float)));
    outputBuffer.release();
}

void FieldSceneDrawer::Renderer::clearGeometry()
{
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

QVariant FieldSceneDrawer::Renderer::compute()
{
    QVariant retVal;

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

    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, arrayBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, indBuffer.bufferId());
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 2, outputBuffer.bufferId());

    computeProgram.bind();
    computeProgram.setUniformValue("uViewPort", viewPort);
    computeProgram.setUniformValue("uRay", rayWorld);
    computeProgram.setUniformValue("uProjectionMatrix", projectionMatrix);
    computeProgram.setUniformValue("uMVMatrix", mvMatrix);

    glDispatchCompute(primitiveCount, 1, 1);

    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);

    computeProgram.release();

    sortProgram.bind();
    sortProgram.setUniformValue("uPrimitiveCount", primitiveCount);

    for(GLuint i = 0; i < primitiveCount; i++)
    {
        sortProgram.setUniformValue("uNumIteration", i);

        glDispatchCompute(primitiveCount/2, 1, 1);

        glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT | GL_SHADER_STORAGE_BARRIER_BIT | GL_BUFFER_UPDATE_BARRIER_BIT);
    }

    sortProgram.release();

    outputBuffer.bind();

    float out[3];

    outputBuffer.read(0, out, 3*sizeof (float));

    outputBuffer.release();

    if(out[2] > 0) retVal = out[1];

    return retVal;
}
