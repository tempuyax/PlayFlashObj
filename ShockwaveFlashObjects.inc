
;--- Generated .INC file by COMView
;--- typelib name=ShockwaveFlashObjects
;--- documentation=Shockwave Flash
;--- GUID={D27CDB6B-AE6D-11CF-96B8-444553540000}
;--- Version 1.0, LCID 0

;--- prototypes too complex for MASM may exist
;--- if such ones reside in a vtable they will be replaced by dummies
;--- search for occurances of ';+++' to have a closer look at these

sTLBID_ShockwaveFlashObjects textequ <GUID {0D27CDB6Bh,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>
_MajorVer_ShockwaveFlashObjects equ 1
_MinorVer_ShockwaveFlashObjects equ 0

;--- IShockwaveFlash, Type=INTERFACE, GUID={D27CDB6C-AE6D-11CF-96B8-444553540000}

ifndef IShockwaveFlashVtbl
BEGIN_INTERFACE IShockwaveFlash, IDispatch
	STDMETHOD	get_ReadyState	, :ptr SDWORD
	STDMETHOD	get_TotalFrames	, :ptr SDWORD
	STDMETHOD	get_Playing	, :ptr BOOL
	STDMETHOD	put_Playing	, :BOOL
	STDMETHOD	get_Quality	, :ptr SDWORD
	STDMETHOD	put_Quality	, :SDWORD
	STDMETHOD	get_ScaleMode	, :ptr SDWORD
	STDMETHOD	put_ScaleMode	, :SDWORD
	STDMETHOD	get_AlignMode	, :ptr SDWORD
	STDMETHOD	put_AlignMode	, :SDWORD
	STDMETHOD	get_BackgroundColor	, :ptr SDWORD
	STDMETHOD	put_BackgroundColor	, :SDWORD
	STDMETHOD	get_Loop	, :ptr BOOL
	STDMETHOD	put_Loop	, :BOOL
	STDMETHOD	get_Movie	, :ptr BSTR
	STDMETHOD	put_Movie	, :BSTR
	STDMETHOD	get_FrameNum	, :ptr SDWORD
	STDMETHOD	put_FrameNum	, :SDWORD
	STDMETHOD	SetZoomRect	, :SDWORD,:SDWORD,:SDWORD,:SDWORD
	STDMETHOD	Zoom	, :SDWORD
	STDMETHOD	Pan	, :SDWORD,:SDWORD,:SDWORD
	STDMETHOD	Play	
	STDMETHOD	Stop	
	STDMETHOD	Back	
	STDMETHOD	Forward	
	STDMETHOD	Rewind	
	STDMETHOD	StopPlay	
	STDMETHOD	GotoFrame	, :SDWORD
	STDMETHOD	CurrentFrame	, :ptr SDWORD
	STDMETHOD	IsPlaying	, :ptr BOOL
	STDMETHOD	PercentLoaded	, :ptr SDWORD
	STDMETHOD	FrameLoaded	, :SDWORD,:ptr BOOL
	STDMETHOD	FlashVersion	, :ptr SDWORD
	STDMETHOD	get_WMode	, :ptr BSTR
	STDMETHOD	put_WMode	, :BSTR
	STDMETHOD	get_SAlign	, :ptr BSTR
	STDMETHOD	put_SAlign	, :BSTR
	STDMETHOD	get_Menu	, :ptr BOOL
	STDMETHOD	put_Menu	, :BOOL
	STDMETHOD	get_Base	, :ptr BSTR
	STDMETHOD	put_Base	, :BSTR
	STDMETHOD	get_Scale	, :ptr BSTR
	STDMETHOD	put_Scale	, :BSTR
	STDMETHOD	get_DeviceFont	, :ptr BOOL
	STDMETHOD	put_DeviceFont	, :BOOL
	STDMETHOD	get_EmbedMovie	, :ptr BOOL
	STDMETHOD	put_EmbedMovie	, :BOOL
	STDMETHOD	get_BGColor	, :ptr BSTR
	STDMETHOD	put_BGColor	, :BSTR
	STDMETHOD	get_Quality2	, :ptr BSTR
	STDMETHOD	put_Quality2	, :BSTR
	STDMETHOD	LoadMovie	, :SDWORD,:BSTR
	STDMETHOD	TGotoFrame	, :BSTR,:SDWORD
	STDMETHOD	TGotoLabel	, :BSTR,:BSTR
	STDMETHOD	TCurrentFrame	, :BSTR,:ptr SDWORD
	STDMETHOD	TCurrentLabel	, :BSTR,:ptr BSTR
	STDMETHOD	TPlay	, :BSTR
	STDMETHOD	TStopPlay	, :BSTR
	STDMETHOD	SetVariable	, :BSTR,:BSTR
	STDMETHOD	GetVariable	, :BSTR,:ptr BSTR
	STDMETHOD	TSetProperty	, :BSTR,:SDWORD,:BSTR
	STDMETHOD	TGetProperty	, :BSTR,:SDWORD,:ptr BSTR
	STDMETHOD	TCallFrame	, :BSTR,:SDWORD
	STDMETHOD	TCallLabel	, :BSTR,:BSTR
	STDMETHOD	TSetPropertyNum	, :BSTR,:SDWORD,:REAL8
	STDMETHOD	TGetPropertyNum	, :BSTR,:SDWORD,:ptr REAL8
	STDMETHOD	TGetPropertyAsNumber	, :BSTR,:SDWORD,:ptr REAL8
	STDMETHOD	get_SWRemote	, :ptr BSTR
	STDMETHOD	put_SWRemote	, :BSTR
	STDMETHOD	get_FlashVars	, :ptr BSTR
	STDMETHOD	put_FlashVars	, :BSTR
	STDMETHOD	get_AllowScriptAccess	, :ptr BSTR
	STDMETHOD	put_AllowScriptAccess	, :BSTR
	STDMETHOD	get_MovieData	, :ptr BSTR
	STDMETHOD	put_MovieData	, :BSTR
	STDMETHOD	get_InlineData	, :ptr LPUNKNOWN
	STDMETHOD	put_InlineData	, :LPUNKNOWN
	STDMETHOD	get_SeamlessTabbing	, :ptr BOOL
	STDMETHOD	put_SeamlessTabbing	, :BOOL
END_INTERFACE
endif

sIID_IShockwaveFlash textequ <IID {0D27CDB6Ch,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- IFlashFactory, Type=INTERFACE, GUID={D27CDB70-AE6D-11CF-96B8-444553540000}

ifndef IFlashFactoryVtbl
BEGIN_INTERFACE IFlashFactory, IUnknown
END_INTERFACE
endif

sIID_IFlashFactory textequ <IID {0D27CDB70h,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- IDispatchEx, Type=INTERFACE, GUID={A6EF9860-C720-11D0-9337-00A0C90DCAA9}

ifndef IDispatchExVtbl
BEGIN_INTERFACE IDispatchEx, IDispatch
	STDMETHOD	GetDispID	, :BSTR,:DWORD,:ptr SDWORD
	STDMETHOD	RemoteInvokeEx	, :SDWORD,:DWORD,:DWORD,:ptr DISPPARAMS,:ptr VARIANT,:ptr EXCEPINFO,:ptr IServiceProvider,:DWORD,:ptr DWORD,:ptr VARIANT
	STDMETHOD	DeleteMemberByName	, :BSTR,:DWORD
	STDMETHOD	DeleteMemberByDispID	, :SDWORD
	STDMETHOD	GetMemberProperties	, :SDWORD,:DWORD,:ptr DWORD
	STDMETHOD	GetMemberName	, :SDWORD,:ptr BSTR
	STDMETHOD	GetNextDispID	, :DWORD,:SDWORD,:ptr SDWORD
	STDMETHOD	GetNameSpaceParent	, :ptr LPUNKNOWN
END_INTERFACE
endif

sIID_IDispatchEx textequ <IID {0A6EF9860h,0C720h,011D0h,{093h,037h,000h,0A0h,0C9h,00Dh,0CAh,0A9h}}>

;--- IFlashObjectInterface, Type=INTERFACE, GUID={D27CDB72-AE6D-11CF-96B8-444553540000}

ifndef IFlashObjectInterfaceVtbl
BEGIN_INTERFACE IFlashObjectInterface, IDispatchEx
END_INTERFACE
endif

sIID_IFlashObjectInterface textequ <IID {0D27CDB72h,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- IServiceProvider, Type=INTERFACE, GUID={6D5140C1-7436-11CE-8034-00AA006009FA}

ifndef IServiceProviderVtbl
BEGIN_INTERFACE IServiceProvider, IUnknown
	STDMETHOD	RemoteQueryService	, :ptr GUID,:ptr GUID,:ptr LPUNKNOWN
END_INTERFACE
endif

sIID_IServiceProvider textequ <IID {06D5140C1h,07436h,011CEh,{080h,034h,000h,0AAh,000h,060h,009h,0FAh}}>

;--- _IShockwaveFlashEvents, Type=DISPATCH, GUID={D27CDB6D-AE6D-11CF-96B8-444553540000}

;--- dispinterface only
ifndef _IShockwaveFlashEventsVtbl
BEGIN_INTERFACE _IShockwaveFlashEvents, IDispatch
	DISPMETHOD	OnReadyStateChange	, :SDWORD
	DISPMETHOD	OnProgress	, :SDWORD
	DISPMETHOD	FSCommand	, :BSTR,:BSTR
END_INTERFACE
endif

sIID__IShockwaveFlashEvents textequ <IID {0D27CDB6Dh,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- ShockwaveFlash, Type=COCLASS, GUID={D27CDB6E-AE6D-11CF-96B8-444553540000}

sCLSID_ShockwaveFlash textequ <GUID {0D27CDB6Eh,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- FlashProp, Type=COCLASS, GUID={1171A62F-05D2-11D1-83FC-00A0C9089C5A}

sCLSID_FlashProp textequ <GUID {01171A62Fh,005D2h,011D1h,{083h,0FCh,000h,0A0h,0C9h,008h,09Ch,05Ah}}>

;--- FlashObjectInterface, Type=COCLASS, GUID={D27CDB71-AE6D-11CF-96B8-444553540000}

sCLSID_FlashObjectInterface textequ <GUID {0D27CDB71h,0AE6Dh,011CFh,{096h,0B8h,044h,045h,053h,054h,000h,000h}}>

;--- end of type library ---
