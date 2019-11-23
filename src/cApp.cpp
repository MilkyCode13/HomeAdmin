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

#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit()
{
    m_lang = (wxLanguage)wxLocale::GetSystemLanguage();
    m_locale.Init(m_lang, wxLOCALE_DONT_LOAD_DEFAULT);

    // The program is not installed in default location
    wxLocale::AddCatalogLookupPathPrefix("po");
    const wxLanguageInfo* lInfo = wxLocale::GetLanguageInfo(m_lang);
    m_locale.AddCatalog("HomeAdmin");
        
    m_frame = new cMainFrame(m_locale);
    m_frame->Show();
    return true;
}
