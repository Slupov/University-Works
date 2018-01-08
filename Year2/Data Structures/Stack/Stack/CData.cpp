#include <string>
#include "CData.h"

CData::CData()
{
}

CData::CData(int prio, int val, std::string data)
{
	m_nPrio = prio;
	m_nValue = val;
	m_sData = data;
};