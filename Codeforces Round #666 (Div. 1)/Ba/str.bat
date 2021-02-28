:beg
gen.exe > .in
main.exe < .in > outmain
slow.exe < .in > outslow
fc outmain outslow
if errorlevel 1 goto bug
goto beg
:bug
echo found!