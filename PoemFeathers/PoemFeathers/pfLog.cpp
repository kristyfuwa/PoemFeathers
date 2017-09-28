#include "pfPrivatePCH.h"

namespace PoemFeathers
{
	pfLog*	pfLog::m_pSelf = 0;

	pfLog::pfLog()
	{
		m_pSelf = this;
		fopen_s(&m_pFileLog, "pfLog.log", "wb");
		assert(m_pFileLog != nullptr);
		if (m_pFileLog == nullptr)
		{
			char text[2048] = { 0 };
			sprintf_s(text, "fopen_s return NULL,error r = %d\n", GetLastError());
		}
	}


	pfLog::~pfLog()
	{
		if (m_pFileLog)
		{
			fclose(m_pFileLog);
		}
	}

	void pfLog::Log(const char* strLog, size_t nSize)
	{
		assert(strLog != nullptr);
		char	text[2048] = { 0 };
		sprintf_s(text, "%s\n", strLog);
		size_t  len = strlen(text);
		if (m_pFileLog)
			fwrite(text, 1, len, m_pFileLog);

	}
}


