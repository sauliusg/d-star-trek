//
// Copyright (c) 1997 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// CUIPSfileSelect.cc   Initial author: N. Chen           15-Jul-1997
//    This file contains the methods to implement the user interface class
//    CUIPSfileSelect which implements a d*TREK print selection box.
/*
 *
 * Copyright (C) 2014 Rigaku Americas Corporation
 *                    9009 New Trails Drive
 *                    The Woodlands, TX, USA  77381
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice(s), this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice(s), this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the Rigaku Americas Corporation nor the 
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL RIGAKU AMERICAS CORPORATION BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS INTERUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
*/

//
// README: Portions of this file are merged at file generation
// time. Edits can be made *only* in between specified code blocks, look
// for keywords <Begin user code> and <End user code>.
//
/////////////////////////////////////////////////////////////
//
// Source file for CUIPSfileSelect
//
//    This file generated by Builder Xcessory 3.5.1.
//
//    This class is a user interface "component", as described
//    in "Object-Oriented Programming with C++ and OSF/Motif",
//    by Douglas Young, Prentice Hall, 1992. ISBN 0-13-630252-1
//
/////////////////////////////////////////////////////////////
#include <X11/StringDefs.h>
#include <Xm/FileSB.h>
#include <Xm/Form.h>
#include <Xm/Label.h>
#include <Xm/ScrolledW.h>
#include <Xm/Text.h>
#include "CUIPSfileSelect.h"

//
// Convenience functions from utilities file.
//
extern void RegisterBxConverters(XtAppContext);
extern XtPointer CONVERT(Widget, char *, char *, int, Boolean *);
extern XtPointer DOUBLE(double);
extern XtPointer SINGLE(float);
extern void MENU_POST(Widget, XtPointer, XEvent *, Boolean *);
extern Pixmap XPM_PIXMAP(Widget, char**);
extern void SET_BACKGROUND_COLOR(Widget, ArgList, Cardinal*, Pixel);


// Begin user code block <head> 
// End user code block <head> 

//
// This table is used to define class resources that are placed
// in app-defaults. This table is necessary so each instance
// of this class has the proper default resource values set.
// This eliminates the need for each instance to have
// its own app-defaults values. This table must be NULL terminated.
//
#if defined(cxx_bx_compat)

Boolean CUIPSfileSelect::_initAppDefaults = True;
UIAppDefault  CUIPSfileSelect::_appDefaults[] = {
    {"", NULL, "dialogTitle", NULL},
    {"", NULL, "selectionLabelString", NULL},
    {"", NULL, "okLabelString", NULL},
    {"", NULL, "filterLabelString", NULL},
    {"lbComment", NULL, "labelString", NULL},
    {NULL, NULL, NULL, NULL}
};
#endif

// These are default resources for widgets in objects of this class
// All resources will be prepended by *<name> at instantiation,
// where <name> is the name of the specific instance, as well as the
// name of the baseWidget. These are only defaults, and may be overriden
// in a resource file by providing a more specific resource name

String  CUIPSfileSelect::_defaultCUIPSfileSelectResources[] = {
        NULL
};

//
// Old style constructor, for compatibility only.
//
CUIPSfileSelect::CUIPSfileSelect(const char *name, Widget parent) : 
    UIComponent(name)
{
    
    // Begin user code block <alt_constructor> 
    // End user code block <alt_constructor> 
    create(parent);
}

//
// Class constructor.
//
CUIPSfileSelect::CUIPSfileSelect(const char *name) : UIComponent(name)
{
    
    // Begin user code block <constructor> 
  m_sHelpLine       = (Cstring)name + (Cstring) "$$"; // No default html file

  m_prvFileCallback = NULL; // Make sure the filecallback is initialized to NULL
  m_pObj            = NULL; //  and there is no object to pass in callback
    // End user code block <constructor> 
}

