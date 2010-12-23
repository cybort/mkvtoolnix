/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   version information

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __MTX_COMMON_VERSION_H
#define __MTX_COMMON_VERSION_H

#include <string>

#define MTX_VERSION_CHECK_URL "http://mkvtoolnix-releases.bunkus.org/latest-release.xml"
#define MTX_VERSION_INFO_URL  "http://mkvtoolnix-releases.bunkus.org/releases.xml"

struct version_number_t {
  unsigned int parts[5];
  bool valid;

  version_number_t();
  version_number_t(const std::string &s);
  version_number_t(const version_number_t &v);

  bool operator <(const version_number_t &cmp) const;
  int compare(const version_number_t &cmp) const;

  std::string to_string() const;
};

struct mtx_release_version_t {
  version_number_t current_version, latest_source, latest_windows_build;
  bool valid;

  mtx_release_version_t();
};

std::string MTX_DLL_API get_version_info(const std::string &program, bool full = false);
int MTX_DLL_API compare_current_version_to(const std::string &other_version_str);
version_number_t MTX_DLL_API get_current_version();

# if defined(HAVE_CURL_EASY_H)
mtx_release_version_t MTX_DLL_API get_latest_release_version();
# endif  // defined(HAVE_CURL_EASY_H)

#endif  // __MTX_COMMON_VERSION_H
