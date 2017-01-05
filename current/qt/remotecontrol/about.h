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

#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include "ui_about.h"

class About :public QDialog, private Ui_About_Base
{
     public:
          About();
          ~About();
     private:
          Ui_About_Base aboutBase;
};


#endif //ABOUT_H
