/*
  wxcommon.h

  Written by Moritz Bunkus <moritz@bunkus.org>
  Parts of this code were written by Florian Wager <root@sirelvis.de>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version $Id$
    \brief definitions for wxWindows
    \author Moritz Bunkus <moritz@bunkus.org>
*/

#ifndef __WXCOMMON_H
#define __WXCOMMON_H

#if defined(wxUSE_UNICODE) && wxUSE_UNICODE
//# error Sorry, mkvtoolnix cannot be compiled if wxWindows has been built with Unicode support.
# if defined(SYS_WINDOWS)
#  error Sorry, mkvtoolnix cannot be compiled on Windows if wxWindows has been built with Unicode support.
#  define wxS(s)                /* not implemented yet */
# else
#  define wxS(s) wxString(s, wxConvUTF8)
# endif
# define WXS "%ls"
# define wxCS(s) ((const wchar_t *)s.wc_str())
# define wxMB(s) ((const char *)s.mb_str(wxConvUTF8))
# define WXUNICODE 1
#else
# define wxS(s) s
# define WXS "%s"
# define wxCS(s) ((const char *)s.c_str())
# define wxMB(s) ((const char *)s.c_str())
# define WXUNICODE 0
#endif
#define wxCS2WS(s) wxS(s.c_str())

#endif /* __WXCOMMON_H */
