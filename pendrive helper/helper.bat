@ECHO OFF

SET unit=E
SET /P unit=Insira a unidade de disco do seu dispositivo

:a                                    
                                            ::verifica e exlui todos os arquivos que NÃO ESTÃO ocultos

SET f=teste
DIR /B /A -H -S| SET /P f             ::incompleto                         


FOR /f %%A IN ('DIR /a-d-s-h /b ^| FIND /v /c ""') DO SET cnt=%%A     ::se ainda houver arquivos não ocultos, volta para o começo da rotina
IF %A%>0 GOTO a

ATTRIB %unit%:\*.* /d /s +a -h -r -s

DEL "%unit%:\iso.vbs"
DEL "%unit%:\SystemValueInformation"

ECHO.Seus arquivos devem aparecer novamente. Obrigado por utilizar.
PAUSE
EXIT