//
// Minimal Destructor. Base class destroys widgets.
//
CUIPSfileSelect::~CUIPSfileSelect() 
{
    
    // Begin user code block <destructor> 

  if (NULL != m_poXhelp)
    {
      delete m_poXhelp;
      m_poXhelp = NULL;
    }

    // End user code block <destructor> 
    delete _clientDataStructs;
}

//
// Handle creation of all widgets in the class.
//
void CUIPSfileSelect::create(Widget parent) 
{
    Arg      args[256];
    Cardinal ac=0;
    
    //
    // Load any class-defaulted resources for this object.
    //
    setDefaultResources(parent, _defaultCUIPSfileSelectResources);
    
#if defined(cxx_bx_compat)
    //
    // Setup app-defaults fallback table if not already done.
    //
    if (_initAppDefaults)
    {
        initAppDefaults(parent, "CUIPSfileSelect", _appDefaults);
        _initAppDefaults = False;
    }
    //
    // Now set the app-defaults for this instance.
    //
    setAppDefaults(parent, _appDefaults);
#endif
    
    //
    // Register the converters for the widgets.
    //
    RegisterBxConverters(XtWidgetToApplicationContext(parent)); 
    XtInitializeWidgetClass(xmFileSelectionBoxWidgetClass);
    XtInitializeWidgetClass(xmFormWidgetClass);
    XtInitializeWidgetClass(xmLabelWidgetClass);
    XtInitializeWidgetClass(xmScrolledWindowWidgetClass);
    XtInitializeWidgetClass(xmTextWidgetClass);
    
    //
    // Create an unmanaged widget as the top of the hierarchy.
    //
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 755); ac++;
    XtSetArg(args[ac], XmNy, 95); ac++;
    XtSetArg(args[ac], XmNwidth, 487); ac++;
    XtSetArg(args[ac], XmNheight, 562); ac++;
    _CUIPSfileSelect = XmCreateFileSelectionBox(parent,
        _name,
        args, 
        ac);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIPSfileSelect,
        XmNokCallback,
        CUIPSfileSelect::vPSfileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIPSfileSelect,
        XmNapplyCallback,
        CUIPSfileSelect::vPSfileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIPSfileSelect,
        XmNcancelCallback,
        CUIPSfileSelect::vPSfileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    
    _w = _CUIPSfileSelect;
    //
    // Install callback to guard against unexpected widget destruction..
    //
    installDestroyHandler();
    
    ac = 0;
    XtSetArg(args[ac], XmNresizePolicy, XmRESIZE_GROW); ac++;
    XtSetArg(args[ac], XmNheight, 120); ac++;
    _form = XmCreateForm(_CUIPSfileSelect,
        "form",
        args, 
        ac);
    XtManageChild(_form);
    
    ac = 0;
    XtSetArg(args[ac], XmNtraversalOn, False); ac++;
    XtSetArg(args[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
    XtSetArg(args[ac], XmNx, 0); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 208); ac++;
    XtSetArg(args[ac], XmNheight, 30); ac++;
    _lbComment = XmCreateLabel(_form,
        "lbComment",
        args, 
        ac);
    XtManageChild(_lbComment);
    
    ac = 0;
    XtSetArg(args[ac], XmNscrollingPolicy, XmAPPLICATION_DEFINED); ac++;
    XtSetArg(args[ac], XmNx, 0); ac++;
    XtSetArg(args[ac], XmNy, 30); ac++;
    XtSetArg(args[ac], XmNwidth, 465); ac++;
    XtSetArg(args[ac], XmNheight, 90); ac++;
    _scrolledWindow = XmCreateScrolledWindow(_form,
        "scrolledWindow",
        args, 
        ac);
    XtManageChild(_scrolledWindow);
    
    ac = 0;
    XtSetArg(args[ac], XmNeditMode, XmMULTI_LINE_EDIT); ac++;
    _tfComment = XmCreateText(_scrolledWindow,
        "tfComment",
        args, 
        ac);
    XtManageChild(_tfComment);
    
    ac = 0;
    XtSetArg(args[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNtopOffset, 30); ac++;
    XtSetArg(args[ac], XmNbottomOffset, 0); ac++;
    XtSetArg(args[ac], XmNleftOffset, 0); ac++;
    XtSetArg(args[ac], XmNrightOffset, 0); ac++;
    XtSetValues(_scrolledWindow, args, ac);
    
    // Begin user code block <endcreate> 

    // Add the help callback
    
    m_poXhelp = new CXhelp(_w);

    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = (UIComponent *)m_poXhelp;
    _clientDataStructs->client_data = (XtPointer) (m_sHelpLine.string());
    XtAddCallback(_CUIPSfileSelect,
		  XmNhelpCallback,
		  CXhelp::vHTMLHelpCallback,
		  (XtPointer)_clientDataStructs);

    // End user code block <endcreate> 
}

//
// Classname access.
//
const char *const CUIPSfileSelect::className()
{
    return ("CUIPSfileSelect");
}

void CUIPSfileSelect::vPSfileSelectCBCallback(Widget w, 
		XtPointer clientData, XtPointer callData)
{
    UICallbackStruct *data = (UICallbackStruct *) clientData;
    CUIPSfileSelect *obj = (CUIPSfileSelect *)data->object;
    obj->vPSfileSelectCB(w, data->client_data, callData);
}

void CUIPSfileSelect::vPSfileSelectCB (Widget w, XtPointer clientData, XtPointer callData)
{
    
    // Begin user code block <vPSfileSelectCB> 

  XmFileSelectionBoxCallbackStruct *pCBS
    = (XmFileSelectionBoxCallbackStruct *) callData;

  if (XmCR_CANCEL == pCBS->reason)
    {
      XtUnmanageChild(w);
    }
  else if (XmCR_OK == pCBS->reason)
    {
      XtUnmanageChild(w);
      // Ok
      char    *pcTemp;
      if (XmStringGetLtoR(pCBS->value,
#if (XmVersion >= 1002)
			   XmFONTLIST_DEFAULT_TAG,
#else
			   XmSTRING_DEFAULT_CHARSET,
#endif
			   &pcTemp))
	{
	  m_sPSFilename = pcTemp;
	}
      XtFree(pcTemp);
      pcTemp = XmTextGetString(_tfComment);
      m_sComment = pcTemp;

      XtFree(pcTemp);
      // If a callback has been specified, then call it

      if (NULL != m_prvFileCallback)
	{
	  m_prvFileCallback(m_pObj, m_sPSFilename, m_sComment);
	}
    }
  else if (XmCR_APPLY == pCBS->reason)
    {
      // Filter
    }
  else if (XmCR_HELP == pCBS->reason)
    {
      // How to pass in help for this widget?
      // No need, it was done above!
    }

    // End user code block <vPSfileSelectCB> 
}

// Begin user code block <tail> 

void
CUIPSfileSelect::vSetFilename(const Cstring& sFilename)
{
  m_sPSFilename = sFilename;
  XmString stxTemp;

  stxTemp = XmStringCreateLtoR(m_sPSFilename.string(),
#if (XmVersion >= 1002)
			       XmFONTLIST_DEFAULT_TAG);
#else
			       XmSTRING_DEFAULT_CHARSET);
#endif
  if (NULL != stxTemp)
    {
      XtVaSetValues(_CUIPSfileSelect, XmNtextString, stxTemp, NULL);
      XmStringFree(stxTemp);
    }
}

void
CUIPSfileSelect::vSetComment(const Cstring& sComment)
{
  m_sComment = sComment;
  XmTextSetString(_tfComment, sComment.string());
}

Cstring 
CUIPSfileSelect::sGetComment(void)
{
  return (m_sComment);
}

Cstring 
CUIPSfileSelect::sGetFilename(void)
{
  return (m_sPSFilename);
}
// End user code block <tail> 
