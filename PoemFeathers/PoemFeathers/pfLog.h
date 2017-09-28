#pragma once

namespace PoemFeathers
{
	class pfCore_API pfLog
	{
	public:
		pfLog();
		~pfLog();
		static  pfLog*		GetLog() { return m_pSelf; }
		void				Log(const char* strLog, size_t nSize);
	private:
		FILE*				m_pFileLog;
		static pfLog*		m_pSelf;
	};
}


