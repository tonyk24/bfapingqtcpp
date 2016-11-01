#ifndef BFEVENTRESULT_H
#define BFEVENTRESULT_H

#include "bftypes/event.h"
namespace BfLib
{
class BfEventResult {
public:
  BfEventResult(const BfEvent &event,
                int marketCount) :
    m_event(event),
    m_marketCount(marketCount)
  {
  }

  BfEvent m_event;
  int m_marketCount;
};
}

#endif // BFEVENTRESULT_H

