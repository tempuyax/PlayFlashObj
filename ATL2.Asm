; ==================================================================================================
; ATL2.asm
; Title:   Pahor1.asm
; Author:  Pahor.m  @ April 2020
; Version: 1.0.0
; Purpose: Main Assembler of Play Flash Object.
;          Dipersembahkan Untuk Hari Ulang Tahun ku yg KE-47
; ==================================================================================================

.386
.model flat, stdcall  ;32 bit memory model
option casemap :none  ;case sensitive

include windows.inc
include user32.inc
include kernel32.inc
include comdlg32.inc
include Comctl32.inc
include shell32.inc
include advapi32.inc
include gdi32.inc
include shlwapi.inc
include D:\masm32\m32lib\masm32.inc


includelib user32.lib
includelib kernel32.lib
includelib comdlg32.lib
includelib Comctl32.lib
includelib shell32.lib
includelib advapi32.lib
includelib gdi32.lib
includelib shlwapi.lib
includelib D:\masm32\m32lib\masm32.lib
     
DlgProc			PROTO	:HWND,:UINT,:WPARAM,:LPARAM
PlayerWin       PROTO	:HWND
GMalloc 		PROTO 	:DWord, :DWORD
GMemFree 		PROTO 	:DWord
Malloc 			PROTO 	:DWord, :DWORD
MemFree 		PROTO 	:DWord


Scall Macro Method:Req, Args:VarArg
    LOCAL   ArgList
    ArgList TEXTEQU <>
      
    IFNB <Args>
        FOR Arg,<Args>
            ArgList CATSTR <Arg>,<,>,ArgList
        ENDM
    ArgList SubStr ArgList, 1, @SizeStr(%ArgList) - 1
    ArgList CATSTR <!<>,ArgList,<!>>

    %FOR parameter,ArgList
        push parameter
    ENDM
    ENDIF

    Call Method
ENDM

Icall Macro pInterface:Req, Method:Req, Args:VarArg
    LOCAL   ArgList
    ArgList TEXTEQU <>
      
    IFNB <Args>
        FOR Arg,<Args>
            ArgList CATSTR <Arg>,<,>,ArgList
        ENDM
    ArgList SubStr ArgList, 1, @SizeStr(%ArgList) - 1
    ArgList CATSTR <!<>,ArgList,<!>>

    %FOR parameter,ArgList
        push parameter
    ENDM
    ENDIF

    mov eax,pInterface
    push eax
    mov eax,[eax]
    Call [Eax].Method
    ;call    dword ptr[eax+Method]
ENDM

;IUnknown Methods
IUnknown Struct
   QueryInterface DWord ?
   AddRef         DWord ?
   Release        DWord ?
IUnknown EndS

include OFlash.inc

.const
IDD_DIALOG		equ 1000
;#########################################################################
.data
szDLL			   db	"atl.dll",0
szAtlAxWinInit     db	"AtlAxWinInit",0    ; ATL Function 
szAtlAxGetControl  db   "AtlAxGetControl",0 ; ATL Function 
szAtlAxWin         db   "AtlAxWin",0        ; ATL Window Class Name  
szCLSID_Swf		   db 	"{D27CDB6E-AE6D-11CF-96B8-444553540000}",0 ; ShockwaveFlash ClassID
szCLSID_Calendar   db   "{8E27C92B-1264-101C-8A2F-040224009C02}",0 ; Calendar ClassID
szCLSID_Sound      db   "{22D6F312-B0F6-11D0-94AB-0080C74C7E95}",0 ; Sound ClassID
szCLSID_Graphics   db   "{369303C2-D7AC-11D0-89D5-00A0C90833E6}",0 ; Graphics ClassID

szFileName	       db  "biohome2.swf",0 ; File target
szBksl             db 	"\",0

IID_IFlash         sIID_IFlash ; from OFlash.inc

AtlAxWinInit       dd  ? ;Pointer "AtlAxWinInit"
AtlAxGetControl    dd  ? ;Pointer "AtlAxGetControl"

pIUnknown          dd  ? ;Pointer IUnknown

pIFlash            dd  ? ;Pointer IFlash 

.data?
hInstance	       dd ?
hPlayWin           dd ?
hLib			   dd ?
Buffer             dd 512 dup (?)
hCurDir            db 512 dup(?)

