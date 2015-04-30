#include "oclint/AbstractSourceCodeReaderRule.h"
#include "oclint/RuleSet.h"

using namespace std;
using namespace oclint;

class NoTrailingWhiteSpaceRule : public AbstractSourceCodeReaderRule
{
public:
    virtual const string name() const override
    {
        return "NoTrailingWhiteSpace";
    }

    virtual int priority() const override
    {
        return 3;
    }

    virtual void eachLine(int lineNumber, string line) override
    {
        int currentLineSize = line.size();
        string description;
        description = "No trailing whitespace is allowed.";
        if (currentLineSize > 0 && isspace(line.at(currentLineSize - 1))) {
            addViolation(lineNumber, 1, lineNumber, currentLineSize, this, description);
        }

    }
};

static RuleSet rules(new NoTrailingWhiteSpaceRule());
