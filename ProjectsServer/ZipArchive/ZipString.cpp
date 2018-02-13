////////////////////////////////////////////////////////////////////////////////
// This source file is part of the ZipArchive library source distribution and
// is Copyrighted 2000 - 2014 by Artpol Software - Tadeusz Dracz
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// For the licensing details refer to the License.txt file.
//
// Web Site: http://www.artpol-software.com
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ZipString.h"

#ifdef _ZIP_IMPL_STL
	std::locale CZipString::m_gCurrentLocale = std::locale("");
	#if defined __GNUC__ && !defined __MINGW32__ 
		std::locale CZipString::m_gGlobalLocale = std::locale();
		std::locale CZipString::m_gClassicLocale = std::locale::classic();
	#endif
#endif
	
ZIPSTRINGCOMPARE GetCZipStrCompFunc(bool bCaseSensitive, bool bCollate)
{
	if (bCollate)
		return bCaseSensitive ? & CZipString::Collate : & CZipString::CollateNoCase;
	else
		return bCaseSensitive ? & CZipString::Compare : & CZipString::CompareNoCase;
}


ZIP_API bool ZipArchiveLib::IsStringAscii(const CZipString& value)
{
	for (int i = 0; i < value.GetLength(); i++)
#if !defined __GNUC__ || defined __MINGW32__
		if (!_istascii(value[i]))
#else
		if (!isascii(value[i]))
#endif
			return false;
	return true;
}
