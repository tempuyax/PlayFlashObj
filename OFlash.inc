; ==================================================================================================
; OFlash.inc
; Title:   Pahor1.asm
; Author:  Pahor.m  @ April 2020
; Version: 1.0.0
; Purpose: Include File of Interface Flash Object.
;          Dipersembahkan Untuk Hari Ulang Tahun ku yg KE-47
; ==================================================================================================

; Adalah IID INTERFACE nya, dari tools ComView.exe
;--- IShockwaveFlash, Type=INTERFACE, GUID={D27CDB6C-AE6D-11CF-96B8-444553540000}

include    oleaut32.inc
includelib oleaut32.lib

sIID_IFlash textequ <IID {0D27CDB6Ch,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;IFlash Methode
IFlash Struct
	QueryInterface        DWord ?
	AddRef                DWord ?
	Release               DWord ?
	GetTypeInfoCount      DWord ?
	GetTypeInfo           DWord ?
	GetIDsOfNames         DWord ?
	Invoke_               DWord ?
	get_ReadyState	      DWord ? ;  :ptr SDWORD
	get_TotalFrames	      DWord ? ;  :ptr SDWORD
	get_Playing	          DWord ? ;  :ptr BOOL
	put_Playing	          DWord ? ;  :BOOL
	get_Quality	          DWord ? ;  :ptr SDWORD
	put_Quality	          DWord ? ;  :SDWORD
	get_ScaleMode	      DWord ? ;  :ptr SDWORD
	put_ScaleMode	      DWord ? ;  :SDWORD
	get_AlignMode	      DWord ? ;  :ptr SDWORD
	put_AlignMode	      DWord ? ;  :SDWORD
	get_BackgroundColor	  DWord ? ;  :ptr SDWORD
	put_BackgroundColor	  DWord ? ;  :SDWORD
	get_Loop	          DWord ? ;  :ptr BOOL
	put_Loop	          DWord ? ;  :BOOL
	get_Movie	          DWord ? ;  :ptr BSTR
	put_Movie	          DWord ? ;  :BSTR
	get_FrameNum	      DWord ? ;  :ptr SDWORD
	put_FrameNum	      DWord ? ;  :SDWORD
	SetZoomRect	          DWord ? ;  :SDWORDDWord ? ; :SDWORDDWord ? ; :SDWORDDWord ? ; :SDWORD
	Zoom	              DWord ? ;  :SDWORD
	Pan	                  DWord ? ;  :SDWORDDWord ? ; :SDWORDDWord ? ; :SDWORD
	Play	              DWord ? ;  NOTHING
	Stop	              DWord ? ;  NOTHING
	Back	              DWord ? ;  NOTHING
	Forward	              DWord ? ;  NOTHING
	Rewind	              DWord ? ;  NOTHING
	StopPlay	          DWord ? ;  NOTHING
	GotoFrame	          DWord ? ;  :SDWORD
	CurrentFrame	      DWord ? ;  :ptr SDWORD
	IsPlaying	          DWord ? ;  :ptr BOOL
	PercentLoaded	      DWord ? ;  :ptr SDWORD
	FrameLoaded	          DWord ? ;  :SDWORDDWord ? ; :ptr BOOL
	FlashVersion	      DWord ? ;  :ptr SDWORD
	get_WMode	          DWord ? ;  :ptr BSTR
	put_WMode	          DWord ? ;  :BSTR
	get_SAlign	          DWord ? ;  :ptr BSTR
	put_SAlign	          DWord ? ;  :BSTR
	get_Menu	          DWord ? ;  :ptr BOOL
	put_Menu	          DWord ? ;  :BOOL
	get_Base	          DWord ? ;  :ptr BSTR
	put_Base	          DWord ? ;  :BSTR
	get_Scale	          DWord ? ;  :ptr BSTR
	put_Scale	          DWord ? ;  :BSTR
	get_DeviceFont	      DWord ? ;  :ptr BOOL
	put_DeviceFont	      DWord ? ;  :BOOL
	get_EmbedMovie	      DWord ? ;  :ptr BOOL
	put_EmbedMovie	      DWord ? ;  :BOOL
	get_BGColor	          DWord ? ;  :ptr BSTR
	put_BGColor	          DWord ? ;  :BSTR
	get_Quality2	      DWord ? ;  :ptr BSTR
	put_Quality2	      DWord ? ;  :BSTR
	LoadMovie	          DWord ? ;  :SDWORDDWord ? ; :BSTR
	TGotoFrame	          DWord ? ;  :BSTRDWord ? ; :SDWORD
	TGotoLabel	          DWord ? ;  :BSTRDWord ? ; :BSTR
	TCurrentFrame	      DWord ? ;  :BSTRDWord ? ; :ptr SDWORD
	TCurrentLabel	      DWord ? ;  :BSTRDWord ? ; :ptr BSTR
	TPlay	              DWord ? ;  :BSTR
	TStopPlay	          DWord ? ;  :BSTR
	SetVariable	          DWord ? ;  :BSTRDWord ? ; :BSTR
	GetVariable	          DWord ? ;  :BSTRDWord ? ; :ptr BSTR
	TSetProperty	      DWord ? ;  :BSTRDWord ? ; :SDWORDDWord ? ; :BSTR
	TGetProperty	      DWord ? ;  :BSTRDWord ? ; :SDWORDDWord ? ; :ptr BSTR
	TCallFrame	          DWord ? ;  :BSTRDWord ? ; :SDWORD
	TCallLabel	          DWord ? ;  :BSTRDWord ? ; :BSTR
	TSetPropertyNum	      DWord ? ;  :BSTRDWord ? ; :SDWORDDWord ? ; :REAL8
	TGetPropertyNum	      DWord ? ;  :BSTRDWord ? ; :SDWORDDWord ? ; :ptr REAL8
	TGetPropertyAsNumber  DWord ? ;  :BSTRDWord ? ; :SDWORDDWord ? ; :ptr REAL8
	get_SWRemote	      DWord ? ;  :ptr BSTR
	put_SWRemote	      DWord ? ;  :BSTR
	get_FlashVars	      DWord ? ;  :ptr BSTR
	put_FlashVars	      DWord ? ;  :BSTR
	get_AllowScriptAccess DWord ? ;  :ptr BSTR
	put_AllowScriptAccess DWord ? ;  :BSTR
	get_MovieData	      DWord ? ;  :ptr BSTR
	put_MovieData	      DWord ? ;  :BSTR
	get_InlineData	      DWord ? ;  :ptr LPUNKNOWN
	put_InlineData	      DWord ? ;  :LPUNKNOWN
	get_SeamlessTabbing	  DWord ? ;  :ptr BOOL
	put_SeamlessTabbing	  DWord ? ;  :BOOL
IFlash EndS


 