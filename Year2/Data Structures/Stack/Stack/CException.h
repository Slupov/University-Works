#pragma once
#include <string>

class CException
{
public:
	CException()
	{
		m_strErr = "Unknown exception";
	}

	CException(std::string err)
	{
		m_strErr = err;
	}

	std::string getErrMsg() { return m_strErr; }
private:
	std::string m_strErr;
};
