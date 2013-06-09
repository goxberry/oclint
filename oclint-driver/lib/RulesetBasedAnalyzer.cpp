#include <llvm/Support/Debug.h>
#include <llvm/Support/raw_ostream.h>

#include "oclint/Results.h"
#include "oclint/RuleBase.h"
#include "oclint/RuleCarrier.h"
#include "oclint/RuleSet.h"
#include "oclint/RulesetBasedAnalyzer.h"
#include "oclint/ViolationSet.h"

using namespace oclint;

void RulesetBasedAnalyzer::preprocess(std::vector<clang::ASTContext *> &contexts)
{
    DEBUG({
        llvm::dbgs() << "Start pre-processing:\n";
    });
    for (int cntxtIdx = 0, numCntxt = contexts.size(); cntxtIdx < numCntxt; cntxtIdx++)
    {
        DEBUG({
            llvm::dbgs() << ".";
        });
    }
    DEBUG({
        llvm::dbgs() << "\n";
    });
}

void RulesetBasedAnalyzer::analyze(std::vector<clang::ASTContext *> &contexts)
{
    DEBUG({
        llvm::dbgs() << "Start analyzing:\n";
    });
    for (int cntxtIdx = 0, numCntxt = contexts.size(); cntxtIdx < numCntxt; cntxtIdx++)
    {
        DEBUG({
            llvm::dbgs() << ".";
        });
        ViolationSet *violationSet = new ViolationSet();
        RuleCarrier *carrier = new RuleCarrier(contexts.at(cntxtIdx), violationSet);
        for (int ruleIdx = 0, numRules = RuleSet::numberOfRules(); ruleIdx < numRules; ruleIdx++)
        {
            RuleSet::getRuleAtIndex(ruleIdx)->takeoff(carrier);
        }
        Results *results = Results::getInstance();
        results->add(violationSet);
    }
    DEBUG({
        llvm::dbgs() << "\n";
    });
}

void RulesetBasedAnalyzer::postprocess(std::vector<clang::ASTContext *> &contexts)
{
    DEBUG({
        llvm::dbgs() << "Start post-processing:\n";
    });
    for (int cntxtIdx = 0, numCntxt = contexts.size(); cntxtIdx < numCntxt; cntxtIdx++)
    {
        DEBUG({
            llvm::dbgs() << ".";
        });
    }
    DEBUG({
        llvm::dbgs() << "\n";
    });
}
