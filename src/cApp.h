/*
 *  HomeAdmin - Home Linux server administration tool.
 *
 *  HomeAdmin is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HomeAdmin is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HomeAdmin.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <wx/wx.h>
#include <wx/intl.h>
#include "cMainFrame.h"

class cApp : public wxApp
{
private:
    cMainFrame* m_frame = nullptr;

public:
    virtual bool OnInit();

protected:
    wxLanguage m_lang;
    wxLocale m_locale;
};
