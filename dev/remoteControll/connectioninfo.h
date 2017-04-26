/*
 * Copyright 2010
 * Richie Adams, Charles Amey, Donald Kinder, Chance Sheets
 * 

This file is part of Remote Control.

Remote Control is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Remote Control.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONNECTIONINFO_H
#define CONNECTIONINFO_H

#include "ui_connectioninfobase.h"

class QDialog;
class QString;

/*!
* ConnectionInfo class.  dialog box to get the ip address and port number of the server
* @author Charles Amey
* @version 0.1
*/
class ConnectionInfo : public QDialog, private Ui_ConnectionInfoBase
{
	Q_OBJECT
	public:
		/*!
		*constructor to create a new object
		*/
		ConnectionInfo();
		/*!
		Returns the ip address
		*/
		QString getIp();
		/*!
		returns the port number
		*/
		QString getPort();
	public slots:
		/*!
		handler for the ok button
		*/
		void okClicked();
	private:
		/*!
		the base class object
		*/
		Ui_ConnectionInfoBase connectInfo;
		/*!
		contains the ip address
		*/
		QString ip;
		/*!
		contains the port number
		*/
		QString port;

};

#endif