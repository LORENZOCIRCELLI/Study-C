@echo off
for %%i in (testes\*.txt) do (
    echo Testando %%i
    code.exe < %%i
    echo -------------
)
pause