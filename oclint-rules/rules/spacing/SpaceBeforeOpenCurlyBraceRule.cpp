#include "oclint/AbstractSourceCodeReaderRule.h"
#include "oclint/RuleSet.h"
#include "oclint/util/StdUtil.h"

using namespace std;
using namespace oclint;

class SpaceBeforeOpenCurlyBraceRule : public AbstractSourceCodeReaderRule
{
public:
    virtual const string name() const override
    {
        return "space before open curly brace";
    }

    virtual int priority() const override
    {
        return 2;
    }

    virtual void eachLine(int lineNumber, string line) override
    {
        string curly_brace = "{";
        int pos = line.find(curly_brace);
        int currentLineSize = line.size();
        string description;
        if (pos != std::string::npos) {
            if (pos != currentLineSize - 1) {
                description = "{ must occur at the end of the line.";
                addViolation(lineNumber, 1, lineNumber, currentLineSize, this, description);
            } else {
              if (currentLineSize > 2 && (!isspace(line.at(currentLineSize - 2)) || isspace(line.at(currentLineSize - 3)))) {
                    description = "{ must have exactly one space preceding it.";
                    addViolation(lineNumber, 1, lineNumber, currentLineSize, this, description);
              } else if (currentLineSize == 1 || isspace(line.at(0))) {
                    description = "{ must be in line with the method or compound statement declaration.";
                    addViolation(lineNumber, 1, lineNumber, currentLineSize, this, description);
              }
            }
        }
    }
};

static RuleSet rules(new SpaceBeforeOpenCurlyBraceRule());
