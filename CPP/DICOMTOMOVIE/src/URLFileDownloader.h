/*******************************************************************************
 *  Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 *  The contents of this file are subject to the Mozilla Public License
 *  Version 1.1 (the "License"); you may not use this file except in
 *  compliance with the License. You may obtain a copy of the License at
 *  http://www.mozilla.org/MPL/
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 *
 *  The Original Code is ICMA
 *
 *  The Initial Developer of the Original Code is University of Auckland,
 *  Auckland, New Zealand.
 *  Copyright (C) 2007-2010 by the University of Auckland.
 *  All Rights Reserved.
 *
 *  Contributor(s): Jagir R. Hussan
 *
 *  Alternatively, the contents of this file may be used under the terms of
 *  either the GNU General Public License Version 2 or later (the "GPL"), or
 *  the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 *  in which case the provisions of the GPL or the LGPL are applicable instead
 *  of those above. If you wish to allow use of your version of this file only
 *  under the terms of either the GPL or the LGPL, and not to allow others to
 *  use your version of this file under the terms of the MPL, indicate your
 *  decision by deleting the provisions above and replace them with the notice
 *  and other provisions required by the GPL or the LGPL. If you do not delete
 *  the provisions above, a recipient may use your version of this file under
 *  the terms of any one of the MPL, the GPL or the LGPL.
 *
 * "2014"
 *******************************************************************************/

#ifndef URLFILEDOWNLOADER_H_
#define URLFILEDOWNLOADER_H_
#include <curl/curl.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

class URLFileDownloader {
	std::string workingDir;
	std::vector<std::string> filenames;
	std::string userid;
	std::string password;
	std::string proxy;
	static int curl_init;
public:
	URLFileDownloader(std::string dir);
	inline void setUserPassword(std::string uid, std::string passwd);
	inline void setProxy(std::string url);
	virtual ~URLFileDownloader();

	int loadURLToFile(std::string uri, std::string filename);

};


inline void URLFileDownloader::setUserPassword(std::string uid, std::string passwd)
{
	userid = uid;
	password = passwd;
}

inline void URLFileDownloader::setProxy(std::string url)
{
	proxy = url;
}

#endif /* URLFILEDOWNLOADER_H_ */
