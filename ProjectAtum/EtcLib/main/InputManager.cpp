// InputManager.cpp: implementation of the CInputManager class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "AtumApplication.h"
#include "InputManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInputManager::CInputManager()
{
	g_pInputManager = this;
}

CInputManager::~CInputManager()
{
	g_pInputManager = NULL;
}
