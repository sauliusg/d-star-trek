//
// Copyright (c) 1996 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// CDevShutter.cc      Initial author: J.W. Pflugrath           10-Dec-1995
//  This file contains the member functions of class CDevShutter which
//     is derived from base class ADevShutter
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
//+Description
//
//+ToDo
//
//   Error messages need implementing
//
//+Include files

#include "CDevShutter.h"

//+Code begin

//+Public functions

// Constructors, destructors and assignments

CDevShutter::CDevShutter(const Cstring sName)
{
  m_sName = sName;
  vConstruct();
}

CDevShutter::~CDevShutter()
{
  (void) nDone();
  vDestruct();
}

void
CDevShutter::vConstruct(void)
{
//  cout << "CDevShutter::vConstruct called!\n";
  m_eState         = eDevShutterState_Unknown;
  m_dMaxTime       = 360000;
  m_dMinTime       = 0.0;
  m_dSetTime       = 0.0;
  m_dRequestedTime = 0.0;
  m_dElapsedTime   = 0.0;
  m_dTimeToOpen    = 0.0;
  m_dTimeToClose   = 0.0;
  m_sStatusMsg     = "No shutter status message";
}

void
CDevShutter::vDestruct(void)
{
//  cout << "CDevShutter::vDestruct called!\n";
}
