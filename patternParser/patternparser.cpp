#include "patternparser.h"

PatternParser::PatternParser()
{

}

void PatternParser::parse(QString patternStr, Amigurumi *a)
{
    //Split per lines
    QRegExp nStitchesRegExp("\[[\d]+\]");
    QRegExp nStitchesEndRegExp("\]");

    QStringList stringList = patternStr.split("\n", QString::SkipEmptyParts);
    int nLines = stringList.count();
    int currentElement = -1;

    for(int i = 0; i<nLines; i++){
        QString currentLine = stringList.at(i);


        if(currentLine.startsWith("-")){
            //new element
            QString elementName = currentLine.mid(1);
            if(!elementName.isEmpty()){
                std::cout << "New element : " << elementName.toStdString() << std::endl;
                a->addElements(new Element(elementName));
                currentElement++;
            }


        }else if(currentLine.startsWith("Round:", Qt::CaseInsensitive) ||
                 currentLine.startsWith("Rnd:", Qt::CaseInsensitive)){
            //new round
            if(currentElement>=0){
                Round r;
                //extract max stitches
                int indexMaxStitches = currentLine.indexOf(nStitchesRegExp);
                int indexMaxStitchesEnd = currentLine.indexOf(nStitchesEndRegExp);
                int nbStitchesStringSize = indexMaxStitchesEnd - indexMaxStitches;

                if(indexMaxStitches!=-1 && indexMaxStitchesEnd!=-1){
                    QString nbStitchesString = currentLine.mid(indexMaxStitches, nbStitchesStringSize);
                    std::cout << "nbStitches : " << nbStitchesString.toStdString() << std::endl;
                }

            }
        }
    }

}