;#########################################################################

.code
start:

	invoke GetModuleHandle,NULL
	mov	   hInstance,eax

    invoke InitCommonControls

    ; Get Handle "atl.dll"
    invoke LoadLibrary,offset szDLL
    .if eax
	    mov hLib,eax
        ; Get Pointer "AtlAxWinInit"
	    invoke GetProcAddress,hLib,addr szAtlAxWinInit
	    mov AtlAxWinInit, eax 
        ; Get Pointer "AtlAxGetControl"
	    invoke GetProcAddress,hLib,addr szAtlAxGetControl
	    mov AtlAxGetControl, eax
        ; Execution Function "AtlAxWinInit" on ATL Initialition
	    Scall AtlAxWinInit
			.if eax
				invoke DialogBoxParam,hInstance,IDD_DIALOG,NULL,addr DlgProc,NULL
			.endif   
		Invoke FreeLibrary,hLib
	.endif   
	invoke ExitProcess,0

;########################################################################

DlgProc proc hWnd:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

	.if uMsg==WM_INITDIALOG
		invoke PlayerWin, hWnd
     
	.elseif uMsg==WM_CLOSE
		invoke EndDialog, hWnd, 0

	.else
		mov eax,FALSE
		ret

	.endif
	mov	eax,TRUE
	ret
DlgProc endp

PlayerWin PROC hWnd:DWORD
	Local lpWideCharStr[512*2]:Byte
	
    ; Init Directory
	invoke GetCurrentDirectory,sizeof hCurDir,addr hCurDir
	invoke lstrcat,addr hCurDir,addr szBksl
	invoke lstrcat,addr hCurDir,addr szFileName ; nama file tggl rubah

    ;View Flahsh Object
	invoke CreateWindowEx,0,addr szAtlAxWin, addr szCLSID_Swf, WS_CHILD or WS_VISIBLE,
	                            0,0,435,299,hWnd,NULL,hInstance,NULL
	mov hPlayWin,eax
	
	;menjalankan fungsi "AtlAxGetControl"(hWnd,pIUnknown)
    Scall AtlAxGetControl,  hPlayWin, offset pIUnknown
    .if (eax == 0) && (pIUnknown != 0)
		;Harus Menambahkan referensi interface dgn Pointer pIUnknown
		Icall pIUnknown, IUnknown.AddRef

		;mengambil Pointer interface IFlash, inputkan IID_IFlash dan 
		;simpan outputnya ditempat pointer pIFlash
		;INGAT! Harus mengetahui IID Interface nya, Bukan CLSID nya
		;       dalam windows terdapat banyak sekali interface dan masing2
		;       memiliki InterfaceID (IID)
		Icall pIUnknown, IUnknown.QueryInterface, offset IID_IFlash, offset pIFlash
	    .if pIFlash
			;Tahap 1 menggelar interface "IFlash"
			;tambah referensi interface dgn Pointer pIFlash
			Icall pIFlash, IFlash.AddRef

			;Tahap 2 pembebasan interface "IUnknown" sebab tdk digunakan lagi
			;Bebaskan interface IUnknown dgn Pointer pIUnknown
			Icall pIUnknown, IUnknown.Release 

			;Tahap 3 mengunakan fungsi2 metode interface "IFlash"
			;Pada interface parameternya berlaku format2 khusus, contoh;
			;  - String: format tipe BString 
			;  - Bool:   format tipe VARIANT_FALSE/VARIANT_TRUE 

		    ;Memasukan Target Nama File "biohome2.swf" (BStr) yg juga memiliki EMBED Flash 
		    Invoke MultiByteToWideChar, CP_ACP, 0, Addr hCurDir, -1, Addr lpWideCharStr, SizeOf lpWideCharStr
		    Invoke SysAllocString, Addr lpWideCharStr
		    Icall pIFlash, IFlash.put_Movie, eax 
		    Icall pIFlash, IFlash.put_EmbedMovie, eax 
		    Invoke SysFreeString, Addr lpWideCharStr
            
            ;Menghilangkan Menu
            Icall pIFlash, IFlash.put_Menu, VARIANT_FALSE
		    
		    ;Memainkan Flash
		    Icall pIFlash, IFlash.Play 
		.endif
	.endif
	ret
PlayerWin endp

end start
