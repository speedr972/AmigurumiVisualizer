#ifndef PATTERNPARSER_H
#define PATTERNPARSER_H

#include <QObject>
#include "amigurumi/amigurumi.h"
#include "amigurumi/element.h"
#include "amigurumi/round.h"
#include "amigurumi/stitch.h"
class PatternParser
{
public:
    PatternParser();

    void parse(QString patternStr, Amigurumi *a);
    void parseLine(QString patternLineStr, Amigurumi *a);

    void resetParser();

private:
    int currentElement;
};

#endif // PATTERNPARSER_H
