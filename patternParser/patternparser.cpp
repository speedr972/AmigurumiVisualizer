#include "patternparser.h"

PatternParser::PatternParser()
{

}

void PatternParser::parse(QString patternStr, Amigurumi *a)
{

    resetParser();
    a->clearElements();

    //Split per lines
    QStringList stringList = patternStr.split("\n", QString::SkipEmptyParts);
    int nLines = stringList.count();


    for(int i = 0; i<nLines; i++){
        QString currentLine = stringList.at(i);
        parseLine(currentLine, a);
    }

}

void PatternParser::parseLine(QString patternLineStr, Amigurumi *a)
{
    //QRegExp nStitchesRegExp("\[[\d]+\]");
    QRegExp nStitchesRegExp("[\[]");
    QRegExp nStitchesEndRegExp("[\]]");
    //QRegExp roundStartRegExp("^(Rnd|Round)\s[\d]+\s:");
    QRegExp roundStartRegExp("^(Rnd|Round)[\s]*\d(-\d)?[\s]*:");

    std::cout << "nStitchesRegExp : " << nStitchesRegExp.isValid() << std::endl;
    std::cout << "nStitchesEndRegExp : " << nStitchesEndRegExp.isValid() << std::endl;
    std::cout << "roundStartRegExp : " << roundStartRegExp.isValid() << std::endl;



    if(patternLineStr.startsWith("-")){
        //NEW ELEMENT
        QString elementName = patternLineStr.mid(1);
        if(!elementName.isEmpty()){
            std::cout << "New element : " << elementName.toStdString() << std::endl;
            a->addElements(new Element(elementName));
            this->currentElement++;
        }

    }else if(patternLineStr.indexOf(roundStartRegExp)>=0){
        //NEW ROUND
        //QString roundLine = patternLineStr.left(10); //10 firsts character
        std::cout << patternLineStr.toStdString() << std::endl;
        if(this->currentElement>=0){
            Round r;
            //extract max stitches
            int indexMaxStitches = patternLineStr.indexOf(nStitchesRegExp);
            int indexMaxStitchesEnd = patternLineStr.indexOf(nStitchesEndRegExp);
            int nbStitchesStringSize = indexMaxStitchesEnd - indexMaxStitches;

            std::cout << "\t indexMaxStitches : "<< indexMaxStitches << ", indexMaxStitchesEnd : " << indexMaxStitchesEnd << ", nbStitchesStringSize : " << nbStitchesStringSize << std::endl;
            if(indexMaxStitches!=-1 && indexMaxStitchesEnd!=-1){
                QString nbStitchesString = patternLineStr.mid(indexMaxStitches, nbStitchesStringSize);
                std::cout << "nbStitches : " << nbStitchesString.toStdString() << std::endl;
            }

        }else{
            std::cerr << "Error : No elements defined before" << std::endl;
        }
    }
}

void PatternParser::resetParser()
{
    this->currentElement = -1;
}
