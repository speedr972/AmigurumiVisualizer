#include "modelelement.h"


/*
ModelElement::ModelElement()
{
    this->vertices = nullptr;
    this->normals = nullptr;
    this->colors = nullptr;
    this->indices = nullptr;
    this->e = nullptr;
}
*/

ModelElement::ModelElement(Element *el)
{
    this->vertices = nullptr;
    this->normals = nullptr;
    this->colors = nullptr;
    this->indices = nullptr;
    this->e = el;

}

ModelElement::~ModelElement()
{
    if(this->vertices!=nullptr)free(this->vertices);
    if(this->normals!=nullptr)free(this->normals);
    if(this->colors!=nullptr)free(this->colors);
    if(this->indices!=nullptr)free(this->indices);

}

void ModelElement::update()
{
    if(this->e!=nullptr){
        int nbCols = e->getMaxStitchesRound();
        int nbRows = e->getRounds().size();
        int nbVertices = nbCols * (nbRows+2);

        this->vertices = (float*)malloc(3*nbVertices*sizeof(float));
        this->normals = (float*)malloc(3*nbVertices*sizeof(float));
        this->colors = (float*)malloc(4*nbVertices*sizeof(float));
        this->indices = (int*)malloc(6*(nbCols-1)*(nbRows-1) * sizeof(int));
        std::vector<QVector3D> normalVertices;
        for(int o = 0; o<nbVertices; o++){
            normalVertices.push_back(QVector3D());
        }

        int vertexPointer = 0;
        float radius;
        float angle;



        //up cap
        radius = 0.01f;
        for(int j = 0; j<nbCols; j++){
            angle = (float)j/nbCols * (2.0f*(float)M_PI);
            this->vertices[vertexPointer*3] = radius * qCos(angle);
            this->vertices[vertexPointer*3+1] = 0;
            this->vertices[vertexPointer*3+2] = radius * qSin(angle);

            this->colors[vertexPointer*3] = 0.0f;
            this->colors[vertexPointer*3+1] = 1.0f;
            this->colors[vertexPointer*3+2] = 1.0f;
            this->colors[vertexPointer*3+3] = 1.0f;
            vertexPointer++;
        }

        //cylinder
        for(int i =0; i<nbRows; i++ ){
            Round r = e->getRounds().at(i);
            int nbStiches = r.getNbStitches();
            radius = (float)nbStiches/(2.0f*(float)M_PI);
            for(int j = 0; j<nbCols; j++){
                angle = (float)j/nbCols * (2.0f*(float)M_PI);
                this->vertices[vertexPointer*3] = radius * qCos(angle);
                this->vertices[vertexPointer*3+1] = i;
                this->vertices[vertexPointer*3+2] = radius * qSin(angle);

                this->colors[vertexPointer*3] = 0.0f;
                this->colors[vertexPointer*3+1] = 1.0f;
                this->colors[vertexPointer*3+2] = 1.0f;
                this->colors[vertexPointer*3+3] = 1.0f;
                vertexPointer++;
            }
        }

        //bottom cap
        radius = 0.01f;
        for(int j = 0; j<nbCols; j++){
            angle = (float)j/nbCols * (2.0f*(float)M_PI);
            this->vertices[vertexPointer*3] = radius * qCos(angle);
            this->vertices[vertexPointer*3+1] = nbRows-1;
            this->vertices[vertexPointer*3+2] = radius * qSin(angle);

            this->colors[vertexPointer*3] = 0.0f;
            this->colors[vertexPointer*3+1] = 1.0f;
            this->colors[vertexPointer*3+2] = 1.0f;
            this->colors[vertexPointer*3+3] = 1.0f;
            vertexPointer++;
        }


        QVector3D p1, p2, normalFace;
        //generate normals and indices
        int pointer = 0;
        for(int i = 0; i < nbRows-1; i++){
            for(int j = 0; j<nbCols-1; j++){
                int topLeft = i*nbCols + j;
                int topRight = topLeft+1;
                int bottomLeft = (i+1)*nbCols + j;
                int bottomRight = bottomLeft+1;

                QVector3D vTopLeft(this->vertices[topLeft*3], this->vertices[topLeft*3+1], this->vertices[topLeft*3+2]);
                QVector3D vTopRight(this->vertices[topRight*3], this->vertices[topRight*3+1], this->vertices[topRight*3+2]);
                QVector3D vBottomLeft(this->vertices[bottomLeft*3], this->vertices[bottomLeft*3+1], this->vertices[bottomLeft*3+2]);
                QVector3D vBottomRight(this->vertices[bottomRight*3], this->vertices[bottomRight*3+1], this->vertices[bottomRight*3+2]);

                //Face topLeft->bottomLeft->topRight
                p1 = vBottomLeft-vTopLeft;
                p2 = vTopRight-vTopLeft;
                normalFace = QVector3D::crossProduct(p1, p2).normalized();
                normalVertices.at(topLeft) += normalFace;
                normalVertices.at(bottomLeft) += normalFace;
                normalVertices.at(topRight) += normalFace;

                //Face topRight->bottomLeft->bottomRight
                p1 = vTopRight-vBottomRight;
                p2 = vBottomLeft-vBottomRight;
                normalFace = QVector3D::crossProduct(p1, p2).normalized();
                normalVertices.at(topRight) += normalFace;
                normalVertices.at(bottomLeft) += normalFace;
                normalVertices.at(bottomRight) += normalFace;

                //indices
                this->indices[pointer++] = topLeft;
                this->indices[pointer++] = bottomLeft;
                this->indices[pointer++] = topRight;
                this->indices[pointer++] = topRight;
                this->indices[pointer++] = bottomLeft;
                this->indices[pointer++] = bottomRight;
            }
        }

        //create vertice normal array
        for(int i = 0; i<normalVertices.size(); i++){
            QVector3D n = normalVertices.at(i).normalized();
            this->normals[i*3] = n.x();
            this->normals[i*3+1] =n.y();
            this->normals[i*3+2] =n.z();
        }








    }

}
