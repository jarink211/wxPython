/////////////////////////////////////////////////////////////////////////////
// Name:        wx/cocoa/choice.h
// Purpose:     wxChoice class
// Author:      David Elliott
// Modified by:
// Created:     2003/03/16
// RCS-ID:      $Id: choice.h 38319 2006-03-23 22:05:23Z VZ $
// Copyright:   (c) 2003 David Elliott
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __WX_COCOA_CHOICE_H__
#define __WX_COCOA_CHOICE_H__

//#include "wx/cocoa/NSPopUpButton.h"
#include "wx/cocoa/NSMenu.h"

class WXDLLIMPEXP_BASE wxSortedArrayString;

// ========================================================================
// wxChoice
// ========================================================================
class WXDLLEXPORT wxChoice: public wxChoiceBase /*, protected wxCocoaNSPopUpButton */, protected wxCocoaNSMenu
{
    DECLARE_DYNAMIC_CLASS(wxChoice)
    DECLARE_EVENT_TABLE()
//    WX_DECLARE_COCOA_OWNER(NSTableView,NSControl,NSView)
// ------------------------------------------------------------------------
// initialization
// ------------------------------------------------------------------------
public:
    wxChoice() { Init(); }
    wxChoice(wxWindow *parent, wxWindowID winid,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            int n = 0, const wxString choices[] = NULL,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxChoiceNameStr)
    {
        Init();
        Create(parent, winid,  pos, size, n, choices, style, validator, name);
    }
    wxChoice(wxWindow *parent, wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            const wxArrayString& choices,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxChoiceNameStr)
    {
        Init();
        Create(parent, winid,  pos, size, choices, style, validator, name);
    }

    bool Create(wxWindow *parent, wxWindowID winid,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            int n = 0, const wxString choices[] = NULL,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxChoiceNameStr);
    bool Create(wxWindow *parent, wxWindowID winid,
            const wxPoint& pos,
            const wxSize& size,
            const wxArrayString& choices,
            long style = 0,
            const wxValidator& validator = wxDefaultValidator,
            const wxString& name = wxChoiceNameStr);
    virtual ~wxChoice();
protected:
    void Init();

// ------------------------------------------------------------------------
// Cocoa callbacks
// ------------------------------------------------------------------------
protected:
    void CocoaNotification_menuDidSendAction(WX_NSNotification notification);
// ------------------------------------------------------------------------
// Implementation
// ------------------------------------------------------------------------
public:
    virtual void Clear();
    virtual void Delete(unsigned int n);
    virtual unsigned int GetCount() const;
    virtual wxString GetString(unsigned int) const;
    virtual void SetString(unsigned int pos, const wxString&);
    virtual int FindString(const wxString& s, bool bCase = false) const;
    virtual int GetSelection() const;
    virtual int DoAppend(const wxString&);
    virtual int DoInsert(const wxString&, unsigned int pos);
    virtual void DoSetItemClientData(unsigned int, void*);
    virtual void* DoGetItemClientData(unsigned int) const;
    virtual void DoSetItemClientObject(unsigned int, wxClientData*);
    virtual wxClientData* DoGetItemClientObject(unsigned int) const;
    virtual void SetSelection(int pos);
protected:
    wxSortedArrayString *m_sortedStrings;
    wxArrayPtrVoid m_itemsClientData;
};

#endif // __WX_COCOA_CHOICE_H__
