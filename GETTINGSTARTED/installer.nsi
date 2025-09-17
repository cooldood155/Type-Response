!include "MUI2.nsh"

; Define product details
!define PRODUCT_NAME "Type + Response"
!define PRODUCT_VERSION "1.0"
!define PRODUCT_PUBLISHER "Evan Reumann"

; Installer settings
Name "${PRODUCT_NAME}"
OutFile "TypeResponse_Installer.exe"
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"
RequestExecutionLevel admin

; Pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

Section "Install"
  ; Where to install the files
  SetOutPath "$INSTDIR"

  ; Copy the built app into the install directory
  ; ⚠️ This path must be correct relative to your .nsi file!
  File "x64\Release\TypeResponse.exe"

  ; Create a desktop shortcut to the APP
  CreateShortcut "$DESKTOP\${PRODUCT_NAME}.lnk" "$INSTDIR\TypeResponse.exe"
SectionEnd

Section "Uninstall"
  ; Remove installed files
  Delete "$INSTDIR\TypeResponse.exe"
  Delete "$DESKTOP\${PRODUCT_NAME}.lnk"
  RMDir "$INSTDIR"
SectionEnd