/*
 * Copyright 2010-2013
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

#include <QDebug>
#include <QFile>
#include "about.h"

//constructor
About::About()
{
     aboutBase.setupUi(this);
     QString programName = "Remote Control";
     
     QString licenseFileName = "COPYING";
     QString path = "/usr/share/doc/remotecontrol-";
     
     QString info = "";
     aboutBase.programName->setText(programName + " " + APP_VERSION);
     
     //open up the authors file,  copyright info
     //QFile authorsFile(":/authors");
     QFile authorsFile("authors");
     if (authorsFile.exists())
     {
          //open the authors file
          if(authorsFile.open(QIODevice::ReadOnly))
          {
               QTextStream ts (&authorsFile);
               info = info + ts.readAll();
               info = info + "\n";
          }
     }
     //open up the GPL license file
     QFile license(licenseFileName);
     QFile docpathlicense(path+APP_VERSION+"/"+licenseFileName);
     //make sure the file is there
     if (license.exists())  
     {
          //open the gpl license file
          if (license.open(QIODevice::ReadOnly))
          {
               QTextStream ts (&license);
               info += ts.readAll();
          }
          else
          {
               info = "Please see \"http://www.gnu.org/licenses\" for the license to this program.";
          }
     }
     else if (docpathlicense.exists())
     {
          if (docpathlicense.open(QIODevice::ReadOnly))
          {
               QTextStream t(&docpathlicense);
               info = info + t.readAll();
          }
          else
               info = "Please see \"http://www.gnu.org/licenses\" for the license to this program.";
     }
     else
     {
          info = "Please see \"http://www.gnu.org/licenses\" for the license to this program.";
     }
     //put the text into the box
     aboutBase.license->setText(info);
} //end about constructor

//destructor
About::~About()
{
}
