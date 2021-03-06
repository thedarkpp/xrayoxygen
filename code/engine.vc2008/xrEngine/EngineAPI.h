﻿// EngineAPI.h: interface for the CEngineAPI class.
//
//****************************************************************************
// Support for extension DLLs
//****************************************************************************
#pragma once

// Abstract 'Pure' class for DLL interface
class ENGINE_API DLL_Pure {
public:
	CLASS_ID				CLS_ID;
	DWORD					SpectreObjectId;

	DLL_Pure(void *params)	{CLS_ID=0; };
	DLL_Pure()				{CLS_ID=0; };
	virtual	DLL_Pure*		_construct		()	{ return this; 	}
	virtual ~DLL_Pure();
};

// Class creation/destroying interface
extern "C" {
typedef DLL_API  DLL_Pure*	  __cdecl Factory_Create	(CLASS_ID	CLS_ID);
typedef DLL_API  void		  __cdecl Factory_Destroy	(DLL_Pure*	O);
};

class ENGINE_API		CEngineAPI
{
private:
	HMODULE				hGame;
	HMODULE				hRender;
public:
	BENCH_SEC_SCRAMBLEMEMBER1
	Factory_Create*		pCreate;
	Factory_Destroy*	pDestroy;
	void				Initialize	();
	void				InitializeRenderer();
	void				Destroy		();

	CEngineAPI	();
	~CEngineAPI	();
};

ENGINE_API void InitSettings();
ENGINE_API void InitConsole();
ENGINE_API void InitInput();
ENGINE_API void InitInput(bool bExclusiveMode);
ENGINE_API void InitSound1();
ENGINE_API void InitSound2();


#define NEW_INSTANCE(a)		Engine.External.pCreate(a)
#define DEL_INSTANCE(a)		{ Engine.External.pDestroy(a); a=0; }
