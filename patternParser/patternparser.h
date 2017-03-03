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
};

#endif // PATTERNPARSER_H
