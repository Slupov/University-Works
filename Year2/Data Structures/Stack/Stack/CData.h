#pragma once
#include <string>
using namespace std;

class CData
{
public:
	CData();

	CData(int prio, int val, string data);

	friend ostream& operator<<(ostream& out, const CData data)
	{
		out << data.m_nPrio << " " << data.m_nValue << " " << data.m_sData;
		return out;
	}

	friend istream& operator>>(istream& in, CData& data)
	{
		in >> data.m_nPrio >> data.m_nValue >> data.m_sData;
		return in;
	}

private:
	int m_nPrio;
	int m_nValue;
	string m_sData;
};
