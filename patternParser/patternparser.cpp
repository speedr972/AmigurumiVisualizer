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

    QRegExp roundStartRegExp("^(Rnd|Round)");


    if(patternLineStr.startsWith("-")){
        //NEW ELEMENT
        QString elementName = patternLineStr.mid(1);
        if(!elementName.isEmpty()){
            std::cout << "New element : " << elementName.toStdString() << std::endl;
            a->addElements(new Element(elementName));
            this->currentElement++;
        }

    }else if(patternLineStr.indexOf(roundStartRegExp)>=0){
        std::cout << "-----------------------------------------------" << std::endl;
        //NEW ROUND
        if(this->currentElement>=0){

            //extract round numbers parts
            int indexColon = patternLineStr.indexOf(":");
            QString roundNumberPartsString = patternLineStr.left(indexColon);

            //split round numbers
            QStringList roundNumberPartsStringList = roundNumberPartsString.split(" ", QString::SkipEmptyParts);
            QString roundIntervalString = roundNumberPartsStringList.at(1);
            int firstNumberIndex = roundNumberPartsString.indexOf(QRegExp("[0-9]+"));
            int hyphenIndex = roundNumberPartsString.indexOf(QRegExp("-"));

            std::cout << "roundIntervalString : " << roundIntervalString.toStdString() << std::endl;

            //QStringList splitRoundNumberPartsString = patternLineStr.mid(indexColon+1);
            int nbRounds = 1;
            if(hyphenIndex==-1){

            }else{
                QStringList minMaxRoundStringList = roundIntervalString.split("-");
                bool okFirst = false;
                bool okSecond = false;
                int firstNumber = minMaxRoundStringList.at(0).toInt(&okFirst);
                int lastNumber = minMaxRoundStringList.at(1).toInt(&okSecond);
                std::cout << firstNumber << ";" << lastNumber << std::endl;
                if(okFirst && okSecond){
                    nbRounds = lastNumber-firstNumber+1;
                }else{
                    std::cerr << "error parseint" << std::endl;
                }
            }
            std::cout << "nbRounds : " << nbRounds << std::endl;









            //Instructions parts
            QString stitchesPartStr = patternLineStr.mid(indexColon+1);
            std::cout << "stitchesPartStr : " <<stitchesPartStr.toStdString() << std::endl;
            int indexLeftBracket = stitchesPartStr.indexOf(QRegExp("\\["));
            std::cout << "index left bracket : " << indexLeftBracket << std::endl;
            if(indexLeftBracket!=-1){ //multiplier and right bracket must be present

                int indexRightBracket = stitchesPartStr.indexOf(QRegExp("\\]"));
                 QString instructionsBetweenBrackets = stitchesPartStr.mid(indexLeftBracket+1, indexRightBracket-indexLeftBracket-1);

                 std::cout << "instructions between brackets : " << instructionsBetweenBrackets.toStdString() << std::endl;
                QRegExp multiplierRegExp("(x[\\d]+)");

                int nbLoopsInstructions = 1;
                int multiplierIndex = multiplierRegExp.indexIn(stitchesPartStr);
                if(multiplierIndex!=-1){
                    QString multiplierSubString = multiplierRegExp.cap(0);

                    bool nbLoopsInstructionsBool = false;
                    nbLoopsInstructions = multiplierSubString.mid(1).toInt(&nbLoopsInstructionsBool);
                    if (!nbLoopsInstructionsBool){
                        std::cerr << "Impossible to convert multiplier into integer" << std::endl;
                    }
                    std::cout << "multiplier : " << nbLoopsInstructions << std::endl;
                }

                QStringList instructionsSplited = instructionsBetweenBrackets.split(",", QString::SkipEmptyParts);
                for(int roundRepeatNumber = 0; roundRepeatNumber <nbRounds; roundRepeatNumber++){
                    Round r;

                    for(int loopStitchesNum = 0; loopStitchesNum < nbLoopsInstructions; loopStitchesNum++){
                        for(int instructionNumber = 0; instructionNumber < instructionsSplited.size(); instructionNumber++){
                            QString currentInstruction = instructionsSplited.at(instructionNumber);
                            //std::cout << "current Instruction : " << currentInstruction.toStdString() << std::endl;
                            QRegExp stitchNumberRegexp("[\\d]+");
                            QRegExp stitchNameRegexp("(sc|inc|dec|ch|ss|hdc)");
                            int stitchNumberIndex = stitchNumberRegexp.indexIn(currentInstruction);
                            int stitchNameIndex = stitchNameRegexp.indexIn(currentInstruction);

                            QString nbStitchesStr = stitchNumberRegexp.cap(0);
                            int nbStitches = nbStitchesStr.toInt();
                            QString stitchName = stitchNameRegexp.cap(0);
                            std::cout << "nbStitches stitchName : " << nbStitches << " " << stitchName.toStdString() << std::endl;
                            if(QString::compare(stitchName, QString("sc"))){
                                r.addStitches(Stitch(StitchType::SINGLE_CROCHET), nbStitches);
                            }else if(QString::compare(stitchName, QString("inc"))){
                                r.addStitches(Stitch(StitchType::INCREASE), nbStitches);
                            }else if(QString::compare(stitchName, QString("dec"))){
                                r.addStitches(Stitch(StitchType::DECREASE), nbStitches);
                            }else if(QString::compare(stitchName, QString("ch"))){
                                r.addStitches(Stitch(StitchType::CHAIN), nbStitches);
                            }else if(QString::compare(stitchName, QString("ss"))){
                                r.addStitches(Stitch(StitchType::SLIP_STITCH), nbStitches);
                            }else if(QString::compare(stitchName, QString("hdc"))){
                                r.addStitches(Stitch(StitchType::HALF_DOUBLE_CROCHET), nbStitches);
                            }else{
                                //necessary ?
                            }

                        }

                    }
                    a->elements[this->currentElement]->addRound(r);

                }



            }else{
            }



            /*
            QRegExp nStitchesRegExp("[\[]");
            QRegExp nStitchesEndRegExp("[\]]");
            int indexMaxStitches = patternLineStr.indexOf(nStitchesRegExp);
            int indexMaxStitchesEnd = patternLineStr.indexOf(nStitchesEndRegExp);
            int nbStitchesStringSize = indexMaxStitchesEnd - indexMaxStitches;

            std::cout << "\t indexMaxStitches : "<< indexMaxStitches << ", indexMaxStitchesEnd : " << indexMaxStitchesEnd << ", nbStitchesStringSize : " << nbStitchesStringSize << std::endl;
            if(indexMaxStitches!=-1 && indexMaxStitchesEnd!=-1){
                QString nbStitchesString = patternLineStr.mid(indexMaxStitches, nbStitchesStringSize);
                //std::cout << "nbStitches : " << nbStitchesString.toStdString() << std::endl;
            }
            */




        }else{
            std::cerr << "Error : No elements defined before" << std::endl;
        }
    }
}

void PatternParser::resetParser()
{
    this->currentElement = -1;
}
