@echo off

rem normally, only 127 patches can be applied to an msi

set /A ii=0

rem msiexec /i DentalWingsUpdateHelper.msi /qn
rem echo original product installed

:repeat

msiexec /update GoogleUpdateHelperPatch.msp REINSTALL=ALL /qn /L*v patchapply%ii%.log
echo patch %ii% applied
if %ii% GEQ 127 pause
msiexec /uninstall {75791684-1D4C-4423-B29B-825C71bE4A67} /package {7E1E0758-17F6-4924-9AC6-63DD97406D7F} /qn /L*v patchremove%ii%.log
echo patch %ii% removed

set /A ii=%ii%+1

if %ii% NEQ 300 goto repeat
rem if %ii% NEQ 127 goto repeat

set ii=
